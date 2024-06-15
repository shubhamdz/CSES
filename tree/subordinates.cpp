#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long int
#define int long long
#define pb push_back
#define F first
#define S second 
const int INF = 100;

int n;
vector<vector<int>> g;
vector<int> vis;
vector<int>sub;

void dfs(int node) {
    vis[node] = 1;
    sub[node]=0;
    for (auto v : g[node]) {
        if(!vis[v]){
            dfs(v);
            sub[node] += 1 + sub[v];
        }
    }
}

void solve() {
   cin >> n;
   g.resize(n + 1);
   vis.resize(n + 1, 0);
   sub.resize(n + 1, 0);
   for (int i = 2; i <= n; i++) {
       int x;
       cin >> x;
       g[x].push_back(i);
   }
   dfs(1);
   for(int i=1;i<=n;i++){
    cout<<sub[i]<<" ";
   }
   cout<<endl;

   
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
