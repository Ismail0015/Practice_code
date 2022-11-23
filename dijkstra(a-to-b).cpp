#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1000000000000000000

int vis[100005], dis[505][505];
vector<pair<int,int>> adj[100005];
void solve(){
    int n,m,q; cin >> n >> m >> q;
    int M = 1000000000000;
    for(int i = 1; i <= n+1; i++)
        for(int j = 1; j <= n+1; j++)dis[i][j]=M;


    for(int i = 0; i < m; i++){
        int u,v,w; cin >> u >> v >> w;
        dis[u][u]=0, dis[v][v]=0;
        dis[u][v]=min(dis[u][v],w), dis[v][u]=min(dis[u][v],w);
    }

    for(int k = 1; k <= n+1; k++){
       for(int i = 1;i <= n+1; i++){
            for(int j = 1; j <= n+1; j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int a,b; cin >> a>> b;
        if (dis[a][b]<M)cout << (dis[a][b]);
        else cout << (-1);
    }
}
signed main(){
    int t=1;

    while(t--){
        solve();

    }

}

