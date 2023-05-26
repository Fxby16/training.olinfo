#include <iostream>
#pragma GCC optimize ("O3")
#define ll long long
#define MAXN 1500000
using namespace std;

int temp[MAXN];
int a[MAXN/2+1],b[MAXN/2+1];
int v[MAXN];

ll merge(int A[],int temp[],int left,int mid,int right){
int i=left,j=mid,k=left;
ll ans=0;
	while((i<=mid-1)&&(j<=right)){
		if(A[i]<=A[j]){
			temp[k++]=A[i++];
		}
		else{
			temp[k++]=A[j++];
			/* If a[i] is greater than a[j], then there are (mid – i) inversions because left and right subarrays are sorted, 
            so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]. */
			ans=ans+(mid-i);
		}
    }
    while(i<=mid-1)
        temp[k++]=A[i++];
 
    while(j<=right)
        temp[k++]=A[j++];
 
    for (i=left;i<=right;i++)
        A[i]=temp[i];

	return ans;
}
ll mergeSort(int A[],int temp[],int left,int right){
ll ans=0;
	int mid;
	if (right>left){
		mid=(right+left)/2;
		ans+=mergeSort(A,temp,left,mid); //sommo gli scambi della metà di sinistra dell'array
		ans+=mergeSort(A,temp,mid+1,right); //sommo gli scambi della metà destra dell'array
		ans+=merge(A,temp,left,mid+1,right); //sommo gli scambi unendo gli array
	}
	return ans;
}

ll paletta_sort(int N,int V[]){
int indexa=0,indexb=0;
    for(int i=0;i<N;i++){
        if(V[i]%2 != i%2) //controllo se l'array è ordinabile
            return -1;
        if(i%2==0) //creo l'array per gli indici pari
            a[indexa++]=V[i];
        else //creo l'array per gli indici dispari
            b[indexb++]=V[i];
    }
	return mergeSort(a,temp,0,indexa-1)+mergeSort(b,temp,0,indexb-1); //gli scambi totali saranno la somma tra gli scambi dell'array a e quelli dell'array b
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int N;
    cin>>N;
    for(int i=0;i<N;i++)   
        cin>>v[i];
    cout<<paletta_sort(N,v);

    return 0;
}