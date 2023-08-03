#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int N,M,T,ans=0;
    cin>>T>>N;
vector<pii>a(N);
    for(auto &[x,y]:a)
        cin>>x>>y;
    cin>>M;
vector<pii>b(M);
    for(auto &[x,y]:b)
        cin>>x>>y;

    int i=0,j=0;
    while(i<N && j<M){
        if(a[i].first>b[j].first){                  //1° caso   b= -----------------------------
            if(a[i].first>b[j].second)              //          a=            ------------
                ++j;                                //          a=            ------------------
            else if(a[i].second<b[j].second){       //          a=            ------------------------
                ans+=a[i].second-a[i].first+1;      //          a=                                    -------------
                b[j].first=a[i].second+1;           //se l'inizio di a è maggiore dell'inizio di b ci sono 4 combinazioni
                ++i;
            }
            else if(a[i].second==b[j].second){ 
                ans+=a[i].second-a[i].first+1; 
                ++j;                          
                ++i;                           
            }                                 
            else{
                ans+=b[j].second-a[i].first+1;
                a[i].first=b[j].second+1;
                ++j;
            }
        }
        else if(a[i].first==b[j].first){         //2° caso    b= -------------------------
            if(a[i].second<b[j].second){         //           a= ----------
                ans+=a[i].second-a[i].first+1;   //           a= -------------------------
                b[j].first=a[i].second+1;        //           a= -----------------------------
                ++i;                             //se l'inizio di a e l'inizio di b combaciano, ci sono 3 combinazioni
            }
            else if(a[i].second==b[j].second){
                ans+=a[i].second-a[i].first+1;
                ++j;
                ++i;
            }
            else{
                ans+=b[j].second-a[i].first+1;
                a[i].first=b[j].second+1;
                ++j;
            }
        }
        else if(a[i].first<b[j].first){                             //3° caso   a= ---------------------------------
            if(a[i].second<b[j].first || a[i].first+T<b[j].first)   //          a= --------------------------
                ++i;                                                //          a= -------------------
            else if(a[i].second<b[j].second){                       //          b=          -----------------
                ans+=a[i].second-b[j].first+1;                      //se l'inizio di b è maggiore dell'inizio di a, ci sono 3 combinazioni
                b[j].first=a[i].second+1;
                ++i;
            }
            else if(a[i].second==b[j].second){
                ans+=a[i].second-b[j].first+1;
                ++j;
                ++i;
            }
            else{
                ans+=b[j].second-b[j].first+1;
                a[i].first=b[j].second+1;
                ++j;
            }
        }
    }
    cout<<ans;

    return 0;
}