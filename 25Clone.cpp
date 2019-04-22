#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
//返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        map<int, RandomListNode> s;
		RandomListNode* tmp = pHead;
		RandomListNode* newHead = NULL;
		//first create all nodes and store them in s
		while(tmp != NULL){
			RandomListNode* t = new RandomListNode(tmp->label);
			if(s.find(tmp->label) != s.end()){
				std::cout<< tmp->label << "has appeared before" << std::endl;
			}
			s[tmp->label] = t;
			tmp = tmp->next;
		}
		tmp = pHead;
		RandomListNode* tmp2;
		while(tmp != NULL){
			if(newHead == NULL){
				newHead = s[tmp->label];
				tmp2 = newHead;
			}
			if(tmp->next != NULL){
				tmp2->next = s[tmp->next->label]
			}
			if(tmp->random != NULL){
				tmp2->random = s[tmp->random->label]
			}
			tmp2 = tmp2->next;
		}
		return newHead;
    }
	// 参考讨论区代码
	// 1 挨个复制每个节点A的A1， 然后把A1挂载A的next指针上
	// 2 A1->random = A->random->next
	// 3 拆分两个链表
	
	RandomListNode* Clone2(RandomListNode* pHead)
    {
        RandomListNode* tmp = pHead;
		RandomListNode* newHead = NULL;
		// step 1 
		while(tmp != NULL){
			RandomListNode* t = new RandomListNode(tmp->label);
			t->next = tmp->next;
			tmp->next = t;
			tmp = t->next;
		}
		// step 2 
		tmp = pHead;
		while(tmp != NULL){
			RandomListNode* t = tmp->next;
			if(tmp->random != NULL){
				t->random = tmp->random->next;
			}
			tmp = t->next;
		}
		// step 3 
		tmp = pHead;
		while(tmp != NULL){
			RandomListNode* t = tmp->next;
			if(newHead == NULL){
				newHead = tmp->next;
			}
			tmp->next = t->next;
			if(tmp->next != NULL){
				t->next = tmp->next->next;
			}else{
				t->next = NULL;
			}
			tmp = tmp->next;
		}
		return newHead;
    }
};
