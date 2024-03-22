#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin>>N;

    vector<int>v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }

    int val=(v[0]+v[v.size()-1])/2;

    auto mid=lower_bound(v.begin(),v.end(),val);
    auto left=mid-1;
    auto right=mid+1;

    int max1=INT_MAX;
    if(right!=v.end()){   
        max1=max(abs(v[0]-*right),abs(v[v.size()-1])-*right);
    }
    int max2=INT_MAX;
    if(left>=v.begin()){
        max2=max(abs(v[0]-*left),abs(v[v.size()-1])-*left);
    }

    int max3=max(abs(v[0]-*mid),abs(v[v.size()-1])-*mid);

    cout<<min(max1,min(max2,max3))<<endl;

    return 0;
}