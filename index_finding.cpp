#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
int main(){
    int n; cin >> n;
    vector<int>v(n); for(int i = 0; i < n; i++)cin >> v[i];
    ordered_set st;
         n = v.size();
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            ans[i] = st.order_of_key(v[i]);
            //cout << ans[i] << " ";
            st.insert(v[i]);
        }
        for(auto x:ans)cout << x << " ";
}

