
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "ip1.c"
int getsr();
int getNbc(int max);
void animation(char *mess);
char *stringg(int nbr);
char **str(int nbr,int nb);
void netBroad(int *token);         // exo 1  avec le netmask par defaut;
int classerIP(int ip);             // neccesssaire au netBroad
void checkPointCharBits1(int *octet,int *ipp); 
void checkPointCharBits(int *octet,int *ipp);   // verifier si l ip est valide ou non
//void checkPointCharBits(char *str1,int *octet,int *ipp);   // verifier si l ip est valide ou non
void copie(int *tab,int *tab0,int *tab1,int *tab2,int *tab3);     // tab=tab0
void pieco(int *tab,int *tab0,int *tab1,int *tab2,int *tab3);     // tab0=tab
void BIDE(int *tab,int *tab0,int *tab1,int *tab2,int *tab3);      // tab[0]=decimale(tab0);
void DEBI(int *tab,int *tab0,int *tab1,int *tab2,int *tab3);      // binaire(tab[0],tab0);
void afficheBinaire(int *tab);
void afficheDecimal(int *tab);

void getIP(int sr,int n,int *octet,int *ipp );   // neccessaire au decoupage

void getIP1(int sr,int *octet0,int *ipp );       // exo 2)a- affichage avec BIN
void netmaskget(int *netmi,int *sr); // verifie le netmask et mettre son valeur en 32bits dans netmi si valide
void getNetmask(int *netmask,int *octet,int sr,int* ipp); // rep de exo 1)
int couper(int n,int *octet,int *ipp ,int sr );        //


//-----------------------------------------------------


int bbinaire(int n,int *tab,int srrr);
void aafficheBinaire(int *tab,int n);