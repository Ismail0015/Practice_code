#include<bits/stdc++.h>
using namespace std;
vector<int>v[10005];
int vis[10005], subtree_size[10005];
int dfs(int node){
    vis[node] = 1;
    int d = 1;
    for(auto x : v[node]){
        if(!vis[x]){
            d++; dfs(x);
        }
    }
    subtree_size[node] = d;
    return d;
}
int main()
{
    int n,k;
    cin >> n>>k;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    int cnt = 0;
    for(int i = 1; i <= n; i++)cout << subtree_size[i] << " ";
}

