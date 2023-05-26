#include <iostream>
#pragma GCC optimize ("O3")
using namespace std;
#define MAXN (int)1e6

int a[MAXN],b[MAXN];

int tempo_massimo(int N, int A[], int B[]){
    A[0]=(A[0]>=B[0])?A[0]:B[0];
    A[1]=(B[1]>(A[0]+A[1]))?B[1]:A[0]+A[1];

    for(int i=2;i<N;i++)
        A[i]=((A[i-2]+B[i])>(A[i-1]+A[i]))?A[i-2]+B[i]:A[i-1]+A[i];

    return A[N-1];
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    cout<<tempo_massimo(n,a,b);
    
    return 0;
}