

#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
int a[2000000];
map<int,int>mp;
void fun(){
    a[1] = 1, a[2] = 1;
    for(int i = 3; i<= 2000000; i+= 2)a[i] = 1;

    for(int i = 2; i <= 2000000; i++){
        if(a[i]){
            for(int j = i; j <= 2000000; j += i)a[i] = 0;
            mp[i]++;
        }
    }
}
int main(){
  fun();

}
