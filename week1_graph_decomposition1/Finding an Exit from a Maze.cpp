/*
Author: Anurag Mishra
Problem: Week 1 assignment 1(Finding an Exit from a Maze)
Logic: Call the dfs for the x and check if y is there in the same graph, if it is, return 1 else o.
*/



#include <bits/stdc++.h>
#include <vector>
using std::vector;
using std::pair;
// int M=1e6+5;
vector<int>adj[1000005];
int vis[100005]={0};
bool dfs(int node,int v){
    if(node==v)
    return true;
  vis[node]=1;
  for(auto child:adj[node]){
    if(!vis[child]){
       if(dfs(child,v)){
      return true;
    }
    }
  }
  return false;
}
int reach(int x, int y) {
   
  if(dfs(x,y))
  return 1;
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
//   vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach( x , y );
   vis[100005]={0};

}
