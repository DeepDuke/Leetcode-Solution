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
private:
    int max_diam = 0;
    int maxHeightOfTree(TreeNode* root){
        if(!root) return 0;
        int leftHeight = maxHeightOfTree(root->left);
        int rightHeight = maxHeightOfTree(root->right);
        max_diam = max(max_diam, leftHeight+rightHeight); // current diameter = number of edges
        
        return max(leftHeight, rightHeight)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxHeightOfTree(root);
        return max_diam;
    }
};