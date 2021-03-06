#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORi(i,a,b) for(int i=(a);i>=(b);i--)
#define FORZ(i,a) for(int i=0;i<(a);i++)
#define FORZi(i,a) for(int i=(a)-1;i>=0;i--)
#define trav(a,x) for (auto& a: x)

#define printl(a) cout << a << "\n";
#define prints(a) cout << a << " ";
#define printall(x) FORZ(i,sz(x))prints(x[i])
#define nextl cout << "\n"

#define in(a) cin >> a;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int H = INT_MIN;
int heights[100001];

int main(){
  io_setup();
  int n;
  in(n);
  FORZ(i,n){
    in(heights[i]);
    H = max(H,heights[i]);
  }
  ll MAX = LLONG_MIN;
  FORi(i,H,1){
    ll l = -1,r = -1;
    FORZ(j,n){if(heights[j]>=i){l=j;break;}}
    FORZi(j,n){if(heights[j]>=i){r=j;break;}}
    if(l==r || l==-1 || r==-1)continue;
    MAX = max(MAX,(r-l)*(ll)i);
  }
  printl(MAX);
}

/*
  `-.    .-'
     :  :
  --:--:--
   :  :
.-'    `-.  ~LaKsHiTh_
*/
