#include<bits/stdc++.h>
using namespace std;
bool cycleDFS(int node,int parent,vector<int> adj[],vector<int> &vis){
    vis[node]=1;

    for(auto it : adj[node]){
        if(!vis[it]){
            if(cycleDFS(it,node,adj,vis)){
                return true;
            }
            else if(it!=parent) return true;
        }
    }
    return false;
}
bool checkCycle(vector<int> adj[],int n){
    vector<int> vis(n+1,0);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(cycleDFS(i,-1,adj,vis)){
                return true;
            }
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
        adj[v].push_back(u);
    }

    if(checkCycle(adj,n))
        cout << "Present" << endl;
    else
        cout << "Not Present " << endl;
    
    return 0;
}