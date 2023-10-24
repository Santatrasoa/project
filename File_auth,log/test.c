#include <stdio.h>
#include <stdlib.h>

#include "util.h"

int main(){
	char * get = getenv("QUERY_STRING");
	char users[100], password[100];
	if (*get == 0){
		printf("location: http://www.login.mit\n\n");
	}
	else{
		int count = 0;
		for (size_t i = 0; i < strlen(get); i++){
			if (get[i] == '&'){
				count ++; 
			}
		}
		printf("content-type:  text/html\n");
		sscanf(get, "%*[^=]=%[^&]&%*s", users);
		sscanf(get, "%*[^&]&%*[^=]=%s", password);
			
		int flags = test(users, password);
				
		if (flags == 1){
			printf("location: http://www.user.mit/main.cgi/?user=%s&password=%s\n\n", users, password);
		}
		else{
			printf("location: http://www.login.mit\n\n");
			printf("<h1>Password 0r Login Incorrect</h1>\n");
		}
	}
		
	
	
	return 0;
}
