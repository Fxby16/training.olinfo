#include <iostream>
#include <vector>
using namespace std;

long long aggiorna(int N, vector<int> A, vector<int> B);

long long aggiorna(int N, vector<int> A, vector<int> B)
{
long long int count=0;
int temp;
    for(int i=N-2;i>=0;i--)
    {
        temp=((A[i+1]-A[i])/B[i]);
        count+=temp;
        A[i]+=B[i]*temp;
    }
    return count;
}