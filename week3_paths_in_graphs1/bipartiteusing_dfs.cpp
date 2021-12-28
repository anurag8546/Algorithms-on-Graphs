/*
Author : Anurag Mishra
Problem: Week 3(Checking whether a Graph is Bipartite)
Logic: Bipartite using dfs
*/
        #include<bits/stdc++.h>
        using namespace std;
        #define int long long
        #define fr(i,a,b) for(int i=a;i<b;i++)
        #define pb push_back
        vector<int>adj[100000+2];
        // vector<bool>col(100000+2,-1);
        vector<bool>dfsvis(100000+2,0);
        // stack<int> st;
        int elements=0;
        int M=1e9+7;
        bool dfs(int n,int col[]){
          if(col[n]==-1)
          col[n]=1;
           
            for(auto child:adj[n]){
                if(col[child]==-1){
                  col[child]=1-col[n];
                if(!dfs(child,col))
              return false;
                }
                else if(col[n]==col[child])
                return false;
            }
            return true;
        }

    int isbpt(int n){
      int col[n+1];
      memset(col,-1, sizeof col);
        for(int i=1;i<=n;i++){
            if(col[i]==-1){
                if(!dfs(i,col))
                return 0;
            }
        }
        return 1;
    }
   
 const int N=1000000;
        int32_t main(){
            int n,m;
            cin>>n>>m;
            for(int i=0;i<m;i++){
                int x,y;
                cin>>x>>y;
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
            
            
           cout<<isbpt(n);
        }
       
        
        
