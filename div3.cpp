#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int count_r(string &s,int r){ //conta il numero di cifre con resto r
int n=0;
    for(int i=0;i<s.length();i++)
        if((s[i]-'0')%3==r)
            n++;

    return n;    
}

int count_3_r(string &s,int r){ //conta il numero di cifre con resto 3-r
int n=0;
    for(int i=0;i<s.length();i++)
        if((s[i]-'0')%3==3-r)
            n++;

    return n;
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);

int T;
    cin>>T;
    while(T--){
        int r=0;
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++) //somma delle cifre
            r+=s[i]-'0';
        
        r%=3; //resto del numero
        
        if(r==0){ //numero divisibile per 3, mi fermo
            cout<<s<<'\n';
            continue;
        }

        //provo rimuovendo una cifra con resto uguale a r
        string ans1;
        if(count_r(s,r)>0){ //se c'è almeno una cifra con resto uguale a r
            bool rem=true;
            ans1=s;
            for(int i=0;i<ans1.length()-1;i++)
                if((ans1[i]-'0')%3==r && ans1[i]<ans1[i+1]){
                    rem=false;
                    ans1.erase(i,1);
                    break;
                }

            for(int i=ans1.length()-1;rem;i--) //se non ho trovato una cifra uguale al resto che rispetti s[i]<s[i+1], tolgo quella meno significativa
                if((ans1[i]-'0')%3==r){
                    rem=false;
                    ans1.erase(i,1);
                }
            
            int start;
            if((start=ans1.find_first_not_of('0'))!=string::npos) //se ci sono cifre diverse da 0
                ans1=ans1.substr(start); //rimuovo dalla stringa gli zeri iniziali
            else
                ans1=""; 
        }
    
        //provo rimuovendo due cifre che hanno resto uguale a 3-r
        string ans2;
        if(count_3_r(s,r)>=2){ //se ci sono almeno due cifre con resto 3-r
            int rem=2;
            ans2=s;

            for(int k=0;k<2;k++) //al massimo elimino due cifre. ricomincio il ciclo perchè rimuovendo un carattere dalla stringa potrebbero crearsi dei problemi con gli indici
                for(int i=0;i<ans2.length()-1;i++){
                    if((ans2[i]-'0')%3==3-r && ans2[i]<ans2[i+1]){
                        rem--;
                        ans2.erase(i,1);
                        break;
                    }
                }
            
            while(rem) //mi rimangono rem cifre da rimuovere. ricomincio il ciclo perchè rimuovendo un carattere dalla stringa potrebbero crearsi dei problemi
                for(int i=ans2.length()-1;1;i--){
                    if((ans2[i]-'0')%3==3-r){
                        rem--;
                        ans2.erase(i,1);
                        break;
                    }
                }

            int start;
            if((start=ans2.find_first_not_of('0'))!=string::npos) //se ci sono cifre diverse da 0
                ans2=ans2.substr(start); //rimuovo dalla stringa gli zeri iniziali
            else
                ans2="";
        }

        if(ans1.length()>ans2.length()) //se le due stringhe non hanno la stessa lunghezza, la più lunga è la maggiore
            cout<<ans1<<'\n';
        else if(ans2.length()>ans1.length())
            cout<<ans2<<'\n';
        else if(ans1.empty() && ans2.empty()) //se entrambe le stringhe sono vuote il numero non può diventare dispari
            cout<<-1<<'\n';
        else
            cout<<max(ans1,ans2)<<'\n'; //se le stringhe hanno la stessa lunghezza ritorno il massimo
    }

    return 0;
}