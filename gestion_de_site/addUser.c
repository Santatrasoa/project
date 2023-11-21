#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "verification.h"

int main() {
	char * url = getenv("QUERY_STRING");
	char user[100], password[100], conf_password[100];
	sscanf(url, "user=%[^&]&password=%[^&]&password=%s", user, password, conf_password);

	if (strcmp(password, conf_password) == 0){
		addUser(user, password);
		writeVerif(1);
		printf("location: http://www.gestion.mit/welcome.html\n\n");
	}
	else{
		printf("location: http://www.gestion.mit/signUp.html\n\n");
	}

	return 0;
}
