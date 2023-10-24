#include <stdio.h>
#include <stdlib.h>

int main(){
	char * get = getenv("QUERY_STRING");

	if (*get == 0){
		printf("location: http://www.login.mit\n\n");
	}
	else {
		FILE * f = fopen("search.html", "r");
		char line[100]; 
		printf("content-type: text/html\n\n");
		while(fgets(line, 99, f)!=NULL){
			printf("%s", line);
		}
		
	}
	return 0;
}
