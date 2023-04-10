#include <bits/stdc++.h>
using namespace std;

void sposta(int,vector<int>&,vector<int>&,set<int>&);

int ans=0;
int main() {
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int N,Q,n;
char ch;
cin>>N>>Q;
vector<int>K(N,-1);
vector<int>K2(N,-1);
set<int>postiliberi;
    for(int i=0;i<N;i++)
        postiliberi.insert(i);
    for(int i=0;i<Q;i++)
    {
        cin>>ch>>n;
        if(ch=='b')
        {
            auto it=postiliberi.begin();
                if((*it)<=n){
                    K[*it]=n;
                    K2[n]=*it;
                    postiliberi.erase(it);
                }
                else
                {
                    ++ans;
                    int temp=K[n];
                    K[n]=n;
                    K2[n]=n;
                    sposta(temp,K,K2,postiliberi);
                }
        }
        else if(ch=='l')
        {
            postiliberi.insert(K2[n]);
        }
    }
    cout<<ans;
    return 0;
}
void sposta(int n,vector<int>&K,vector<int>&K2,set<int>&postiliberi)
{
while(1){    
    if(postiliberi.find(n)!=postiliberi.end()){
        K[n]=n;
        K2[n]=n;
        postiliberi.erase(n);
        break;
    }
    else
    {
        ++ans;
        int temp=K[n];
        K[n]=n;
        K2[n]=n;
        n=temp;
    }
}
}