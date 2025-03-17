class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            if(!st.count(nums[i]))
            {
                st.insert(nums[i]);
            }
            else
            {
                st.erase(nums[i]);
            }
        }
        if(st.size()>0)
        {
            return false;
        }
        return true;
        
    }
};