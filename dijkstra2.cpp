#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

int vis[100005], dis[100005];
vector<pair<int,int>> adj[100005];
void solve(){
    int n,m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v,w;cin >> u >> v >> w;
        adj[u].pb({v,w});
    }
    //dijkstra
   for(int i = 2; i <= n; i++) dis[i]=1000000000000000000;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,1});
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u]=1;

        for (auto e : adj[u]){
                int v = e.first, w = e.second;
            if (dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
    for(int i = 1; i <= n; i++)cout << dis[i]<< " ";
}
signed main(){
    int t=1;

    while(t--){
        solve();

    }

}

