//Implemented a brute-force solution to find the least length string subsequence that contains all uppercase letters.


#include <bits/stdc++.h>
using namespace std;

bool multicases_=true;
#define int long long



void solve(int tc){
	// //dbg:
	 // cerr<<"at the test case no."<<tc<<" : \n";
	
	//can it be done using prefix and suffix arrays
	
	int n; cin>>n;
	string s;cin>>s;
	
	vector<vector<int>>prf(ni,vector<int>(26,0));
	
	
	for(int i = 0 ;i < n; i++){
		prf[i][s[i]-'A']++;///////fix:::: uppercase letters not lowercase
		if(i!=0){
			for(int j = 0 ;j < 26;j++){
				prf[i][j]+=prf[i-1][j];
			}
		}
	}
	
	// vector<vector<int>>suf(n,vector<int>(26,0));
// 	
	// for(int i = n-1 ;i >= 0; i--){
		// suf[i][s[i]-'a']++;
		// if(i!=n-1){
			// for(int j = 0 ;j < 26;j++){
				// suf[i][j]+=suf[i+1][j];
			// }
		// }
	// }
	
	int ans=LLONG_MAX;
	
	for(int i=0 ;i < n; i++){
		for(int j = i+25 ;j < n; j++){
			
			bool ok = true;
			
			for(int k = 0 ; k < 26 ; k++){
				ok&=(  prf[j][k]-(i?prf[i-1][k]:0LL)  );
			}
			
			
			
			if(ok)ans=min(ans,j-i+1);
			
			
		}
	}
	
	cout<<ans<<'\n';
	
	
	
	
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	//pre computations:
	
	
	int tc=1;
	if(multicases_)cin>>tc;
	int total_tcs=tc;
	while(tc--){
		solve(total_tcs-tc);
	}
	return 0;
}
