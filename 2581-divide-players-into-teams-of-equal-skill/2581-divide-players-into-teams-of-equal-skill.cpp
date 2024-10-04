class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long sum = accumulate(skill.begin(), skill.end(), 0LL);
        
        if (sum % (n / 2) != 0) {
            return -1;
        }
        
        long long target = sum / (n / 2);
        sort(skill.begin(), skill.end());
        long long chemistry = 0;
        
        for (int i = 0; i < n / 2; ++i) {
            int pairSum = skill[i] + skill[n - i - 1];
            if (pairSum != target) {
                return -1;
            }
            chemistry += (long long)skill[i] * skill[n - i - 1];
        }
        
        return chemistry;
    }
};
