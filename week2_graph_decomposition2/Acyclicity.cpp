/*
Author : Anurag Mishra 
Problem : Week 2 (Acyclicity)
Logic : find another visit array as dfsvis and initially make it visited and as the dfs for any node is over just make dfsvis[node]=0.
edit: make sure you only store " adj[u].push_back(v);" 'v' in the list of 'u'.
*/


        #include<bits/stdc++.h>
        using namespace std;
        #define int long long
        #define fr(i,a,b) for(int i=a;i<b;i++)
        vector<int>adj[100000+2];
        vector<bool>vis(100000+2,0);
        vector<bool>dfsvis(100000+2,0);
        int elements=0;
        int M=1e9+7;
        bool dfs(int n){
            vis[n]=true;
            dfsvis[n]=1;
           
            for(auto child:adj[n]){
                if(!vis[child]){
                if(dfs(child))
                return true;
                }
                else if(dfsvis[child]==1)
                return true;
            }
            dfsvis[n]=0;
            return false;
        }
        int iscycle(int n){
            fr(i,1,n+1){
          if(!vis[i]){
          if(dfs(i))
          return 1;
          }
      }
      return 0;
        }
        int32_t main(){
    
          int n,m;
          cin>>n>>m;
          fr(i,0,m){
              int u,v;
              cin>>u>>v;
          adj[u].push_back(v);
       
          }
       cout<<iscycle(n);
     
    for(int i=1;i<=n;i++){
     adj[i].clear();
       vis[i]=0;
       dfsvis[i]=0;
   }
      }
        // }
        
