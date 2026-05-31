/*
Given a binary tree, determine if it is height-balanced.

Height- balanced = height of LST - height of RSt <= 1

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/


class Solution { // O(N^2) - because calculating height 2x
public:
    int height(TreeNode* root) {
        if(!root) return 0;

        return max(height(root->left), height(root->right)) +1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        if (abs(height(root->left) - height(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};


// Approach 2: DFS - O(N)

class Solution2 {
public:
    int dfs(TreeNode* root) {
        if (!root) return 0;

        int lh = dfs(root->left);
        if (lh == -1) return -1;

        int rh = dfs(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;

        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};