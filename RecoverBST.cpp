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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;
    void recoverTree(TreeNode* root) {
        Traversal(root);
        swap(first-> val, second-> val); // swap the values of the two nodes that are out of order
    }
    void Traversal(TreeNode* root){
        if(!root) return; 
        Traversal(root->left);
        
        if (prev && root->val < prev->val) {
            if (!first) first = prev; // store the first node that is out of order
            second = root;
        }
        prev = root;

        Traversal(root->right); // traverse the right subtree
    }
};
// Time Complexity: O(N) where N is the number of nodes in the BST
// Space Complexity: O(H) where H is the height of the BST due to the recursive