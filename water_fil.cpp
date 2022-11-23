#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> v[i];
        int mx[n], mi[n];
        mx[0] = v[0], mi[n-1] = v[n-1];
        for(int i = 1; i < n; i++)mx[i] = max(mx[i-1], v[i]);
        for(int i = n-2; i >= 0; i--)mi[i] = max(mi[i+1],v[i]);

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += min(mx[i], mi[i])-v[i];
        }
        cout << ans;
}
