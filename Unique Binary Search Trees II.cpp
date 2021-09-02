class Solution {
public:
    vector<TreeNode*> generate(int start, int end) {
        if(start > end)
            return {NULL};
        
        if(start == end) {
            return {new TreeNode(start)};
        }
        
        vector<TreeNode*> left, right;
        vector<TreeNode*> result;
        for(int i = start; i<= end; i++) {
            left  = generate(start, i-1);
            right = generate(i+1, end);
            
            for(TreeNode* leftSub : left) {
                for(TreeNode* rightSub : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left  = leftSub;
                    root->right = rightSub;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};
