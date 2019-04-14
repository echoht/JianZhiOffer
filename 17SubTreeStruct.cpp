/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool isSubStructFromRoot(TreeNode* A, TreeNode* B){
        //base situation here 
        if(B == NULL){
            return true;
        }
        if(A == NULL){
            return false;
        }
        if(B->val == A->val){
            return isSubStructFromRoot(A->left, B->left) && isSubStructFromRoot(A->right, B->right);            
        }
        return false;
    }
    
    // 用递归 遍历 看B是否是节点A的， 是否是A的左子树的子结构，是否是A的右子树的子结构
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        //base 
        if(pRoot1==NULL || pRoot2 == NULL){
            return false;
        }
        bool ret;
        if(pRoot2->val == pRoot1->val){
            ret = isSubStructFromRoot(pRoot1, pRoot2);
        }
        if(ret == true){
            return true;
        }
        return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};
