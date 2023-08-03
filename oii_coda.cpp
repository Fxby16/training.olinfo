#include <bits/stdc++.h>
using namespace std;

vector<int> cucina(int N, int K, int X, vector<int> H){
vector<int>dp(X);
vector<int>v(X,0);
    for(auto h:H)
        v[h]++;
    dp[X-1]=min(1,v[X-1]);

int spazio_coda=K-dp[X-1];
    for(int i=X-2;i>=0;i--){
        spazio_coda=min(spazio_coda+1,K); //al secondo dopo una persona sarà già andata via
        int temp=min(v[i],spazio_coda); //le persone si fermano soltanto se in coda ci sono meno di K persone
        spazio_coda-=temp; //se si fermano delle persone la coda si allunga
        dp[i]=min(dp[i+1]+temp,X-i); //dato che viene servita una persona al secondo, se il numero di persone è maggiore, verranno servite al massimo X-i persone
    }
    return dp;
}

//grader
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int N, K, X;
    cin >> N >> K >> X;

    vector<int> H(N);
    for (int& h : H) {
        cin >> h;
    }

    vector<int> res = cucina(N, K, X, move(H));
    for (int r : res) {
        cout << r << ' ';
    }
    cout << endl;

    return 0;
}