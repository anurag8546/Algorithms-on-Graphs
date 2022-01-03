/*
Logic:  
1)input the graph
2)make a distance function which calculates distance between two point
3)make edges, i.e. every pair (i,j) such that (j>i) from 1 to n;
   e.g. for (1 , 4)-> (1,2), (1,3),(1,4), (2,3),(2,4),(3,4);
4) find the distances between these pairs and store them in your adjacency triplet (double, pair<int,int>)
5) now apply kruskal's algorithm to find minimum spanning tree.

PS: use double and int carefully :)

*/
/*

{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}

===========================================


kruskal's algorithm

{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}

===========================================
*/
/*

{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}

===========================================


kruskal's algorithm

{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}

===========================================
*/

#include<bits/stdc++.h>
using namespace std;
#define d long double
#define pii pair<int , int>
#define pb push_back
vector<pair<d,pair<int,int>>>adj;
const int  N=201;
vector<int>parent(N,-1);
vector<pii>p(N);
#define inf 1e18
int M=1e5+7;
int n,m;
d ans=0;
//finding the distance between pairs
d dis(pii &a,pii &b){
    d q=(d)(a.first-b.first)*(a.first-b.first);
    d w=(d)(a.second-b.second)*(a.second-b.second);
    d r=sqrt(q+w);
    return r;
}
// kruskal's algorithm starts from here :)


//find parent of nodes
int find_parent(int a){
    if(parent[a]<0){
        return a;
        
    }
    return parent[a]=find_parent(parent[a]);
    
}
void unionn(pair<d,pii> a){
    int z=a.second.first;
    int x=a.second.second;
    int p1=find_parent(z);
    int p2=find_parent(x);
    d wt=a.first;
    if(p1==p2) return;
    ans+=wt;
    if (parent[p2]<parent[p1]){
			parent[p2]+=parent[p1];
         	parent[p1]=p2;
	}
	else{
	parent[p1]+=parent[p2] ;
	parent[p2]=p1 ;
}
}
void kruskal() {
	sort(adj.begin(),adj.end()) ;
	for(int i=0;i<adj.size();i++) {
		unionn(adj[i]) ;
	}
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
       cin>>p[i].first>>p[i].second;
    }
     for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            double dist=dis(p[i],p[j]);
            adj.pb({dist,{i,j}});
        }
    }
	kruskal() ;
	 cout << fixed << setprecision(10) << ans ;
}
