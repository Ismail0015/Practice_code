#include<bits/stdc++.h>
using namespace std;
int main(){

    int n, m; cin >> n >> m;
    int a[n+1]; for(int i = 0; i < n; i++)cin >> a[i], a[i] %= m;

     if(n >= m)cout << "YES";
     else {
    set<int>s; s.insert(a[0]);
    for(int i = 1; i < n; i++){
            set<int>temp;
        for(auto x:s){
            temp.insert((x+a[i])%m);
        }
        for(auto x:temp){
            s.insert(x);
        }
        s.insert(a[i]);
    }
    if(!*s.begin())cout << "YES";
    else cout << "NO";
     }
}

