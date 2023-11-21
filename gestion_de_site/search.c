#include <stdio.h>
#include <stdlib.h>

#include "verification.h"

int main() {
    FILE * file = fopen(".search.html", "r");
    char line[400];
    int flags = verif();

    if (flags == 0){
        printf("location: http://www.gestion.mit/login.html\n\n");
    }
    else if (flags == 1){

        printf("content-type: text/html\n\n");

        if (file == NULL){
            printf("Tsy Mety");
        }
        while(fgets(line, 399, file)){
            printf("%s", line);
        }

        fclose(file);
    }
    return 0;
}