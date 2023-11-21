#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "verification.h"

// Verifie si il y a un utilisateur connecter
int verif (){
	FILE * file = fopen(".verification.mit", "r");
	char line[100];
	
	if (file == NULL){
		exit(1);
	}
	while(fgets(line, 99, file)){
		if (strstr(line, "true")){
			return 1;
		}
	}
	return 0;
}

void writeVerif(int flags){
	FILE * file = fopen(".verification.mit", "w");
	if (file == NULL){
		printf("Erreur lors de l'ecriture du fichier de verification\n");
		exit(1);
	}
	
	if (flags == 0){
		fprintf(file, "false");
	}
	
	else if(flags == 1){
		fprintf(file, "true");
	}
}

// ajouter un nouveau utilisateur
void addUser(char * user, char * password){
	FILE * sign = fopen(".login.mit", "a");
	int flags;
	if (sign == NULL){
		printf("<h5>Erreur !!!</h5>");
		exit(1);
	}
	
	flags = verifUser(user);
	
	if (flags == 0){
		fprintf(sign, "%s=%s\n", user, password);
	}
	else if (flags == 1){
		printf("location: http://www.gestion.mit/login.html\n\n");
	}
	
	fclose(sign);
}

// tester si le login est correcte ou non
int test(char * user, char * password){
	int flags = 0;
	FILE * log = fopen(".login.mit", "r");
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
				break;
		}
	}

	fclose(log);
	
	return flags;
}

// Verifie si l'utilisateur à enregistrer existe deja si oui return 1 si non return 0
int verifUser(char * string){
	char line[100], tmp[100];
	FILE * file = fopen(".login.mit", "r");
	if (file == NULL){
		printf("Null");
	}
	while (fgets(line, sizeof(line), file)){
		sscanf(line, "%[^\n]", tmp);
		if (strcmp(tmp, string) == 0)	return 1;
	}
	return 0;
	fclose(file);
}
