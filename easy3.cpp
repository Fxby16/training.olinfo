#include <iostream>
#include <queue>
using namespace std;

int main()
{
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
ios::sync_with_stdio(false);
cin.tie(0);
int N,temp,somma1=0,somma2=0;
priority_queue<int>pari;
priority_queue<int>dispari;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        if(temp%2==0)
            pari.push(temp);
        else
            dispari.push(temp);
    }
    if(pari.size()>=2){
        somma1=pari.top();
        pari.pop();
        somma1+=pari.top();
    }
    if(dispari.size()>=2){
        somma2=dispari.top();
        dispari.pop();
        somma2+=dispari.top();
    }
    int flag=max(somma1,somma2);
    if(flag>0)
        cout<<flag;
    else 
        cout<<-1;

    return 0;
}