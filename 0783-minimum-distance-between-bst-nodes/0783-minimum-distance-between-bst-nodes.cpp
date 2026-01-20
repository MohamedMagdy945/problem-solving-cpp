class Solution {
private:
    vector<int> vec ;
    void Traversal(TreeNode* root)
    {
        if(!root) return ;
        vec.push_back(root->val);
        Traversal(root-> left);
        Traversal(root-> right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        Traversal(root);
        sort(vec.begin() , vec.end());
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