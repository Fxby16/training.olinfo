#include <set>
#include <iostream>
using namespace std;
#define ll long long

set<ll>S;

void inizia(){};
void apri(ll p){
    S.insert(p);
}
void chiudi(ll p){
    S.erase(p);
}
ll chiedi(ll p){
auto it=S.lower_bound(p);
    if(S.size()==0)
        return -1;
    if(it==S.begin())
        return *it;
    if(it==S.end())
        return *S.rbegin();
    if((*it)-p<=p-(*prev(it)))
        return *it;
    else
        return *prev(it);
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int Q;
    cin >> Q;

    inizia();

    for (int i = 0; i < Q; i++){
        long long p;
        char t;
        cin >> t >> p;
        if (t == 'a') apri(p);
        else if (t == 'c') chiudi(p);
        else cout << chiedi(p) << endl;
    }

    return 0;
}