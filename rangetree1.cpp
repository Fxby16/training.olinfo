#include <bits/stdc++.h>
#pragma GCC optmize ("O3")
using namespace std;

struct node{
    int val;
    bool lazy;
    node(): val(0),lazy(false){}
    void join(node &a,node &b){
        val=a.val+b.val;
    }
};

vector<node>segtree;
int Size;

void propagate(int i,int l,int r){
    if(segtree[i].lazy){
        segtree[i].val=r-l-segtree[i].val;
        if(i*2+1<segtree.size()){
            segtree[i*2+1].lazy=!segtree[i*2+1].lazy;
            segtree[i*2].lazy=!segtree[i*2].lazy;
        }
        segtree[i].lazy=false;
    }
}

int get_sum(int i,int l,int r,int lq,int rq){
    propagate(i,l,r);

    if(l>=rq || r<=lq)
        return 0;
    
    if(l>=lq && r<=rq)
        return segtree[i].val;
    
    return get_sum(i*2,l,(l+r)/2,lq,rq)+get_sum(i*2+1,(l+r)/2,r,lq,rq);
}

void update(int i,int l,int r,int lq,int rq){
    propagate(i,l,r);

    if(l>=rq || r<=lq)
        return;

    if(l>=lq && r<=rq){
        segtree[i].val=r-l-segtree[i].val;
        if(i*2+1<segtree.size()){
            segtree[i*2+1].lazy=!segtree[i*2+1].lazy;
            segtree[i*2].lazy=!segtree[i*2].lazy;
        }
        return;
    }
    update(i*2,l,(l+r)/2,lq,rq);
    update(i*2+1,(l+r)/2,r,lq,rq);
    segtree[i].join(segtree[i*2],segtree[i*2+1]);
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int n,q;
    cin>>n>>q;
    Size=1<<(int)ceil(log2(n));
    segtree.assign(2*Size,node());
    while(q--){
        int op,a,b;
        cin>>op>>a>>b;
        if(op==0)
            update(1,0,Size,a,b+1);
        else
            cout<<get_sum(1,0,Size,a,b+1)<<'\n';
    }

    return 0;
}