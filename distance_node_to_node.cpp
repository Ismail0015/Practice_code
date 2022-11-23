#include<bits/stdc++.h>
using namespace std;
vector<int>ar[10001];
int level[10001], lca[10001][10];

void dfs(int node, int lvl, int par){
   level[node] = lvl;
   lca[node][0] = par;
   for(auto child : ar[node]){
     if(child != par){
        dfs(child, lvl+1, node);
     }
   }
}
void init(int n){
  dfs(1, 0, -1);
  for(int i = 1; i <= 10; i++){
    for(int j = 1; j <= n; j++){
        if(lca[j][i-1] != -1){
            int par = lca[j][i-1];
            lca[j][i] = lca[par][i-1];
        }
    }
  }
}
int getLCA(int a, int b){

  if(level[b] < level[a])swap(a,b);
  int d = level[b] - level[a];
  while(d > 0){
    int i = log2(d);
    b = lca[b][i];
    d -= 1 << i;
  }
  if(a == b)return a;

  for(int i = 10; i >= 1; i--){
    if(lca[a][i] != -1 and (lca[a][i] != lca[b][i])){
        a = lca[a][i], b = lca[b][i];
    }
  }return lca[a][0];
}
int getdist(int a, int b){
    int LCA = getLCA(a, b);
    return level[a]+level[b] - 2*level[LCA];
 }
int main()
{
    int n, a , b , q;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 10; j++){
            lca[i][j] = -1;
        }
    }
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        ar[a].push_back(b), ar[b].push_back(a);
    }
    init(n);
    cin >> q;
    while(q--){
        cin >> a >> b;
        cout << getdist(a, b) << endl;
    }
}

