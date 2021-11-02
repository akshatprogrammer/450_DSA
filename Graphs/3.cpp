#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],int node,vector<int> &vis,vector<int> &res){
    vis[node]=1;
    res.push_back(node);
    for(auto it : adj[node])
    {
        if(!vis[it]){
            dfs(adj,it,vis,res);
        }
    }
}
vector<int> dfs(vector<int> adj[],int n){
    vector<int> vis(n+1,0);
    vector<int> res;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(adj,i,vis,res);
        }
    }
    return res;
}
int main(){
    int n,m;
    cin >> n >>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<int> res=dfs(adj,n);

    for(int i=0;i<res.size();i++)
        cout << res[i] << " ";
        cout <<endl;
    return 0;
}
