#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  char ch[500]; int v[500];
  cin >> t;
  getchar();
  while(t--){
    int mx = 0;
    int m = 0;
    gets(ch);
    stringstream in(ch);
    while(in >> v[m]){
       m++;
    }
            for(int i = 0; i < m; i++){
                for(int j = i+1; j < m; j++){
                    mx = max(mx, __gcd(v[i], v[j]));
                }
            }

    cout << mx << endl;
    }

}
