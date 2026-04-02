/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return head;

        Node* curr = head;

        while(curr !=NULL){
            if(curr->child != NULL){
                // 1. Flatten child nodes
                Node* nxt = curr->next;
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = NULL;

                //2.Find tail 
                while(curr->next != NULL) curr = curr->next;

                //3.Attach tail with nxt ptr
                if(nxt != NULL){
                    curr->next = nxt;
                    nxt->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};