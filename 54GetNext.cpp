/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
//注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

// 这道题有些意思，很容易输出错误结果。
// 当前节点有以下这些情况：
// 1、有右子树，则当前节点的下一个中序遍历节点是右子树的最左节点;
// 2、无右子树，且当前节点是其父节点的左节点，则下一个中序遍历的节点是当前节点的父节点
// 3、无右子树，且当前节点是其父节点的右节点，则下一个中序遍历的节点需要递归找到，递归到其父节点，其父节点作为新节点，若新节点是新节点的父节点，则最初节点的下一个遍历节点是这个新节点的父节点，否则继续遍历，直到父节点为NULL，这说明最初节点已经是中序遍历的最后一个节点
class Solution {
public:
	//获取pNode的最左边节点
	TreeLinkNode* getLeftMostNode(TreeLinkNode* pNode){
		while(pNode->left != NULL){
			pNode = pNode->left;
		}
		return pNode;
	}
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL){
			return NULL;
		}
		if(pNode->right != NULL){
			return getLeftMostNode(pNode->right);
		}
		while(pNode->next != NULL){
			if(pNode->next->left == pNode){
				return pNode->next;
			}
			pNode = pNode->next;
		}
		return NULL;
		
    }
};
