#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);							/*	La fonction f(x)	*/
double g(double x);							/*	Ici g(x) est la fonction dérivé de f(x)	*/
double tangente(double a, double);		/*	le méthode de Newton (tangete) pour trouver la solution unique de f(x) = 0	*/

int main() {
	double a = 1, b=4;
	printf("%lg\n", tangente(a, b));
	
	return 0;
}

double f(double x){
	return log(x)-1;
}

double g(double x){
	return 1/(x);
}

double tangente(double x0, double b){
	double solution=0.0, eps = 0.0000001;
	while (fabs(f(x0)-f(b)) > eps){
		solution = x0 - f(x0)/g(x0);
		x0 = solution;
		
		if (f(x0) == 0.0)	return solution;
		
	}
	
	return solution;
}
