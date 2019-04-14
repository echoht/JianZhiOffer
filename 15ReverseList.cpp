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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* newHeadTmp = new ListNode(-1);
        ListNode* tmp = pHead;
        while(tmp != NULL){
            ListNode* next = newHeadTmp->next;
            newHeadTmp->next = tmp;
            tmp = tmp->next;
            newHeadTmp->next->next = next;
        }
        tmp = newHeadTmp->next;
        delete newHeadTmp;
        
        return tmp;
    }
};
