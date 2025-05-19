#include <bits/stdc++.h>

using namespace std;
class DisjointSetUnion {
private:
    vector<int> parent, rank,size;
public: 
    DisjointSetUnion(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
                size[rootX] += size[rootY];
            }
        }
    }

    void unionBySize(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return;
        }
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    }
};

int main(){

    DisjointSetUnion dsu(10);
    dsu.unionBySize(1, 2);
    dsu.unionBySize(2, 3);
    dsu.unionBySize(4, 5);
    dsu.unionBySize(6, 7);
    dsu.unionBySize(7, 8);
    dsu.unionBySize(8, 9);
    if(dsu.find(1) == dsu.find(9)){
        cout << "In same set" << endl;
    }else{
        cout << "Not in same set" << endl;
    }
    dsu.unionBySize(1, 4);
    dsu.unionBySize(5, 6);
    if(dsu.find(1) == dsu.find(9)){
        cout << "Already in the same set" << endl;
    }else{
        cout << "Not in same set" << endl;
    }
    //what is the time complexity of this algorithm?
    // The time complexity of the union-find algorithm with path compression and union by size is nearly constant,  
    return 0;
}