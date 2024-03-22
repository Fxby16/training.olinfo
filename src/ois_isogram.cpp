#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,ans=0;

    cin>>N;
    cin.ignore();

    vector<int>characters('z'-'a'+1);

    for(int i=0;i<N;i++){
        characters.assign(characters.size(),0);

        string s;
        getline(cin,s);

        bool correct=true;

        for(auto c:s){
            c=tolower(c);
            if(c>='a' && c<='z'){
                c-='a';
                characters[c]++;
                if(characters[c]>2){
                    correct=false;
                    break;
                }
            }
        }

        ans+=correct;
    }

    cout<<ans<<'\n';

    return 0;
}