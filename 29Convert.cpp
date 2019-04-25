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
   //find the max node in left sub tree , left point into the node   
	//root is already the left sub tree
	TreeNode* leftMaxNode(TreeNode * root){
		if(root == NULL){
			return NULL;
		}
		if(root->right == NULL){
			return root;
		}
		return leftMaxNode(root->right);
	}
	// find the min node in right sub tree, right point into the node
	//root is already the right sub tree
	TreeNode* rightMinNode(TreeNode * root){
		if(root == NULL){
			return NULL;
		}
		if(root->left == NULL){
			return root;
		}
		return rightMinNode(root->left);
	}
	
	TreeNode* conv(TreeNode* root){
		if(root == NULL){
			return NULL;
		}
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		TreeNode* lmn = leftMaxNode(left);
		TreeNode* rmn = rightMinNode(right);
		
        if(root->left == NULL || root->left->right == root){
            //nothing 
            ;
        }else{
            root->left = lmn;
			lmn->right = root;
			conv(left);
            
        }
        if(root->right == NULL || root->right->left == root){
            //nothing
            ;
        }else{
            root->right = rmn;
			rmn->left = root;
			conv(right);
        }
		return root;
	}
	
    //方法二 中序遍历  注意参数pre是指针引用
	void ConvertImp(TreeNode* root, TreeNode*& pre){
		if(root == NULL){
			return ;
		}
		ConvertImp(root->left, pre);
		root->left = pre;
		if(pre != NULL)
			pre->right = root;
		pre=root;
		ConvertImp(root->right, pre);
	}
	
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* tmp = conv(pRootOfTree);
        while(tmp!= NULL &&　tmp->left != NULL){
			tmp = tmp->left;
		}
		return tmp;
    }
};
