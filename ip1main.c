#include "ip1.h"


int main()
{

        char *ip,*netmask;
        int sr=0,n,ssrr;
        int ipp[32];  //ip en 32 bits
        int octet[4],msr[32];
        ip=stringg(256);
        netmask=stringg(256);
        checkPointCharBits(octet,ipp);

ssrr=getsr();
getIP1(ssrr, octet,ipp);  // display in binary and byte the firs @reseau and the last @broadcast 

printf("\n\n--------------------\n\n");

n=getNbc(ssrr);
getIP(ssrr, n,octet,ipp);  // couper a partir de votre sr et n
//couper1(n, octet,ipp );  // coupe a partir de son classe
return (EXIT_SUCCESS);
}

