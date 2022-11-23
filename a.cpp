#include<bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i==0 or j==0)dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string st = "";
    int i = n, j = m;
    while(i > 0 and j > 0){
        if(s[i-1] == t[j-1]){
            st += s[i-1]; i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])i--;
        else j--;
    }reverse(st.begin(), st.end());
    cout << st;
}
