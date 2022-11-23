#include<bits/stdc++.h>
using namespace std;
vector<int>v[100005];
int vis[100005];
bool dfs(int node, int par){
   vis[node] = 1;
   for(auto x : v[node]){
    if(!vis[x]){
        if(dfs(x, node) == true)return true;
    }
    else {
        if(x != par)return true;
    }
   }
   return false;
}
int main(){
   int n, m;
   cin >> n >> m;
   for(int i = 0; i <m; i++){
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
   }
   cout << "It has cycle ? -->> " << dfs(1, -1);

}
