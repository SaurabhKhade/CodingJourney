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
    bool isValidBST(TreeNode* root) {
        long last = -1e11;
        return isValidBST(root, last);
    }

    bool isValidBST(TreeNode* root, long& last) {
        if (root == NULL) return true;

        bool isLeftSubtreeValid = isValidBST(root->left, last);

        if (isLeftSubtreeValid && root->val > last) {
            last = root->val;
            return isValidBST(root->right, last);
        }

        return false;
    }
};