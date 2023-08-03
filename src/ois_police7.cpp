#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    ll maxx;
    ll sum;
    node():sum(0),maxx(0){}
};

vector<node>segtree;
int Size;

/*void printSegmentTree(const vector<node>& tree, int node, int level, const string& prefix = ""){
    if (node>=tree.size())
        return;
    printSegmentTree(tree,node*2+1,level+1,prefix+"    ");
    cout<<prefix;
    cout<<tree[node].maxx<<","<<tree[node].sum<<'\n';
    printSegmentTree(tree,node*2,level+1,prefix+"    ");
}*/

ll calc(int i,ll x){
    if(segtree[i].maxx<=x)
        return 0;
    if(i>=Size)
        return segtree[i].sum;
    ll temp=calc(i*2+1,x);
    if(temp!=0)
        return segtree[i].sum-segtree[i*2+1].sum+temp;
    return calc(i*2,x);
}

void build(int i){
    segtree[i].maxx=max(segtree[i*2].maxx,segtree[i*2+1].maxx);
    segtree[i].sum=calc(2*i,segtree[2*i+1].maxx)+segtree[i*2+1].sum;
}

void update(int i,ll x){
    i+=Size;
    segtree[i].maxx=x;
    segtree[i].sum=x;
    while(i/=2)
        build(i);
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

int n,q;
    cin>>n>>q;
    Size=1<<(int)ceil(log2(n));
    segtree.resize(2*Size);

    for(int i=0;i<n;i++){
        cin>>segtree[i+Size].maxx;
        segtree[i+Size].sum=segtree[i+Size].maxx;
    }

    for(int i=Size-1;i>0;i--)
        build(i);
    //printSegmentTree(segtree, 1, 0);
    //cout<<"------------------------------------------------------------------\n";
    while(q--){
        int i;
        ll x;
        cin>>i>>x;

        update(i,x);
        //printSegmentTree(segtree, 1, 0);
        //cout<<segtree[1].sum<<"---------------------------------------------------------------\n";
        cout<<segtree[1].sum<<'\n';
    }
    
    return 0;
}