#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util.h"

int main(){
	
/**-----------------------------------------------------------------------------------------**/
	Etudiant* olona = malloc(sizeof(Etudiant)*nombre_eleve);

/**-----------------------------------------------------------------------------------------**/	
	FILE* eleve = fopen("eleve.csv", "w+");
	FILE* info = fopen("info_Etudiant.csv", "r+");

/**-----------------------------------------------------------------------------------------**/
	if(eleve == NULL)
	{
		printf("Tsy nisokatra ny rakitra");
		return EXIT_FAILURE;
	}

	if (info == NULL)
	{
		printf("Tsy nisokatra ilay rakitra");
		exit(1);
	}

/**-----------------------------------------------------------------------------------------**/
	fprintf(eleve, "Anarana,fanampin'anarana,finday,mailaka,adiresy,daty nahaterahana,Toerana nahaterahana,bakaloreat,Lahy sa Vavy,karam-panondro,url");
/**-----------------------------------------------------------------------------------------**/
	olona = makainfo(info);

/**-----------------------------------------------------------------------------------------**/
	sort_struct(olona);

/**-----------------------------------------------------------------------------------------**/	

	for (int i =  0; i < nombre_eleve; i++)
	{
		fprintf(eleve, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", olona[i].nom, olona[i].prenom, olona[i].tel, olona[i].email, olona[i].adresse, olona[i].birthday, olona[i].birthplace, olona[i].bacc, olona[i].genre, olona[i].cin,olona[i].url);
	}
	
/**-----------------------------------------------------------------------------------------**/
	fclose(info);
	fclose(eleve);

	return 0;
}
