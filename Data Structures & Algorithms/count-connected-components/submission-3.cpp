class DisjointSet {
public:

    vector<int> par;
    vector<int> size;

    DisjointSet(int n) {
        par.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int findUltPar(int node) {
        if(node == par[node])
            return node;

        return par[node] = findUltPar(par[node]);
    }

    void unionBySize(int u, int v) {

        int ult_u = findUltPar(u);
        int ult_v = findUltPar(v);

        if(ult_u == ult_v)
            return;

        if(size[ult_u] > size[ult_v]) {
            par[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        else {
            par[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
    }
};

class Solution {
public:

    int countComponents(int n, vector<vector<int>>& edges) {

        DisjointSet ds(n);

        int cnt = n;

        for(auto it : edges) {

            int u = it[0];
            int v = it[1];

            int ult_u = ds.findUltPar(u);
            int ult_v = ds.findUltPar(v);

            if(ult_u != ult_v) {

                ds.unionBySize(u, v);
                cnt--;
            }
        }

        return cnt;
    }
};