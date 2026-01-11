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
    vector<string> path;
    void Traversal(TreeNode* node,string s)
    {
        if(!node) return ;

        if(!node->left && !node->right)
        {
            s += to_string(node->val);
            path.push_back(s);
            return ;
        }
        s += to_string(node->val) + "->";
        Traversal(node->left, s);
        Traversal(node->right, s);
    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        if(!root) return path;
        Traversal(root,"");
        return path;
    }
};