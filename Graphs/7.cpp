#include<bits/stdc++.h>
using namespace std;
bool check(int n,int x,int y){
        if(x>=0 and y>=0 and x<n and y<n) return true;
        return false;
    }
	int minStepToReachTarget(vector<int>&k,vector<int>&t,int n)
	{
	    // Code here
	    int dx[]={-2,-1,1,2,2,1,-1,-2};
	    int dy[]={1,2,2,1,-1,-2,-2,-1};
	    
	    int **chess=new int*[n];
	    for(int i=0;i<n;i++){
	        chess[i]=new int[n];
	        for(int j=0;j<n;j++)
	            chess[i][j]=-1;
	    }
	    chess[k[0]-1][k[1]-1]=0;
	    queue<pair<int,int>> q;
	    q.push({k[0]-1,k[1]-1});
	    
	    while(!q.empty()){
	        int x=q.front().first;
	        int y=q.front().second;
	        
	        q.pop();
	        
	        for(int i=0;i<8;i++){
	            int targetX=x+dx[i];
	            int targetY=y+dy[i];
	            
	            if(check(n,targetX,targetY) and chess[targetX][targetY]==-1){
	                chess[targetX][targetY]=chess[x][y]+1;
	                if(targetX==t[0]-1 and targetY==t[1]-1){
	                    return chess[targetX][targetY];
	                }
	                q.push({targetX,targetY});
	            }
	        }
	    }
	    int ans=chess[t[0]-1][t[1]-1];
	    for(int i=0;i<n;i++){
	        delete chess[i];
	    }
	    delete chess;
	    return ans;
	}