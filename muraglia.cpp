#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

// Declaring variables
static int R;
static vector<int> risultato1;
static vector<int> risultato2;
int Size,SizeO;
vector<int>tree;
int qstart,qend;

void build(int node, int l, int r){
	if(l==r) //se sono una foglia ritorno (le avevo già inizializzate prima)
        return;
	int mid=(l+r)/2;
	build(2*node,l,mid); //ricorro sul figlio di sinistra
	build(2*node+1,mid+1,r); //ricorro sul figlio di destra
	tree[node]=max(tree[node*2],tree[node*2+1]); //aggiorno il nodo corrente dopo aver aggiornato i figli
}
void cambia(int i,int n){
    i+=Size;
    tree[i]=n; //aggiorno la posizione i nel segment tree
    i/=2; //mi sposto alla posizione del nodo padre
    while(i>0){
        tree[i]=max(tree[i*2],tree[i*2+1]); //ricalcolo il nodo corrente dopo l'update
        i/=2; //mi sposto alla posizione del nodo padre
    }
}
void getright(int node,int l,int r,int qs,int qe,int x){
    if(l>qe || r<qs) //se è fuori dal range ritorno
        return;
    if(l==r){ //se è una foglia
        if(qend!=SizeO-1) //se ho già trovato un valore maggiore mi fermo
            return;
        if(tree[node]>x){ //se il valore è maggiore lo metto nel risultato di destra
            qend=node-Size;
        }
        return;
    }
    int mid=(l+r)/2;
    if(l>=qs){
		if(tree[node*2]>x) //se il figlio di sinistra è maggiore del valore del bastione di partenza ricorro su di lui
			getright(node*2,l,mid,qs,qe,x);
		else 
            		getright(node*2+1,mid+1,r,qs,qe,x); //altrimenti ricorro sul figlio di destra
		return;
	}
	getright(node*2,l,mid,qs,qe,x); //ricorro sui figli
	getright(node*2+1,mid+1,r,qs,qe,x);
}
void getleft(int node,int l,int r,int qs,int qe,int x){
    if(l>qe || r<qs) //se è fuori dal range ritorno
        return;
    if(l==r){ //se è una foglia
        if(tree[node]>x){ //se il valore è maggiore allora lo metto nel risultato di sinistra
            qstart=node-Size;
        }
        return;
    }
    int mid=(l+r)/2;
    if(r<=qe){
        if(tree[node*2+1]>x) //se il figlio di destra è maggiore del valore del bastione di partenza ricorro sul figlio di destra
            getleft(node*2+1,mid+1,r,qs,qe,x);
        else 
            getleft(node*2,l,mid,qs,qe,x); //altrimenti ricorro sul figlio di sinistra
        return;
    }
    getleft(node*2,l,mid,qs,qe,x); //ricorro sui figli
    getleft(node*2+1,mid+1,r,qs,qe,x);
}
pair<int,int>chiedi(int pos){
qstart=0; 
qend=SizeO-1;
    getleft(1,0,Size-1,0,pos-1,tree[pos+Size]); //vedo fino a quanto posso spiare a sinistra
    getright(1,0,Size-1,pos+1,SizeO-1,tree[pos+Size]); //vedo fino a quanto posso spiare a destra
    return {qstart,qend}; //ritorno il valore di sinistra e quello di destra
}

void inizializza(int N, vector<int> H){
SizeO=N; //salvo la lunghezza del vettore
Size=1<<(int)ceil(log2(N)); //trasformo la dimensione in una potenza di 2
tree.resize(Size*2); //aggiorno la dimensione dell'albero
    for(int i=Size;i<Size+N;i++) //assegno i valori alle foglie
        tree[i]=H[i-Size];
    build(1,0,Size-1); //costruisco il resto dell'albero
}

//grader
void leggi_eventi(int M) {
    for (int i = 0; i < M; i++) {
        char tipo;
        cin >> tipo;

        if (tipo == 'Q') {
            int x;
            cin >> x;
            pair<int, int> risultato = chiedi(x);
            risultato1[R] = risultato.first;
            risultato2[R] = risultato.second;
            R++;
        } else {
            int x, h;
            cin >> x >> h;
            cambia(x, h);
        }
    }
}


int main() {
	// Reading input
	int N, M;
	cin >> N >> M;

	vector<int> H(N);
	risultato1.resize(M);
	risultato2.resize(M);

	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	
	// Calling functions
	inizializza(N, H);
	leggi_eventi(M);

	// Writing output
	for (int i = 0; i < R; i++) {
		cout << risultato1[i] << ' ' << risultato2[i] << '\n';
	}

	return 0;
}
