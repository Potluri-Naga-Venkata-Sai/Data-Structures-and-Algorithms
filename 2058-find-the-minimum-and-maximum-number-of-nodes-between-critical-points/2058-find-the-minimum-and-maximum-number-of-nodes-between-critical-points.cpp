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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result = {-1, -1};
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
            return result;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;
        int first = -1;
        int last = -1;

        int min_dist = INT_MAX;

        while(curr->next != nullptr){

            bool is_critical = (curr-> val > prev->val && curr->val > curr->next->val) ||
            (curr->val < prev->val && curr->val < curr->next->val);

            if(is_critical){
                if(first == -1){
                    first = index;
                }else{
                    min_dist = min(min_dist, index - last);
                }
                last = index;
            }
            prev = curr;
            curr = curr->next;
            index++;
        }
        if(first == -1 || first == last){
            return result;
        }
        int max_dist = last - first;
        result[0] = min_dist;
        result[1] = max_dist;

        return result;
    }
};