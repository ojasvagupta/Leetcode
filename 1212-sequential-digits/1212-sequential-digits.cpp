class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int num = low;
        int min = 0;
        int i = 0;
        while (num > 0) {
            i++;
            min = num % 10;
            num = num / 10;
        }
        vector<int> v(i, 0);
        for (int a = 0; a < i; a++) {
            if (min > 9) {
                break;
            }
            v[a] = min;
            min = min + 1;
        }
        if (v[v.size() - 1] == 0) {
            v.push_back(0);
            int x = 1;
            for (int a = 0; a < v.size(); a++) {
                v[a] = x;
                x = x + 1;
            }
        }
        long long val = 0;
        int x = 10;
        for (int a = 0; a < v.size(); a++) {
            val = (val * x) + (v[a]);
        }
        if(val<=high && val>=low)
        {
             res.push_back(val);
        }
       
        val = 0;
        while (val < high) {
            val = 0;
            x = 10;
            for (int a = 0; a < v.size(); a++) {
                v[a] = v[a] + 1;
                val = (val * x) + (v[a]);
                if (v[a] > 9) {
                    val = 0;
                    v.push_back(0);
                    int y = 1;
                    for (int b = 0; b < v.size(); b++) {
                        v[b] = y;
                        y = y + 1;
                    }
                    x = 10;
                    for (int c = 0; c < v.size(); c++) {
                        val = (val * x) + (v[c]);
                    }
                    break;
                }
            }
            if (val > high) {
                break;
            }
            res.push_back(val);
        }
        return res;
    }
};