using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head -> next) return head;
        ListNode* root = head -> next;
        
        ListNode* next = head -> next;
        
        head -> next = next -> next;
        next -> next = head;
        head = head -> next;
        
        while (head && next){
            ListNode *record = next -> next;
            next = head -> next;
            
            if (!next) break;
            head -> next = next -> next;
            next -> next = head;
            record -> next = next;
            head = head -> next;
        }
        
        return root;
    }
};