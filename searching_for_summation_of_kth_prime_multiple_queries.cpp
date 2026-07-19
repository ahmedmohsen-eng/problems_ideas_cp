


/*


Problem Statement

Given several queries, each containing an integer k, output the sum of the first k prime numbers.

The sequence of prime numbers begins as:
2, 3, 5, 7, 11, 13, ...

For each query, compute the sum of the first k prime numbers.

It is guaranteed that every queried value of k is valid.

Input

The first line contains an integer T, the number of queries.

Each of the next T lines contains a single integer k.

Output

For each query, print the sum of the first k prime numbers on its own line.

Constraints

1 ≤ T ≤ 10^5
1 ≤ k ≤ 25

Example

Input
4
1
2
5
25

Output
2
5
28
1060

Explanation

For k = 1, the sum is:
2

For k = 2, the sum is:
2 + 3 = 5

For k = 5, the sum is:
2 + 3 + 5 + 7 + 11 = 28

For k = 25, the sum of all prime numbers less than or equal to 100 is:
1060



*/








// بسم الله الرحمن الرحيم  
//متنساش تصل على النبي -صلى الله عليه وسلم- بس كده



// ===================== CORE =====================
    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>

    using namespace std;
    using namespace __gnu_pbds;

// ===================== FAST IO / DEBUG ===================== 
    #ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << '\n';
    #define iosystem freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    #else
    #define debug(x)
    #define iosystem
    #endif

    #define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

// ===================== OPTIMIZATION =====================
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("avx2,popcnt")

// ===================== TYPES =====================
    using ll = long long;
    using vi = vector<int>;
    using vll = vector<ll>;
    using pii = pair<int,int>;
    using vpii = vector<pii>;

// ===================== CONSTANTS =====================
    const ll mod = 1e9 + 7;
    const int oo = 0x3f3f3f3f;/////take care it is int here<<<<
    const ll OO = 0x3f3f3f3f3f3f3f3fLL;//take care that here it is capitalized!! OO
    const double PI = acos(-1.0);
    //char space = ' ';<< i don't know if it is a good practice or not!! mm..
    const char* no="NO\n";
    const char* yes="YES\n";

// ===================== CUSTOM HASH =====================
    struct custom_hash {
        static uint64_t splitmix64(uint64_t x){
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

        template<class T, class U>
        size_t operator()(const pair<T,U>& p) const {
            static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(hash<T>{}(p.first) + FIXED_RANDOM)
                ^ (splitmix64(hash<U>{}(p.second) + FIXED_RANDOM) << 1);
        }
    };

// ===================== PBDS =====================
    template<class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

    template<class T>
    using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

    // order_of_key, find_by_order

    template<class T>
    void safe_erase(ordered_multiset<T>& s, const T& val){
        int idx = s.order_of_key(val);
        auto it = s.find_by_order(idx);
        if(it != s.end() && *it == val) s.erase(it);
    }

// ===================== LOGIC HELPERS =====================
    //
    
//
#define int long long


vector<int>primes_till_now;
vector<bool>is_composite;
void linear_sieve(int n){
    is_composite.assign(n+1,0);
    
    for(int i = 2 ; i<=n ; i++){
        if(!is_composite[i]){
            primes_till_now.push_back(i);
        }
        int prd;//product of i * pr (current index with inner loop current prime)
        for(auto&prime:primes_till_now){
            prd=prime*i;
            if(prd>n) break;
            is_composite[prd]=true;
            if(i%prime==0) break;
        }
    }
}

int customized_binary_search(vector<pair<int,int>>&ans,int x){
    //what is needed to binary search on the pair.first
    int sz=ans.size();
    int l=0,r=sz-1;
    int mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(ans[mid].first==x){
            return ans[mid].second;
        } else if(ans[mid].first<x){
            l=mid+1;
        } else{
            r=mid-1;
        }
    }
    //no need for another return because in the problem it is found
    //but only writing the return to avoid UB
    return -1;
}

// order_of_key, find_by_order
// ===================== SOLVE =====================
    bool multicases = false;

void solve(){
    
    linear_sieve((int)1e2);
    
    //available vectors : 
        //primes_till_now
        //is_composite
    //
    
    int sz=primes_till_now.size();
    vector<pair<int,int>>ans(sz);
    for(int i = 0 ; i < sz ;i++){
        //fix : index is 0-based so add 1
        ans[i].first=i+1;//saving index to save the order : is it the 1st or 234th prime etc..
        ans[i].second=primes_till_now[i];
        if(i) ans[i].second+=ans[i-1].second;//precompute prefix sums
    }
    
    //now all needed is only a customized lowerbound function!!!
    
    //dbg
    //for(auto&p:ans)cerr<<p.first<<' '<<p.second<<'\n';
    
    int ttt;cin>>ttt;
    while(ttt--){
        int x;cin>>x;
        cout<<customized_binary_search( ans, x )<<'\n';
    }
    
    
    
}
// order_of_key, find_by_order


// ===================== MAIN =====================
signed main(){
    cin.exceptions(cin.failbit);
    //if wrong in thing which usually fails silently it makes rutime error 
    //instead of wrong answer to know that problem may be not in the logic
    
    fastio;
    // iosystem;//<<<<<<<<<<<
    
    int T = 1;
    if(multicases) cin >> T;
    
    while(T--) solve();
    
    return 0;
}
