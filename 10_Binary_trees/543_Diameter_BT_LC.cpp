/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Example 1:

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:

Input: root = [1,2]
Output: 1

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
*/

//////////// Solution 1: O(N^2)
/*
    Calculate 3 ways:
    1. left diameter
    2. right diameter
    3. Root diameter : height of LSt + height RST
*/

class Solution1{
public:
    int height(TreeNode* root) {
        if(!root) return 0;

        return max(height(root->left), height(root->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int leftDia = diameterOfBinaryTree(root->left);
        int rightDia = diameterOfBinaryTree(root->right);
        int rootDia = height(root->left) + height(root->right);

        return max(rootDia, max(leftDia, rightDia));
    }
};

//////////// Solution 2: O(N) :Using global ans variable
/*
    Calculate 3 things:
    1. left height
    2. right height
    3. Root diameter : height of LSt + height RST (or curr diameter)
*/

class Solution2 {
public:
    int ans = 0;
    int height(TreeNode* root) {
        if(!root) return 0;
        int leftHt = height(root->left);
        int rightHt = height(root->right);

        ans = max(ans, leftHt + rightHt);

        return max(leftHt, rightHt) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        height(root);

        return ans;
    }
};


//////////// Solution 3: O(N) :Using pair
/*
    Calculate 3 ways:
    1. left diameter
    2. right diameter
    3. Root diameter : height of LSt + height RST
*/

class Solution3 {
public:
    pair<int, int> diameter(TreeNode* root) {
        pair<int, int> p;
        if(!root) {
            p.first = p.second = 0;
            return p;
        }
            
        pair<int, int> left = diameter(root->left);
        pair<int, int> right = diameter(root->right);

        p.first = max(left.first, right.first) +1;

        int op1 = left.first + right.first;
        int op2 = left.second;
        int op3 = right.second;

        p.second = max(op1, max(op2, op3));

        return p;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> p;
        p = diameter(root);
        return p.second;
    }
};


