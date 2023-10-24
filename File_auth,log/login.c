#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

int main(){
	char * get = getenv("QUERY_STRING");
	char users[100], password[100], conf_pass[100];

	sscanf(get, "%*[^=]=%[^&]", users);
	sscanf(get, "%*[^&]%*[^=]=%[^&]" ,password);
	sscanf(get, "%*[^&]&%*[^&]&%*[^=]=%s" ,conf_pass);

	if (strcmp(password, conf_pass) == 0){
		addUser(users, password);
		printf("location: http://www.login.mit\n\n");
	}
	else{
		 printf("location: http://www.login.mit/index.html\n\n");
	}
	
	return 0;
}
