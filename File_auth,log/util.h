#include "util.c"
#ifndef STATS
#define SPLIT__
	char** split(char* string, char delimiteur);
	
#define __TEST__
	int test(char * user, char * password);
#define __PRINT__
	void print(char* str, int num_pag);
#define __ADD_USER__
	void addUser(char * user, char * password);
#define __DECONNECTED__
   void deconnected();
#define __VERIFICATION__
	bool verification();
#endif
