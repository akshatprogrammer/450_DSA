#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<int> adj[],int n){
    vector<int> vis(n+1,0);
    vector<int> res;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i]=1;

            while(!q.empty()){
                int node=q.front();
                q.pop();
                res.push_back(node);


                for(auto it : adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
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

    vector<int> res=bfs(adj,n);

    for(int i=0;i<res.size();i++)
        cout << res[i] << " ";
        cout <<endl;
    return 0;
}
