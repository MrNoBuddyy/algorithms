#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    bool bfs(vector<int>adj[],int src,vector<bool>&vis){
        vis[src]=true;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while (!q.empty()){
            pair<int,int>p=q.front();
            int nn=p.first;
            int parent=p.second;
            for(auto &it:adj[nn]){
                if(vis[nn]==false){
                    q.push(make_pair(it,nn));
                    vis[nn]=true;
                }else if (parent!=it)
                {
                    return true;
                }
                
            }
        }
        return false;
    }
    public:
    bool isCycle(vector<int>adj[],int V){
        vector<bool>vis(V,0);
        for(auto it:vis){
            if(!vis[it]){
                if(bfs(adj,it,vis))return true;
            }
        }
        return false;
    }
};