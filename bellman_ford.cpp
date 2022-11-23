#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n, m;
   cin >> n >> m;
   vector<vector<int>>v;
   for(int i = 0; i < m; i++){
      int a, b, w;
      cin >> a >> b >> w;
      v.push_back({a, b, w});
   }
   int src; cin >> src;
   vector<int>dis(n,1000000000);
   dis[src] = 0;
   for(int i = 0; i < n-1; i++){
     for(auto x : v){
     int a = x[0], b= x[1], w = x[2];
     dis[b] = min(dis[b], w + dis[a]);
     }
   }
   for(auto x : dis)cout << x << " ";
}

