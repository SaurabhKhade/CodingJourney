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
    int depthFromTarget = 0;
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, TreeNode*> parents;
        unordered_map<int, bool> visited;
        TreeNode* startNode = traverse(root, start, parents);

        queue<pair<TreeNode*, int>> q;
        q.push({startNode, 0});
        visited[start] = true;
        int mxTime = 0;

        while (!q.empty()) {
            pair<TreeNode*, int> front = q.front();
            q.pop();

            cout<<front.first->val<<" "<<front.second<<endl;

            mxTime = max(mxTime, front.second);

            if (front.first->left != NULL && !visited[front.first->left->val]) {
                q.push({front.first->left, front.second+1});
                visited[front.first->left->val] = true;
            }
            if (front.first->right != NULL && !visited[front.first->right->val]) {
                q.push({front.first->right, front.second+1});
                visited[front.first->right->val] = true;
            }
            if (parents[front.first->val] != NULL && !visited[parents[front.first->val]->val]) {
                q.push({parents[front.first->val], front.second+1});
                visited[parents[front.first->val]->val] = true;
            }
        }

        return mxTime;
    }

    TreeNode* traverse(TreeNode* root, int start, unordered_map<int, TreeNode*> &parents) {
        TreeNode *onLeft = NULL, *onRight = NULL;

        if (root->left != NULL) {
            parents[root->left->val] = root;
            onLeft = traverse(root->left, start, parents);
        }
        if (root->right != NULL) {
            parents[root->right->val] = root;
            onRight = traverse(root->right, start, parents);
        }

        if (onLeft != NULL) return onLeft;
        if (onRight != NULL) return onRight;
        if (root->val == start) return root;
        return NULL;
    }
};