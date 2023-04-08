#include <bits/stdc++.h>
using namespace std;

int scarta(int M, vector<bool> L, vector<bool> D, vector<bool> N);

int main()
{
// Uncomment the following lines if you want to read or write from files
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  int M;
  cin >> M;

  vector<bool> L(M, false), D(M, false), N(M, false);
  for (int i = 0; i < M; i++) {
    int l, d, n;
    cin >> l >> d >> n;
    if (l) L[i] = true;
    if (d) D[i] = true;
    if (n) N[i] = true;
  }

  cout << scarta(M, L, D, N);

    return 0;
}
int scarta(int M, vector<bool> L, vector<bool> D, vector<bool> N)
{
int i;
int count=0;
    for(i=0;i<M;i++)
    {
        if((L[i] && D[i] && N[i])== 1)
            count++;
        else if((L[i] && D[i])==1 || (D[i] && N[i])==1 || (L[i] && N[i]) == 1)
                count++;
        else if((L[i] || D[i] || N[i]) == 0)
            count++;
    }
    return count;
}