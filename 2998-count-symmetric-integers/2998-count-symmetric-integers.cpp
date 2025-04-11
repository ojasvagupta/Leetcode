class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int i = low; i <= high; i++) {
            string s = to_string(i);
            if (s.size() % 2 == 0) {
                int n = s.size();
                string left = s.substr(0, n / 2);
                string right = s.substr((n / 2), n / 2);
                int lt = stoi(left);
                int rt = stoi(right);
                int leftcount = 0;
                int rightcount = 0;
                n = n / 2;
                while (n > 0) {
                    leftcount = leftcount + (lt % 10);
                    lt = lt / 10;
                    rightcount = rightcount + (rt % 10);
                    rt = rt / 10;
                    n--;
                }
                if (leftcount == rightcount && leftcount!=0 && rightcount!=0) {
                    res++;
                }
            }
        }
        return res;
    }
};