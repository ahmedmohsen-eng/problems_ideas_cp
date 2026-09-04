#include <bits/stdc++.h>
using namespace std;

bool multicases_=true;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// template<class  T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
#define int long long//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<??
typedef unsigned long long u64;//this or the one  below
#define ull unsigned long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}


int mod=1e9+7;

int mod_mul(int a, int b){
	a = (int)  (( (__int128) a%mod+mod )%mod);
	b = (int)  (( (__int128) b%mod+mod )%mod);
	return (a*b)%mod;
}

int fastpow(int a, int b){
	a%=mod;
	int ret = 1;
	while(b){
		if(b&1) ret = mod_mul(ret,a);
		a=mod_mul(a,a);
		b>>=1;
	}
	return ret;
}

/*
int recursive_fastpow(int a, int b){
	if(b==0)return 1;
	a%=mod;
	int ret = fastpow(a,b/2);
	if(b&1){
		ret=mod_mul(ret,a);
	}
	return ret;
}
*/



int fermat(int x){/////////modular inverse (for this way there is a condition that :
																	// : mod is a prime)
						//for modular inverse to exist mod and number must be comprimes
	return fastpow(x,mod-2);
}
vector<int>inv_fact;

vector<int>fact;

void pre_compute(){
	int N=1000'000;
	fact.resize(N+1);
	fact[0]=1;
	for(int i = 1; i<= N; i++){
		fact[i]=mod_mul(i,fact[i-1]);
	}
	
	inv_fact.resize(N+1);
	inv_fact[0]=inv_fact[1]=1;
	
	/////////////////////
	inv_fact[N] = fermat(fact[N]);
	for(int i = N; i >= 1; i--){
        inv_fact[i-1] = mod_mul(inv_fact[i], i);
    }
    /////////////////////
}

void solve(int tc){
	// //dbg:
	 // cerr<<"at the test case no."<<tc<<" : \n";
	
	int n; string s; cin>>n>>s;
	
	
	//lowercase alpahabets
	int arr[26]={};
	//get char from index
	auto get_char=[](int x){return (char) (x+'a'); };
	//get index from char      ,,,,, i mean index in the arr
	auto get_idx=[](char c){return (int) (c-'a');};
	
	
	for(auto&c:s){
		arr[get_idx(c)]++;
	}
	
	// ///////dbg
	// for(int i = 0 ;i < 26;i++)cout<<get_char(i)<<' '<<arr[i]<<endl;
	
	
	
	//////////////////////logic/////////////////////////////////
	
	
	//it is a combinatorics problem !
	// all possible ways =   n! / (frq(a)!*frq(b)!*.........*frq(z)!)  (without repeating)
	
	
	int ans = fact[n];
	
	/////fix i<26 not n,, and use mod_mul ,, start from 0
	for(int i = 0 ;i < 26;i++) ans=mod_mul(ans,inv_fact[arr[i]]);
	
	cout<<ans<<'\n';
	
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	//setIO("problemname");
	
	//the following output way overwrites the file:
	
	// freopen("problemname.in", "r", stdin);
	// // the following line creates/overwrites the output file
	// freopen("problemname.out", "w", stdout);
	
	
	
	pre_compute();
	
	int tc=1;
	if(multicases_)cin>>tc;
	int total_tcs=tc;
	while(tc--){
		solve(total_tcs-tc);
	}
	return 0;
}
