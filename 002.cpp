//problem statement:
/*
Problem

A country has n cities connected by m existing undirected roads. No two roads connect the same pair of cities, and there are no self-loops.
Your task is to add the minimum number of new roads so that there exists a city directly connected to every other city. Existing roads cannot be removed.
In other words, after adding the roads, the graph must contain a spanning star centered at some city, although additional roads may also exist.

Input
The first line contains two integers n and m.
Each of the next m lines contains two integers u and v, indicating that there is already a road between cities u and v.

Output
Print the minimum number of roads to add.
Then print the roads to add.
If there are multiple optimal solutions, print any.


There are n cities and initially no roads.
It is guaranteed that m<n/2
Construct the minimum number of roads so that every pair of cities can reach each other using at most two roads.
*/

#include<bits/stdc++.h>
using namespace std;


#define int long long


int n,m;
vector<string>maze;


////if 8 directions:
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};


int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

//solution is to make it a star by:
                                // finding the one which has the most number of edges connected to it(highest degree)
                                //then connect the rest to it (things which are not actually connected to it yet)


//some observations: required shape is star, m<n/2 means there is at least node which is not connected to any one 

vector<vector<int>>adj;
vector<int>vis;

void dfs(int x){
    vis[x]=1;
    
    for(auto&v:adj[x]){
        if(!vis[v]){
            dfs(v);
        }
    }
}



void solve(const int&tt){
    //dbg:
    // cerr<<"reached";
    int n,m;
    cin>>n>>m;
    adj.assign(n+1,{});
    vis.assign(n+1,0);
    
    //excluded indices from begin the center
    unordered_set<int>excluded;
    
    int u,v;
    for(int i=0 ;i < m; i++){
        cin>>u>>v;
        //undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
        
        excluded.insert(u);
        excluded.insert(v);
    }
    
    int idx_parent;
    int mn_deg=100000;
    
    //fix 3: <  not <=    adj.size()
    for(int i = 1 ; i<adj.size() ;i++){ 
        if(excluded.count(i)) continue;//skipping blocked indices
        
        if( (int)adj[i].size()<mn_deg ){
            idx_parent=i;
            mn_deg=adj[i].size();
        }
    }
    
    //fix 1 : .size()
    //fix 2 : -1
    cout<<n-(int)adj[idx_parent].size() -1<<'\n';// -1 to exclude the parent itself
    
    
    
    
    
    // last fix is that there are no roads between any things
    
    // unordered_map<int,int>found;
    
    // found[idx_parent]++;// to avoid recounting the parent as a child
    // for(auto&x:adj[idx_parent]){
    //     found[x]++;
    // }
    
    for(int i = 1 ;i <= n ;i++){
        //but after removing these conditions you must take sure it is not the same node:
        if(i==idx_parent) continue;
        
        // if(!found[i])
        cout<<idx_parent<<' '<<i<<'\n';
    }
    
    
}


signed main(){
    
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    
    int tt=1;
    // cin>>tt;
    while(tt--){
        solve(tt);
    }
    
    
}
