
/*
problem : 

"Take the maximum subarray of the original array, 
and compute what its value would become after applying the operation optimally for that fixed subarray."

If I am forced to keep the original maximum subarray, what is the largest value I can make it have?


*/




#include<bits/stdc++.h>
using namespace std;

//take care: 
#define int long long ////<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



bool cmp(pair<char,int>&p1,pair<char,int>&p2){
    return p1.second>p2.second;//write return right
}

//strong custom hash for antihacking
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    template<class T1, class T2>
    size_t operator()(const pair<T1,T2>& p) const {
        uint64_t h1 = splitmix64(hash<T1>{}(p.first));
        uint64_t h2 = splitmix64(hash<T2>{}(p.second));
        return h1 ^ (h2 << 1);
    }
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};



bool multi_cases = true;////////////////////////////////////////////////////<<<<<<<<<<<<<<<<<<<<
// void solve(const int&t);

void solve(const int& t){
    
    //kadane's algorithm
    
    int n; cin>>n;
    int k,x;cin>>k>>x;
    vector<int>v(n);
    for(auto&x:v)cin>>x;
    
    
    //wrong trial
    /*
    vector<pair<int,int>>mins;
    for(int i = 0 ; i < n ;i++){
        mins.push_back({v[i],i});
    }
    
    sort(mins.begin(),mins.end());
    
    int idx;
    for(int i=0 ; i < k ; i++){
        idx=mins[i].second;
        v[idx]+=x;
    }
    
    for(int i = k ; i < n ;i++){
        idx=mins[i].second;
        v[idx]-=x;
    }
    */
    
    int cur=0,   mx=LLONG_MIN;//who said that min value is 0 xxx , intitalize it with the least possible
    //                ^ because of # define int long long
    int tmp;
    int l , r;
    int curL,curR;//don't forget semi coloumn
    
    for(int i = 0; i < n ;i++){ //fix : from 0 to n to read all
        
        // cur=max(v[i],cur+v[i]);
        // mx=max(mx,cur);
        if(v[i]>cur+v[i]){
            cur=v[i];
            curL=i;
            curR=i;
        } else {
            cur=cur+v[i];
            curR=i;
        }
        
        if(cur>mx){
            mx=cur;
            l=curL;
            r=curR;
        }
        
        
    }
    
    int len=r-l+1;
    
    
    //ai says that it is the same as : (2*min(len,k)-len)*x
    cout<<mx + min(len,k)*x -max(0LL,len-k)*x  <<'\n';
    //                                 ^ # define int long long
    
    
}


signed main(){
    // freopen("cost.in","r",stdin);       ///// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//forgot to remove it
    
    cin.exceptions(cin.failbit);// important to know wrong input (sometimes)
    ios::sync_with_stdio(0);cin.tie(0);
    
    /////////////////////////////////////////////////hackerrank hasn't defined ONLINE_JUDGE ************
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    
    int test_cases=1;
    if(multi_cases)cin>>test_cases;
    for(int i = 1 ; i <= test_cases; i++){
        solve(i);
    }
    
    //test_cases are 1-indexed
    
    return 0;
}

