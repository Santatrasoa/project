#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "util.h"

void head(){
    printf("<!DOCTYPE>\n");
    printf("<html>\n");
    printf(
        "<head>\n"
            "<meta charset='UTF-8'>\n"
            "<title>Gestion de Site</title>\n"        
    );
}

AllSiteDepend getinfo(char * link){
    AllSiteDepend getterInfo;
    sscanf(link, "%*[^=]=%[^&]", getterInfo.nomConf);
    sscanf(link, "%*[^&]&%*[^=]=%[^&]", getterInfo.serverName);
    sscanf(link, "%*[^&]&%*[^&]&%*[^=]=%[^&]", getterInfo.serverAdmin);
    sscanf(link, "%*[^&]&%*[^&]&%*[^&]&%*[^=]=%[^&]", getterInfo.documentRoot);
    sscanf(link, "%*[^&]&%*[^&]&%*[^&]&%*[^&]&%*[^=]=%[^&]", getterInfo.directoryIndex);
    sscanf(link, "%*[^&]&%*[^&]&%*[^&]&%*[^&]&%*[^&]&%*[^=]=%s",getterInfo.mot_de_passe);
    
    if (*getterInfo.directoryIndex == 0){
			strcpy(getterInfo.directoryIndex, "index.html");
	 }
    
    return getterInfo;
}

void writeFileConf(AllSiteDepend information){
    char nomConf[500];
    char createFile[200];
    FILE * conf;
    FILE * file;
    char * docRoot = convertHexa(information.documentRoot);
    char * servAdmin = convertHexa(information.serverAdmin);
	sprintf(createFile, "sudo touch %s.conf", information.nomConf);
    sprintf(nomConf, "%s.conf", information.nomConf);
    conf = popen(createFile, "w");

    if (conf == NULL){
        printf("<h1>Le fichier %s.conf n'a pas pu être créer<h1>", information.nomConf);
        exit(1);
    }
    pclose(conf);

    file = changePermission(nomConf);
    conf = fopen(nomConf, "w");
    if (conf == NULL){
        printf("RETURN");
        exit(1);
    }

    fprintf(conf,
         "<VirtualHost *:80>\n"
             "\tServerName %s\n"
             "\tServerAdmin %s\n\n"
             "\tDocumentRoot %s\n\n"
             "\tErrorLog ${APACHE_LOG_DIR}/error.log\n"
             "\tCustomLog ${APACHE_LOG_DIR}/access.log combined\n\n"
             "\t<Directory %s>\n"
                 "\t\tOptions +ExecCGI\n"
                 "\t\tAllowOverride All\n"
                 "\t\tAddHandler cgi-script .cgi .li\n"
                 "\t\tDirectoryIndex %s\n"
                 "\t\tRequire all granted\n"
             "\t</Directory>\n\n"
         "</VirtualHost>\n"
         ,information.serverName, servAdmin, docRoot, docRoot, information.directoryIndex
        
    );
    fclose(conf);
}

char *convertHexa(char *message){
    char *result = (char*)malloc(sizeof(char)*255);
    int j=0;
    int i=0;
    while(i<strlen(message)){
        if(message[i]=='%'){
            int tmp;
            sscanf(&message[i+1], "%02x", &tmp);
            result[j] = tmp;
            j++;
            i+=3;
        }
        else{
            result[j]=message[i];
            j++;
            i++;
        }
    }
    return result;
}

void moveFile(AllSiteDepend information){
    char commande_de_copie[500];
    sprintf(commande_de_copie, "sudo mv %s.conf /etc/apache2/sites-available", information.nomConf);
    popen(commande_de_copie,"w");
}

void activate(AllSiteDepend information){
    char commande_d_activation[500];
    sprintf(commande_d_activation, "sudo a2ensite %s", information.nomConf);
    popen(commande_d_activation, "w");
    popen("sudo systemctl reload apache2", "w");

}

void etcHosts(AllSiteDepend information){
    char commande_ecriture_hosts[500];
    sprintf(commande_ecriture_hosts,"sudo sh -c 'echo 127.0.0.1\t%s >> /etc/hosts'", information.serverName);
    popen(commande_ecriture_hosts, "w");
}

FILE * changePermission(char * nameOfFile){
    FILE * file = NULL;
    char tmp[100];
    sprintf(tmp, "sudo chmod o+w %s", nameOfFile);
    file = popen(tmp, "w");
    if (file == NULL){
        printf("Erreur lors du changement du permission");
        exit(1);
    }
    pclose(file);
    return file;
}

FileConf * getListFile(int * number_of_site){
    FileConf * listSite = (FileConf*)malloc(sizeof(FileConf)*100);
    FILE * listfile = popen("ls /etc/apache2/sites-available", "r");
    char listSiteEnabled[100][100];
    char list[100];
    int nbrOfSiteAvailable = 0, nbrOfSiteEnabled = 0, i, j, flags = 0;


    if (listfile == NULL){
        perror ("Erreur !!!");
    }
    while (fgets(list, sizeof(list), listfile)){
        strcpy(listSite[nbrOfSiteAvailable].nameFile, list);
        nbrOfSiteAvailable ++;
    }
    pclose(listfile);
    listfile = popen("ls /etc/apache2/sites-enabled", "r");
    
    if (listfile == NULL){
        perror ("Erreur !!!");
    }

    while (fgets(list, sizeof(list), listfile)){    
        strcpy(listSiteEnabled[nbrOfSiteEnabled], list);
        nbrOfSiteEnabled ++;
    }
    pclose(listfile);

    for (i = 0; i < nbrOfSiteAvailable; i++){
        for (j = 0; j < strlen(listSite[i].nameFile); j++){
            if (listSite[i].nameFile[j] == '\n')    listSite[i].nameFile[j] = '\0';
        }
    }

    for (i = 0; i < nbrOfSiteEnabled; i++){
		for (j = 0; j < strlen(listSiteEnabled[i]); j++){
            if (listSiteEnabled[i][j] == '\n')    listSiteEnabled[i][j] = '\0';
		}
	}

	for (i = 0; i < nbrOfSiteAvailable; i++){
		flags = 0;
		for (j = 0; j < nbrOfSiteEnabled; j++){
			if (strstr(listSite[i].nameFile, listSiteEnabled[j])){
				flags = 1;
			}
		}
		if (flags == 1){
			strcpy(listSite[i].status, "Activate");
            strcpy(listSite[i].notStatus, "Deactivate");
		}
		else{
			strcpy(listSite[i].status, "Deactivate");
            strcpy(listSite[i].notStatus, "Activate");
		}
	}
    *number_of_site = nbrOfSiteAvailable;
    return listSite;
}


void showList(FileConf * allFile, int number_of_site){
    int i;
    printf(
        "<table>"
            "<th>File Conf</th>"
            "<th>Status</th>"
            "<th>Change Status</th>"
    );
    for (i = 0; i < number_of_site; i++){
        printf(
            "<tr>"
                "<td>%s</td>"
                "<td>%s</td>"
                "<td><a href='http://www.gestion.mit/listSite.cgi?%s=%s'><input type='button' value='%s'><a></td>"
            "</tr>"
            , allFile[i].nameFile, allFile[i].status ,allFile[i].notStatus,allFile[i].nameFile,allFile[i].notStatus
        );
    }
    printf("</table>");
}

AccessContent * infoAccess(int * number_of_site){
    AccessContent * info;
    char lineAccess[1000], removeNonUtil[1000];
    int index = 0, number;
    FILE * accessLog = popen("sudo cat /var/log/apache2/access.log", "r");

    number = countLine();

    info = (AccessContent*)malloc(sizeof(AccessContent)*number);

    // printf("number : %d", number);

    if (accessLog == NULL){
        perror("Erreur Lors De L'Ouverture Du Fichier Access.log");
        exit(1);
    }

    while (fgets(lineAccess, sizeof(lineAccess), accessLog)){
		sscanf(lineAccess, "%15s - - [%49[^]]] \"%*s %199[^\"]\"", info[index].ipAdress, info[index].date, removeNonUtil);
        sscanf(removeNonUtil, "%[^?]", info[index].nameOfSite);
        index ++;
    }
    * number_of_site = index;
    pclose(accessLog);
    return info; 
}

void showListAccess(char * string, int number_of_site, int num_pag,AccessContent * info){
    AccessContent * tmp = (AccessContent*)malloc(sizeof(AccessContent)*number_of_site);
    int i, j=0, c;
    for (i = 0; i < number_of_site; i++){
        if (strstr(info[i].nameOfSite, string)){
            tmp[j] = info[i];
            j++;
        }
    }
    printf("<main>");
    if (j == 0){
        printf("<h1 class='text-center display-4'>Site Not Found</h1>");
    }
    else{
        printf("<div>\n<table>\n"
            "<th>Name of Site</th>"
            "<th>Ip Address</th>"
            "<th>Date</th>"
        );

        for (i = (num_pag-1)*10; i < (num_pag*10) && i<j; i++){
            printf(
                "<tr>"
                "<td>%s</td>"
                "<td>%s</td>"
                "<td>%s</td>"
                "</tr>"
                , tmp[i].nameOfSite, tmp[i].ipAdress, tmp[i].date
            );
        }
    }

    printf("</table>"
		"</main>"
	);

	printf("<br>");

	printf("<footer>"
		"<ul class='page'>"
	);
	c = j/10;
	if(j%10!=0)
		c++;

	if(num_pag<=5){
		for(int i=0;i<10;i++){
			if(i==c) break;
			printf(
					"<a href='/listAccess.cgi?name=%s&page=%d' class='active'>"
						"<li>%d</li>"
					"</a>"
					,string,i+1,i+1
					);
		}
		if (c > 5)
			printf("  ...  "
			"<a href='/listAccess.cgi?name=%s&page=%d' class='active'>"
				"<li>%d</li>"
			"</a>"
			,string, c, c
			);
	}
	else{
		printf(
		"<a href='/listAccess.cgi?name=%s&page=1' class='active'>"
			"<li>1</li>"
		"</a>"
		"  ...  "
		,string
		);
		for(int i=num_pag-4;i<num_pag+6;i++){
			if(i==c) break;
			printf(
					"<a href='/listAccess.cgi?name=%s&page=%d' class='active'>"
						"<li>%d</li>"
					"</a>"
					,string,i+1,i+1
					);
		}
		
		if (num_pag <= c - 5)
		
		printf("  ...  "
		"<a href='/listAccess.cgi?name=%s&page=%d' class='active'>"
			"<li>%d</li>"
		"</a>"
		,string, c, c
		);
	}

	printf("</ul></footer>");

}

int countLine(){
    char number[100];
    FILE * countLineAccess = popen("sudo cat /var/log/apache2/access.log | wc -l", "r");
    fgets(number, 99, countLineAccess);
    pclose(countLineAccess);
    return atoi(number);
}
