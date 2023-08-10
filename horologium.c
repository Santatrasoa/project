/**********************************************************************************************************************************************/
/**********************************************************************************************************************************************/

 /*
 * 		Auteurs		:	-ANDRIAMIHARINJARA	Coriolan Richia
 * 						-FOCK 				Lahoussa Mireilla
 * 						-HERIMAMPIONONA 	Santatrasoa Diary
 * 						-JUSTIN				Zarasoa Anita
 * 
 * 		Mention		:	Informatique et Technologie
 * 		Niveau		:	L1
 * 		Objectif	:	Faire une horloge avec toutes ses fonctionalitées(horloge, minuterie, chronomètre)
 * 
 */
 
/**********************************************************************************************************************************************/
/**********************************************************************************************************************************************/

/**********************************************************************************************************************************************/
/**********************************************************************************************************************************************/
/*														DEBUT DU PROGRAMME																		*/
/**********************************************************************************************************************************************/
/**********************************************************************************************************************************************/

/**	Les fichiers d'entête de bibliotheques	**/

#include <fcntl.h>										// ~	nous incluons fcntl pour pouvoir user du mode non-bloquant
#include <math.h>										// ~	on use de la bibliothèque pour les fonctions trigonométriques
#include <signal.h>										// ~	on gèrera le signal SIGKILL
#include <stdio.h>										// ~	gestion de l'entrée et la sortie standard
#include <stdlib.h>										// ~	on a besoin des fonctions exit() et system()
#include <string.h>										// ~	comparaison de chaines de caractères
#include <termios.h>									// ~	c'est par termios.h que nous pourrons paramétrer le terminal
#include <time.h>										// ~	bien évidemment, nous avons besoin de manipuler le temps pour afficher une horloge fonctionnelle
#include <unistd.h>										// ~ 	beaucoup de nécessités

struct termios oldt, newt;								// ~	on y accueillera respectivement les configurations d'origine et modifiées du terminal 

int flags;
double pi=3.1415926535897932384626;						// ~	le nombre pi: avec même plus de chiffres après virgule que l'ordinateur n'en a besoin	
char 	chemin_son[40]="$HOME/.horologium/son",			// ~	chemin absolu du répertoire des tonalités par défaut
		chemin_minute[40]="$HOME/.horologium/timer";	// ~	chemin du répertoire des fichiers de ton de la minuterie


/**	Toutes les fonctions utilisées lors du programme au total 20 fonctions	**/
void aff(char *affichage1, char *affichage2, char *affichage3, char *affichage4, char *affichage5);
void affiche(int dim, char table[dim][dim]);
void aide();
void aiguille(int dim, int indmax,int lng, int s, char table[dim][dim], char car);
void bord(int dim, int indmax, char table[dim][dim]);
void choix(char*choice);
void chrono();
void enter_tune();
void horloge(int dim,int indmax,char table[dim][dim]);
void introduction();
void minuterie();
void parametre();
void options();
void quit();
void start();
void stop();
void test_tune();
void trotte(int dim, int indmax, char table[dim][dim], char*choix, float timezone);
void videtable(int dim, char table[dim][dim]);
void zones();

/**********************************************************************************************************************************************/
/**********************************************************************************************************************************************/
/*														FONCTION MAIN DU PROGRAMME																*/
/**********************************************************************************************************************************************/
/**********************************************************************************************************************************************/

int main(){
/**	Petite introduction	*/
	//~ introduction();
	
	char affichage1[100] = " _____\n/     \\\n|  <  |\n\\_____/";
	char affichage2[100] = " _____\n/     \\\n| C.M |\n\\_____/";
	char affichage3[100] = " _____\n/     \\\n| C.D |\n\\_____/";
	char affichage4[100] = " _____\n/     \\\n| |_| |\n\\_____/";
	char affichage5[100] = " _____\n/     \\\n|  X  |\n\\_____/";
	char choice[100]="\0";							// ~ Le choix à faire au debut du lancement du programme
	int	dim = 32,									// ~ La dimension du tableau à utiliser pour contenir le cercle pour l'horloge
		indmax = dim - 1;							// ~ L'indice maximal possible dans les deux dimensions du tableau.
	char table[dim][dim];							// ~ la variable, le tableau, qui sert à construire le cercle pour l'horloge
	
	///	int timezone = 3;							// ~ Le decalage horaire à Madagascar
	/**	ce décalage horaire n'est plus utile dans notre horloge principale en utilisant localtime() de la bibliothèque de gestion
	 * 	du temps elle a été nécessaire dans des versions antérieures;
	 * 	mais elle sera reprise plus tard, dans une option d'affichage du temps d'un fuseau horaire choisi par l'utilisateur.
	 * */
	
/**	initialisation des structures termios oldt et newt, et de flags	*/
	tcgetattr(STDOUT_FILENO,&oldt);					//	on stocke les anciens parametres du terminal dans la structure oldt
	newt = oldt;									/*	on copie les configurations anciennes dans une autre structure afin de pouvoir
													 *	modifier certains points tout en ayant à disposition les configurations d'origine
													 */
													
	newt.c_lflag &= ~(ICANON | ECHO);				/*	C'est cette ligne qui modifie les parametres stockées dans newt.
													 *	ceci sert à désactiver les indicateurs ICANON (mode canonique),
													 * 	tout caractère entré est immédiatement traité même si aucun line delimiter n'est rencontré,
													 * 	et ECHO (renvoi au terminal des caractères saisis), nécessaire pour une bonne présentation.
													 */
													
	flags = fcntl(STDIN_FILENO, F_GETFL, 0);		//	on accueille dans flags la valeur du premier mode, avant modification
	
menu:
	aff(affichage1, affichage2, affichage3, affichage4, affichage5);
	
/***  Entrée des données, entrée du choix au menu principal	***/
	choix(choice);
	
/***  Corps du programme	***/

	/*	Nous proposons cinq choix à l'utilisateur:
	 * 	horloge		pour visualiser l'horloge analogique que nous avons créée
	 * 	minuterie	pour utiliser un minuteur, compte à rebours
	 * 	chronomètre	pour mesurer le temps
	 * 	parametre	pour quelques parametres
	 * 	quitter
	 * 	[on bosse encore sur la fonctionnalité alarme]
	 */
	
	
	/*	pour savoir le choix, on compare la réponse entrée et les chaînes de caractères qui décrivent les choix possibles
	 * 	si aucun choix valide n'est sélectionné, on n'entre dans aucune des instructions conditionnelles et on revient 
	 * 	immédiatement dans le menu.
	 */
	 
	if(strcmp(choice,"horloge")==0) horloge(dim, indmax, table);	/**	horloge analogique	*/
	
	else if(strcmp(choice,"chronomètre")==0) chrono();				/**	chronomètre	*/
	
	else if(strcmp(choice,"minuterie")==0) minuterie();				/**	minuterie	*/
	
	else if(strcmp(choice,"parametre")==0) parametre();				/**	parametres*/
	
	else if(strcmp(choice,"quitter")==0) goto quit;					/**	quitter	*/
	
	goto menu;
	
	free(choice);

quit:
	system("clear");
	return EXIT_SUCCESS;
}


/**********************************************************************************************************************************************/
/**********************************************************************************************************************************************/
/*														LES AUTRES FONCTIONS DU PROGRAMME														*/
/**********************************************************************************************************************************************/
/**********************************************************************************************************************************************/

/**	fonction de présentation du menu	*/
void aff(char *affichage1, char *affichage2, char *affichage3, char *affichage4, char *affichage5){
	
	printf("\e[1;33m%s\e[0m", affichage1);
	printf("\thorloge\n");
	
	printf("\e[1;32m%s\e[0m", affichage2);
	printf("\tchronomètre\n");
	
	printf("\e[1;31m%s\e[0m", affichage3);
	printf("\tminuterie\n");
	
	printf("\e[1;35m%s\e[0m", affichage4);
	printf("\tparametre\n");
	
	printf("\e[1;36m%s\e[0m", affichage5);
	printf("\tquitter\n");
}

/**	une fonction qui sert à afficher la montre	*/												//	OK
void affiche(int dim, char table[dim][dim]){
	for (int i=0; i<dim;i++){
		for(int j=0;j<dim;j++){
			printf("%c ",table[i][j]);
		}
        printf("\n");
    }
}

/**	affichage d'une aide sur l'application	*/
void aide(){
	system("clear");
	printf("SERVICE D'AIDE\n");
	
	printf("Taper ENTRÉE pour quitter\n");
	getchar();
}

/**	fonction qui permet l'affichage d'une l'aiguille	*/										//	OK
void aiguille(int dim, int indmax,int lng, int s, char table[dim][dim], char car){
	for(int length=0; length<lng; length++){	/**	Création de l'aiguille proprement dite */
		int i=(indmax/2+(length)*cos(-s*pi/30+pi)), j=(indmax/2+(length)*sin(-s*pi/30+pi));
		*(*(table+i)+j)=car;
	}
}

/**	fonction pour dessiner les bords de l'horloge	*/											//	OK
void bord(int dim, int indmax, char table[dim][dim]){
	
	for(int s=0; s<60;s++){
		int i = (indmax/2+(indmax/2)*sin(-s*pi/30)); 				//~		Formule appliquer pour dessiner les ordronners du cercle
		int j = (indmax/2+(indmax/2)*cos(-s*pi/30));				//~		Formule appliquer pour dessiner les abscisses du cercle
		*(*(table+i)+j)='*';
	}
	table[(int)(indmax/2+(indmax/2)*sin(-2*pi/6))][(int)(indmax/2+(indmax/2)*cos(2*pi/6))]='1';			
	table[(int)(indmax/2+(indmax/2)*sin(-1*pi/6))][(int)(indmax/2+(indmax/2)*cos(1*pi/6))]='2';			
	table[(int)(indmax/2+(indmax/2)*sin(-0*pi/6))][(int)(indmax/2+(indmax/2)*cos(0*pi/6))]='3';			
	table[(int)(indmax/2+(indmax/2)*sin(-11*pi/6))][(int)(indmax/2+(indmax/2)*cos(11*pi/6))]='4';		
	table[(int)(indmax/2+(indmax/2)*sin(-10*pi/6))][(int)(indmax/2+(indmax/2)*cos(10*pi/6))]='5';		
	table[(int)(indmax/2+(indmax/2)*sin(-9*pi/6))][(int)(indmax/2+(indmax/2)*cos(9*pi/6))]='6';			
	table[(int)(indmax/2+(indmax/2)*sin(-8*pi/6))][(int)(indmax/2+(indmax/2)*cos(8*pi/6))]='7';			
	table[(int)(indmax/2+(indmax/2)*sin(-7*pi/6))][(int)(indmax/2+(indmax/2)*cos(7*pi/6))]='8';			
	table[(int)(indmax/2+(indmax/2)*sin(-6*pi/6))][(int)(indmax/2+(indmax/2)*cos(6*pi/6))]='9';			
	table[(int)(indmax/2+(indmax/2)*sin(-5*pi/6))][(int)(indmax/2+(indmax/2)*cos(5*pi/6))]='1';			
	table[(int)(indmax/2+(indmax/2)*sin(-5*pi/6))][(int)(indmax/2+(indmax/2)*cos(5*pi/6))+1]='0';		
	table[(int)(indmax/2+(indmax/2)*sin(-4*pi/6))][(int)(indmax/2+(indmax/2)*cos(4*pi/6))]='1';			
	table[(int)(indmax/2+(indmax/2)*sin(-4*pi/6))][(int)(indmax/2+(indmax/2)*cos(4*pi/6))+1]='1';		
	table[(int)(indmax/2+(indmax/2)*sin(-3*pi/6))][(int)(indmax/2+(indmax/2)*cos(3*pi/6))]='1';			
	table[(int)(indmax/2+(indmax/2)*sin(-3*pi/6))][(int)(indmax/2+(indmax/2)*cos(3*pi/6))+1]='2';		
}

/**	la fonction pour choisir au menu	*/														//	OK
void choix(char*choice){
	
	printf("\n\n>>\t");
	scanf("%s", choice);
	system("clear");
	getchar();
	printf("\n");

}

/**	la fonction qui assurera notre chronomètre	*/												//	OK
void chrono(){
	char choix[10]="\0";
	
menu:
	system("clear");
	printf("\t(début)\tcommencer le chronomètre\n\t(quit)\tretour au menu\n>>\t");
	scanf("%s", choix);
	system("clear");
	if(strcmp(choix, "début")!=0&&strcmp(choix, "quit")!=0)
		goto menu;
	else if(strcmp(choix, "quit")==0)
		goto quit;
	
	int seconde=0;
	char c;
	int count=0;
	
strt:
	c ='p';
	count=0, seconde=0;
	start();

	while(1){
		
		system("clear");
		printf("%02d:%02d:%02d\n", seconde/3600%24, seconde/60%60, seconde%60);
		options();

		if(c=='p'){
			while((c=getchar())!='d'&&c!='q'&&c!='r');
		}
		if(c=='s'){
			system("clear");
			printf("Le temps effectué est : %02d:%02d:%02d\n", seconde/3600%24, seconde/60%60, seconde%60);
			printf("Entrez 'r' pour continuer\n");
			while((c=getchar())!='r');
		}
		
		if(c=='r'){
			goto strt;
		}
		
		if(c=='q'){
			stop();
			goto menu;
		}
		
		usleep(500000);
		count++;
		seconde+=count%2;
		c = getchar();
	}
	
	puts("Appuyez sur ENTRÉE pour continuer.");
	getchar();
	goto menu;
quit:;
}

/**	fonction pour entrer la tonalité à la fin de la minuterie	*/								//	OK
void enter_tune(){
	char cmd[350]="\0";
	char choix[10]="\0";
	char c[30]="\0";
	
choix:
	system("clear");
	printf("CHOIX DE TONALITÉ POUR LA MINUTERIE\n");
	printf("\t(test)\ttester une tonalité\n\t(save)\tchoisir une tonalité\n\t(quit)\tretour aux parametres\n>>\t");
	scanf("%s", choix);
	
	if(strcmp(choix, "test")==0){
		test_tune();
	}
	
	if(strcmp(choix,"save")==0){
save:
		system("clear");
		sprintf(cmd, "ls -1 %s|cut -d . -f 1", chemin_son);
		system(cmd);
		
		printf("(quit)\tretour au menu précédent\n");
		printf("Entrez votre choix à enregistrer: ");
		scanf("%s",c);
		//~ getchar();
		
		if(strcmp(c,"quit")==0){
			goto choix;
		}
		
		sprintf(cmd, "if [ $(ls -1 %s|cut -d . -f 1|grep -w %s) = '%s' ]\nthen echo 'rvlc %s/%s.mp3'> %s/tonmin\necho 'Opération effectuée avec succès'; sleep 1\nfi",chemin_son, c, c, chemin_son, c, chemin_minute);
		printf("%s\n", cmd);
		getchar();
		system(cmd);
		goto save;
	}
	
	if(strcmp(c,"quit")==0){
		goto quit;
	}
	
	goto choix;
quit:;
}

/**	la fonction qui se charge de l'horloge entière	*/											//	OK
void horloge(int dim,int indmax,char table[dim][dim]){
	char choix[20]="\0";
	float timezone=0;
	videtable(dim, table);
	bord(dim, indmax, table);
	
option:
	system("clear");
	printf("Choisissez votre option:\n\t(loc)\t\theure locale\n\t(aut)\t\tautre fuseau horaire\n\t(quit)\t\tretour au menu principal\n>>\t");
	scanf("%s", choix);
	system("clear");
	getchar();
	if(strcmp(choix, "loc")==0||strcmp(choix, "aut")==0){
		if(strcmp(choix, "aut")==0){
	
enter_zone:
			zones();
			printf("\nEntrez 13 pour revenir au menu précédent\n\n");
			printf("Entrez le fuseau horaire voulu:\n>>\tUTC");
			while(scanf("%f",&timezone)!=1||timezone<-12||timezone>13){
				getchar();
				goto enter_zone;
			}
			if(timezone == 13){
				goto option;
			}
			getchar();
		}
		
		while(1){
			start();
			trotte(dim, indmax, table, choix, timezone);
			char c;
			c =getchar();
			if(c =='q'){
				stop();
				break;
			}
		}
	}
	else if(strcmp(choix, "quit")==0){
		goto quit;
	}
	
	goto option;
		
quit:
	;
}

/**	ceci affichera une petite introduction simpa au démarrage du programme	*/					//	OK
void introduction(){
	char intro[100] = "HORLOGE";
	char intro1[100] = "MINUTERIE";
	char intro2[100] = "CHRONOMETRE";
	char intro4[100] = "HORLOGE  MINUTERIE  CHRONOMETRE";

	system("clear");
	printf("\t\t");
	for(int p = 0; p < strlen(intro); p++){
		printf("\e[1;31m%c \e[0m", intro[p]);
		fflush(stdout);
		usleep(60000);
	}
	usleep(500000);
	system("clear");
	
	printf("\t\t");
	for(int p = 0; p < strlen(intro1); p++){
		printf("\e[1;33m%c \e[0m", intro1[p]);
		fflush(stdout);
		usleep(60000);	
	}
	usleep(500000);
	system("clear");
	
	printf("\t\t");
	for(int p = 0; p < strlen(intro2); p++){
		printf("\e[1;34m%c \e[0m", intro2[p]);
		fflush(stdout);
		usleep(60000);
	}
	usleep(500000);
	system("clear");
	
	printf("\t\t");	
	for(int p = 0; p < strlen(intro4); p++){
		printf("\e[1;36m%c \e[0m", intro4[p]);
		fflush(stdout);
		usleep(60000);
	}
	usleep(700000);
	system("clear");
}

/**	la fonction utilisée dans la minuterie	*/													//	OK
void minuterie(){
	
	/**	trois variables sont nécessaires dans une minuterie classique	*/
	int heure = 0,
		minute = 0,
		secondes = 3;
		
	char choix[10]="\0";
	
menu:	
	system("clear");
	printf("\t(début)\tcommencer la minuterie\n\t(quit)\tretour au menu\n>>\t");
	scanf("%s", choix);
	
	if(strcmp(choix, "début")!=0&&strcmp(choix, "quit")!=0)
		goto menu;
	else if(strcmp(choix, "quit")==0)
		goto quit;
		
	/**	on demande d'entrer la durée du compte à rebours	*/
	system("clear");
	printf("Entrez le temps à décompter\nhh:mm:ss >>\t");
	while(scanf("%d:%d:%d", &heure, &minute, &secondes) != 3){
		printf("Veuillez entrer hh:mm:ss  ");
		getchar();
	}
	
	int seconde;		//	on cherche à utiliser la valeur du temps utilisé initialement par l'utilisateur sans la modifier
	int count;			//	count nous permet une meilleure précision
	
strt:	
	seconde = 3600*heure+60*minute+secondes;
	count=0;
	start();
	
	char c='p';
	
	/**	le compte à rebours	*/
	while(seconde >= 0){
		system("clear");
		
		printf("%02d:%02d:%02d\n", (seconde/3600), (seconde/60)%60, seconde%60);

		options();
		
		if(c=='p'){
			while((c=getchar())!='d'&&c!='q'&&c!='r');
		}
		if(c=='s'){
			system("clear");
			printf("Le temps restant est : %02d:%02d:%02d\n", seconde/3600%24, seconde/60%60, seconde%60);
			printf("Entrez 'q' pour continuer\n");
			while((c=getchar())!='q');
		}
		if(c=='r'){
			goto strt;
		}
		if(c=='q'){
			stop();
			goto menu;
		}
		
		usleep(500000);
		count ++;
		
		seconde -= count%2;
		
		c=getchar();
	}
	
	stop();
	system("$HOME/.horologium/timer/tonmin");
	goto menu;
	
quit:
	;
}

/**	options à afficher pour les chronomètres et les minuteries	*/								//	OK
void options(){
	printf("Play			: 'd'\n");
	printf("Pause			: 'p'\n");
	printf("Recommencer		: 'r'\n");
	printf("Arrêter			: 's'\n");
	printf("Quitter			: 'q'\n");
}

/**	le parametre	*/																			//	OK
void parametre(){
	char choix[10]="\0";
	
	/**	on présente les options du parametre:
	 * 		tune	tonalités du chronomètre
	 * 		help	une aide sur le programme
	 * */
choix:
	printf("\n");
	system("clear");
	printf("parametre\n");
	printf("\t(tune)\tchoisir une tonalité pour la minuterie\n\t(help)\tobtenir de l'aide sur l'application\n\t(quit)\tretourner au menu\n>>\t");
	scanf("%s", choix);
	system("clear");
	getchar();
	if(strcmp(choix,"tune")==0) enter_tune();
	else if(strcmp(choix,"help")==0) aide();
	else if(strcmp(choix,"quit")==0) goto quit;
	
	goto choix;
	
quit:;
}

/**	fonction pour quitter si le signal SIGINT est rencontré	*/									//	OK
void quit(){
	stop();
	puts("OK");
	getchar();
	exit(EXIT_SUCCESS);
}

/**	fonction d'activation de la possibilité de détection de touche	*/							//	OK
void start(){
	signal(SIGINT, quit);									//	afin de veiller à ce que les parametres du terminal soient correctement rétablis, on change les réponses du programme au signal SIGINT.
	fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);		//	mettre l'entrée standard en mode non bloquant, i.e le programme peut tourner même si on n'a saisi aucune touche
	tcsetattr(STDOUT_FILENO,TCSANOW,&newt);					//	on applique les configurations enregistrées dans newt au terminal
}

/**	fonction inverse de start	*/																//	OK
void stop(){
	fcntl(STDIN_FILENO, F_SETFL, flags);					//	réactivation du mode bloquant
	tcsetattr(STDOUT_FILENO,TCSANOW,&oldt);					//	restauration des parametres de terminal originaux en réappliquant les parametres que l'on a stockées dans oldt
	signal(SIGINT, SIG_DFL);								//	on rétablit le comportement par défaut du programme face à SIGINT
}

/**	fonction pour tester les sonneries	*/														//	OK
void test_tune(){
	char c[30];
	char cmd[250]="\0";
	
entre:
	system("clear");
	sprintf(cmd, "ls -1 %s|cut -d . -f 1", chemin_son);
	system(cmd);
	printf("(quit)\tretour au menu précédent\n");
	printf("Entrez votre choix pour le test: ");
	scanf("%s",c);
	system("clear");
	
	if(strcmp(c,"quit") == 0){
		goto quit;
	}
	else{
		sprintf(cmd,"if [ $(ls -1 %s|cut -d . -f 1|grep -w %s) = '%s' ]\nthen\n\trvlc %s/%s.mp3\nfi", chemin_son, c, c, chemin_son, c);
		system(cmd);
		goto entre;
	}
	
quit:
	;
}

/**	fonction assure l'affichage d'une aiguille changeant de position en fonction du temps	*/	//	OK
void trotte(int dim, int indmax, char table[dim][dim], char*choix, float timezone){
	
	system("clear");

	/** On souhaite voir un mouvement des aiguilles */

	time_t secondes;				//	une variable spéciale pour accueillir un nombre de secondes très élevé
	struct tm instant;				//	une structure qui nous permettra de manipuler le temps
	char date[120]="\0";			//	on affichera la date en chaîne de caractères au dessous de l'horloge
	
	time(&secondes);				//	on initialise secondes avec le temps
	
	/**	une petite différence d'exécution est engendrée par les deux choix concernant l'horloge	*/
	if(strcmp(choix, "loc")==0){
		instant=*localtime(&secondes);
	}
	else{
		instant = *gmtime(&secondes);
		instant.tm_hour = (instant.tm_hour+24+(int)timezone)%24;
		instant.tm_min	+= (timezone - (int)timezone)*60;
	}
	
	/**	on refait la montre à chaque fois	*/
	videtable(dim, table);
	bord(dim, indmax, table);
	
	/**	trois nouvelles positions d'aiguilles à remplir	*/
	aiguille(dim, indmax, indmax/4, ((float)(instant.tm_hour%12)*5+(time(NULL)%3600)/720), table,'~');	/*	l'heure	*/
	aiguille(dim, indmax, 2*indmax/5, (instant.tm_min), table,'-');										/*	la minute	*/
	aiguille(dim, indmax, 4*indmax/9, instant.tm_sec, table,'`');										/*	la seconde	*/
	
	/**	on affiche le tableau	*/
	affiche(dim, table);	/*	affichage	*/
	
	/**	on souhaite aussi afficher avec l'horloge la date et l'heure en une ligne	*/
	/* 	strftime() est plutôt adapté à cet usage, elle sert à convertir en une chaîne de caractères
	 * 	le temps stocké dans une structure tm;
	 * 	dans notre code:
	 * 		%a affiche le jour de la semaine (abrégé) en anglais
	 * 		%b le mois
	 * 		%d le numéro du jour dans le mois
	 * 		%Y l'année
	 * 		%H l'heure en format 24h
	 * 		%M la minute
	 * 		%S la seconde
	 * */
	if(strcmp(choix, "loc")==0){
		strftime(date, 50, "%a %b %d %Y %H:%M:%S", &instant);
	}
	else{
		strftime(date, 50, "%H:%M:%S", &instant);
	}
	
	printf("%s\n", date);
	printf("Taper 'q' pour revenir au menu\n");
	usleep(100000);			/*	un moment pour visualiser la montre avant que l'écran ne s'efface	*/	
}

/**	fonction permettant d'avoir un fond propre pour la montre	*/								//	OK
void videtable(int dim, char table[dim][dim]){
	/**	on remplit le tableau du caractère ESPACE afin qu'il paraisse vide	*/
	for (int i=0; i<dim;i++){
        for(int j=0;j<dim;j++){
            table[i][j]=' ';
        }
    }	
}

/**	une liste non exhaustive de fuseaux horaires	*/											//	OK
void zones(){
	system("clear");
	
	printf("Quelques fuseaux horaires, liste non exhaustive:\n");
	printf("UTC-12\t:\tInternational Date Line West (IDLW)\n");
	printf("UTC-11\t:\tSamoa Standard Time (SST)\n");
	printf("UTC-10\t:\tHawaii-Aleutian Standard Time (HST)\n");
	printf("UTC-9\t:\tAlaska Standard Time (AKST)\n");
	printf("UTC-8\t:\tPacific Standard Time (PST)\n");
	printf("UTC-7\t:\tMountain Standard Time (MST)\n");
	printf("UTC-6\t:\tCentral Standard Time (CST)\n");
	printf("UTC-5\t:\tEastern Standard Time (EST)\n");
	printf("UTC-4\t:\tAtlantic Standard Time (AST)\n");
	printf("UTC-3\t:\tNewfoundland Standard Time (NST)\n");
	printf("UTC-2\t:\tBrasilia Time (BRT)\n");
	printf("UTC-1\t:\tWest Africa Time (WAT)\n");
	printf("UTC(+0)\t:\tCoordinated Universal Time (UTC)\n");
	printf("UTC+1\t:\tCentral European Time (CET)\n");
	printf("UTC+2\t:\tEastern European Time (EET)\n");
	printf("UTC+3\t:\tMoscow Standard Time (MSK)\n");
	printf("UTC+4\t:\tGulf Standard Time (GST)\n");
	printf("UTC+5\t:\tPakistan Standard Time (PKT)\n");
	printf("UTC+6\t:\tBangladesh Standard Time (BST)\n");
	printf("UTC+7\t:\tIndochina Time (ICT)\n");
	printf("UTC+8\t:\tChina Standard Time (CST)\n");
	printf("UTC+9\t:\tJapan Standard Time (JST)\n");
	printf("UTC+10\t:\tAustralian Eastern Standard Time (AEST)\n");
	printf("UTC+11\t:\tSolomon Islands Time (SBT)\n");
	printf("UTC+12\t:\tNew Zealand Standard Time (NZST)\n");
}

/**********************************************************************************************************************************************/
/**********************************************************************************************************************************************/
/*														FIN DU PROGRAMME																		*/
/**********************************************************************************************************************************************/
/**********************************************************************************************************************************************/

