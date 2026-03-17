/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Size of LL
        int n = 1;
        if (head == NULL) return head; 
        ListNode* last = head;
        while(last->next){
            n++;
            last = last->next;
        }
        k = k % n;
        ListNode* curr = head;
        //Reach at (size-k) in 1 based indexing
        for(int i=1 ;i < n-k; i++){
            curr = curr->next;
        }

        last->next = head;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};