#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "verification.h"

int main() {
	int flags = verif();
	
	if (flags == 0){
		printf("location: http://www.gestion.mit/login.html\n\n");
	}
	
	else if(flags == 1){
		char *link = getenv("QUERY_STRING");
		printf("content-type: text/html\n\n");
		head();

		printf(
			"<link rel='stylesheet' type='text/css' href='css/welcome.css'>"
			"<link rel='stylesheet' href='css/adminlte.min.css'>"
			"<link rel='stylesheet' href='css/acceuil.css'>"
			"</head>"
			"<body>"
		);

		AllSiteDepend get = getinfo(link);
		writeFileConf(get);
		moveFile(get);
		activate(get);
		etcHosts(get);

	printf(
    	"<section>"
    	"<h1 ><a href='http://www.gestion.mit' class='home'><img src='img/home.png' class='img'>home</a></h1>"
    	"</section>"
	);

     printf("<div class='welcome-menu'>"
        "<div class='welcome-content'>"
            "<h1 class='text-center display-4'>Votre site %s a été activé avec succé</h1>"
            "<p class='text-center display-4'>Explorez et découvrez votre site.</p>"
            "<a href='http://%s'>%s</a>"
        "</div>"
      "</div>"
    , get.serverName, get.serverName, get.serverName);

  	printf("</body>"
    	"</html>"
  	);

		printf(
			"</body>\n"
			"</html>\n"
		);
	}
    return 0;
}
