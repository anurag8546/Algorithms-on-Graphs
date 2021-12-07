#include <bits/stdc++.h>
#include <vector>
using std::vector;
using std::pair;
// int M=1e6+5;
vector<int>adj[1000005];
int vis[100005]={0};
bool dfs(int node,int v){
  vis[node]=1;
  for(auto child: adj[node]){
    if(!vis[child]){
      if(child==v){
      return true;
    }
      dfs(child,v);
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
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach( x - 1, y - 1);
}
