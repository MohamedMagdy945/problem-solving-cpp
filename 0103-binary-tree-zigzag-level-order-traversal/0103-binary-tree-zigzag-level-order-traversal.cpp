/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root)
        {
            if (!root) return {} ;
            vector<vector<int>> result ;
            vector<int> path ;
            queue<TreeNode*> q ;
            bool left = false ;
            q.push(root);
            int j = 0 ;
            while(!q.empty())
            {
                int size = q.size();
                for (int i = 0 ; i < size ; i++)
                {
                    TreeNode* node= q.front();
                    q.pop();
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                    if (result.size() <= j) {
                        result.push_back(vector<int>()); 
                    }
                    result[j].push_back(node -> val) ;
                }
                if(left)
                    reverse(result[j].begin(), result[j].end());
                left = !left;
                j++;
            }
            return result ;
        }
};