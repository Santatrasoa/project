#ifndef __UTILS__
typedef struct {
    char mot_de_passe[100];
    char documentRoot[100];
    char directoryIndex[30];
    char nomConf[100];
    char serverName[100];
    char serverAdmin[100]; 
}AllSiteDepend;

typedef struct{
    char nameFile[100];
    char status[100];
    char notStatus[100];
}FileConf;

typedef struct {
    char nameOfSite[1000];
    char date[1000];
    char ipAdress[1000];
}AccessContent;


#define __HEAD__
void head();

#define __WRITE_FILE__
void writeFileConf(AllSiteDepend information);

#define __GETINFO__
AllSiteDepend getinfo(char * link);

#define __HEXA__
char *convertHexa(char *message);

#define __MOVE__
void moveFile(AllSiteDepend information);

#define __ACTIVATE__
void activate(AllSiteDepend information);

#define __WRITE_HOSTS__
void etcHosts(AllSiteDepend information);

#define __PERMISSION__
FILE * changePermission(char * nameOfFile);

#define __LISTFILE__
FileConf * getListFile();

#define __SHOW_LIST__
void showList(FileConf * allFile, int number_of_site);

#define __ACCESS_LOG__
int countLine();
void getUtil(char * string);
void showListAccess(char * string, int number_of_site, int num_pag, AccessContent * info);
AccessContent * infoAccess(int * number_of_site);

#endif