class Solution {
public:
    unordered_map<int, int> isVisited;

    vector<vector<int>> matrixToAdjList(const vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (i != j && matrix[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }

        return adj;
    }

    void dfs(int node, vector<vector<int>>& adjList) {
        isVisited[node] = 1;

        for (int neighbor : adjList[node]) {
            if (!isVisited[neighbor]) {
                dfs(neighbor, adjList);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjList = matrixToAdjList(isConnected);

        int provinces = 0;

        for (int i = 0; i < adjList.size(); i++) {
            if (!isVisited[i]) {
                provinces++;
                dfs(i, adjList);
            }
        }

        return provinces;
    }
};