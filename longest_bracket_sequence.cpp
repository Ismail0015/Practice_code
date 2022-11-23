#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
     int ans = 0;
        stack<char>st;
        stack<int>inx;
        inx.push(-1);
        int c = 0;

        for(int i = 0; i < s.size(); i++){
           if(s[i] == ')'){
            if(!st.empty() and st.top() == '('){
                     st.pop();
                     inx.pop();
                     ans = max(ans, i-inx.top());
                }
                else st.push(')'), inx.push(i);
            }

            else st.push('('), inx.push(i);
        }
        cout << ans;
}
