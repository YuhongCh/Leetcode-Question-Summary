#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class comp{
    public:
    bool operator()(const ListNode *n1, const ListNode *n2){
        return n1 -> val > n2 -> val;
    }
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
		
        int size = lists.size();
        ListNode *start = new ListNode();
        ListNode * result = start;
		
        priority_queue<ListNode*, vector<ListNode*>, comp>queue;
        for (int i = 0; i < size; i++){
            if (lists[i])
                queue.push(lists[i]);
        }
        while (!queue.empty()){
            ListNode* top = queue.top();
            queue.pop();
            start -> next = top;
            start = start -> next;
            top = top -> next;
            if (top)
                queue.push(top);
        }
        
        return result -> next;
    }
};