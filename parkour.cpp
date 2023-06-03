#include <bits/stdc++.h>
#pragma GCC optmize ("O3")
using namespace std;

int salta(int N, vector<int> S, vector<int> A, vector<int> B){
vector<int>height(N+1,INT_MAX);
priority_queue<int>tovisit;
    height[0]=S[0];
    tovisit.push(-0);
    while(!tovisit.empty()){
        int temp=-tovisit.top();
        tovisit.pop();
        height[temp]=max(height[temp],S[temp]);

        for(int i=upper_bound(height.begin()+A[temp]+temp,height.begin()+B[temp]+temp,height[temp])-height.begin();i<=B[temp]+temp;i++){
            if(height[i]>height[temp]){
                height[i]=height[temp];
                if(i<N)
                    tovisit.push(-i);
            }
            else
                break;
        }
    }

    return height[N];
}

//grader
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  // Uncomment the following lines if you want to read or write from files
  // ifstream cin("input.txt");
  // ofstream cout("output.txt");

  int N;
  cin >> N;

  vector<int> S(N), A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i] >> A[i] >> B[i];
  }

  cout << salta(N, S, A, B) << endl;

  return 0;
}
