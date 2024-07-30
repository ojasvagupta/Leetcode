class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int bCount = 0;
        int deletions = 0;

        for (char c : s) {
            if (c == 'b') {
                bCount++;
            } else if (c == 'a') {
                if (bCount > 0) {
                    deletions++;
                    bCount--;
                }
            }
        }

        return deletions;
    }
};
