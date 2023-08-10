#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comma(char* aTransf);
int count_char(char* aTransf);
double create_pow(double iva, int avo);
int charToInt(char* aTransf);
float charTofloat(char* aTransf);
char** repair_separator(char* aTransf, char getsep);
float dayTosec(double dd);
void hours(float seconde, int* hh, int* mn, int* s);
char* get_hms_ymd(int, int, int, int, int, int);
void start_progr(char* yy, char* mm, char* dd, char* date);
char** allouer2D(int line, int rows);
int** allouer2Dint(int line, int rows);
float monthToSec(float mm);
float secToDay(double s);
char* restart_prog(char* date);

int main(){
	//~ char* y = NULL;	char* mm = NULL; char* dd = NULL;
	char* date = NULL;
/* allocation dynamique des variables declarées */
	//~ y = (char*)malloc(5);	mm = (char*)malloc(5);	dd = (char*)malloc(11);
	date = (char*)malloc(22);
	//~ date = "17.91667/05/2005";
	date = "05/10/1981 9:30:00";
	restart_prog(date);
	//~ start_progr(y, mm, dd, date);
	return 0;
}

/*	
 * */
int comma(char* aTransf){
	int l= 0;
	while(aTransf[l] != '.' || aTransf[l] != ',')	l++;
	return l;
}

/*	
 * */
int count_char(char* aTransf){
	int l= 0;
	while(aTransf[l] != '\0')	l++;
	return l;
}

/*	
 * */
double create_pow(double iva, int avo){
	double nombre = 1;
	for(int p = 0; p < avo; p++)	nombre = nombre*iva;
	return nombre;
}

/*	
 * */
int charToInt(char* aTransf){

	int number = 0;
	int line = count_char(aTransf);

	for(int l = line - 1, p = 0; l >= 0; l--, p++){
		int n = aTransf[l] - 48, pow_10 = create_pow(10, p);
		if(n < 0 || n >= 10)		return 0;
		else{
			n = n*pow_10;
			number = number+n;
		}
	}

	return number;
}

/*	
 * */
float charTofloat(char* aTransf){	
	float number = 0.0;
	int p_neg = -1;
	for(int p = 0; p < count_char(aTransf); p++){
		number += (*(aTransf+p)-48)*pow(10, p_neg);
		p_neg --;
	}
	return number;
}

/*	
 * */
char** repair_separator(char* aTransf, char getsep){
	char** slash;
	int counts = 2, predim = 0, deudim = 0;
	slash = allouer2D(counts+1, 5);
	
	for (int i = 0; i < count_char(aTransf); i++){
		if(aTransf[i] == getsep){
			predim ++;	deudim = 0;
		}
		else{
			slash[predim][deudim] =  aTransf[i];	deudim++;
		}
	}
	
	return slash;
}

/*	
 * */
float dayTosec(double dd){
	return (dd*86400);
}

/*	
 * */
void hours(float seconde, int* h, int* mn, int* s){
	*h = (int)seconde/(3600);	seconde = (int)seconde%(3600);
	*mn= ((int)seconde)/(60);	seconde = (int)seconde%(60);
	*s = seconde;
}

/*	
 * */
char* get_hms_ymd(int hh, int mn, int s, int yy, int mm, int dd){
	char* hms_ymd = (char*)malloc(32);
	sprintf(hms_ymd, "%02d:%02d:%02d	%d/%02d/%02d", hh, mn, s, yy, mm, dd);
	return hms_ymd;
}

/*
 * */
void start_progr(char* yy, char* mm, char* dd, char* date){
	char** find_slash = repair_separator(date, '/');
	int hh = 0, mn = 0, ss = 0;
	float seconde = 0.0;
	float mon=0.0;
	
	strcpy(dd, find_slash[0]);		strcpy(mm, find_slash[1]);		strcpy(yy, find_slash[2]);	/*omena an'ny valeur yy/mm/dd */
	
	char** find_comma = repair_separator(dd, '.'); 
	
	seconde=dayTosec(charTofloat(*(find_comma+1)));
	
	hours(mon,&hh,&mn,&ss);
	hours(seconde,&hh,&mn,&ss);	
	//~ printf("%s", get_hms_ymd(hh, mn, ss, charToInt(yy),charToInt(mm), charToInt(find_comma[0])));
	
}

/*
 * */
char** allouer2D(int line, int rows){
	char** allouer = NULL;
	allouer = malloc(line);
	for (int i = 0; i < line; i++)	allouer[i] = malloc(rows);
	return allouer;
}

/*
 * */
float secToDay(double s){
	return (s/86400);
}

/*
 * */
 char* restart_prog(char* date){
	char* day = malloc(27);
	char* dmy = malloc(12);
	char* hms = malloc(12);
	char** find_space = allouer2D(2, 6);
	find_space = repair_separator(date, ' ');
	
	strcpy(dmy , *(find_space));
	strcpy(hms , *(find_space+1));

	char** find_slash = allouer2D(3, 32);
	char* d = malloc(4);
	char* m = malloc(4);
	char* y = malloc(4);
	int ds = 0;
	find_slash = repair_separator(dmy, '/');
	strcpy(d, *find_slash);
	strcpy(m, *(find_slash+1));
	strcpy(y, *(find_slash+2));
	ds = charToInt(d);
	
	char** find_2point = allouer2D(3, 4);
	char* hour = malloc(4);
	char* min = malloc(4);
	char* sec = malloc(4);
	
	find_2point = repair_separator(hms, ':');
	strcpy(hour, *(find_2point));
	strcpy(min, *(find_2point+1));
	strcpy(sec, *(find_2point+2));


	int heur = 0; heur = charToInt(hour);
	int minut=0;minut = charToInt(min);
	int second = 0; second = charToInt(sec);	
	int secondes = 0;
	
	secondes = (heur*3600) + (minut*60) + second;

	float convert = 0.0;
	convert = secToDay(secondes);
	float result = 0.0;
	result = (float)ds + convert;

	sprintf(day, "%f/%s/%s",result, m, y);
	printf("\n%s", day);
	return day;
}

