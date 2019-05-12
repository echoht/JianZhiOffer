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
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    ListNode* slow = pHead;
    ListNode* fast = pHead;
    //is slow and fsat can meet
    int ts = 0;
    while(true){
        if(fast == NULL){
            return nullptr;
        }
        slow = slow->next;
        fast = fast->next;
        if(fast == NULL){
            return nullptr;
        }
        fast = fast->next;
        ts++;
        if(slow == fast){ //fast meet with slow
            std::cout<<slow->val << " " << fast->val << " " << std::endl;
            break;
        }
    }
    int cicle = 0;
    int delta = 1;
    //while(delta <= ts){
        if (ts%delta == 0){
            int n=0;
            cicle = ts/delta;
            std::cout<<"cicle sz is" << cicle << ", total ts is" << ts << ", delta is" << delta << std::endl;
            // fast slow
            slow = pHead;
            fast = pHead;
            int i = 0;
            while(i++ < cicle){
                fast = fast->next;
            }
            
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
                 n++;
            }
            std::cout<< "cicle entry is" << slow->val << std::endl;
        }
        //delta++;

    //}
    return slow;
}
int main(){
    ListNode* head = new ListNode(0);
    ListNode* tmp = head;
    for(int i = 1; i < 10; i ++){
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    tmp->next = head;
    // print
    tmp = head;
    for(int i = 0; i < 10; i++){
        std::cout<< tmp->val;
        tmp = tmp->next;
    }
    EntryNodeOfLoop(head);
}
