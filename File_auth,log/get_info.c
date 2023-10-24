#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char user[100];
	char session[100];
	char date[100];
}Name;

char * transform(char * mois){
	char * m = (char*)malloc(sizeof(char)*50);
	
	if (strcmp(mois, "Jan") == 0){strcpy(m, "Janoary");}
	if (strcmp(mois, "Fev") == 0){strcpy(m, "Febroary");}
	if (strcmp(mois, "Mar") == 0){strcpy(m, "Martsa");}
	if (strcmp(mois, "Avr") == 0){strcpy(m, "Aprily");}
	if (strcmp(mois, "May") == 0){strcpy(m, "May");}
	if (strcmp(mois, "Jun") == 0){strcpy(m, "Jona");}
	if (strcmp(mois, "Jul") == 0){strcpy(m, "Jolay");}
	if (strcmp(mois, "Aout") == 0){strcpy(m, "Aogositra");}
	if (strcmp(mois, "Sept") == 0){strcpy(m, "Septambra");}
	if (strcmp(mois, "Oct") == 0){strcpy(m, "Oktobra");}
	if (strcmp(mois, "Nov") == 0){strcpy(m, "Novambra");}
	if (strcmp(mois, "Dec") == 0){strcpy(m, "Desambra");}
	
	return m;
}

Name* pic(int* numEntries) {
    FILE* auth_log = fopen("/var/log/auth.log", "r");
    Name * auth = (Name*)malloc(sizeof(Name) * 1000);

    if (auth_log == NULL) {
        printf("<h1>Erreur lors de l'ouverture du fichier</h1><h1>/var/log/auth.log</h1>");
        exit(1);
    }

    int i = 0;
    char line[255];
    while (fgets(line, 254, auth_log)) {
		
        if (strstr(line, "for user")) {
            char tmp1[20], tmp2[20], tmp3[20], tmp4[20];
				sscanf(line, "%[^ ] %[^ ] %[^ ] %*s %*s %*s %*s %[^ ] %*s %*s %s", tmp1, tmp2, tmp3, auth[i].session, tmp4);

				if (strchr(tmp4, '(')){
						sscanf(tmp4, "%[^(](%*s", auth[i].user);
				}
				else{
					strcpy(auth[i].user, tmp4);
				}

				char * mois = transform(tmp1);

				strcpy(auth[i].date, mois);
				strcat(auth[i].date, " ");
				strcat(auth[i].date, tmp2);
				strcat(auth[i].date, " ");
				strcat(auth[i].date, tmp3);
				
				i++;
        }
    }
    fclose(auth_log);
    *numEntries = i;
    return auth;
}

