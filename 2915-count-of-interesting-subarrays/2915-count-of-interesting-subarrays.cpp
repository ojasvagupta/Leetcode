class Solution 
{
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) 
    {
        // Step 1 : Initialize result, prefix sum, and map
        long long result = 0;
        int prefix = 0;
        unordered_map<int, long long> countMap;
        countMap[0] = 1;

        // Step 2 : Loop through the array
        for (int num : nums) 
        {
            // Step 3 : Update prefix count if condition is satisfied
            if (num % modulo == k) 
            {
                prefix++;
            }

            int mod = prefix % modulo;
            int target = (mod - k + modulo) % modulo;

            // Step 4 : Add count of matching prefix mod to result
            result += countMap[target];

            // Step 5 : Update map with current mod value
            countMap[mod]++;
        }

        // Step 6 : Return the result
        return result;
    }
};