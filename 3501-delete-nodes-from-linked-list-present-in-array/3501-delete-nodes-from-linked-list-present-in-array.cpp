class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool> mp;
        for (int a : nums) {
            mp[a] = true;
        }
        
        // Skip nodes from the head that are in the map
        while (head != nullptr && mp.count(head->val)) {
            head = head->next;
        }

        // If the list becomes empty after skipping, return null
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode* current = head;
        
        // Traverse the list and remove nodes whose values are in nums
        while (current != nullptr && current->next != nullptr) {
            if (mp.count(current->next->val)) {
                // Skip the next node
                current->next = current->next->next;
            } else {
                // Move to the next node
                current = current->next;
            }
        }

        return head;
    }
};
