#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

int N,M;
    cin>>N>>M;

    int DIM=(int)sqrt(N)+1;
    vector<deque<int>>v(DIM);

    for(int i=0;i<N;i++)
        v[i/DIM].emplace_back(i);

    while(M--){
        char choice;
        int a,b;
        cin>>choice;
        if(choice=='c'){
            cin>>a;
            cout<<v[a/DIM][a%DIM]<<' ';
        }else{
            cin>>a>>b;

            int primadeq=a/DIM;
            int secondadeq=b/DIM;
            if(primadeq<secondadeq){
                int tmp=v[primadeq][a%DIM];
                v[primadeq].erase(v[primadeq].begin()+a%DIM);

                while(primadeq<secondadeq){
                    v[primadeq].emplace_back(v[primadeq+1].front());
                    v[primadeq+1].pop_front();
                    primadeq++;
                }
                v[secondadeq].insert(v[secondadeq].begin()+b%DIM,tmp);
            }else{
                int tmp=v[primadeq][a%DIM];
                v[primadeq].erase(v[primadeq].begin()+a%DIM);

                int k=secondadeq;
                while(k<primadeq){
                    v[k+1].emplace_front(v[k].back());
                    v[k].pop_back();
                    k++;
                }
                v[secondadeq].insert(v[secondadeq].begin()+b%DIM,tmp);
            }
        }

    }

    return 0;
}