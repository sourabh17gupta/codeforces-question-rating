#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll solve(vector<int>&v){
    sort(v.begin(),v.end(),[&](const int&a,const int&b){
        return a>b;
    });
 
    //nlogn is suitable for that question
    ll ans = 0;
    ll totalMoster = 0;
    for(int i = 0;i<v.size();i++){
        totalMoster+=v[i];
    }
    ll rem = totalMoster/2;
    ans = totalMoster-rem;
    for(auto x:v){
         if(rem<=0) break;
         ans++;
         rem = rem-x;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i = 0;i<n;i++){
            int a;
            cin>>a;
            v[i] = a;
        }
        cout<<solve(v)<<"\n";
    }
}