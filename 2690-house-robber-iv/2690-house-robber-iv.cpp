class Solution {
public:
    int minCapability(vector<int>& A, int k) {
        int start = 1, end = 1e9, n = A.size();
        while (start < end){
            int mid = (start + end) / 2, take = 0;
            for (int i = 0; i < n; ++i)
                if (A[i] <= mid)
                    take++, i++;
            if(take >= k)
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
};