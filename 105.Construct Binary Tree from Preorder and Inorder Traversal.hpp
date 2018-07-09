#include <vector>
#include <algorithm>
using std::find;
using std::vector;
//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() > 1) {
            TreeNode* root = new TreeNode(preorder[0]);
            auto rootInInorder = find(inorder.begin(), inorder.end(), root->val);
            vector<int> leftInOrder = vector<int>(inorder.begin(), rootInInorder);
            vector<int> rightInOrder = vector<int>(rootInInorder + 1, inorder.end());
            vector<int> leftPreOrder = vector<int>(preorder.begin() + 1, preorder.begin() + leftInOrder.size() + 1);
            vector<int> rightPreOrder = vector<int>(preorder.begin() + leftInOrder.size() + 1,preorder.begin() + leftInOrder.size() + 1 + rightInOrder.size());
            root->left = this->buildTree(leftPreOrder, leftInOrder);
            root->right = this->buildTree(rightPreOrder, rightInOrder);
            return root;
        } else if (preorder.size() == 1) {
            return new TreeNode(preorder[0]);
        } else {
            return NULL;
        }
    }
};