/*
Author: Anurag Mishra
Problem: week 2 (Topological sort)
Logic: create a stack and as the dfs for a node is completed push it to the stack.
and pop the stack to get a toposort .

*/        


#include<bits/stdc++.h>
        using namespace std;
        #define int long long
        #define fr(i,a,b) for(int i=a;i<b;i++)
        vector<int>adj[100000+2];
        vector<bool>vis(100000+2,0);
        // vector<bool>dfsvis(100000+2,0);
        stack<int> st;
        int elements=0;
        int M=1e9+7;
        void dfs(int n){
            vis[n]=true;
            // dfsvis[n]=1;
           
            for(auto child:adj[n]){
                if(!vis[child]){
                dfs(child);
                // return true;
                }
                
            }
            st.push(n);
            // dfsvis[n]=0;
            // return false;
        }
       
    // vector<int>
    void Tp(int n){
        //  stack<int>st;
         for(int i=1;i<=n;i++){
             if(!vis[i]){
                 dfs(i);
             }
         }
         vector<int>ans;
         while(!st.empty()){
             ans.push_back(st.top());
             st.pop();
         }
         for(auto it: ans)
         cout<<it<<" ";
         cout<<endl;
        // return ans;
     }

        int32_t main(){
    
          int n,m;
          cin>>n>>m;
          fr(i,0,m){
              int u,v;
              cin>>u>>v;
          adj[u].push_back(v);
       //   adj[v].push_back(u);
          }
       cout<<"";
       Tp(n);
     
    for(int i=1;i<=n;i++){
     adj[i].clear();
       vis[i]=0;
    //   dfsvis[i]=0;
   }
      }
        // }
        
