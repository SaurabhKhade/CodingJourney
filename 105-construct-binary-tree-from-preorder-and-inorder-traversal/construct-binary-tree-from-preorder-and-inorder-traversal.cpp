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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int, int> map;
        for (int i=0; i<in.size(); i++) {
            map[in[i]] = i;
        }

        int preIndex = 0;
        return helper(pre, map, preIndex, 0, in.size()-1);
    }

    TreeNode* helper(vector<int>& pre, unordered_map<int, int> &map, int &preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;
        if (inStart == inEnd) {
            return new TreeNode(pre[preIndex++]);
        }

        int preVal = pre[preIndex];
        int inIndex = map[preVal];
        preIndex++;
        TreeNode* left = helper(pre, map, preIndex, inStart, inIndex-1);
        TreeNode* right = helper(pre, map, preIndex, inIndex+1, inEnd);

        return new TreeNode(preVal, left, right);
    }
};