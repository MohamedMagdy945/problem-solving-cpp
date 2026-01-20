class Solution {
    private:
        int minDiff = INT_MAX ;
        int preVal =  -1 ;
        void Traversal(TreeNode* root , int rootVal)
        {
            if(!root) return ;
        
            Traversal(root-> left , root -> val);
            if(preVal != -1 )
            {
                minDiff= min(minDiff, root -> val - preVal);
            }
            preVal = root -> val ;
            Traversal(root-> right , root -> val);
        }
public:
    int minDiffInBST(TreeNode* root) {
        Traversal(root , -1);
        return minDiff;
    }
};