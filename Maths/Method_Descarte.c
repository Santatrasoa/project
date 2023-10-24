#include <stdio.h>
#include <math.h>

typedef struct {
	double coef_dir;
	double constante;
}Coeff;

double f(double x){
	return exp(x) -1;
}

Coeff coefficient(double a, double b) {
    Coeff cf;

    cf.coef_dir = (f(b) - f(a)) / (b - a);
    cf.constante = -cf.coef_dir * a + f(a);

    return cf;
}

double secante(double a, double b) {
	double solution = 0.0;
	
	while(1) {
		Coeff cf = coefficient(a, b);
		solution = - cf.constante / cf.coef_dir;
		
		if (f(solution) == 0){
			return solution;
		}
		b = solution;
	}
	
	return solution;
}

int main() {
	double a = 1, b = 5;
	
	printf("%lg", secante(a,b));

	return 0;
}
