#include "util.c"
#ifndef UTILITY
#define __UTILITY__
	char** repair_separator(char* aTransf, char getsep);
	Etudiant* makainfo(FILE* info);
	void sort_struct(Etudiant* info);
	Pc* makainfopc(FILE* info);
#endif
