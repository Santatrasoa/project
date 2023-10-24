#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "util.h"

int main() {
	char * get = getenv("QUERY_STRING");
	char * getter = (char *)malloc(10);
	int num_page=1;
	//char num[10];

	bool flags = verification();

	if (flags){
		
		if (get == NULL){
			printf("location: http://www.login.mit\n\n");
		}
		else{
			if(strchr(get,'&')) sscanf(get,"%*[^=]=%[^&]",getter);
			
			else sscanf(get,"%*[^=]=%s",getter);

			sscanf(get,"%*[^&]&value=%d",&num_page);

			for (int i = 0; i < strlen(getter); i++){
				getter[i] = tolower(getter[i]);
			}
			
			//~ int num_page = 1;
			//~ char getter[100] = "diary";
			
			printf("content-type: text/html\n\n");

			printf("<!DOCTYPE html>\n");
			printf("<html>\n");

			printf("<head>\n");
			printf("<meta charset=\"UTF-8\">\n");
			printf("<title>File Name Log</title>\n");
			printf("<link rel='stylesheet' type=\"text/css\" href='style.css'>");
			 
			printf("</head>\n");

			printf("<body>\n");
			
			
			show(getter, num_page);
			
			printf("<br><br><br>");
			printf("<footer>"
					"<form action='http://www.user.mit/deconnected.cgi'>"
						"<input type='submit' value='Deconnexion'>"
					"</form>"
			"</footer>");
				
			printf("</body>\n");

			 printf("</html>\n");
		}
	}
	else{
		printf("location: https://www.login.mit");
	}
    return 0;
}
