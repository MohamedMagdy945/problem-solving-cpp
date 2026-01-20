class Solution {
private:
    vector<int> vec ;
    void Traversal(TreeNode* root)
    {
        if(!root) return ;
        Traversal(root-> left);
        vec.push_back(root->val);
        Traversal(root-> right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        Traversal(root);
        int minDiff= INT_MAX ;
        for(int i=1 ; i < vec.size() ; i++)
        {
            int diff = vec[i] - vec[i -1];
            if(minDiff  > diff)
            {
                minDiff = diff ;
            }
        }
        return minDiff;
    }
};