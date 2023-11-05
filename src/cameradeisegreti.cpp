#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

constexpr int MOD=104857601;
using ll=long long;

namespace USACO {

using db = double;  // or double, if TL is tight
using str = string;      // yay python!

using vl = vector<ll>;
using vi = vector<int>;

#define tcT template <class T
#define tcTU tcT, class U
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
tcT > using PR = pair<T, T>;

// pairs
#define mp make_pair

#define sz(x) int((x).size())

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define each(a, x) for (auto &a : x)

// INPUT
#define tcTUU tcT, class... U
tcT > void re(T &x) { cin >> x; }
tcTUU > void re(T &t, U &...u) {
	re(t);
	re(u...);
}
tcT > void re(V<T> &x) { each(a, x) re(a); }

void setPrec() { cout << fixed << setprecision(15); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO() {
	unsyncIO();
	setPrec();
}

#define rep(i, a, b) for (int i = a; i < (b); ++i)
typedef pair<int, int> pii;

typedef complex<double> C;
void fft(vector<C> &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n);
		rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
	}
	vi rev(n);
	rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j, 0, k) {
				// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  ///
				// include-line
				auto x = (double *)&rt[j + k],
				     y = (double *)&a[i + j + k];  /// exclude-line
				C z(x[0] * y[0] - x[1] * y[1],
				    x[0] * y[1] + x[1] * y[0]);  /// exclude-line
				a[i + j + k] = a[i + j] - z;
				a[i + j] += z;
			}
}

typedef vector<ll> vl;
vl convMod(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	vl res(sz(a) + sz(b) - 1);
	int B = 32 - __builtin_clz(sz(res)), n = 1 << B, cut = int(sqrt(MOD));
	vector<C> L(n), R(n), outs(n), outl(n);
	rep(i, 0, sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
	rep(i, 0, sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
	fft(L), fft(R);
	rep(i, 0, n) {
		int j = -i & (n - 1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
	}
	fft(outl), fft(outs);
	rep(i, 0, sz(res)) {
		ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
		ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
		res[i] = ((av % MOD * cut + bv) % MOD * cut + cv) % MOD;
	}
	return res;
}
}

/*
2 step:
step 1: p(x)=∏ N−1 i=0 (x+a[i])
step 2: ans=∏ N−1 i=0 p(b[i])
*/

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    out << "[";
    for (const T& element : vec) {
        out << element;
        if (&element != &vec.back()) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

inline int deg(vector<ll>&a){
	return a.size()-1;
}

vector<ll> operator~(vector<ll>v){
    reverse(v.begin(),v.end());
    return v;
}

vector<ll> operator*(vector<ll>a,vector<ll>b){
    return USACO::convMod(a,b);
}

vector<ll> operator-(vector<ll>v){
    for(auto &i:v)
        i=(MOD-i)%MOD;
    return v;
}

vector<ll> operator+(vector<ll>a,vector<ll>b){
    vector<ll>S(max(a.size(),b.size()));

    for(int i=0;i<S.size();i++){
        if(i<a.size())
            S[i]=(S[i]+a[i])%MOD;
        if(i<b.size())
            S[i]=(S[i]+b[i])%MOD;
    }
    return S;
}

vector<ll> operator-(vector<ll>a,vector<ll>b){
    return a+(-b);
}

pair<vector<ll>,vector<ll>>split(vector<ll>v,int l){
vector<ll>a,b;
    for(int i=0;i<v.size();i++){
        if(i<l)
            a.push_back(v[i]);
        else
            b.push_back(v[i]);
    }
    return {a,b};
}

vector<ll>inv(vector<ll>v,int L){
vector<ll>a={1};
    for(int l=1;l<=L;l*=2){
        auto [h_0, h_1]=split(v,l);
        h_1.resize(l);
        auto c=split(a*h_0,l).second;
        c.resize(l);
        auto b=-(a*(h_1*a+c));
        
        b.resize(l);
        for(auto k:b)
            a.push_back(k);
    }
    return a;
}

pair<vector<ll>,vector<ll>> operator/(vector<ll>f,vector<ll>g){ //http://people.csail.mit.edu/madhu/ST12/scribe/lect06.pdf
    vector<ll>q=~f*inv(~g,deg(f)-deg(g)); //Rev(q) = Rev(g)^−1 * Rev(f)     mod(x^(deg(f)−deg(g)))
    q.resize(deg(f)-deg(g)+1);
    q=~q;
    vector<ll>r=f-g*q;
    while(r.size()>1 && r.back()==0)
        r.pop_back();

    return {q,r};
}

map<pair<int,int>,vector<ll>>M; //subproduct tree
vector<int>B;

vector<ll>subproduct_tree(int l,int r){
	if(l+1==r)
		return M[{l,r}]={(MOD-B[l])%MOD,1}; //foglie = (x-B[l]) dove B[l] è il punto in cui valutare il polinomio

	auto v1=subproduct_tree(l,(l+r)/2);
	auto v2=subproduct_tree((l+r)/2,r);
	return M[{l,r}]=v1*v2; //gli altri nodi contengono figlio_sinistro * figlio_destro
}

void fast_eval(int l,int r,vector<ll>p){
	if(l+1==r){ //se sono in una foglia il grado di p dovrebbe essere 0
		B[l]=p[0]; //assegno a B[l] p[B[l]]
		return;
	}
	auto v1=(p/M[{l,(l+r)/2}]).second; //tengo il resto della divisione con il figlio sinistro
	auto v2=(p/M[{(l+r)/2,r}]).second; //tengo il resto della divisione con il figlio destro
	fast_eval(l,(l+r)/2,v1); //ricorro sui figli
	fast_eval((l+r)/2,r,v2);
}

int solve(int N,vector<int>a,vector<int>b){
B=b; //copio b per poterlo usare dopo
vector<vector<ll>>px(N,vector<ll>(2));

	for(int i=0;i<N;i++)
		px[i]={a[i],1};

	while(px.size()>1){ //calcolo p(x) con divide and conquer
		for(int i=0;i<px.size()-1;i+=2)
			px[i/2]=px[i]*px[i+1]; //prima di raggiungere l'ultima moltiplicazione ogni polinomio avrà al massimo grado n/2
		if(px.size()%2){ //dividendo sempre per due, se avanza un polinomio lo riaggiungo alla fine dopo aver ridimensionato px
			vector<ll>temp=px.back();
			px.resize(px.size()/2);
			px.push_back(temp);
		}
		else
			px.resize(px.size()/2);	
	}

    //http://www.cecm.sfu.ca/CAG/theses/justine.pdf -- capitolo 2
	subproduct_tree(0,N);
	fast_eval(0,N,px[0]);

ll ans=1;

    //ora B contiene p[b[i]] per i che va da 0 a N-1. 
    //l'ultima cosa da fare è calcolare ans=∏ B[i] con i che va da 0 a N-1
	for(auto i:B)
		ans=(ans*i)%MOD;

	return ans;
}

//grader
int main(){
	int N;
	cin>>N;
	vector<int> R(N), B(N);
	for(int i=0;i<N;i++)
		cin>>R[i];
	for(int i=0;i<N;i++)
		cin>>B[i];
	cout<<solve(N, move(R), move(B));
}