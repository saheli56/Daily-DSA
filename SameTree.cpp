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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true; // If both nodes are null, they are the same.
        if(!p || !q) return false;// If one of the nodes is null and the other is not, they are not the same.
        return p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right); // Check if the current nodes have the same value and recursively check the left and right subtrees.
    }
};
// Time Complexity: O(N), where N is the number of nodes in the binary trees. This is because we visit each node exactly once to compare them.
// Space Complexity: O(H), where H is the height of the binary trees. In the
