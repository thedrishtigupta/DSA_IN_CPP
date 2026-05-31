/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.
*/



//Binary Tree Method
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;

        if(root->val == p->val || root->val == q->val) return root;

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if(leftLCA && rightLCA) return root;
        else if (leftLCA) return leftLCA;
        else return rightLCA;
    }
};


class Solution {
public:
    TreeNode* find_lca(TreeNode*r, TreeNode* p, TreeNode* q){
        if(r->val < p->val) return find_lca(r->right, p , q);
        if(r->val > q->val) return find_lca(r->left, p , q);
        return r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)swap(p, q);
        return find_lca(root, p, q);
    }
};