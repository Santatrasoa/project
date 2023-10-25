#include <stdio.h>
#include <math.h>


typedef struct {
	double coef_dir;
	double constante;
}Coeff;

double f(double x){
	return log(x) - 1;
}

Coeff coefficient(double a, double b) {
    Coeff cf;

    cf.coef_dir = (f(b) - f(a)) / (b - a);
    cf.constante = -cf.coef_dir * a + f(a);

    return cf;
}

void head(){
	printf("<! DOCTYPE html>\n");
	printf("<html>\n");
	printf("<head>\n"
		"<meta charset='UTF-8'>\n"
		"<title>Solution</title>\n"
	"</head>\n"
	);

}


double rectangle(double a, double b){
	double solution = 0.0;
	double division = 0.001;

	for (double i = a; i < b; i+=division){
		solution += fabs(division*f(i));
	}
	
	return solution;
}

double trapeze(double a, double b) {
    double solution = 0.0;
    double division = 0.00001;

    for (double i = a; i < b; i += division) {
        solution += f((i + i + division) / 2) * division;
    }

    return solution;
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
		printf("<h4>%lg</h4>", solution);
	}
	
	return solution;
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
		printf("<h4>%lg</h4>", solution);
	}
	
	return solution;
}


double sol(double first, double end){
	double solution, epsilon = 0.000001;
	while ((fabs(first-end)>epsilon)){
		solution=(float)(first+end)/2;
		if ( f(first) * f(solution) < 0){
			end = solution;
		}
		else if (f(solution) * f(end) < 0){
			first = solution;
		}
		printf("%lg\n", solution);
	}
	
	return solution;
}
