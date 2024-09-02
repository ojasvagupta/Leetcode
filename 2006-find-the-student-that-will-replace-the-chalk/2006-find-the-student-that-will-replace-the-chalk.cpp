class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = 0;
        int a = chalk.size();
        int res = 0;
        long sum = 0;

        for (int i = 0; i < a; i++) {
            sum = sum + chalk[i];
        }
        k = k % sum;

        for (int i = 0; i < a; i++) {
            if(k<chalk[i])
            {
                return i;
            }
            k=k-chalk[i];
        }

        return res;
    }
};