#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5+5;
int a[mx]; vector<int>tree[4*mx];
void built(int si, int ss, int se){
    if(ss == se){
        tree[si].push_back(a[ss]); return;
    }
    int mid = (ss+se)/2;
    built(si*2, ss, mid);
    built(si*2+1, mid+1, se);
    tree[si].resize(tree[si*2].size()+tree[si*2+1].size());
    merge(tree[si*2].begin(), tree[si*2].end(), tree[si*2+1].begin(), tree[si*2+1].end(),
          tree[si].begin());
}
int queary(int si, int ss, int se, int x, int y, int val){
    if(x > se or y < ss)return 0;
    if(x <= ss and y >= se){
        return lower_bound(tree[si].begin(), tree[si].end(), val)-tree[si].begin();
    }
    int mid = (ss+se)/2;
    return queary(si*2,ss,mid,x,y,val)+queary(si*2+1,mid+1,se, x,y,val);
}
int main(){
   int n, m; cin >> n >> m;
   for(int i = 0; i < n; i++)cin >> a[i];
   built(1, 0, n-1);
   //sort(a,a+n);
   while(m--){
    int  x, y, z; cin >> x >> y >> z;
     x--, y--, z--;
       int l = 0, r = n-1, ans;
       while(l <= r){
            int mid = (l+r)/2;
           if(queary(1, 0, n-1, x, y, a[mid]) <= z){
              ans = a[mid]; l = mid+1;
           }
           else r = mid-1;
       }cout << ans << endl;
   }

}
