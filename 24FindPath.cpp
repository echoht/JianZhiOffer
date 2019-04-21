/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

bool myfunction (vector<int> i,vector<int> j) { return i.size() > j.size(); }

class Solution {
public:
    void FindPathImp(TreeNode* root, vector<int> &path, int num,
                     vector< vector<int> > &res, int exp){
        //base situation
        if(root == NULL){
            return ;
        }
        if(root->left == NULL && root->right == NULL){
            num += root->val;
            if( num == exp){
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        num += root->val;
        if(root->left != NULL){
            FindPathImp(root->left, path, num, res, exp);
        }
        if(root->right != NULL){
            FindPathImp(root->right, path, num, res, exp);
        }
        path.pop_back(); 
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int> path;
        vector<vector<int>> res;
        FindPathImp(root, path, 0, res, expectNumber );
        //sort 
        sort(res.begin(), res.end(), myfunction);
        return res;
    }
};
