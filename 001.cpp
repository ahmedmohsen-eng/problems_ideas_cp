///first problem is:
/*

Problem

You are given an undirected graph with n vertices and m edges.

Your task is to transform the graph into a star graph by adding the minimum number of edges. You are not allowed to remove existing edges.

A star graph is a graph in which there exists one vertex (the center) that is adjacent to every other vertex.

Input
The first line contains two integers n and m.
The next m lines each contain two integers u and v, indicating that an undirected edge already exists between vertices u and v.
Output
Print the minimum number of edges that must be added.
Then print those edges.

If multiple solutions exist, print any.

if he said m<n/2 it doesn't matter here

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


//some observations: required shape is star, 
// if he said m<n/2 means there is at least node which is not connected to any one  ,,, but it doesn't matter here

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

//custom sort by size .. desc.
// bool custom_sort(vector<int>v1,vector<int>v2){
//     return v1.size()>v2.size();
// }

void solve(const int&tt){
    //dbg:
    // cerr<<"reached";
    int n,m;
    cin>>n>>m;
    adj.assign(n+1,{});
    vis.assign(n+1,0);
    
    int u,v;
    for(int i=0 ;i < m; i++){
        cin>>u>>v;
        //undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // //sorting desc.. by size so the highest degree node is at the beginning  ,, it can be made in better comlpexity in a linear check!!
    // sort(adj.begin(),adj.end(),custom_sort);      //two disadvantages : not knowing index of it , and larger complexity as mentioned
    
    
    
    
    
    //changing logic
    
    int parent=0;
    int mx_deg=0;//maximum degree
    for(int i=1 ; i<=(int)adj.size() ;i++){
        if( (int)adj[i].size()>mx_deg ){
            mx_deg=adj[i].size();
            parent=i;
        }
    }
    
    //printing number of non connected points to the 
    cout<<n-adj[parent].size() -1 <<'\n'; //-1 to exclude itself 
    
    //frequency map for better check
    map<int,int>mp;
    
    mp[parent]=1;//to avoid making pair with it self
    
    for(int i = 0 ; i < (int)adj[parent].size()  ;i++){
        mp[adj[parent][i]]++; 
        
        // //dbg
        // cerr<<i<<endl;
        
    }
    
    
    for(int i =1 ; i<=n; i++){ //checking all points 
        if(mp[i]==0) cout<<parent<<' '<<i<<'\n';
    }
    
    
    // //dbg:
    // cerr<<endl<<endl;
    // for(auto&x:mp) cerr<<x.first<<' '<<x.second<<endl;
    
    
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
