#include <iostream>
using namespace std;

int messaggio[100];
char plaintext[101];

int _pow(int base,int esp,int MOD){
    long long r=1;
    long long _base=base;
    while(esp>0){
        if(esp%2) 
         r=(r*_base)%MOD;
        _base=(_base*_base)%MOD;
        esp>>=1; 
    }
    return r;
}

void decifra(int N,int d,int L,int messaggio[],char plaintext[]){
    for(int i=0;i<L;i++)
        plaintext[i]=_pow(messaggio[i],d,N);
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int N,d,L;
    cin>>N>>d>>L;
    for(int i=0;i<L;i++)
        cin>>messaggio[i];
    decifra(N,d,L,messaggio,plaintext);
    plaintext[L]='\0';
    cout<<plaintext;

    return 0;
}