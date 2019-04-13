/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    // what if k is larger then list size? return NULL?
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *tmp, *first;
        tmp = pListHead;
        first = pListHead;
        // first point go first k step 
        while(k > 0 && first != NULL){
            first = first->next;
            k--;
        }
        // k is larger then list size
        if(k > 0){
            return NULL;
        }
        while(first != NULL){
            first = first->next;
            tmp = tmp->next;
        }
        return tmp;
    }
};
