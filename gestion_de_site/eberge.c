#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "verification.h"

int main() {
    int flags = verif();
    char line[500];
    FILE * file = fopen(".index.html", "r");

    if (flags == 0){
        printf("location: http://www.gestion.mit/login.html\n\n");
    }
    else if (flags == 1){
        printf("content-type: text/html\n\n");
        while (fgets(line, 499, file)){
            printf("%s", line);
        }
    }


    return 0;
}