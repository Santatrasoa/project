#ifndef __MATHS__
#include "utilMaths.c"
#define __FONCTION__
	double f(double x);
	double g(double x);

#define __TRAPEZE__
	double trapeze(double a, double b);
#define __RECTANGLE__
	double rectangle(double a, double b);
#define __HEAD__
	void head();
#define __SECANTE__
	double tangente(double x0, double b);
#define __TANGENTE__
	double secante(double a, double b);
#define __STRUCT__
	Coeff coefficient(double a, double b);
#define __DICHOTOMIE__
	double sol(double first, double end);
#endif
