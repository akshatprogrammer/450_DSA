class Solution{
    public:
    void ratmaze(vector<vector<int>> &m,int n,vector<string> &res,int x,int y,vector<vector<int>> &vis,string op){
        // Base case:
        
        
        //1 
        if(x>=n or y>=n or x<0 or y<0) return;
        
        //2
        if(vis[x][y]==1) return;
        //3
        if(m[x][y]==0) return;
        
        if(x==n-1 and y==n-1){
            res.push_back(op);
            return;
        }
        
        
        
        vis[x][y]=1;
        
        ratmaze(m,n,res,x+1,y,vis,op+'D'); //down
        ratmaze(m,n,res,x,y-1,vis,op+'L'); //left
        ratmaze(m,n,res,x,y+1,vis,op+'R'); //right
        ratmaze(m,n,res,x-1,y,vis,op+'U'); //up
    
        
        vis[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        if(m[0][0]==0 or m[n-1][n-1]==0)
            return res;
        
        
        int xaxis=0,yaxis=0;
        
        string final="";
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        ratmaze(m,n,res,xaxis,yaxis,vis,final);
        
        return res;
    }
};
