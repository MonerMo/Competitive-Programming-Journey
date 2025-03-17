//
// Created by orabi on 1/2/2025.
//

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //let us start by creating a head pointer to the starting node of our solution list
        ListNode *ansHead = nullptr ;
        ListNode *ansTrack = nullptr ;

        short remaining = 0 ;

        while(l1 || l2){
            //here we check that keep going while we have at least one list we can traverse
            if(l1 && l2){
                //this means that both didn't finish
                short holder = l1->val + l2->val + remaining ;
                remaining = (holder >= 10) ? 1 : 0 ;
                holder = (holder >= 10) ? holder-10 : holder ;
                ListNode *newNode = new ListNode(holder) ;
                if(!ansHead){
                    ansHead = newNode ;
                    ansTrack = ansHead ;
                }else{
                    ansTrack->next = newNode ;
                    ansTrack = newNode ;
                }
                l1 = l1->next ;
                l2 = l2->next ;
            }else if(l1 != nullptr && l2 == nullptr){
                //in this case we may have remaining so we are going to add it to the current number
                short holder = l1->val + remaining ;
                remaining = (holder >= 10) ? 1 : 0 ;
                holder = (holder >= 10) ? holder-10 : holder ;
                ListNode *newNode = new ListNode(holder) ;
                if(!ansHead){
                    ansHead = newNode ;
                    ansTrack = ansHead ;
                }else{
                    ansTrack->next = newNode ;
                    ansTrack = newNode ;

                }
                l1 = l1->next ;
            }else if(l2 != nullptr && l1 == nullptr){
                //in this case we may have remaining so we are going to add it to the current number
                short holder = l2->val + remaining ;
                remaining = (holder >= 10) ? 1 : 0 ;
                holder = (holder >= 10) ? holder-10 : holder ;
                ListNode *newNode = new ListNode(holder) ;
                if(!ansHead){
                    ansHead = newNode ;
                    ansTrack = ansHead ;
                }else{
                    ansTrack->next = newNode ;
                    ansTrack = newNode ;
                }
                l2 = l2->next ;
            }else{
                break ;
            }
        }
        //you need one more check if there are a remaining append it to the end of the list
        if(remaining){
            ListNode *newNode = new ListNode(remaining);
            ansTrack->next = newNode ;
            ansTrack = newNode ;
        }
        return ansHead ;
    }
};