#include<math.h>
int binaire(int n,int *tab)
{
    int qq;
    int m=n;
    int j;
    qq=1;
    j=7;
    while(qq>0)
    {
        tab[j]=m%2;
        qq=m/2;
        j--;
        m=qq;
    }
}

int decimale(int *tab)
{ 
    int x=0;
    for (int i=0;i<=7;i++)
    {
        x+=pow(2,i)*tab[7-i];
    }
   //printf("\n%d",x);
    return x;
}

    void animation(char *mess)
{
	int i;
	for(i = 0; i < strlen(mess); i++)
	{
		printf("%c",mess[i]);
		fflush(stdout);
		usleep(5000);  // Pause de 50 millisecondes entre chaque caractère
	}
}

char *stringg(int nbr)
{
	char *tab=NULL;
	tab=(char*)malloc(nbr*sizeof(char));
	if(tab == NULL)
	{
		printf("Erreur d'allocation");
		exit(1);
	}
	return (tab);
}

char **str(int nbr,int nb)
{
	char **tab=NULL;
	tab=(char**)malloc(nbr*sizeof(char*));
    for(int i=0;i<nb;i++)
        tab[i]=(char*)malloc(nbr*sizeof(char));
	if(tab == NULL)
	{
		printf("Erreur d'allocation\n");
	}
	return (tab);
}

int classerIP(int ip)
{

        if (ip>=0 && ip<=127)
        {
            printf("votre IP est de classe A\n");
            animation("votre netmask (par defaut) est 255.0.0.0\n");
            return  1;
        }
        else if (ip>127 && ip<=191)
        {
            printf("votre IP est de classe B\n");
            animation("votre netmask (par defaut) est 255.255.0.0\n");
            return  2;
        }
        else if (ip>191 && ip<=223)
        {
            printf("votre IP est de classe C\n");
            animation("votre netmask (par defaut) est 255.255.255.0\n");
            return  3;
        }
        else if (ip>223 && ip<=239)
        {
            printf("votre IP est de classe D\n");
            printf("addresse ip a usage specifique\n");
            return 0;
        }
        else if (ip>239 && ip<=255)
        {
            printf("votre IP est de classe E\n");
            printf("addresse ip a usage specifique\n");
            return 0;
        }
        else
        { 
            printf("Enter a valid IP ");
        }
}

int getsr()
{
    int ssrr;
    char str1[10];
    printf ("SR:");
    scanf("%s",str1);
    ssrr=atoi(str1);
    while(ssrr<=0 || ssrr >31)
    {
        animation("le nombre de bits pour le reseau doit etre entre 1 et 30\n");
        ssrr=getsr();
    };
    return ssrr;

}

int getNbc(int ssrr)
{
    int n;
    char str1[10];
    printf ("Nombre de coupe:");
    scanf("%s",str1);
    n=atoi(str1);
      while(n<=0 || n+ssrr>31)
    {
        printf("le nombre de decoupage doit etre entre 1 et %d\n",31-ssrr);
        n=getNbc(ssrr);
    }; 
   // printf("%d",ssrr);
    return n;
}

void BIDE(int *tab,int *tab0,int *tab1,int *tab2,int *tab3)
{
    tab[0]=decimale(tab0);
    tab[1]=decimale(tab1);
    tab[2]=decimale(tab2);
    tab[3]=decimale(tab3);
}

void DEBI(int *tab,int *tab0,int *tab1,int *tab2,int *tab3)
{
    binaire(tab[0],tab0);
    binaire(tab[1],tab1);
    binaire(tab[2],tab2);
    binaire(tab[3],tab3);
}

void copie(int *tab,int *tab0,int *tab1,int *tab2,int *tab3)
{
    int z;
    for ( z=0;z<32;z++)
    {
        if (z>=0 && z<=7)
            tab[z]=tab0[z];
        if (z>=8 && z<=15)
            tab[z]=tab1[z-8];
        if (z>=16 && z<=23)
            tab[z]=tab2[z-16];
        if (z>=24 && z<=31)
            tab[z]=tab3[z-24];
    }
}

void pieco(int *tab,int *tab0,int *tab1,int *tab2,int *tab3)
{
    int z;
    for ( z=0;z<32;z++)
    {
        if (z>=0 && z<=7)
            tab0[z]=tab[z];
        if (z>=8 && z<=15)
            tab1[z-8]=tab[z];
        if (z>=16 && z<=23)
            tab2[z-16]=tab[z];
        if (z>=24 && z<=31)
            tab3[z-24]=tab[z];
    }
}

void afficheBinaire(int *tab)
{
   printf("BINAIRE => ");
    for (int i=0;i<32;i++)
    {
        printf("%d",tab[i]);
    }
    printf("\n");
}

void afficheDecimal(int *tab)
{
   printf("DECIMAL => ");
    printf("%d.%d.%d.%d\n",tab[0],tab[1],tab[2],tab[3]);
}

void checkPointCharBits(int *octet,int *ipp)
{     
    char **token;
    int nbPoint=0;
    int tab[4];
    int count=0;
    int i;
    int j=0;
    char *endptr;
    int ok=0;
    char *str2;
    char *str1;
    str1=stringg(256);
    str2=stringg(256);
    printf("IP:");
    fgets(str1,256,stdin);
    while(str1[j]!='\0')
    {
        if (isalpha(str1[j]))
        {
            count ++;
        }
        j++;
    }
    token=str(4,100); 
    char *subtoken=strtok(str1,".");
        while(subtoken!=NULL)
        {
            strcpy(token[nbPoint],subtoken);
            subtoken=strtok(NULL,".");
            nbPoint++;
        }
    int n=nbPoint;
    if(count !=0 || n!=4)
    {
        animation("ERROR:char ou nombre de point a verifie\n ");
        checkPointCharBits(octet,ipp);
       // exit(1);
    }

    else 
    {
        for(i=0;i<n;i++)
        {
            tab[i]=atoi(token[i]);
        }
         for(i=0;i<n;i++)
        {
            // if ((tab[i] >=0 && tab[i] <=255 && strcmp(token[i],"0")!=0 )||(tab[i] ==0 && strcmp(token[i],"0")==0))
            if (tab[i] >=0 && tab[i] <=255 )
                strcat(str2,token[i]);
            else
            {
                ok=1;
            }
         }
        if(ok==1)
        {
             animation(" ERROR: Nombre maximale de Bits depassé \n");
             checkPointCharBits(octet,ipp);
             //exit(1);
        }
        else
        {
            if ((tab[0]==127 && tab[1]==0 && tab[2]==0 &&tab[3]==1)|| (tab[0]==0 && tab[1]==0 && tab[0]==0 &&tab[3]==0))
                {
                    animation("IP specifique et  bien reservé\n");
                    exit(1);
                }
            else{
                for(i=0;i<n;i++)
                {
                    octet[i]=tab[i];
                }
                    int *tab1,*tab2,*tab3,*tab0;
                    tab1=(int *)malloc(8*sizeof(int));
                    tab2=(int *)malloc(8*sizeof(int));
                    tab3=(int *)malloc(8*sizeof(int));
                    tab0=(int *)malloc(8*sizeof(int));

                DEBI(octet, tab0, tab1, tab2, tab3) ;
                copie(ipp, tab0, tab1, tab2, tab3);
            }
        }
    }
}

void checkPointCharBits1(int *octet,int *ipp)
{     
    char **token;
    int nbPoint=0;
    int tab[4];
    int count=0;
    int i;
    int j=0;
    char *endptr;
    int ok=0;
    char *str2;
    char *str1;
    str1=stringg(256);
    str2=stringg(256);
    printf("netmask:");
    fgets(str1,256,stdin);
    while(str1[j]!='\0')
    {
        if (isalpha(str1[j]))
        {
            count ++;
        }
        j++;
    }
    token=str(4,100); 
    char *subtoken=strtok(str1,".");
        while(subtoken!=NULL)
        {
            strcpy(token[nbPoint],subtoken);
            subtoken=strtok(NULL,".");
            nbPoint++;
        }
    int n=nbPoint;
    if(count !=0 || n!=4)
    {
        animation("ERROR:char ou nombre de point a verifie\n ");
        checkPointCharBits1(octet,ipp);
       // exit(1);
    }

    else
    {
        for(i=0;i<n;i++)
        {
            tab[i]=atoi(token[i]);
        }
         for(i=0;i<n;i++)
        {
            if (tab[i] >=0 && tab[i] <=255 )
                strcat(str2,token[i]);
            else
            {
                ok=1;
            }
         }
        if(ok==1)
        {
             animation(" ERROR: Nombre maximale de Bits depassé \n");
             checkPointCharBits1(octet,ipp);
             //exit(1);
        }
        else
        {
            for(i=0;i<n;i++)
            {
                octet[i]=tab[i];
            }
                int *tab1,*tab2,*tab3,*tab0;
                tab1=(int *)malloc(8*sizeof(int));
                tab2=(int *)malloc(8*sizeof(int));
                tab3=(int *)malloc(8*sizeof(int));
                tab0=(int *)malloc(8*sizeof(int));

            DEBI(octet, tab0, tab1, tab2, tab3) ;
            copie(ipp, tab0, tab1, tab2, tab3);
        }
    }
}


 void netBroad(int *token)
{     
    int ipadresse;
    ipadresse=classerIP(token[0]);
    if(ipadresse==0)
    {
        animation("Je ne sais pas la speficite de votre reseau\n");
        animation("desole,je ne peux pas fournir son @net et @broad\n");
    }

    else if(ipadresse==1)
    {
        printf("=> @net: %d.0.0.0\n",token[0]);
        printf("=> @broad: %d.255.255.255\n",token[0]);
        animation("=> nbMac: 16 777 214\n");
    }

    else if(ipadresse==2)
    {
        printf("=> @net: %d.%d.0.0\n",token[0],token[1]);
        printf("=> @broad: %d.%d.255.255\n",token[0],token[1]);
        animation("=> nbMac: 35 534\n");
    }

    else if(ipadresse==3)
    {
        printf("=> @net: %d.%d.%d.0\n",token[0],token[1],token[2]);
        printf("=> @broad: %d.%d.%d.255\n",token[0],token[1],token[2]);
        animation("=> nbMac: 254\n");
    }
}

/* 
void getIP2(int sr,int n,int *octet,int *ipp)
{  
    int *tab1,*tab2,*tab3,*tab0;
        tab1=(int *)malloc(8*sizeof(int));
        tab2=(int *)malloc(8*sizeof(int));
        tab3=(int *)malloc(8*sizeof(int));
        tab0=(int *)malloc(8*sizeof(int));

        int netmask[32];
        int netmi[4];
        int adBi[4];
        int adRi[4];
        int netmask1[32];
        int adB[32],adR[32];

    animation("IP :");
    afficheDecimal(octet);

        for (int i=0;i<32;i++)
        {
            if (i<sr)
            {
                netmask[i]=1;
                netmask1[i]=ipp[i];
            }
            else
            {
                netmask[i]=0;
                netmask1[i]=1;
            }
        }


    pieco( netmask, tab0, tab1, tab2, tab3);
    BIDE(netmi, tab0, tab1, tab2, tab3);
    animation("Masque de sous Reseau:");
    afficheDecimal(netmi);

        for (int i=0;i<32;i++)
        {
            adR[i]=ipp[i]*netmask[i];
        }

    pieco( adR, tab0, tab1, tab2, tab3);
    BIDE(adRi, tab0, tab1, tab2, tab3);
    animation("\nadresse Reseau   :");
    afficheDecimal(adRi);


        for (int i=0;i<32;i++)
        {
            adB[i]=netmask1[i];
        }
    pieco( adB, tab0, tab1, tab2, tab3);
    BIDE(adBi, tab0, tab1, tab2, tab3);
    animation("adresse Broadcast:");
    afficheDecimal(adBi);

        int nhots=32-sr;
        int nbMac=pow(2,nhots)-2;
        printf("nombre de machine:    %d\n",nbMac);


    int i,limit=pow(2,n);
    int max=255/limit;
        if (octet[0]>=0 && octet[0]<=127)
        {
            for(i=1;i<=limit;i++)
            {
                printf("%d)\n",i);
                animation("\nadresse Reseau   :");
                if (i==1)
                {
                    printf("    %d.0.0.0\n",adRi[0]);
                    animation("adresse Broadcast:");
                    printf("    %d.%d.255.255\n",adBi[0],max);
                    printf("nombre de machine:    %d\n",nbMac);
                    printf("        ------------------\n");
                }
                if(i>1 && i<=limit)
                {
                    printf("    %d.%d.0.0\n",adRi[0],-1+i+(i-1)*max);
                    animation("adresse Broadcast:");
                    printf("    %d.%d.255.255\n",adBi[0],i-1+(max)*i );
                    printf("nombre de machine:    %d\n",nbMac);
                    printf("        ------------------\n");
                }
            }
        }
        
        else if (octet[0]>127 && octet[0]<=191)
        {
           
            for(i=1;i<=limit;i++)
            {
                printf("%d)\n",i);
                animation("\nadresse Reseau   :");
                if (i==1)
                {
                    printf("    %d.%d.0.0\n",adRi[0],adRi[1]);
                    animation("adresse Broadcast:");
                    printf("    %d.%d.%d.255\n",adBi[0],adBi[1],max);
                    printf("nombre de machine:    %d\n",nbMac);
                    printf("        ------------------\n");
                }
                if(i>1 && i<=limit)
                {
                    printf("    %d.%d.%d.0\n",adRi[0],adRi[1],-1+i+(i-1)*max);
                    animation("adresse Broadcast:");
                    printf("    %d.%d.%d.255\n",adBi[0],adBi[1],i-1+(max)*i );
                    printf("nombre de machine:    %d\n",nbMac);
                    printf("        ------------------\n");
                }
            }

        }
        else if (octet[0]>191 && octet[0]<=223)
        {
           for(i=1;i<=limit;i++)
            {
                printf("%d)\n",i);
                animation("\nadresse Reseau   :");
                if (i==1)
                {
                    printf("    %d.%d.%d.0\n",adRi[0],adRi[1],adRi[2]);
                    animation("adresse Broadcast:");
                    printf("    %d.%d.%d.%d\n",adBi[0],adBi[1],adBi[2],max);
                    printf("nombre de machine:    %d\n",nbMac);
                    printf("        ------------------\n");
                }
                if(i>1 && i<=limit)
                {
                    printf("    %d.%d.%d.%d\n",adRi[0],adRi[1],adRi[2],-1+i+(i-1)*max);
                    animation("adresse Broadcast:");
                    printf("    %d.%d.%d.%d\n",adBi[0],adBi[1],adBi[2],i-1+(max)*i );
                    printf("nombre de machine:    %d\n",nbMac);
                    printf("        ------------------\n");
                }
            }
        }
        else
        {
            animation("addresse ip a usage specifique!!\n");
        }
}
 */
void aafficheBinaire(int *tab,int n)
{
    printf("BINAIRE => ");
    for (int i=1;i<=n;i++)
    {
        printf("%d",tab[i]);
    }
    printf("\n");
}
int bbinaire(int n,int *tab,int kkk)
{
        int qq;
        int m=n;
        int j;
        qq=1;
        j=kkk;
        while(qq>0)
        {
            tab[j]=m%2;
            qq=m/2;
            j--;
            m=qq;
        } 
}

 void getIP(int sr,int n,int *octet,int *ipp)
{  
    int *tab1,*tab2,*tab3,*tab0;
        tab1=(int *)malloc(8*sizeof(int));
        tab2=(int *)malloc(8*sizeof(int));
        tab3=(int *)malloc(8*sizeof(int));
        tab0=(int *)malloc(8*sizeof(int));
    int *msrTab;
    msrTab=(int *)calloc(n,sizeof(int));
        
        int netmi[4];
        int adBi[4];
        int adRi[4];
        int netmask1[32];
        int adB[32],adR[32];
int i,j,limit=pow(2,n);
    int nhots=32-sr-n;
    int nbMac=pow(2,nhots)-2;
int netmask[32];
    animation("IP :");
    afficheDecimal(octet);
    for (j=0;j<limit;j++)
    {
        printf("%d)\n",j);
    bbinaire(j,msrTab,n);
        for (i=0;i<32;i++)
        {
            if (i<sr)
            {
                netmask[i]=1;
                netmask1[i]=ipp[i];
            }
           else  if (i>=sr && i<sr+n)
            {
                netmask[i]=msrTab[i-sr+1];
                ipp[i]=msrTab[i-sr+1];
                netmask1[i]=msrTab[i-sr+1];
            }
            else
            {
                netmask[i]=0;
                netmask1[i]=1;
            }

        }
    
        printf("\n")  ;
    pieco( netmask, tab0, tab1, tab2, tab3);
    BIDE(netmi, tab0, tab1, tab2, tab3);
    animation("Masque de sous Reseau:");
     afficheDecimal(netmi);

        for (int i=0;i<32;i++)
        {
            adR[i]=ipp[i]*netmask[i];
        }
    pieco( adR, tab0, tab1, tab2, tab3);
    BIDE(adRi, tab0, tab1, tab2, tab3);
    animation("adresse Reseau       :");
    afficheDecimal(adRi);

    for (int i=0;i<32;i++)
    {
        adB[i]=netmask1[i];
    }
    pieco( adB, tab0, tab1, tab2, tab3);
    BIDE(adBi, tab0, tab1, tab2, tab3);
    animation("adresse Broadcast    :");
    afficheDecimal(adBi);

        printf("nombre de machine    :        =>%d\n\n             -------------\n",nbMac);
    }
} 

void netmaskget(int *netmi,int *sr)
{
    int octet[4];
    int netmask[32];
    int z;
    char str1[256];
    int oui=0,non=0;
    // printf("Netmask:");
    // fgets(str1,256,stdin);
    checkPointCharBits1(octet,netmask);
        int *tab1,*tab2,*tab3,*tab0;
        tab1=(int *)malloc(8*sizeof(int));
        tab2=(int *)malloc(8*sizeof(int));
        tab3=(int *)malloc(8*sizeof(int));
        tab0=(int *)malloc(8*sizeof(int));

            for ( z=0;z<32;z++)
            {
                if (netmask[z]==0)
                {
                    oui=z;
                    *sr=z-1;
                    break;
                }
            }
            for ( z=0;z<32;z++)
            {
                if (netmask[z]==1 && z>oui)
                {
                    non=1;
                    break;
                }
            }
            if(non==0)
            {
                animation("Votre netmask en binaire\n");
                for ( z=0;z<32;z++)
                {
                    printf("%d",netmask[z]);
                    netmi[z]=netmask[z];
                }
            }
            if(non==1)
            {
                animation("Masque de sous reseau INVALIDE\n");
                animation("Votre netmask en binaire \n");
                for ( z=0;z<32;z++)
                {
                    printf("%d",netmask[z]);
                }
                printf("\n\n\n");
                netmaskget(netmi,sr);
            }
    free(tab0);
    free(tab1);
    free(tab2);
    free(tab3);
}

void getNetmask(int *netmask,int *octet,int sr,int *ipp)
{ 
    int *tab1,*tab2,*tab3,*tab0;
        tab1=(int *)malloc(8*sizeof(int));
        tab2=(int *)malloc(8*sizeof(int));
        tab3=(int *)malloc(8*sizeof(int));
        tab0=(int *)malloc(8*sizeof(int));

        int netmask1[32];
        int i;
        int adR[32],adB[32];
        int adRi[4],adBi[4],netmi[4];

    animation("\nIP :");
    afficheDecimal(octet);
        for (int i=0;i<32;i++)
        {
            if (i<sr)
            {
                netmask1[i]=ipp[i];
            }
            else
            {
                netmask1[i]=1;
            }
        }

    pieco(netmask, tab0, tab1, tab2, tab3);
    BIDE(netmi, tab0, tab1, tab2, tab3);

    animation("Masque de sous Reseau\n");
    afficheBinaire(netmask);
    afficheDecimal(netmi);


        for (int i=0;i<32;i++)
        {
            adR[i]=ipp[i]*netmask[i];
        }
    pieco( adR, tab0, tab1, tab2, tab3);
    BIDE(adRi, tab0, tab1, tab2, tab3);
    animation("\nadresse Reseau\n");
    afficheDecimal(adRi);
    afficheBinaire(adR);


        for (int i=0;i<32;i++)
        {
            adB[i]=netmask1[i];
        }

    pieco( adB, tab0, tab1, tab2, tab3);
    BIDE(adBi, tab0, tab1, tab2, tab3);
    animation("\nadresse Broadcast\n");
    afficheDecimal(adBi);
    afficheBinaire(adB);


        int nhots=32-sr;
        int nbMac=(pow(2,nhots)-2)/2;
        printf("nombre de machine :%d\n",nbMac-1);
}


int couper1(int n,int *octet,int *ipp )
{
    int sr=0;
        if (octet[0]>=0 && octet[0]<=127 && n>0 && n <= 23)
        {
            sr=8+n;
            getIP(sr,n,octet,ipp);
        }
        else if (octet[0]>127 && octet[0]<=191 && n>0 && n <= 15)
        {
            sr=16+n;
            getIP(sr,n,octet,ipp);
        }
        else if (octet[0]>191 && octet[0]<=223 && n>0 && n <= 7)
        {
            sr=24+n;
            getIP(sr,n,octet,ipp);
        }
        else if (octet[0]>223 && octet[0]<=255)
        {
            sr=n;
            getIP(sr,n,octet,ipp);
            // printf("addresse ip a usage specifique,NOn decoupable\n");
            // return 0; 
        }
        else if (octet[0]>239 && octet[0]<=255)
        {
            sr=n;
            getIP(sr,n,octet,ipp);
            //  printf("addresse ip a usage specifique,Non decoupable\n");
            // return 0; 
        }
        else
        { 
            printf("addresse ip a usage specifique,Non decoupable\n");
           return 0;
        }
}

void getIP1(int sr,int *octet, int *ipp )
{
    int *tab1,*tab2,*tab3,*tab0;
        tab1=(int *)malloc(8*sizeof(int));
        tab2=(int *)malloc(8*sizeof(int));
        tab3=(int *)malloc(8*sizeof(int));
        tab0=(int *)malloc(8*sizeof(int));

        int netmask[32];
        int netmi[4];
        int adBi[4];
        int adRi[4];
        int ippi[4];
        int netmask1[32];
        int adB[32],adR[32];

    printf("IP\n");
    afficheBinaire(ipp);
    afficheDecimal(octet);

        for (int i=0;i<32;i++)
        {
            if (i<sr)
            {
                netmask[i]=1;
                netmask1[i]=ipp[i];
            }
            else
            {
                netmask[i]=0;
                netmask1[i]=1;
            }
        }

    pieco(netmask, tab0, tab1, tab2, tab3) ; 
    BIDE(netmi, tab0, tab1, tab2, tab3);
    animation("Masque de sous Reseau\n");
    afficheBinaire(netmask);
    afficheDecimal(netmi);

        for (int i=0;i<32;i++)
            {
                adR[i]=ipp[i]*netmask[i];
            }
    pieco( adR, tab0, tab1, tab2, tab3);
    BIDE(adRi, tab0, tab1, tab2, tab3);
    animation("\nadresse Reseau\n");
    afficheBinaire(adR);
    afficheDecimal(adRi);


        for (int i=0;i<32;i++)
            {
                adB[i]=netmask1[i];
            }
    pieco( adB, tab0, tab1, tab2, tab3) ;  
    BIDE(adBi, tab0, tab1, tab2, tab3);
    animation("adresse Broadcast\n");
    afficheBinaire(adB);
    afficheDecimal(adBi);

        int nhots=32-sr;
        int nbMac=pow(2,nhots)-2;
        printf("nombre de machine :%d\n",nbMac);

   // int nbc=getNbc(31);
   // couper(nbc, octet,ipp ,sr);
  // getIP(sr, n,octet,ipp);
}
