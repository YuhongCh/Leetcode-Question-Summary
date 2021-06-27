struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Used to reverse [front, end]
    void reverse_k_nodes(ListNode* front, ListNode* end, int k){
        ListNode* next = front -> next;
        front -> next = end -> next;
        
        for (k = k - 1; k; k--){
            end = next -> next;
            next -> next = front;
            front = next;
            next = end;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* ans = head;
        ListNode* end = head;
        ListNode* record = nullptr;
        

        while (end){
            // get end pointer to end of k elements
            for (int i = 1; i < k || !end; i++){
                if (end -> next) end = end -> next;
                else return ans;
            }
            reverse_k_nodes(head, end, k);
            
            // reconnect the pointers together
            if (record) record -> next = end;
            else ans = end;
            record = head;
            
            head = head -> next;
            end = head;
        }
        
        return ans;
    }
};