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
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T power(T base, T exp){T result = 1;while (exp) {if (exp & 1) result *= base;base *= base;exp >>= 1;}return result;}
const int INF = 1e9;

int n;
int dp[1000100];
int rec(int level){
    if(level==n){
        return 1;
    }
    
    if(dp[level]!= -1){
        return dp[level];
    }   
    
    int ans=0; 
    for(int num =1;num<=6;num++){
        if(level+num<=n){
            ans = (ans+rec(level+num))%MOD;
        }
    }

    dp[level] = ans;
    return ans;
}

void solve(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
