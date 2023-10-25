#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcul(long double *a, long double *b, long double *c, long double *y, long double *f1, long double *f2, long double *f3){
	*c = (*b+*a)/2;
	*y = *c;
	*f1 = log(*a) - 1;
	*f2 = log(*c) - 1;
	*f3 = log(*b) - 1;
	*a=(*f1*(*f2)<0)?*a:*c;
	*b=(*f1*(*f2)<0)?*c:*b;
}

void aire(long double *a, long double *b, long double *c, long double *y, long double *f1, long double *f2){
	float inc = 0.01;
	long long isa = 0;
	long double y1 = 0.0;
	*y = 0.0;
	printf("\n\nDonner les bornes pour calculer l'aire du domaine delimite par l'axe des abcisses et la courbe et les droit  et a = ");	
	scanf("%Lf", a);
	printf("b = ");	
	scanf("%Lf", b);
	for(double i=*a,j=*a+inc;i<*b;i+=inc,j+=inc){
		*f1 = log(i) - 1;
		*f2 = log(j) - 1;
		*y += fabs(inc*(*f1));
		y1 += fabs(inc*(*f1) + (*f2-*f1)*inc/2);
		isa++;
	}
	printf("L'aire par methode rectangle est %.19Lf et par trapeze est %.19Lf", *y, y1);
}

void todo(long double *a, long double *b, long double *c, long double *y, long double *f1, long double *f2, long double *f3){
	printf("Ce programme permet de trouver la solution unique de la fonction f(x)=ln(x)-1 par le theoreme de valeur intermediaire\nTaper les deux intervales a = ");
	scanf("%Lf", a);
	printf("b = ");	
	scanf("%Lf", b);
	*f1 = log(*a) - 1;
	*f2 = log(*b) - 1;
	if(*f1*(*f2)<0){
		while(fabs(*f2-*f1)>0.000001){
			calcul(a, b, c, y, f1, f2, f3);
		}
		printf("La solution est %.19Lf", *y);
	}
	else{
		printf("Pas de solution");
	}
}
