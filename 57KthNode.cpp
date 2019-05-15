#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};
	
	void fn(TreeNode * pRoot, int &nodeNum, TreeNode *&target, int k){
		if(pRoot == NULL){
			return ;
		}
		fn(pRoot->left, nodeNum, target, k);
		pRoot;
		nodeNum++;
		if(nodeNum == k){
			target = pRoot;
			return;
		}
		fn(pRoot->right, nodeNum, target, k);
	}
        
	// mid-order to find the k'th node 
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
		TreeNode* res= NULL;
		int num = 0;
        fn(pRoot, num, res, k);
		
        return res;
    }
    
int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
	
	TreeNode* tmp = KthNode(root,8);
    if(tmp == NULL){
        std::cout<<"null";
    }
    else
    std::cout<<tmp->val;
}
