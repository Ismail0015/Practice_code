#include<bits/stdc++.h>
#define ll  int
using namespace std;
ll vis[50000], k, val, level[50000], par[50000];
vector<ll>v[50000];
void bfs(int node){
   queue<int>q;
   q.push(1);
   vis[node] = 1;
   while(!q.empty()){
      int x = q.front();
      q.pop();
      for(auto child: v[x]){
        if(!vis[child]){
            vis[child] = 1;
            q.push(child);
            par[child] = x;
            level[child] = level[x]+1;
        }
      }
   }
}
int LCA(int a, int b){
 if(level[a] > level[b])swap(level[a], level[b]);
 int d = level[b] - level[a];
 while(d){
    b = par[b]; d--;
 }
 if(a==b)return a;
 while(par[a] != par[b]){
    a = par[a], b = par[b];
 }
 return par[a];

}
int main(){


     ll n;
     cin >> n;
     for(ll i = 1; i <= n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
     }
     bfs(1);

     int a, b, p;

     cin >> a>>b;
     cout << LCA(a, b) << endl;

}


