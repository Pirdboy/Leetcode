//Title:Path Sum
//二叉树的DFS，注意根节点为空的情况
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL){
            return false;
        }
        else if(root->left!=NULL && root->right!=NULL){
            bool ok1=hasPathSum(root->left,sum-root->val);
            bool ok2=hasPathSum(root->right,sum-root->val);
            return ok1|ok2;
        }
        else if(root->left!=NULL && root->right==NULL){
            return hasPathSum(root->left,sum-root->val);
        }
        else if(root->left==NULL && root->right!=NULL){
            return hasPathSum(root->right,sum-root->val);
        }
        else if(root->left==NULL && root->right==NULL){
            if(root->val==sum)
                return true;
            else
                return false;
        }
    }
};
