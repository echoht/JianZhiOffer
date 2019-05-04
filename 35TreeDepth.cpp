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
    void bfs(TreeNode* node, int depth, int &max){
        if(node == NULL){
            if(depth > max){
                max = depth;
            }
            return;
        }
        
        bfs(node->left, depth+1, max);
        bfs(node->right, depth+1, max);
        return;
    }
    int TreeDepth(TreeNode* pRoot)
    {
        int max = 0;
        bfs(pRoot, 0, max);
        return max;
    }
};
