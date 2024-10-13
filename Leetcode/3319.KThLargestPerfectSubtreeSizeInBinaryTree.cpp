class Solution {
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> heights;
        findSubtrees(root, heights);

        if (heights.size() < k) return -1;
        sort(heights.begin(), heights.end(), greater<int>());
        return heights[k-1];
    }

    int findSubtrees(TreeNode* root, vector<int> &heights) {
        if (root == NULL) return -1;
        if (root->left == NULL && root->right == NULL) {
            heights.push_back(1);
            return 1;
        }

        int leftHeight = findSubtrees(root->left, heights);
        int rightHeight = findSubtrees(root->right, heights);

        if (leftHeight == rightHeight && leftHeight != -1) {
            heights.push_back(2*rightHeight+1);
            return 2*rightHeight+1;
        }
        return -1;
    }
};