#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
//请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
// 非递归实现方法 注意空节点也很关键，可以起到判断是否结构对称的作用
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
		vector<TreeNode*> ql, qr; //keep the val， used as queue
		int tmpl=0, tmpr=0, last, start;
		if(pRoot == NULL){
			return true;
		}
		if(pRoot->left){
			tmpl = 1;
			ql.push_back(pRoot->left);
		}
		if(pRoot->right){
			tmpr = 1;
			qr.push_back(pRoot->right);
		}
	    	
		start = 0;
	
		while(true){
			//check last level is symm
			if(tmpl ==0 && tmpr == 0){
				return true;
			}
			if(tmpl != tmpr){
				return false;
			}
            last = tmpl;
			for(int i = start, j = start+last-1; i< start+last; i++, j--){
				if(ql[i]==NULL && qr[i]==NULL){
					continue;
				}
				if((ql[i]==NULL && qr[i]!=NULL) || (ql[i]!=NULL && qr[i]==NULL)){
					return false;
				}
				if(ql[i]->val != qr[j]->val){
					return false;
				}
			}
			// push the next level into each queue
			tmpl = 0, tmpr=0;
			for(int i = start; i < start+last; i++){
				//left 
				if(ql[i]){
					ql.push_back(ql[i]->left);
					//if(ql[i]->left)
						tmpl++;	
					ql.push_back(ql[i]->right);
					//if(ql[i]->right)
						tmpl++;
				}
				
				//right
				if(qr[i]){
					qr.push_back(qr[i]->left);
					//if(qr[i]->left)
						tmpr++;	
					qr.push_back(qr[i]->right);
					//if(qr[i]->right)
						tmpr++;
				}	
			}
			//update start
			start = start+last;
		}
    }

};
int main(){
    TreeNode* root = new TreeNode(2);
    std::cout<<isSymmetrical(root);
}
