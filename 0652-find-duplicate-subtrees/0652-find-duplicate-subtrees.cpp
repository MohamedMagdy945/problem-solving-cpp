class Solution{
    private:
    unordered_map<string, int> subTrees;
    vector<TreeNode*> subTreeNodes;
    string Traversal(TreeNode* root)
    {
        if(!root)
            return "#";
        
        string subTree = to_string(root->val) + "#" + Traversal(root->left) + "#" + Traversal(root-> right);
        
        if(subTrees[subTree]++ == 1)
        {
            subTreeNodes.push_back(root);
        }
        return subTree ;
    }
    public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        Traversal(root);
        return subTreeNodes;
    }
};