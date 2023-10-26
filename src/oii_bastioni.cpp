#include <bits/stdc++.h>
using namespace std;

#define NONE 0
#define RIGHT 1
#define LEFT 2

int solve_segment(int N,string &s){
int ans=1;
int dir=NONE;

vector<char>v(N+1);
    v[N]=-1;
    for(int i=N-1;i>=0;i--){
        if(s[i]=='?')
            v[i]=v[i+1];
        else
            v[i]=s[i];
    }

    for(int i=0;i<N;i++){
        if(s[i]=='<'){
            if(dir==RIGHT){
                ans++;
                dir=NONE;
            }else
                dir=LEFT;
        }else if(s[i]=='>'){
            if(dir==LEFT){
                ans++;
                dir=NONE;
            }else
                dir=RIGHT;
        }else{
            if(dir==RIGHT)
                s[i]='<';
            else if(dir==LEFT)
                s[i]='>';
            else if(v[i]=='<')
                s[i]='>';
            else
                s[i]='<';
            i--;
        }
    }

    return ans;
}

int arrampicate(int N, string s){
string segment;
int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='=') //lo spazio non influisce in alcun modo
            continue;
        if(s[i]=='#'){ //possiamo vedere la stringa come un insieme di sottostringhe delimitate da #
            ans+=solve_segment(segment.size(),segment);
            segment.clear();
        }else 
            segment.push_back(s[i]);
    }
    ans+=solve_segment(segment.size(),segment);
    return ans;
}
