#include <stdbool.h>

#include "get_info.h"


int test(char * user, char * password){
	int flags = 0;
	FILE * deconnexion = fopen(".deconnected.mit", "w+");
	FILE * log = fopen(".login.mit", "r");
	if (deconnexion == NULL){
		printf("Erreur!!!");
		exit(1);
	}
	if (log == NULL){
		printf("Erreur!!!");
		exit(1);
	}
	char str[100];
	while (fgets(str, 99, log)){

		char tmp[100], tmp1[100];

		sscanf(str, "%[^=]=%[^\n]", tmp, tmp1);
		if ((strcmp(user, tmp ) == 0) && (strcmp(password, tmp1) == 0)){
				flags = 1;
				fprintf(deconnexion, "true\n");
				break;
		}
	}

	fclose(log);
	
	return flags;
}

void show(char* str, int num_pag){
	int number, j=0;
	Name * auth = pic(&number);
	Name * tmp = (Name*)malloc(sizeof(Name)*number);

	for (int i = 0; i < number; i++){
		if (strcmp(auth[i].user,str) == 0){
			tmp[j] = auth[i];
			j++;
		}
	}
	
	if (j == 0){
		printf("<h5>User %s Not Found</h5>", str);
		printf("<div class='box_search'><h5><a href='http://www.user.mit' class='research'>Research</a></h5></div>");
	}
	else{
		printf("<table>"
		"<tr>"
			"<th style=\"width:30vw;font-size:20px;\">Date</th>\n"
			"<th style=\"width:30vw;font-size:20px;\">User</th>\n"
			"<th style=\"width:30vw;font-size:20px;\">Session</th>\n"
		"</tr>"
		);
		
		
		for (int i = (num_pag-1)*10; i < (num_pag*10) && i<j; i++){
			if (strcmp(tmp[i].session, "opened") == 0){
				printf("<tr class='opened'>\n");
					printf("<td>%s</td>\n", tmp[i].date);
					printf("<td>%s</td>\n", tmp[i].user);
					printf("<td>%s</td>\n", tmp[i].session);
				printf("</tr>");
			}
			if (strcmp(tmp[i].session, "closed") == 0){
				printf("<tr class='closed'>\n");
					printf("<td>%s</td>\n", tmp[i].date);
					printf("<td>%s</td>\n", tmp[i].user);
					printf("<td>%s</td>\n", tmp[i].session);
				printf("</tr>");
			}
		}
		printf("<div class='box_search'><h5><a href='http://www.user.mit' class='research'>Research</a></h5><div>");

		printf("</table>");
	}


	printf("<table style='border:10px;'><tr>");
	int c=j/10;
	if(j%10!=0)
		c++;

	if(num_pag<=5){
		for(int i=0;i<10;i++){
			if(i==j) break;
			printf(
					"<td><li><a href=\"/source.cgi?users=%s&value=%d\" style='text-decoration:none;padding-right:8px;color:pink;border:10px'>%d</a></li></td>"
					,str,i+1,i+1
					);
		}
	}
	else{
		for(int i=num_pag-4;i<num_pag+6;i++){
			if(i==j) break;
			printf(
					"<td><li><a href=\"/source.cgi?users=%s&value=%d\" style='text-decoration:none;padding-right:8px;color:pink;border:10px'>%d</a></li></td>"
					,str,i+1,i+1
					);
		}
	}

	printf("</tr><table>");
}


void addUser(char * user, char * password){
	FILE * sign = fopen(".login.mit", "a");
	
	if (sign == NULL){
		printf("<h5>Erreur !!!</h5>");
		exit(1);
	}

	fprintf(sign, "%s=%s\n", user, password);
	fclose(sign);
}

void deconnected(){
	FILE * deconnexion = fopen(".deconnected.mit", "w+");
	if (deconnexion == NULL){
		printf("ERREUR LORS DE LA DECONNECTION");
		exit(1);
	}
	fprintf(deconnexion,"false\n");
	fclose(deconnexion);
}

bool verification() {
	char * line = (char*) malloc(sizeof(char)*12);
	FILE * verify_file = fopen(".deconnected.mit", "r");
	if (verify_file == NULL){
		printf("ERREUR D'OUVERTURE");
		exit(1);
	}
	
	while (fgets(line, 11, verify_file)){
		if (strcmp(line, "false\n") == 0){
			printf("location: http://www.login.mit\n\n");
		}
		else {
			printf("location: http://www.user.mit");
		}
	}
	
	return false;
}


