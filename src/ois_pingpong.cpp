#include <bits/stdc++.h>
using namespace std;

void solve(int A,int B){
	if(A<33){
		cout<<-1<<' '<<-1<<'\n';
		return;
	}
	
	int remaining_points=A-33;
	vector<int>A_points;

	while(remaining_points>0 || B>30){
		int temp=min(remaining_points,10);
		remaining_points-=temp;
    		A_points.push_back(temp);
    		B-=11;
	}

	if(A_points.size()>2 || B<0 || B>30){
		cout<<-1<<' '<<-1<<'\n';
		return;
	}

	for(int i=0;i<A_points.size();i++){
		cout<<A_points[i]<<' '<<11<<'\n';
	}

	for(int i=0;i<3;i++){
		int temp=min(B,10);
		B-=temp;
		cout<<11<<' '<<temp<<'\n';
	}
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int A, B;
        cin >> A >> B;
        solve(A,B);
    }

    return 0;
}
