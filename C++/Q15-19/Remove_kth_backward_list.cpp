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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* result = head;
        ListNode* prev = head;
        
        while (n){
            head = head -> next;
            n--;
        }
        
        if (!head){
            return result -> next;
        }
        
        for (; head -> next; head = head -> next){
            prev = prev -> next;
        }
        
        prev -> next = prev -> next -> next;
        return result;   
    }
};