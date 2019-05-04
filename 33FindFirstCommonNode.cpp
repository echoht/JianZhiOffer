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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        
        //先分别求出两个链表的长度
        int  n = 0, m = 0;
        ListNode *tmp1 = pHead1, * tmp2 = pHead2;
        while(tmp1!=nullptr){
            n++;
            tmp1 = tmp1->next; 
        }
        while(tmp2!=nullptr){
            m++;
            tmp2 = tmp2->next; 
        }
        if(n == 0 || m == 0){
            return NULL;
        }
        tmp1 = pHead1;
        tmp2 = pHead2;
        if(m > n){
            tmp1 = pHead2;
            tmp2 = pHead1;
        }
        // tmp1 先走|m-n|
        int gofirst = abs(m-n);
        int i = 0;
        while(i++ < gofirst){
            tmp1 = tmp1->next;
        }
        //tmp1 和 tmp2一起走
        while(tmp1 != tmp2){
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        return tmp1;
    }
};
