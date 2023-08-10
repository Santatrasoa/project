#include <stdio.h>			/*	bibliothèques d'entrer standard	*/
#include <stdlib.h>			/*	bibliothèques pour manipuler la memoire du pc */
#include <string.h>			/*	bibliothèques pour manipuler les chaînes de caractère	*/

/**		Pour garder le contenue des prototipes ci-dessous veuillez regader les fonctions au dessous du main	**/

char* atomboka(char* isa);						//~		cette fonction assure le lancement du programme 
char* isaHsivy(char isa);						//~		cette fonction montre les chiffres entres 0 à 9
char* ireo_folo_isany(char isa);				//~		cette fonction montre les chiffres entres 10 à 90
char* ireo_zato_isany(char isa);				//~		cette fonction montre les chiffres entres 100 à 900
char* hoanNyfoloIsany(char* isa);				//~		cette fonction montre les chiffres entres 0 à 99
char* hoanNyzato(char* isa);					//~		cette fonction montre les chiffres entres 100 à 999
char* hoanNyarivo(char* isa);					//~		cette fonction montre les chiffres entres 1000 à 9999
char* hoanNyalina(char* isa);					//~		cette fonction montre les chiffres entres 10000 à 99999
char* hoanNyhetsy(char* isa);					//~		cette fonction montre les chiffres entres 100000 à 999999
char* hoanNytapitrisa(char* isa);				//~		cette fonction montre les chiffres entres 1000000 à 9999999
char* hoanNysafatsiroa(char* isa);				//~		cette fonction montre les chiffres entres 10000000 à 99999999
char* hoanNytsitamboisa(char* isa);				//~		cette fonction montre les chiffres entres 100000000 à 999999999
char* hoanNylavitrisa(char* isa);				//~		cette fonction montre les chiffres entres 1000000000 à 9999999999
char* hoanNyalinkisa(char* isa);				//~		cette fonction montre les chiffres entres 10000000000 à 99999999999
char* hoanNytsipesimpesenina(char* isa);		//~		cette fonction montre les chiffres entres 100000000000 à 999999999999
char* hoanNytsitokotsiforohana(char* isa);		//~		cette fonction montre les chiffres entres 1000000000000 à 9999999999999

/**		La fonction main	**/
/*
 * */
int main(){
	char* isa = malloc(10);
	isa = "511981";
	//~ isa = " ";
	atomboka(isa);
	return 0;
}

/*
 * */
char* isaHsivy(char isa){
	char* iray = malloc(12);
	if((isa == '0'))	iray = "";
	if((isa == '1'))	iray = "iray";
	if((isa == '2'))	iray = "roa";
	if((isa == '3'))	iray = "telo";
	if((isa == '4'))	iray = "efatra";
	if((isa == '5'))	iray = "dimy";
	if((isa == '6'))	iray = "enina";
	if((isa == '7'))	iray = "fito";
	if((isa == '8'))	iray = "valo";
	if((isa == '9'))	iray = "sivy";
	
	return iray;
}

/*
 * */
char* ireo_folo_isany(char isa){
	char* iray = malloc(26);
	if((isa == '0'))	iray = "";
	if((isa == '1'))	iray = "folo";
	if((isa == '2'))	iray = "roapolo";
	if((isa == '3'))	iray = "telopolo";
	if((isa == '4'))	iray = "efapolo";
	if((isa == '5'))	iray = "dimapolo";
	if((isa == '6'))	iray = "enimpolo";
	if((isa == '7'))	iray = "fitopolo";
	if((isa == '8'))	iray = "valopolo";
	if((isa == '9'))	iray = "sivifolo";
	
	return iray;
}

/*
 * */
char* ireo_zato_isany(char isa){
	char* iray = malloc(12);
	if((isa == '0'))	iray = "";
	if((isa == '1'))	iray = "zato";
	if((isa == '2'))	iray = "roanjato";
	if((isa == '3'))	iray = "telonjato";
	if((isa == '4'))	iray = "efajato";
	if((isa == '5'))	iray = "dimanjato";
	if((isa == '6'))	iray = "eninjato";
	if((isa == '7'))	iray = "fitonjato";
	if((isa == '8'))	iray = "valonjato";
	if((isa == '9'))	iray = "sivinjato";
	return iray;
}

/*
 * */
char* hoanNyfoloIsany(char* isa){
	char* iray = malloc(12);
	char* folo = malloc(12);
	strcpy(folo, ireo_folo_isany(isa[strlen(isa)-2]));
	strcpy(iray, isaHsivy(isa[strlen(isa)-1]));
	//~ printf("ito %s\n", iray);
	//~ printf("ito ihany koa %s\n", folo);

	if(isa[strlen(isa)-2] == '1' && isa[strlen(isa)-2] != '0'){
		if(isa[strlen(isa)-1] == '0')	strcpy(iray, "folo");
		else	strcat(iray, " ambin'ny folo");
	}
	else if(isa[strlen(isa) - 1] == '0' && isa[strlen(isa)-2] != '0')	strcpy(iray, ireo_folo_isany(isa[strlen(isa)-2]));
	else if(isa[strlen(isa) - 1]!= '0' && isa[strlen(isa)-2] == '0');
	else if(isa[strlen(isa) - 1] == '0' && isa[strlen(isa)-2] == '0');
	else{
		strcat(iray, " amby ");
		strcat(iray, ireo_folo_isany(isa[strlen(isa)-2]));
	}
	//~ printf("dikateny: %s", iray);
	
	return iray;
}

/*
 * */
char* hoanNyzato(char* isa){
	char* iray = malloc(12);

	strcpy(iray, hoanNyfoloIsany(isa));
	if(isa[strlen(isa) -3 ] == '0');
	else if(isa[strlen(isa)-3] != '0' && isa[strlen(isa)-2] == '0'){
		if(isa[strlen(isa)-3] == '1'){
			if(isa[strlen(isa) - 1] == '0'){
				strcat(iray, ireo_zato_isany(isa[strlen(isa) - 3]));
			}
			else{
				strcat(iray, " amby ");
				strcat(iray, ireo_zato_isany(isa[strlen(isa)-3]));
			}
		}
		else{
			if(isa[strlen(isa) - 1] == '0'){
				strcat(iray, ireo_zato_isany(isa[strlen(isa) - 3]));
			}
			else{
				strcat(iray, " sy ");
				strcat(iray, ireo_zato_isany(isa[strlen(isa)-3]));
			}
		}
	}
	else{
		if(isa[strlen(isa)-3] == '1'){
				strcat(iray, " amby ");
				strcat(iray, ireo_zato_isany(isa[strlen(isa)-3]));
		}
		else{
			strcat(iray, " sy ");
			strcat(iray, ireo_zato_isany(isa[strlen(isa)-3]));
		}
	}
	//~ printf("%s", iray);
	return iray;
}

/*
 * */
char* hoanNyarivo(char* isa){
	char* arivo = malloc(26);
	strcpy(arivo, isaHsivy(isa[strlen(isa) -4]));
	if(isa[strlen(isa)-4] == '0');
	if(isa[strlen(isa) - 4] == '1')	arivo = "arivo";
	else strcat(arivo, " arivo");
	
	char* iray = malloc(19);
	strcpy(iray, hoanNyzato(isa));

	if(isa[strlen(isa) - 4] == '0');
	else{
		if(isa[strlen(isa) - 3] == '0' && isa[strlen(isa) - 2] == '0' && isa[strlen(isa)-1] == '0')	strcat(iray, arivo);
		else{
			strcat(iray, " sy ");
			strcat(iray, arivo);
		}
	}
	//~ printf("%s", iray);
	return iray;
}

/*
 * */
char* hoanNyalina(char* isa){
	char* alina = malloc(26);
	strcpy(alina, isaHsivy(isa[strlen(isa) - 5]));
	if(isa[strlen(isa)-5] == '0');
	else strcat(alina, " alina");
	
	char* iray = malloc(17);
	strcpy(iray, hoanNyarivo(isa));
	if(isa[strlen(isa) - 5] == '0');
	else{
		if(isa[strlen(isa)- 4] == '0' && isa[strlen(isa) - 3] == '0' && isa[strlen(isa) - 2] == '0' && isa[strlen(isa)-1] == '0')	strcat(iray, alina);
		else{
			strcat(iray, " sy ");
			strcat(iray, alina);
		}
	}
	//~ printf("%s", iray);
	
	return iray;
}

/*
 * */
char* hoanNyhetsy(char* isa){
	char* hetsy = malloc(26);
	strcpy(hetsy, isaHsivy(isa[strlen(isa) - 6]));
	if(isa[strlen(isa)-6] == '0');
	else strcat(hetsy, " hetsy");
	
	char* iray = malloc(26);
	strcpy(iray, hoanNyalina(isa));
	if(isa[strlen(isa) - 6] == '0');
	else{
		if(isa[strlen(isa) - 5] == '0' && isa[strlen(isa)- 4] == '0' && isa[strlen(isa) - 3] == '0' && isa[strlen(isa) - 2] == '0' && isa[strlen(isa)-1] == '0')	strcat(iray, hetsy);
		else{
			strcat(iray, " sy ");
			strcat(iray, hetsy);
		}
	}
	//~ printf("%s", iray);
	return iray;
}

/*
 * */
char* hoanNytapitrisa(char* isa){
	char* tapitrisa = malloc(26);
	strcpy(tapitrisa, isaHsivy(isa[strlen(isa) - 7]));
	if(isa[strlen(isa)-7] == '0');
	else strcat(tapitrisa, " tapitrisa");
	
	char* iray = malloc(16);
	strcpy(iray, hoanNyhetsy(isa));
	
	if(isa[strlen(isa)-7] == '0');
	else{
		if(isa[strlen(isa) - 6] == '0' && isa[strlen(isa) - 5] == '0' && isa[strlen(isa)- 4] == '0' && isa[strlen(isa) - 3] == '0' && isa[strlen(isa) - 2] == '0' && isa[strlen(isa)-1] == '0')	strcat(iray, tapitrisa);
		else{
			strcat(iray, " sy ");
			strcat(iray, tapitrisa);
		}
	}
	//~ printf("%s", iray);
	return iray;
}

/*
 * */
char* hoanNysafatsiroa(char* isa){
	char* safatsiroa = malloc(26);
	strcpy(safatsiroa, isaHsivy(isa[strlen(isa) - 8]));
	if(isa[strlen(isa)-8] == '0');
	else strcat(safatsiroa, " safatsiroa");
	
	char* iray = malloc(15);
	strcpy(iray, hoanNytapitrisa(isa));
	if(isa[strlen(isa)-8] == '0');
	else{
		if(isa[strlen(isa) - 7] == '0' && isa[strlen(isa) - 6] == '0' && isa[strlen(isa) - 5] == '0' && isa[strlen(isa)- 4] == '0' && isa[strlen(isa) - 3] == '0' && isa[strlen(isa) - 2] == '0' && isa[strlen(isa)-1] == '0')	strcat(iray, safatsiroa);
		else{
			strcat(iray, " sy ");
			strcat(iray, safatsiroa);
		}
	}
	//~ printf("%s", iray);
	return iray;
}

/*
 * */
char* hoanNytsitamboisa(char* isa){
	char* tsitamboisa = malloc(26);
	strcpy(tsitamboisa, isaHsivy(isa[strlen(isa) - 9]));
	if(isa[strlen(isa)-9] == '0');
	else strcat(tsitamboisa, " tsitamboisa");
	
	char* iray = malloc(13);
	strcpy(iray, hoanNysafatsiroa(isa));
	if(isa[strlen(isa) - 9] == '0');
	else{
		if(isa[strlen(isa) - 8] == '0' && isa[strlen(isa) - 7] == '0' && isa[strlen(isa) - 6] == '0' && isa[strlen(isa) - 5] == '0' && isa[strlen(isa)- 4] == '0' && isa[strlen(isa) - 3] == '0' && isa[strlen(isa) - 2] == '0' && isa[strlen(isa)-1] == '0')	strcat(iray, tsitamboisa);
		else{
			strcat(iray, " sy ");
			strcat(iray, tsitamboisa);	
		}
	}
	//~ printf("%s", iray);
	return iray;
}

/*
 * */
char* hoanNylavitrisa(char* isa){
	char* lavitrisa = malloc(26);
	strcpy(lavitrisa, isaHsivy(isa[strlen(isa) - 10]));
	if(isa[strlen(isa)- 10] == '0');
	else strcat(lavitrisa, " lavitrisa");
	char* iray = malloc(17);
	strcpy(iray, hoanNytsitamboisa(isa));
	if(isa[strlen(isa) - 10] == '0');
	else{
		if(isa[strlen(isa) - 9] == '0' && isa[strlen(isa) - 8] == '0' && isa[strlen(isa) - 7] == '0' && isa[strlen(isa) - 6] == '0' && isa[strlen(isa) - 5] == '0' && isa[strlen(isa)- 4] == '0' && isa[strlen(isa) - 3] == '0' && isa[strlen(isa) - 2] == '0' && isa[strlen(isa)-1] == '0')	strcat(iray, lavitrisa);
		else{
			strcat(iray, " sy ");
			strcat(iray, lavitrisa);
		}
	}
	//~ printf("%s", iray);
	return iray;
}

/*
 * */
char* hoanNyalinkisa(char* isa){
	char* alinkisa = malloc(26);
	strcpy(alinkisa, isaHsivy(isa[strlen(isa) - 11]));
	if(isa[strlen(isa)-11] == '0');
	else strcat(alinkisa, " alinkisa");
	
	char* iray = malloc(13);
	strcpy(iray, hoanNylavitrisa(isa));
	if(isa[strlen(isa)-11] == '0');
	else{
		if(isa[strlen(isa) - 10] == '0' && isa[strlen(isa) - 9] == '0' && isa[strlen(isa) - 8] == '0' && isa[strlen(isa) - 7] == '0' && isa[strlen(isa) - 6] == '0' && isa[strlen(isa) - 5] == '0' && isa[strlen(isa)- 4] == '0' && isa[strlen(isa) - 3] == '0' && isa[strlen(isa) - 2] == '0' && isa[strlen(isa)-1] == '0')	strcat(iray, alinkisa);
		else{
			strcat(iray, " sy ");
			strcat(iray, alinkisa);
		}
	}
	//~ printf("%s", iray);
	return iray;
}

/*
 * */
char* hoanNytsipesimpesenina(char* isa){
	char* tsipesimpesenina = malloc(26);
	strcpy(tsipesimpesenina, isaHsivy(isa[strlen(isa) - 12]));
	if(isa[strlen(isa)-12] == '0');
	else strcat(tsipesimpesenina, " tsipesimpesenina");
	
	char* iray = malloc(18);
	strcpy(iray, hoanNyalinkisa(isa));
	if(isa[strlen(isa)-12] == '0');
	else{
		if(isa[strlen(isa) - 11] == '0' && isa[strlen(isa) - 10] == '0' && isa[strlen(isa) - 9] == '0' && isa[strlen(isa) - 8] == '0' && isa[strlen(isa) - 7] == '0' && isa[strlen(isa) - 6] == '0' && isa[strlen(isa) - 5] == '0' && isa[strlen(isa)- 4] == '0' && isa[strlen(isa) - 3] == '0' && isa[strlen(isa) - 2] == '0' && isa[strlen(isa)-1] == '0')	strcat(iray, tsipesimpesenina);
		else{
			strcat(iray, " sy ");
			strcat(iray, tsipesimpesenina);
		}
	}
	//~ printf("%s", iray);
	return iray;
}

/*
 * */
char* hoanNytsitokotsiforohana(char* isa){
	char* tsitokotsiforohana = malloc(26);
	strcpy(tsitokotsiforohana, isaHsivy(isa[strlen(isa) - 13]));
	if(isa[strlen(isa)-13] == '0');
	else strcat(tsitokotsiforohana, " tsitokotsiforohana");
	
	char* iray = malloc(18);
	strcpy(iray, hoanNyalinkisa(isa));
	if(isa[strlen(isa)-13] == '0');
	else{
		if(isa[strlen(isa) - 12] == '0' && isa[strlen(isa) - 11] == '0' && isa[strlen(isa) - 10] == '0' && isa[strlen(isa) - 9] == '0' && isa[strlen(isa) - 8] == '0' && isa[strlen(isa) - 7] == '0' && isa[strlen(isa) - 6] == '0' && isa[strlen(isa) - 5] == '0' && isa[strlen(isa)- 4] == '0' && isa[strlen(isa) - 3] == '0' && isa[strlen(isa) - 2] == '0' && isa[strlen(isa)-1] == '0')	strcat(iray, tsitokotsiforohana);
		else{
			strcat(iray, " sy ");
			strcat(iray, tsitokotsiforohana);
		}
	}
	//~ printf("%s", iray);
	return iray;
}

/*
 * */
char* atomboka(char* isa){
	char* iray = malloc(32);

	for(int p = 0; p < strlen(isa)-1; p++) if(*(isa+p) == '0') strcpy(iray, "aotra");

	if(strlen(isa) == 0)	iray = "aotra";
	if(strlen(isa) == 1)	iray = isaHsivy(isa[strlen(isa)-1]);	
	if(strlen(isa) == 2)	iray = hoanNyfoloIsany(isa);
	if(strlen(isa) == 3)	iray = hoanNyzato(isa);
	if(strlen(isa) == 4)	iray = hoanNyarivo(isa);
	if(strlen(isa) == 5)	iray = hoanNyalina(isa);
	if(strlen(isa) == 6)	iray = hoanNyhetsy(isa);
	if(strlen(isa) == 7)	iray = hoanNytapitrisa(isa);
	if(strlen(isa) == 8)	iray = hoanNysafatsiroa(isa);
	if(strlen(isa) == 9)	iray = hoanNytsitamboisa(isa);
	if(strlen(isa) == 10)	iray = hoanNylavitrisa(isa);
	if(strlen(isa) == 11)	iray = hoanNyalinkisa(isa);
	if(strlen(isa) == 12)	iray = hoanNytsipesimpesenina(isa);
	if(strlen(isa) == 13)	iray = hoanNytsitokotsiforohana(isa);
	//~ else 	iray = "Tsy manam-petra";
	
	printf("dikateny: %s", iray);
		
	return iray;
}
