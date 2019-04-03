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
    TreeNode* reConstructBinaryTreeImp(vector<int> &pre, int pleft, int pright,vector<int> &vin, int vleft, int vright) {
		//base situation
		int nodes_num = pright-pleft+1;
		if(nodes_num != vright - vleft + 1){
			std::cout<<"input error"<<std::endl;
			return NULL;
		}
		if(nodes_num <= 0){
			return NULL;
		}
		if(nodes_num == 1){
			TreeNode *node = new TreeNode(pre[pleft]);
			return node;
		}
		//divide and conque
		TreeNode *root = new TreeNode(pre[pleft]); //root 
		//find the left sub tree nodes val here 
		int left_sub_tree_nodes_num = 0;
		for(int i = vleft; i <= vright; i++){
			if(vin[i] != pre[pleft]){
				left_sub_tree_nodes_num ++;
			}else{
				break;
			}
		}
		TreeNode *left_tree = reConstructBinaryTreeImp(pre, pleft+1, pleft + left_sub_tree_nodes_num, vin, vleft, vleft+left_sub_tree_nodes_num-1);
		TreeNode *right_tree = reConstructBinaryTreeImp(pre, pleft + left_sub_tree_nodes_num+1, pright, vin, vleft+left_sub_tree_nodes_num+1, vright);
		root->left = left_tree;
		root->right = right_tree;
		return root;
	}
	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		return reConstructBinaryTreeImp(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }
};
