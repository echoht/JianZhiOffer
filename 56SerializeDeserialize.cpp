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

    char* Serialize(TreeNode *root) {    
        // level travel, if null put "#" , untill no new level 
	    // what if val is two or more digits? some char (like a space) used to split node and node
		stringstream ss;
		queue<TreeNode*> q;
		
		if(root == NULL){
			return NULL;
		}
		
		if(root != NULL){
			q.push(root);	
			ss << root->val;
		}
		while(!q.empty()){
			TreeNode *tmp = q.front();
            q.pop();
			if(tmp->left){
				q.push(tmp->left);
				ss << "$";
				ss << tmp->left->val;
			}else{
				ss << "$";
				ss << "#";
			}
			if(tmp->right){
				q.push(tmp->right);
				ss << "$";
				ss << tmp->right->val;
			}else{
				ss << "$";
				ss << "#";
			}
		}
		string s = ss.str();
		char * str = new char[s.size()+1];
		for(int i = 0; i < s.size(); i++){
			str[i] = s[i];
		}
		str[s.size()] = '\0';
		return str;
    }
    TreeNode* Deserialize(const char *str) {
		TreeNode* root = NULL;
		if(str == NULL){
			return root;
		}
		
		int i = 0;	
		
        queue<TreeNode*> q;
		//the first node 
		i = 0;
		int val = 0;
		while(str[i] != '\0' && str[i] != '$'){
			val *= 10;
			val += str[i]-'0';
			i++;
		}
        if(str[i] == '$'){
			i++;
		}
		root = new TreeNode(val);
		q.push(root);
		
		while(str[i] != '\0'){
			int j = i;
			int lval = 0;
			int rval = 0;
			//get node val 
			while(str[j] != '\0' && str[j] != '$'){
				if(str[j] == '#'){
					lval = -1;
					j++;
					break;
				}else{
					lval *= 10;
					lval += str[j]-'0';
					j++;
				}
			}
			if(str[j] == '$'){
				j++;
			}
			// right val 
			while(str[j] != '\0' && str[j] != '$'){
				if(str[j] == '#'){
					rval = -1;
					j++;
					break;
				}else{
					rval *= 10;
					rval += str[j]-'0';
					j++;
				}
			}
			if(str[j] == '$'){
				j++;
			}
			//update i
            i = j;
			TreeNode * tmp = q.front();
			q.pop();
			if(lval != -1){
				tmp->left = new TreeNode(lval);
				q.push(tmp->left);
			}
			if(rval != -1){
				tmp->right = new TreeNode(rval);
				q.push(tmp->right);
			}	 
		}
		return root;
    }
    
int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);

    root->right->left = NULL;//new TreeNode(7);
    root->right->right = new TreeNode(8);
	char * c = Serialize(root);
	std::cout<< c << std::endl;
	int i = 0;
    while(c[i] != '\0'){
        //std::cout<<i<<":"<<c[i]<<std::endl;
        i++;
    }
    std::cout<<Serialize(Deserialize(c));
}
