#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "verification.h"

int main() {
	char * url = getenv("QUERY_STRING");
	char password[100], user[100];
	int flags;
	
	sscanf(url, "user=%[^&]&password=%s", user, password);
	flags = test(user, password);
	
	if (flags == 0){
		printf("location: http://www.gestion.mit/login.html\n\n");
	}
	else if (flags == 1){
		writeVerif(flags);
		printf("location: http://www.gestion.mit\n\n");
	}
	
	return 0;
}
