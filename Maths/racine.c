#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "racine-lib.c"

int main(){
	long double a = 0.0, b = 1.0, c = 0.0, y = 0.0, f1 = 0.0, f2 = 0.0, f3 = 0.0;
	todo(&a, &b, &c, &y, &f1, &f2, &f3);
	aire( &a, &b, &c, &y, &f1, &f2);
	
	return 0;
}
