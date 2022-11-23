#include<bits/stdc++.h>
using namespace std;
int main(){
    string A; cin >> A;
    stack<int>st;
    int mx = 0;
    st.push(-1);
    for(int i = 0; i < A.size();i++){
       if(A[i] == '(')st.push(i);
       else {
           st.pop();
           if(st.empty())st.push(i);
           else mx = max(mx, i-st.top());
       }
    }cout << mx;
}
