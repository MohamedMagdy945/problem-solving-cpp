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
    
vector<int> order;
void Traversal(TreeNode* root)
{
    if (!root) return ; 
    order.push_back(root-> val);
    Traversal(root-> left);
    Traversal(root-> right);
}
vector<int> preorderTraversal(TreeNode* root) {
    Traversal(root);
    return order;
}

};