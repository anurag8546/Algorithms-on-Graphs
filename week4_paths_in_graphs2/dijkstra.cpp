/*Author: Anurag*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
vector<pair<int,int>>adj[100000+2];
vector<bool>vis(100000+2,0);
// vector<bool>dfsvis(100000+2,0);
#define inf 1e18
// int elements=0;
int M=1e9+7;

int32_t main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        adj[x].push_back({y,wt});
        //  adj[y].push_back({x,wt});
    }

    int source,e;
    cin>>source>>e;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;// min-heap ; In pair => (dist,from)
	vector<int>dis(n+1,inf);
	dis[source]=0;
	pq.push({0,source});
	while(!pq.empty()){
	    int node=pq.top().second;
	    int dist=pq.top().first;
	    pq.pop();
	    vector<pair<int,int>>::iterator it;
	       for(auto it:adj[node]){
	        int next_node=it.first;
	        int next_dist=it.second;
	        if( dis[next_node] > dis[node] + next_dist){
	            dis[next_node] = dis[node] + next_dist;
	            pq.push({dis[next_node],next_node});
	        }

	    }
	}
	if(dis[e]==inf)
	dis[e]=-1;
    cout<<dis[e]<<endl;
    for(int i=0;i<n;i++){
        adj[i].clear();
        vis[i]=0;
    }
}
