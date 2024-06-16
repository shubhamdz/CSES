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
 
int n, x;
int v[101];
vector<int> dp;
 
int rec(int sum) {
    if (sum == 0) {
        return 0;
    }
    if (sum < 0) {
        return INF;
    }
    if (dp[sum] != -1) {
        return dp[sum];
    }
    
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (sum >= v[i]) {
            ans = min(ans, 1 + rec(sum - v[i]));
        }
    }
 
    dp[sum] = ans;
    return ans;
}
 
void solve() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dp.assign(x + 1, -1);
    int result = rec(x);
    if (result >= INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}