#include <bits/stdc++.h>
#pragma GCC optmize ("Ofast")
using namespace std;
#define ll long long
#define SET LONG_LONG_MIN
#define MAXX LONG_LONG_MAX

struct node{
    ll sum;
    ll lazyadd;
    ll lazyset;
    ll minn;
    node():sum(0),minn(MAXX),lazyadd(0),lazyset(SET) {};
    void join(node &a,node &b){
        sum=a.sum+b.sum;
        minn=min(a.minn,b.minn);
    }
};

vector<node>segtree;
int Size;

void init(vector<ll>v){
    Size=1<<(int)ceil(log2(v.size()));
    segtree.assign(2*Size,node());
    for(int i=0;i<v.size();i++){ //inizializzo le foglie
        segtree[i+Size].sum=v[i];
        segtree[i+Size].minn=v[i];
    }
    for(int i=Size-1;i>0;i--) //inizializzo gli altri nodi
        segtree[i].join(segtree[i*2],segtree[i*2+1]);
}

void propagate(int i,int l,int r){
    if(segtree[i].lazyadd==0 && segtree[i].lazyset==SET) //se non ci sono aggiornamenti in sospeso ritorno
        return;

    if(segtree[i].lazyadd!=0){ //devo sommare
        segtree[i].sum+=(r-l)*segtree[i].lazyadd;
        segtree[i].minn+=segtree[i].lazyadd;
        if(i*2+1<segtree.size()){ //se il nodo non è una foglia aggiorno i figli
            if(segtree[i*2].lazyset!=SET){ //controllo se sui figli è impostato un set, in quel caso aggiungo direttamente al set
                segtree[i*2].lazyset+=segtree[i].lazyadd;
                segtree[i*2].lazyadd=0;
            }
            else
                segtree[i*2].lazyadd+=segtree[i].lazyadd; //altrimenti aggiungo a lazyadd

            if(segtree[i*2+1].lazyset!=SET){ //idem per il figlio di destra
                segtree[i*2+1].lazyset+=segtree[i].lazyadd;
                segtree[i*2+1].lazyadd=0;
            }
            else
                segtree[i*2+1].lazyadd+=segtree[i].lazyadd;
        }
        segtree[i].lazyadd=0; //azzero il lazyadd del nodo corrente perchè è già stato aggiornato e la modifica è stata propagata ai figli
        return;
    }
    if(segtree[i].lazyset!=SET){ //devo settare i nodi
        segtree[i].sum=(r-l)*segtree[i].lazyset;
        segtree[i].minn=segtree[i].lazyset;
        if(i*2+1<segtree.size()){ //se il nodo non è una foglia propago l'update ai figli e azzero lazyadd dato che le modifiche precedenti diventano nulle
            segtree[i*2].lazyset=segtree[i].lazyset;
            segtree[i*2].lazyadd=0;
            segtree[i*2+1].lazyset=segtree[i].lazyset;
            segtree[i*2+1].lazyadd=0;
        }
        segtree[i].lazyset=SET; //ripristino il lazyset del nodo corrente dato che è già stato aggiornato e dato che l'update è già stato propagato ai figli
    }
}

ll get_sum(int i,int l,int r,int lq,int rq){
    propagate(i,l,r); //controllo se ci sono modifiche in sospeso e in caso le faccio

    if(l>=rq || r<=lq) //out of range
        return 0;
    if(l>=lq && r<=rq) //totalmente nel range, il valore del nodo è parte della soluzione
        return segtree[i].sum;

    return get_sum(i*2,l,(l+r)/2,lq,rq)+get_sum(i*2+1,(l+r)/2,r,lq,rq); //parzialmente nel range, ricorro nei figli
}

ll get_sum(int l,int r){
    return get_sum(1,0,Size,l,r);
}

ll get_min(int i,int l,int r,int lq,int rq){
    propagate(i,l,r); //controllo se ci sono modifiche in sospeso e in caso le faccio

    if(l>=rq || r<=lq) //out of range
        return MAXX;
    
    if(l>=lq && r<=rq) //totalmente nel range, il valore del nodo è parte della soluzione
        return segtree[i].minn;

    return min(get_min(i*2,l,(l+r)/2,lq,rq),get_min(i*2+1,(l+r)/2,r,lq,rq)); //parzialmente nel range, ricorro nei figli
}

ll get_min(int l,int r){
    return get_min(1,0,Size,l,r);
}

int lower_bound(int i,int l,int r,int lq,int rq,ll x){
    propagate(i,l,r); //controllo se ci sono modifiche in sospeso e in caso le faccio

    if(l>=rq || r<=lq) //out of range
        return -1;

    if(segtree[i].minn<=x){ //se il valore del nodo è <= a quello richiesto proseguo
        if(!(i*2+1<segtree.size())) //se sono una foglia ritorno l'indice più a sinistra
            return l;

        int temp=lower_bound(i*2,l,(l+r)/2,lq,rq,x); //non ho ancora trovato una soluzione, ricorro sul figlio di sinistra
        if(temp!=-1) //ho trovato una soluzione ricorrendo sul figlio di sinistra, ritorno l'indice trovato
            return temp;

        return lower_bound(i*2+1,(l+r)/2,r,lq,rq,x); //se ricorrendo sul figlio di sinistra non ho trovato una soluzione, ricorro sul figlio di destra
    }
    return -1; //non ho trovato una soluzione
}

int lower_bound(int l,int r,ll x){
    return lower_bound(1,0,Size,l,r,x);
}

void add(int i,int l,int r,int lq,int rq,ll x){
    propagate(i,l,r); //controllo se ci sono modifiche in sospeso e in caso le faccio

    if(l>=rq || r<=lq) //out of range
        return;

    if(l>=lq && r<=rq){ //totalmente nel range
        segtree[i].sum+=(r-l)*x;
        segtree[i].minn+=x;
        if(i*2+1<segtree.size()){ //se il nodo non è una foglia aggiorno i figli
            if(segtree[i*2].lazyset!=SET) //controllo se sui figli è impostato un set, in que,ìl caso aggiungo direttamente al set
                segtree[i*2].lazyset+=x;
            else
                segtree[i*2].lazyadd+=x;

            if(segtree[i*2+1].lazyset!=SET)
                segtree[i*2+1].lazyset+=x;
            else
                segtree[i*2+1].lazyadd+=x;
        }
        return;
    }

    add(i*2,l,(l+r)/2,lq,rq,x); //parzialmente nel range, ricorro sui figli
    add(i*2+1,(l+r)/2,r,lq,rq,x);
    segtree[i].join(segtree[i*2],segtree[i*2+1]); //aggiorno il nodo corrente dopo aver aggiornato i figli
}

void add(int l,int r,ll x){
    add(1,0,Size,l,r,x);
}

void set_range(int i,int l,int r,int lq,int rq,ll x){
    propagate(i,l,r); //controllo se ci sono modifiche in sospeso e in caso le faccio

    if(l>=rq || r<=lq) //out of range
        return;

    if(l>=lq && r<=rq){ //totalmente nel range
        segtree[i].minn=x;
        segtree[i].sum=(r-l)*x;

        if(i*2+1<=segtree.size()){ //se il nodo non è una foglia aggiorno i figli
            segtree[i*2].lazyset=x;
            segtree[i*2].lazyadd=0;
            segtree[i*2+1].lazyset=x;
            segtree[i*2+1].lazyadd=0;
        }
        return;
    }
    set_range(i*2,l,(l+r)/2,lq,rq,x); //parzialmente nel range, ricorro sui figli
    set_range(i*2+1,(l+r)/2,r,lq,rq,x);
    segtree[i].join(segtree[i*2],segtree[i*2+1]); //aggiorno il nodo corrente dopo aver aggiornato i figli
}

void set_range(int l,int r,ll x){
    set_range(1,0,Size,l,r,x);
}

//grader
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

    int n, q;
	cin >> n >> q;
	
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	init(a);
	
	for (int i = 0; i < q; i++) {
		int op, l, r;
		long long x;
		cin >> op;
		cin >> l >> r;
		if (op == 2 or op == 3 or op == 5)
			cin >> x;
		if (op == 1) cout << get_sum(l, r) << "\n";
		if (op == 2) add(l, r, x);
		if (op == 3) set_range(l, r, x);
		if (op == 4) cout << get_min(l, r) << "\n";
		if (op == 5) cout << lower_bound(l, r, x) << "\n";
	}

    return 0;
}