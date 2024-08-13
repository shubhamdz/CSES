#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define M_PI                3.14159265358979323846
#define f                   first
#define s                   second
#define endl                '\n'
#define pb                  push_back
#define MP                  make_pair
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T power(T base, T exp){T result = 1;while (exp) {if (exp & 1) result *= base;base *= base;exp >>= 1;}return result;}
const int INF = 1e9+10;
 
ll n;
 
//0 0 0 0 0 0 1 1 1 1 1 
//this cnt variable gives me the amount of integer in the table with values<=mid
ll check(ll mid){ // mid is number not index 
   ll cnt = 0; // this represent the index of mid
   for(int i =1;i<=n;i++){
    cnt+= min(mid/i,n);
   }
   return cnt>=(n*n/2)+1; 
}
 
void solve(){ 
    cin>>n;
    ll lo=1;
    ll hi=1e12;
    ll ans=1e12;
    while(lo<=hi){
        ll mid = lo + (hi-lo)/2;
        if(check(mid)){
            ans = mid;
            hi = mid -1;
        }else{
            lo = mid +1;
        }
    }
    cout<<ans<<endl; 
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //int t; cin >> t; while (t--)
        solve();
    return 0;
}