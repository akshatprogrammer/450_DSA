#include<bits/stdc++.h>
using namespace std;
bool cyclyeDFSDirect(int node,vector<int> adj[],vector<int>&vis,vector<int>&dfsvis){
    vis[node]=1;
    dfsvis[node]=1;

    for(auto it : adj[node]){
		if(!vis[it]){
			if(cyclyeDFSDirect(it,adj,vis,dfsvis))
				return true;
		}
		else if(dfsvis[it]!=0)
				return true;
	}
	dfsvis[node]=0;
    return false;
}
bool checkCycle(vector<int> adj[],int n){
    vector<int> vis(n+1,0);
    vector<int> dfsvis(n+1,0);

    for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(cyclyeDFSDirect(i,adj,vis,dfsvis))
				return true;
		}
	}
	return false;
}
int main(){
    int n,m;
    cin >> n >>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >>v;
        adj[u].push_back(v);
    }

    if(checkCycle(adj,n))
        cout << "Present" << endl;
    else
        cout << "Not Present " << endl;
    
    return 0;
}