#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utilMaths.h" 

int main(){
	char * intervall = getenv("QUERY_STRING");

	double a = 0, b = 0;
	 
	sscanf(intervall, "%*[^=]=%lg", &a);
	sscanf(intervall, "%*[^&]&second=%lg", &b);


	printf("content-type: text/html\n\n");
	head();

	printf("<body>");
		printf("<table>\n");
		//~ printf("<th></th>");
		printf("<form action='http://www.solution.mit/dichotomie_fonction.cgi' method='get'>\n"
			"<tr>"
			"<td>"
			"<label for='first'>First intervals</label>\n"
			"</td><td>"
			"<input type='number' name='first'>\n"
			"</td></tr>"
			
			"<tr><td>"
			"<label for='second'>Second intervals</label>\n"
			"</td><td>"
			"<input type='number' name='second'>\n"
			"</td></tr>"
			"</table>\n"
			"<input type='submit' value='Find Solution'>\n"
		"</form>\n<br>");
		printf("<h4>La surface du fonction log(x) - 1 == %lg</h4>", sol(a, b));
		
	printf("</body>\n");

	printf("</html>\n</body>\n");
	return 0;
}
