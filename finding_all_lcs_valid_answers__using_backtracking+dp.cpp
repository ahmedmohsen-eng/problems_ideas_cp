// Problem: D - LCS

// Contest: Virtual Judge - #Sheet 3 : Dynamic Programming (Recursive)
// URL: https://vjudge.net/contest/694272#problem/D

#include <bits/stdc++.h>
using namespace std;

bool multicases_=false;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>using ordered_multiset = tree<pair<T,int>, null_type, less<pair<T,int>>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;

#define int long long
#define ull unsigned long long

void pre_compute(){

}

string s,t;

int n,m;

int dp[3000][3000];

int go(int i,int j){

    if(i>=n||j>=m)return 0;

    if(~dp[i][j])return dp[i][j];

    if(s[i]==t[j])
        return dp[i][j]=1+go(i+1,j+1);

    int ch1=go(i,j+1);
    int ch2=go(i+1,j);

    int ans=max(ch1,ch2);

    return dp[i][j]=ans;
}

//edit by ai : instead of global string make a set of string,,,,,,if you want occurences you can use a map instead and make mp[cur]++;
set<string> answers;

void build(int i,int j,string cur){

    if(i>=n||j>=m){
        answers.insert(cur);
        return;
    }

    if(s[i]==t[j]){
        cur.push_back(s[i]);
        build(i+1,j+1,cur);
        return;
    }

    int ch1=go(i+1,j);
    int ch2=go(i,j+1);

    if(ch2>ch1){
        return build(i,j+1,cur);
    }
    else if(ch1>ch2){
        return build(i+1,j,cur);
    }
    else{/////////to explore all valid answers using backtracking
        build(i,j+1,cur);
        build(i+1,j,cur);
    }
}

void solve(int tc){

    cin>>s>>t;

    n=s.size();
    m=t.size();

    memset(dp,-1,sizeof(dp));

    go(0,0);

    answers.clear();

    build(0,0,"");

    for(auto &x:answers)
        cout<<x<<'\n';
}

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    pre_compute();

    int tc=1;

    if(multicases_)
        cin>>tc;

    int total_tcs=tc;

    while(tc--){
        solve(total_tcs-tc);
    }

    return 0;
}
