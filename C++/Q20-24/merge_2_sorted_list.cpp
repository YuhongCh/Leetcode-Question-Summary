#include <algorithm>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1 -> val > l2 -> val)
            swap(l1, l2);
        
        ListNode *start = l1;
        ListNode *result = l1;
        l1 = l1 -> next;
        
        for (; l1 && l2; result = result -> next){
            if (l1 -> val < l2 -> val){
                result -> next = l1;
                l1 = l1 -> next;
            }
            else{
                result -> next = l2;
                l2 = l2 -> next;
            }
        }
        
        if (l1) result -> next = l1;
        else if (l2) result -> next = l2;
        return start;
    }
};