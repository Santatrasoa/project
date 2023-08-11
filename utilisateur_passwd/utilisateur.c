#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char** repair_separator(char* aTransf, char getsep);

int main(){
	FILE* file1 = fopen("utilisateur.csv", "w+");
	FILE* file = fopen("/etc/passwd", "r");

	if(file == NULL){
		return EXIT_FAILURE;
	}
	
	if(file1 == NULL){
		return EXIT_FAILURE;
	}

	char line[1000];
	char langage[100][100];
	char dir[100][100];
	char user[100][100];

	int index = 0;
	
	while(fgets(line, 999, file) != NULL){
		char ** sep = repair_separator(line, ':');
		if( atoi(sep[2]) >= 1000 && atoi(sep[2]) < 60000){
			strcpy(user[index],sep[0]);
			strcpy(dir[index],sep[5]);
			strcpy(langage[index],sep[6]);
			index++;
		}
	}	

	for(int i = 0; i < index; i++){
		printf("%s %s %s", user[i], dir[i], langage[i]);
	}

	srand(time(NULL));

	fprintf(file1, "USER,GMAIL,PASSWORD,DIRECTORY,SCRIPT\n");

	for(int i = 0; i < index; i++){
		fprintf(file1, "%s,%s@mit.mg,%d,%s,%s", user[i], user[i], rand() / 6, dir[i], langage[i]);
	}
		

	fclose(file1);
	fclose(file);

	return 0;
}

char** repair_separator(char* aTransf, char getsep){
	char** slash = malloc(sizeof(char*)*100);
	for(int i = 0; i < 100; i++) slash[i] = malloc(100);

	int predim = 0, deudim = 0;
	
	for (int i = 0; i < strlen(aTransf); i++){
		if(aTransf[i] == getsep){
			predim ++;	deudim = 0;
		}
		else{
			slash[predim][deudim] =  aTransf[i];	deudim++;
		}
	}
	
	return slash;
}

