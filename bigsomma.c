#include <stdio.h>
#include <unistd.h>
#pragma GCC optimize ("O3")
#define ll long long
#define MAXN 0xFFFFF

char buffer[MAXN];

ll somma(FILE *f){
int fp=fileno(f);
int sign=1;
int bytes;
ll sum=0;
int num=0;
int first=1;
    while((bytes=read(fp,buffer,MAXN))>0){
        int i=0;
        if(first){ //se è la prima lettura devo togliere il numero di elementi da leggere
            while(buffer[i]!='\n')
                i++;
            first=0;
        }
        for(;i<bytes;i++){
            if(buffer[i]>='0' && buffer[i]<='9') //ho letto una cifra. dato che leggo da sinistra, sommo la cifra al numero, e alla cifra successiva moltiplico il numero per 10. 
                num=(num*10)+(buffer[i]-'0');    //dato che l'ultima cifra corrisponde a 10^0, non moltiplicherò ulteriormente, 
                                                 //arrivando cosi ad aver moltiplicato il numero per 10^(n_cifre-1), ricomponendo il numero originale
            else if(buffer[i]=='-') //se trovo un meno il numero è negativo. modifico il segno da applicare al numero
                sign=-1;
            else{                   //arrivato qui significa che ho trovato uno spazio.
                sum+=(num*sign);    //sommo il numero applicando il segno e resetto numero e segno
                sign=1;
                num=0;
            }
        }
    }
    sum+=(num*sign); //dato che dopo l'ultimo numero non troverò nessun carattere da leggere, devo aggiungere il numero manualmente
    return sum;
}

int main(){
FILE *fp=fopen("input.txt","r");
    printf("%lld",somma(fp));
    return 0;
}