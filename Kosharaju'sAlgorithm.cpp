#include <bits/stdc++.h>
using namespace std;
//documentation comment block

/***
 * Kosaraju's Algorithm
 * https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
 * ### 
*- only valid for directed graphs
*- dfs the directed graph
*- store the nodes in when their dfs is done (before return of dfs or say according to a nodes dfs finishing order (push_back))
*- reverse the graph edges direction
*- iterate over finishing array such that last finished unvisited node is the starting point (rbegin() )
*- if the node is unvisited then we say it a connected component’s start
*- keep doing this until finished
* time complexity
* 3*O(V + E) where V is the number of vertices and E is the number of edges
* O(V + E) for dfs
* O(V + E) for reversing the graph
* O(V + E) for the second dfs
* space complexity O(3V + E) for the adjacency list representation of the graph
*O(V) for the visited array
*O(V) for the finishing array
*O(V+E) for the reversed adjacency list
* 
*/

class Solution {
    void dfs(int i,vector<vector<int>>&adj,vector<int>&visit,vector<int>&finish){
        if(visit[i])return;
        visit[i]=1;
        for(auto it :adj[i]){
            dfs(it,adj,visit,finish);
        }
        finish.push_back(i);
    }
    void dfs2(int i,vector<vector<int>>&adj,vector<int>&visit){
        if(visit[i]==0)return;
        visit[i]=0;
        for(auto it :adj[i]){
            dfs2(it,adj,visit);
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int n=adj.size();
        
        vector<int>visit(n,0),finish;
        //time complexity O(V+E)
        for(int i=0;i<n;i++){
            if(visit[i]==0){
                dfs(i,adj,visit,finish);
            }
        }
        //time complexity O(V+E)
        vector<vector<int>>revAdj(n,vector<int>());
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                revAdj[it].push_back(i);
            }
        }
        //time complexity O(V+E)
        int ans=0;
        for(auto it=finish.rbegin();it<finish.rend();it++){
            if(visit[*it]){
                ans++;
                dfs2(*it,revAdj,visit);
            }
        }
        return ans;
        
    }
};