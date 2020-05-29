/**
 * Leetcode 23 Merge k Sorted Lists
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*> > pr;
        for(auto ls: lists)
            if(ls != nullptr)
                pr.emplace( - ls -> val, ls);
        ListNode* head = new ListNode(-1);
        ListNode* current = head;
        while(!pr.empty()){
            auto ls = pr.top().second;
            pr.pop();
            current -> next = new ListNode(ls -> val);
            current = current -> next;
            if(ls -> next != nullptr){
                pr.emplace(- ls->next->val, ls->next);
            }
        }
        return head -> next;
    }
};
