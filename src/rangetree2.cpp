#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;

struct node{
    int zero;
    int uno;
    int due;
    int lazy;
    node(): zero(0),uno(0),due(0),lazy(0){}
    void join(node &a,node &b){
        zero=a.zero+b.zero;
        uno=a.uno+b.uno;
        due=a.due+b.due;
    }
};

vector<node>segtree;
int Size;

void rotate(int i){ //aggiorno il nodo
    while(segtree[i].lazy>0){
        swap(segtree[i].zero,segtree[i].uno);
        swap(segtree[i].zero,segtree[i].due);
        segtree[i].lazy--;
    }
}

int get_sum(int i,int l,int r,int lq,int rq){
    if(segtree[i].lazy){ //se devo fare degli aggiornamenti
        if(2*i+1<segtree.size()){ //propago ai figli
            segtree[i*2].lazy+=segtree[i].lazy;
            segtree[i*2+1].lazy+=segtree[i].lazy;
            segtree[i*2].lazy%=3;
            segtree[i*2+1].lazy%=3;
        }
        rotate(i); //aggiorno il nodo corrente
    }

    if(l>=rq || r<=lq) //out of range
        return 0;
    
    if(l>=lq && r<=rq){ //totalmente compreso nel range, ritorno il numero di multipli di 3 nel range
        return segtree[i].zero;
    }
    
    return get_sum(i*2,l,(l+r)/2,lq,rq)+get_sum(i*2+1,(l+r)/2,r,lq,rq); //parzialmente nel range, ricorro sui figli
}

void update(int i,int l,int r,int lq,int rq){
    if(segtree[i].lazy){ //se devo fare degli aggiornamenti
        if(2*i+1<segtree.size()){ //propago ai figli
            segtree[i*2].lazy+=segtree[i].lazy;
            segtree[i*2+1].lazy+=segtree[i].lazy;
            segtree[i*2].lazy%=3;
            segtree[i*2+1].lazy%=3;
        }
        rotate(i); //aggiorno il nodo corrente
    }

    if(l>=rq || r<=lq) //out of range
        return;

    if(l>=lq && r<=rq){ //totalmente compreso nel range
        segtree[i].lazy+=1; //compio una rotazione sul nodo corrente
        rotate(i);
        if(2*i+1<segtree.size()){ //propago ai figli
            segtree[i*2].lazy++;
            segtree[i*2].lazy%=3;
            segtree[i*2+1].lazy++;
            segtree[i*2+1].lazy%=3;
        }
        return;
    }
    update(i*2,l,(l+r)/2,lq,rq); //parzialmente nel range, ricorro sui figli
    update(i*2+1,(l+r)/2,r,lq,rq);
    segtree[i].join(segtree[i*2],segtree[i*2+1]); //aggiorno il nodo corrente dopo aver modificato i figli
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int n,q;
    cin>>n>>q;
    Size=1<<(int)ceil(log2(n));
    segtree.assign(2*Size,node());

    for(int i=Size;i<n+Size;i++) //inizializzo le foglie
        segtree[i].zero=1;
    for(int i=Size-1;i>0;i--) //aggiorno gli altri nodi
        segtree[i].join(segtree[i*2],segtree[i*2+1]);

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