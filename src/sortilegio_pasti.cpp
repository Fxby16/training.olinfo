#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dividi(int N, vector<int> V)
{
    int sum = 0;
    for(int n : V){
        sum += n;
    }

    vector<vector<bool>> dp(N+1, vector<bool>(sum + 1, false));

    dp[0][0] = true;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < sum; j++){
            if(dp[i][j]){
                dp[i + 1][j + V[i]] = true;
                dp[i + 1][j] = true;
            }
        }
    }

    int best = 0;
    for(int i = 0; i <= sum / 2; i++){
        if(dp[N][i]){
            cout << i << ' ';
            best = i;
        }
    }
    cout << '\n';

    return sum - best * 2;
}

int main()
{
    
    cout << dividi(5, {1,2,3,4,5}) << '\n';
}
