#include <stdio.h>
#include "util.h"

int main(int argc, char **argv)
{
	FILE* infoPc = fopen("PCprop.csv", "r+");
	FILE* entre = fopen("PC.csv", "w+");

	Pc* mit = (Pc*)malloc(sizeof(Pc)*50);

	if (infoPc == NULL)
	{
		exit(1);
	}

	if (entre == NULL)
	{
		exit(1);
	}


	fprintf(entre, "Adiresy MAc,Famatarana,Marika");

	mit = makainfopc(infoPc);

	for (int i = 0; i < 20; i++)
	{
		fprintf(entre, "%s,%s,%s", mit[i].adresseMac, mit[i].ethique, mit[i].marque);
	}
	
	fclose(infoPc);
	fclose(entre);
	
	return 0;
}

