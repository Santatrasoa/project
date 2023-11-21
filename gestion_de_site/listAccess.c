#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "verification.h"

int main (){
    int number, num_pag, flags = verif();
    char * url = getenv("QUERY_STRING");
    char nameFile[100], line[100];
    AccessContent * info;

    FILE * file = fopen(".search.html", "r");
    
    if (flags == 0){
		printf("location: http://www.gestion.mit/login.html\n\n");
	}
    
	else if(flags == 1){
		printf("content-type: text/html\n\n");
		sscanf(url,"%*[^=]=%[^&]&page=%d", nameFile, &num_pag);
		head();
		printf(
			"<link rel='stylesheet' type='text/css' href='css/table.css'>\n"
			"<link rel='stylesheet' type='text/css' href='css/pagination.css'>\n"
			"<link rel='stylesheet' href='css/all.min.css'>"
			"</head>");
		printf("<body>");
		while(fgets(line, sizeof(line), file)){
			printf("%s", line);
		}

		printf("<br><br>");
		
		info = infoAccess(&number);
		showListAccess(nameFile, number, num_pag, info);

		printf(
			"</body>"
			"</html>"
		);
	}
    return 0;
}
