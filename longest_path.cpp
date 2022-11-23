#include<bits/stdc++.h>
using namespace std;
vector<int>v[10005];
int vis[10005], mx, mx_node;
void dfs(int node, int d){
    vis[node] = 1;
    if(d > mx)mx = d, mx_node = node;

    for(auto x : v[node]){
        if(!vis[x]){
            dfs(x, d + 1);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    mx = -1;
    dfs(1, 0);
    for(int i = 1; i <= n; i++)vis[i] = 0;
    mx = -1;
    dfs(mx_node, 0);
    cout << mx;
}
