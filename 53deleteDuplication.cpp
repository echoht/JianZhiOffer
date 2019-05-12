//
//  permutations2_47.cpp
//  LeetcodeByEcho
//
//  Created by Dylan326 on 2019/5/4.
//  Copyright © 2019 DE. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {
    }
};
ListNode* deleteDuplication(ListNode* pHead)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next = pHead;
    ListNode *fast = pHead;
    ListNode *slow = dummy;
    while(true){
        int dup = 0;
        while(fast != NULL && fast->next != NULL && fast->val == fast->next->val){
            fast = fast->next;
            dup++;
        }
        if(dup == 0 ){
            slow->next = fast;
            slow = fast;
            if(fast != NULL)
                fast = fast->next;
        }else{
            if(fast != NULL)
                fast = fast->next;
        }
        if(fast == NULL){
            if(slow != NULL)
                slow->next = NULL;
            break;
        }
        
    }
    return dummy->next;
}
int main(){
    ListNode* head = NULL ;
    ListNode* tmp;
    /*= new ListNode(1);
    ListNode* tmp = head;
    int a[] = {1,1,3,3,4,4,5};
    for(int i = 1; i < 7; i ++){
        tmp->next = new ListNode(a[i]);
        tmp = tmp->next;

    }
    //tmp->next = head;
    // print
    tmp = head;
    for(int i = 0; i < 7; i++){
        std::cout<< tmp->val;
        tmp = tmp->next;
    }
    */
    std::cout<<std::endl;
    tmp = deleteDuplication(head);
    
    while(tmp != NULL){
        std::cout<< tmp->val;
        tmp = tmp->next;
    }
}
