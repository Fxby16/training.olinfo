#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize ("O3")
#define ll long long

vector<pair<int,int>>x;
vector<pair<int,int>>y;
vector<pair<int,int>>solve1;
vector<pair<int,int>>solve2;
int n,k,s=-1;
ll somm1=0,somm2=0;
ll molt1=0,molt2=0;
ll somm;
int a=1,b=1;

void findSeq(){
bool flag=false;
    for(int i=0;i<n;i++){
        if(x[i].first == y[i].first && flag && x[i].second == y[i].second && flag){ //se la sequenza Ã¨ finita aggiungo 1 perchÃ¨ s partiva da -1
            s++;
            return;
        }
        if(flag){
            ++s;
            solve1[s]=x[i];
            solve2[s]=y[i];
            somm1+=x[i].second;
            somm2+=+y[i].second;
            molt1+=x[i].first;
            molt2+=+y[i].first;
        }
        else if((x[i].first != y[i].first && !flag) || (x[i].second != y[i].second && !flag)){
            flag=true;
            ++s;
            solve1[s]=x[i];
            solve2[s]=y[i];
            somm1+=x[i].second;
            somm2+=+y[i].second;
            molt1+=x[i].first;
            molt2+=+y[i].first;
        }
    }
    if(s!=-1) //se esiste una sequenza diversa aggiungo 1 dato che s partiva da -1
        s++;
}
void solve(){
int i=0;
int count=0;
    for(i=0;i<s;i++){
        if((solve1[i].first*a/b == solve2[i].first)&&(solve1[i].second+somm == solve2[i].second)) //confronto la sequenza di x modificata con la sequenza di y
            count++;
    }
    if(count==s){ //se modificando la sequenza sono uguali
        cout<<"TRANSFORMED "<<s;
        return;
    }
    count=0;
    for(i=0;i<s;i++){
        if((solve1[s-1-i].first*a/b == solve2[i].first)&&(solve1[s-1-i].second+somm == solve2[i].second)) //confronto la sequenza invertita di x modificata con la sequenza di y
            count++;
    }
    if(count==s) //se tutta la sequenza puÃ² essere uguale
        cout<<"TRANSFORMED "<<s;
    else
        cout<<"ORIGINAL "<<s; //se la sequenza non puÃ² essere uguale
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
    cin>>n>>k;
    x.resize(n);
    y.resize(n);
    solve1.resize(n);
    solve2.resize(n);
    
    for(auto &X:x)
        cin>>X.first>>X.second;
    for(auto &Y:y)
        cin>>Y.first>>Y.second;

    findSeq(); //cerco la sequenza di note diverse
    if(s==-1){ //se non ci sono differenze sono uguali
        cout<<"SAME";
        return 0;
    }
    somm=-((somm1-somm2)/s); //valore da sommare o sottarre a x per avere y
    if(molt1==molt2*2)
        b=2; //devo dividere x per 2
    else if(molt1==molt2/2)
        a=2; //devo moltiplicare x per 2
    
    solve();

    return 0;
}