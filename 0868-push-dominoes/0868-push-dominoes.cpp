class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> r(n, 0), l(n, 0);
        
        // Rightward force
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                count = 1;
                r[i] = count;
            } else if (dominoes[i] == '.' && count > 0) {
                count++;
                r[i] = count;
            } else {
                count = 0; // Reset on 'L'
            }
        }

        // Leftward force
        count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                count = 1;
                l[i] = count;
            } else if (dominoes[i] == '.' && count > 0) {
                count++;
                l[i] = count;
            } else {
                count = 0; // Reset on 'R'
            }
        }

        // Build final result
        string result = "";
        for (int i = 0; i < n; i++) {
            if (r[i] == 0 && l[i] == 0) {
                result += dominoes[i]; // '.', 'R', or 'L'
            } else if (r[i] == 0) {
                result += 'L';
            } else if (l[i] == 0) {
                result += 'R';
            } else if (r[i] == l[i]) {
                result += '.';
            } else if (r[i] < l[i]) {
                result += 'R';
            } else {
                result += 'L';
            }
        }

        return result;
    }
};
