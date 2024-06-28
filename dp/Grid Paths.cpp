#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define M_PI                3.14159265358979323846
#define f                   first
#define s                   second
#define endl                '\n'
#define pb                  push_back
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T power(T base, T exp){T result = 1;while (exp) {if (exp & 1) result *= base;base *= base;exp >>= 1;}return result;}
const ll INF = 1e9+7;
 
ll n,m;
vector<vector<char>>grid;
ll dp[1001][1001];
 
ll rec(ll x,ll y){
   if(x<0||y<0||x>n||y>n){
    return 0;
   }
   //base case
   if(x==0&&y==0){
    return (grid[x][y]=='*')?0:1;
   }
 
   if(dp[x][y]!=-1){
    return dp[x][y];
   }
 
   ll ans = 0 ;
   if(grid[x][y]=='*'){
    ans =0;
   }else if(grid[x][y]!='*'){
    ans = rec(x-1,y) + rec(x,y-1);
   }
 
   return dp[x][y] = (ans%MOD+MOD)%MOD;
}
 
void solve(){
   cin>>n;
   grid.resize(n);
   for(ll i=0;i<n;i++){
    grid[i].resize(n);
    for(ll j=0;j<n;j++){
        cin>>grid[i][j];
    }
   }
   for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    cout<<rec(n-1,n-1)<<endl;
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}