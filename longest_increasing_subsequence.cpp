
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int pre[200005], arr[200005];
int main(){
   int n, m;
   cin >> m;
   while(m--){
   cin >> n;

   int a[n+1];
   for(int i = 0; i < n; i++)cin >> a[i];
   vector<int>v;
   v.push_back(a[0]); int x = 1;
   for(int i = 1; i < n; i++){
    if(a[i] > v.front())
    {
        v.push_back(a[i]), x = i+1;
    }
    else {
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        *it = a[i];
    }
   }
   for(auto x : v)cout << x << " ";
   cout << endl;
   }

}
