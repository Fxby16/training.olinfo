#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>add,rm;
int day=1;
int N;

void init(int n){
    N=n;
    add.resize(n+1); //fenwick tree per le figurine aggiunte
    rm.resize(n+1); //fenwick tree per le figurine rimosse
}
void log(vector<int>&added,vector<int>&removed){
    for(int i=day;i<=N;i+=i&-i){ //aggiungo e rimuovo le figurine
        for(auto &it:added)
            add[i].push_back(it);
        for(auto &it:removed)
            rm[i].push_back(it);
    }
    if(day==N){ //se ho finito tutte le modifiche, posso ordinare gli array per poter usare lower bound dopo
        for(auto &it:add)
            sort(it.begin(),it.end());
        for(auto &it:rm)
            sort(it.begin(),it.end());
    }
    day++; //passo al giorno successivo
}
int answer(int d,int y){
int ans=0;
    for(;d>0;d-=d&-d){
        ans+=add[d].end()-lower_bound(add[d].begin(),add[d].end(),y);
        ans-=rm[d].end()-lower_bound(rm[d].begin(),rm[d].end(),y);
    }
    return ans;
}

//grader
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int n, q;
	cin >> n >> q;
	
	init(n);
	
	vector<int> added, removed;
	for (int i = 1; i <= n; i++) {
		added.clear();
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int k;
			cin >> k;
			added.push_back(k);
		}
		removed.clear();
		int r;
		cin >> r;
		for (int j = 0; j < r; j++) {
			int k;
			cin >> k;
			removed.push_back(k);
		}
		log(added, removed);
	}
	
	for (int i = 0; i < q; i++) {
		int d, x;
		cin >> d >> x;
		cout << answer(d, x) << "\n";
	}
	
	return 0;
}
