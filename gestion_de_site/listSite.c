#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "verification.h"

int main() {
    FileConf * fileConf;
    int number_of_site, i, flags = verif();
    char * url = getenv("QUERY_STRING");
    char status[100], nameOfSite[100], commande[300];
    sscanf(url, "%[^=]=%s",status, nameOfSite);
    
    if (flags == 0){
        printf("location: http://www.gestion.mit/login.html\n\n");
    }
    
    else if (flags == 1){
        printf("content-type: text/html\n\n");

        if (strcmp(status, "Deactivate") == 0){
            i = 0;
            sprintf(commande, "sudo a2dissite %s", nameOfSite);
            popen(commande, "w");
            if(i==0){
                printf("<meta http-equiv='refresh' content='0; url=http://www.gestion.mit/listSite.cgi'>");
            }
            i++;
            popen("sudo service apache2 reload", "w");
        }
        else if (strcmp(status, "Activate") == 0){
            i = 0;
            sprintf(commande, "sudo a2ensite %s", nameOfSite);
            popen(commande, "w");
            if(i==0)
                printf("<meta http-equiv='refresh' content='0; url=http://www.gestion.mit/listSite.cgi'>");
            i++;
            popen("sudo service apache2 reload", "w");
        }
        
        head();
        printf("<link rel='stylesheet' type='text/css' href='css/table.css'>"
            "<link rel='stylesheet' href='css/adminlte.min.css'>"
            "<link rel='stylesheet' href='css/all.min.css'>"
            "<link rel='stylesheet' href='css/acceuil.css'>"
        );
        printf("</head>\n<body>");

        printf(
            "<section>"
            "<h1><a href='http://www.gestion.mit' class='home'><img src='img/home.png' class='img'>Home</a></h1>"
            "</section>"
        );

        fileConf = getListFile(&number_of_site);
        showList(fileConf, number_of_site);

        
        printf(
            "</body>"
            "</html>"
        );
    }
    return 0;
}
