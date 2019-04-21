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
    // using queue
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector< TreeNode* > q;
        vector<int> res;
        int idx = 0;
        if(root != NULL){
            q.push_back(root);
        }else{
            return res;
        }
        while(idx < q.size()){
            res.push_back(q[idx]->val);
            if(q[idx]->left != NULL){
                q.push_back(q[idx]->left);
            }
            if(q[idx]->right != NULL){
                q.push_back(q[idx]->right);
            }
            idx++;
        }
        return res;
    }
};
