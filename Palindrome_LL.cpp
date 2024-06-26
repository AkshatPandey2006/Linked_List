class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //find the middle element
        ListNode *slow = head, *fast = head;
        while(fast != NULL and fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        //if nodes are odd then move slow one point
        if(fast != NULL and fast -> next == NULL) {
            slow = slow -> next;
        }

        //reverse the end half
        ListNode *prev = NULL;
        ListNode *temp = NULL;
        while(slow != NULL and slow -> next != NULL) {
            temp = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = temp;
        }

        if(slow != NULL) {
            slow -> next = prev;
        }

        //compare the first and second half
        fast = head;
        while(slow and fast) {
            if(slow -> val != fast -> val) {
                return false;
            }
            slow = slow -> next;
            fast = fast -> next;
        }
        return true;
    }
};
