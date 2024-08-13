class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates, int target, int i, int currsum,
                vector<int> temp) {
        if (currsum > target)
            return;
        if (currsum == target) {
            ans.push_back(temp);
            return;
        }
        for (int j = i; j < candidates.size(); j++) {

            if (j > i && candidates[j] == candidates[j - 1])
                continue;

            temp.push_back(candidates[j]);
            helper(candidates, target, j + 1, currsum + candidates[j], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, 0, temp);
        return ans;
    }
};