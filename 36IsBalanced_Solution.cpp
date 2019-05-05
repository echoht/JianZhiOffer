#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>

using namespace std;
//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
//任何节点的两个子树之间的深度差值小于等于1
struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int v):val(v), left(NULL), right(NULL){} 
};

bool depth(TreeNode* node, int dep, int &res){
	if(node == NULL){
		res = dep;
		return true;
	}
	int resl, resr;
	bool r1, r2;
	r1 = depth(node->left, dep+1, resl);
	r2 = depth(node->right, dep+1, resr);
	res = resl > resr ? resl : resr;

    if(r1 == false || r2 == false){
		return false;
	}
	if(abs(resl - resr) > 1) {
		return false;
	}
	return true;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
	int res=0;
	return depth(pRoot, 0, res);		
}

TreeNode* construct_tree(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    return root;
}

int main(){
    TreeNode* root = construct_tree();

    std::cout<<IsBalanced_Solution(root);
}
