// بسم الله الرحمن الرحيم  
//متنساش تصل على النبي -صلى الله عليه وسلم- بس كده




/*
problem statement :




Prime numbers are positive integers greater than 1 that have exactly two distinct positive divisors: 1 and themselves.

You are given several queries. In each query, you are given an integer K representing the position of a prime number.

For every query, determine the sum of the first K prime numbers.

Input

The first line contains an integer T (1 ≤ T ≤ 10^5), the number of queries.

Each of the next T lines contains a single integer K (1 ≤ K ≤ 25).

Output

For each query, print a single integer representing the sum of the first K prime numbers.

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




*/









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
const int oo = 0x3f3f3f3f;
const ll OO = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
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

template<class T>
void safe_erase(ordered_multiset<T>& s, const T& val){
    int idx = s.order_of_key(val);
    auto it = s.find_by_order(idx);
    if(it != s.end() && *it == val) s.erase(it);
}

// ===================== LOGIC HELPERS =====================
#define int long long

vector<int> primes_till_now;
vector<bool> is_composite;

void linear_sieve(int n){
    is_composite.assign(n+1,0);

    for(int i = 2 ; i <= n ; i++){
        if(!is_composite[i]){
            primes_till_now.push_back(i);
        }

        int prd;
        for(auto &prime : primes_till_now){
            prd = prime * i;
            if(prd > n) break;
            is_composite[prd] = true;
            if(i % prime == 0) break;
        }
    }
}

int customized_binary_search(vector<pair<int,int>> &ans, int x){
    int sz = ans.size();
    int l = 0, r = sz - 1;

    while(l <= r){
        int mid = l + (r - l) / 2;

        if(ans[mid].first == x)
            return ans[mid].second;
        else if(ans[mid].first < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

bool multicases = false;

void solve(){

    linear_sieve(100);

    int sz = primes_till_now.size();
    vector<pair<int,int>> ans(sz);

    for(int i = 0 ; i < sz ; i++){
        ans[i].first = i + 1;
        ans[i].second = primes_till_now[i];
        if(i) ans[i].second += ans[i-1].second;
    }

    int t;
    cin >> t;

    while(t--){
        int x;
        cin >> x;
        cout << customized_binary_search(ans, x) << '\n';
    }
}

signed main(){

    cin.exceptions(cin.failbit);

    fastio;

    int T = 1;
    if(multicases) cin >> T;

    while(T--)
        solve();

    return 0;
}
