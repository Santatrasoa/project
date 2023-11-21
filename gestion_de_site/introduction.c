#include <stdio.h>
#include <stdlib.h>

#include "verification.h"

int main() {
    int flags = verif();
    char line[500];
    FILE * file = fopen(".introduction.html", "r");

    if (flags == 0){
        printf("location: http://www.gestion.mit/login.html\n\n");
    }
    else if (flags == 1){
        printf("content-type: text/html\n\n");
        while ((fgets(line, sizeof(line), file)))
        {
            printf("%s", line);
        }
        fclose(file);
        
    }
    return 0;
}