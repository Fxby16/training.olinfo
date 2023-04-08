#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int organizza(int N, int X, int Y, vector<int> A, vector<int> B);

int main() {
  // Uncomment the following lines if you want to read or write from files
  // ifstream cin("input.txt");
  // ofstream cout("output.txt");

  int N, X, Y;
  cin >> N >> X >> Y;

  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  cout << organizza(N, X, Y, A, B) << endl;

  return 0;
}
int organizza(int N, int X, int Y, vector<int> A, vector<int> B){
map<int,int>festa;
int ans=0;
    for(int i=0;i<N;i++)
    {
        if(B[i]<X || A[i]>Y) //se l'amico è già tornato non ci serve modificare nulla, idem se va via dopo la festa
            continue;
        if(A[i]<X)  //se va via prima del range della festa lo consideriamo come se fosse il primo giorno
            festa[X]--;
        else
            festa[A[i]]--;  //altrimenti togliamo l'amico dal giorno in cui parte
        if(B[i]<Y)
            festa[B[i]+1]++;    //se torna durante il range, lo aggiungiamo al giorno dopo
    }
    festa[X]+=0; //creiamo festa[X] e festa[Y] se non esistono in modo da non avere problemi
	festa[Y]+=0;
    for(auto i=festa.begin();i!=festa.end();i++){
        N+=i->second; //modifichiamo in base a chi va via e a chi torna
        ans=max(ans,N); //troviamo il massimo numero di amici possibile
    }
    return ans;
}