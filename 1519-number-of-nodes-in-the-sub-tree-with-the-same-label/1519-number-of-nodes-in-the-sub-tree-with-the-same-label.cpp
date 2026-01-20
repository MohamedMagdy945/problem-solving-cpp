class Solution {
public:
    vector<int> ans;
    vector<vector<int>> adj;
    string labels;

    vector<int> dfs(int node, int parent) {
        vector<int> count(26, 0);

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            vector<int> childCount = dfs(neighbor, node);
            for (int i = 0; i < 26; i++) {
                count[i] += childCount[i];
            }
        }
        int labelIndex = labels[node] - 'a';
        count[labelIndex]++;
        ans[node] = count[labelIndex];
        return count;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        this->labels = labels;
        ans.resize(n);
        adj.resize(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        return ans;
    }
};