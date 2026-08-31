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

        int minDist = INT_MAX;

        ListNode* prevNode = head;
        ListNode* currNode = head->next;
        int currIndex = 1;
        int prevCriticalIndex = 0;
        int firstCriticalIndex = 0;

        while(currNode->next != nullptr){
            if((currNode->val < prevNode->val && currNode->val < currNode->next->val)|| (currNode->val > prevNode->val && currNode->val > currNode->next->val)){
                if(prevCriticalIndex == 0){
                    prevCriticalIndex = currIndex;
                    firstCriticalIndex = currIndex;
                } else{
                    minDist = min(minDist, currIndex-prevCriticalIndex);
                    prevCriticalIndex = currIndex;
                }
            }
            currIndex++;
            prevNode = currNode;
            currNode = currNode->next;
        }
        if(minDist != INT_MAX){
            int maxDist = prevCriticalIndex - firstCriticalIndex;
            result = {minDist, maxDist};
        }
        return result;
    }
};