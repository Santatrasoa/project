#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
	FILE* file = fopen("trigo.csv", "w+");

	if(file == NULL){
		printf("Erreur");
		exit(1);
	}

	fprintf(file, "Degre,Sinus,Cosinus,Tangente\n");

	for(int i = 0; i <= 360; i++){
		double rad = (M_PI*i)/180;
		fprintf(file, "%d,%lg,%lg,%lg\n", i, sin(rad), cos(rad), tan(rad));
	}

	fclose(file);
	
	return 0;
}
