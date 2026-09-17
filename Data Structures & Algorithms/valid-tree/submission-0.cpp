class Solution {
public:
    bool isCycle(int node, int par,vector<vector<int>>&adj,vector<int>&vis){
        vis[node] = 1;
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                bool ans = isCycle(nbr,node,adj,vis);
                 if(!ans)return false;
            }
            else if(par != nbr)return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        int cnt = 0;
        vector<int>vis(n,0);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                if(!isCycle(i,-1,adj,vis))return false;
                cnt++;
            }
        }
        if(cnt > 1)return false;
        return true;
    }
};
