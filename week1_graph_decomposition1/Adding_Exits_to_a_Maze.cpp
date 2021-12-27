/*
Author: Anurag Mishra
Problem: Week 1 assignment 1(Adding an Exit from a Maze)
Logic: Connected Components: The number of times we are calling our dfs is equal to the connected components
*/
        #include<bits/stdc++.h>
        using namespace std;
        #define int long long
        #define fr(i,a,b) for(int i=a;i<b;i++)
        vector<int>adj[100000+2];
        vector<bool>vis(100000+2,0);
        int elements=0;
        int M=1e9+7;
        void dfs(int n){
            vis[n]=true;
            
            for(auto child:adj[n]){
                if(!vis[child])
                dfs(child);
            }
            
        }
        int32_t main(){
    
          int n,m;
          cin>>n>>m;
          fr(i,0,m){
              int u,v;
              cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
          }
           int ways=1,c=0;
      fr(i,1,n+1){
          if(vis[i]==0){
           dfs(i);
            
              c++;
          }
      }
      cout<<c<<endl;
     
    for(int i=1;i<=n;i++){
     adj[i].clear();
       vis[i]=0;
   }
      }
       
        
