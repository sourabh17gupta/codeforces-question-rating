#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll getans(vector<int>&v,ll idx,vector<ll>&dp){
   if(idx>v.size()) return 1e9;
   if(idx==v.size()) return 0;
   if(dp[idx]!=-1) return dp[idx];
    
   //delete curr idx
   int a = 1+getans(v,idx+1,dp);
   //keep the idx and go now
   int j = 1+v[idx]+idx;
   int b = getans(v,j,dp);
   return dp[idx] = min(a,b);
   
   
}
ll solve(vector<int>&v){
   //nlogn me krna hai
   int val = 0;
   for(int i = 0;i<v.size();i++){
      val = max(val,v[i]);
   }
   vector<ll>dp(v.size()+1,-1);
   return getans(v,0,dp);
}

int main(){
   int t;
   cin>>t;
   while(t--){
     int n;
     cin>>n;
     vector<int>v;
     for(int i = 0;i<n;i++){
      int a;
      cin>>a;
      v.push_back(a);
     }
     cout<<solve(v)<<"\n";
   }
}