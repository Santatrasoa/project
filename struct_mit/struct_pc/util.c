#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "info.h"

#define nombre_eleve 44

char** repair_separator(char* aTransf, char getsep){
	char** slash =(char**)malloc(sizeof(char*)*100);
	for(int i = 0; i < 100; i++) slash[i] =( char*)malloc(100);

	int predim = 0, deudim = 0;
	
	for (int i = 0; i < (int)strlen(aTransf); i++){
		if(aTransf[i] == getsep){
			predim ++;	deudim = 0;
		}
		else{
			slash[predim][deudim] =  aTransf[i];	deudim++;
		}
	}
	
	return slash;
}

Pc* makainfopc(FILE* info){
	Pc* information = (Pc*)malloc(sizeof(Etudiant)*50);

	char ligne[100];
	int index = 0;

	while(fgets(ligne, 256, info) != NULL)
	{
		char** sep = repair_separator(ligne, ',');
		strcpy(information[index].marque, sep[2]);
		strcpy(information[index].ethique, sep[1]);
		strcpy(information[index].adresseMac, sep[0]);
		index++;
	}

	return information;
}

Etudiant* makainfo(FILE* info){
	Etudiant* information = (Etudiant*)malloc(sizeof(Etudiant)*nombre_eleve);
	char ligne[1000];
	int i = 0;
	
	while (fgets(ligne, 256, info) != NULL)
	{
		char** sep = repair_separator(ligne, ',');
		strcpy(information[i].nom, sep[0]);
		strcpy(information[i].prenom, sep[1]);
		strcpy(information[i].tel, sep[2]);
		strcpy(information[i].email, sep[3]);
		strcpy(information[i].adresse, sep[4]);
		strcpy(information[i].birthday, sep[5]);
		strcpy(information[i].birthplace, sep[6]);
		strcpy(information[i].bacc, sep[7]);
		strcpy(information[i].genre, sep[8]);
		strcpy(information[i].cin, sep[9]);
		strcpy(information[i].url, sep[10]);
		i++;
	}	
	return information;
}


void sort_struct(Etudiant* info){	
	for(int i = 0; i < nombre_eleve; i++)
	{
		for(int j = 0; j < nombre_eleve; j++)
		{
			Etudiant tmp[1000];
			if(strcmp(info[j].nom , info[i].nom) > 0)
			{
				tmp[i] = info[i];
				info[i] = info[j];
				info[j] = tmp[i];
			}
		}
	}
}

