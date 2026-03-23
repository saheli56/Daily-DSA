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
    int maxPathSum(TreeNode* root) {
        helper(root);// Call the helper function to compute the maximum path sum starting from the root node. The helper function will update the 'ans' variable with the maximum path sum found during the traversal of the tree.
        return ans;
    }
    int ans= INT_MIN; // Initialize 'ans' to the smallest possible integer value to ensure that any valid path sum will be greater than this initial value.
    int helper(TreeNode* node){
    if(!node) return 0;
    int left = max(helper(node->left),0); // Recursively compute the maximum path sum for the left subtree. If the computed sum is negative, we take 0 instead, as a negative path sum would not contribute to a maximum path sum.
    int right = max(helper(node->right),0);// Recursively compute the maximum path sum for the right subtree, applying the same logic as for the left subtree.
    ans= max(ans, node->val+left+right);// Update the 'ans' variable with the maximum path sum found so far, which includes the current node's value and the maximum contributions from both left and right subtrees.
    return node->val+ max(left,right);// Return the maximum path sum that can be extended to the parent node, which is the current node's value plus the maximum of the left and right contributions. This allows the path to continue upwards in the tree.
}
};
// Time Complexity: O(N), where N is the number of nodes in the binary tree. This is because we visit each node exactly once during the traversal.
// Space Complexity: O(H), where H is the height of the binary tree. In the
