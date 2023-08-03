#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define INF -1e9

struct node{
    int best;
    int suffix;
    int prefix;
    int sub;
    node(): best(0),suffix(INF),prefix(INF),sub(INF){}
    void join(node&a,node&b){
        prefix=max(a.prefix,a.best+b.prefix);
        suffix=max(b.suffix,b.best+a.suffix);
        best=a.best+b.best;
        sub=max({a.sub,b.sub,a.suffix+b.prefix});
    }
};

vector<node>segtree;
int Size;

void update(int i,int x){
    segtree[i].best=x;
    segtree[i].suffix=x;
    segtree[i].prefix=x;
    segtree[i].sub=x;
    i/=2;
    while(i>0){
        segtree[i].join(segtree[i*2],segtree[i*2+1]);
        i/=2;
    }
}

node get_sum(int i,int l,int r,int lq,int rq){
    if(r<=lq || l>=rq)
        return node();

    if(l>=lq && r<=rq)
        return segtree[i];

    node ans;
    node left=get_sum(i*2,l,(l+r)/2,lq,rq);
    node right=get_sum(i*2+1,(l+r)/2,r,lq,rq);
    ans.join(left,right);
    return ans;
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int n,q;
    cin>>n;
    Size=1<<(int)ceil(log2(n));
    segtree.resize(2*Size);

    for(int i=Size;i<n+Size;i++){
        cin>>segtree[i].best;
        segtree[i].suffix=segtree[i].best;
        segtree[i].prefix=segtree[i].best;
        segtree[i].sub=segtree[i].best;
    }
    for(int i=Size-1;i>0;i--)
        segtree[i].join(segtree[i*2],segtree[i*2+1]);
    cin>>q;
    while(q--){
        int op,a,b;
        cin>>op>>a>>b;
        --a;
        if(op==0)
            update(a+Size,b);
        else
            cout<<get_sum(1,0,Size,a,b).sub<<'\n';
    }

    return 0;
}