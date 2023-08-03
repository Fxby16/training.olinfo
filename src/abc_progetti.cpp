#include <iostream>
#include <unordered_map>
#pragma GCC optimize ("O3")
using namespace std;
#define ll long long
#define MOD 1000000007

unordered_map<int,int>memo;

int k;
ll solve(int n){
    if(n<0) 
        return 0;
	if(memo[n])
        return memo[n];
	ll left=n/2,right=(n+1)/2;
	ll ans=(solve(left)*solve(right))%MOD;
	for(int i=2;i<=k;i++)
		for(int j=1;j<i;j++)
			ans=(ans+(solve(left-j)*solve(right-i+j))%MOD)%MOD;
	memo[n]=ans;
    return ans;
}
int progetti(int N, int K){
    k=K;
    memo[0]=1;
    memo[1]=1;
   	return solve(N);
}

int main() {
static FILE *fr, *fw;
	fr = stdin;
	fw = stdout;
int N,K,risultato;
	// Reading input
    fscanf(fr, "%d %d", &N, &K);

	// Calling functions
	risultato = progetti(N, K);

	// Writing output
    fprintf(fw, "%d\n", risultato);
	
	fclose(fr);
	fclose(fw);
	return 0;
}
