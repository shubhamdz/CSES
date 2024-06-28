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

string a,b;
ll dp[5005][5005];
//ll back[3001][3001];
ll rec(ll i,ll j,ll n,ll m){
   //basecase
   if(i>=n ||j>=m){
    return (n-i)+(m-j);
   }

   if(dp[i][j]!=-1){
    return dp[i][j];
   }

   ll ans = INF;
   if(a[i]==b[j]){
    ans = min(ans,rec(i+1,j+1,n,m));
   }else{
        if(i<n){
            ans = min(ans,rec(i+1,j,n,m)+1);//delete
        }
        if(j<m){
            ans = min(ans,rec(i,j+1,n,m)+1);//insert
        }
        ans = min(ans,rec(i+1,j+1,n,m)+1);//replace
   }
   return dp[i][j] = ans;
}
void solve(){
    cin>>a;
    cin>>b;
    ll n = a.size();
    ll m = b.size();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,n,m);
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