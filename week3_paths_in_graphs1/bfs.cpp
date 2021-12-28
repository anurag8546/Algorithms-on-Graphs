/*
Author : Anurag Mishra
Problem: Week 3( Computing the Minimum Number of Flight Segments)
Logic: Shortest path in undirected graphs
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
vector<int>adj[100000+2];
vector<bool>vis(100000+2,0);
vector<bool>dfsvis(100000+2,0);
// stack<int> st;
int elements=0;
int M=1e9+7;

void bfs(int n,int s,int y){
   int dis[n+1];
   for(int i=0;i<=n;i++){
       dis[i]=1000000;
   }
   queue<int>q;
   dis[s]=0;
   q.push(s);
   while(!q.empty()){
       int node=q.front();
       q.pop();
       for(auto child : adj[node]){
           if(dis[child]>dis[node]+1){
               dis[child]=dis[node]+1;
               q.push(child);
           }
       }
   }
if(dis[y]==1000000)
cout<<-1<<endl;
else
cout<<dis[y]<<endl;
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
    int w,e;
    cin>>w>>e;
    cout<<"";
    bfs(n,w,e);
}
