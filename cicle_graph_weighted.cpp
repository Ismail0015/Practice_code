#include<bits/stdc++.h>
#define int long long int
using namespace std;
class triple{
   public:
       int first, second, third;
};
int n, m;
vector<triple>edge;
vector<int>dis, ans;
void belman(){

    int x = -1;
    for(int i = 1; i <= n; i++){
            x= -1;
        for(auto e:edge){
            int u = e.first, v = e.second, w = e.third;
            if(dis[u]+w < dis[v]){
                dis[v] = dis[u]+w;
                ans[v] = u;
                x = v;
            }
        }
    }
    if(x == -1)cout << "NO" <<endl;
    else {

        for(int i = 1; i <= n; i++){
            x = ans[x];
        }
        vector<int>cicle;
        for(int v = x;; v = ans[v]){
            cicle.push_back(v);
            if(v == x and cicle.size()>1)break;
        }
        reverse(cicle.begin(), cicle.end());
       // int y = count(cicle.begin(),cicle.end(), 0);


         cout << "YES" << endl;
        for(auto x:cicle)cout << x << " ";
        cout << endl;
    }
}
int32_t main()
{
    cin >> n >> m;
    dis.resize(n+1);
    ans.resize(n+1);
    edge.resize(m);
    for(int i = 0; i < m; i++){
        struct triple x;
        cin >> x.first >> x.second >> x.third;
        edge[i] = x;
    }
    for(int i = 1; i <= n; i++)ans[i] = -1;

    belman();
}







