class Solution {
public:
    long long int f(int n){
    int ans=-1;
    for(int i=2;i<n/2;i++){
        if(n%i==0){
            ans = n/i;
            break;
        }
    }
    return ans;
}

    int minOperations(vector<int>& nums) {
        long long int n = nums.size();
        vector<int> d = nums;
        long long int count = 0;

        sort(d.begin(), d.end());

        if (d == nums) return 0;

        for (long long int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) continue;

            long long int xx = nums[i];

            while (xx > nums[i + 1]) {
                int res = f(xx);
                if (res == -1) {
                    return -1;
                }
                xx  = xx/res;
                count++;
            }

            nums[i] = xx;

            if (xx > nums[i + 1]) return -1;
        }

        // for (auto x : nums) {
        //     cout << x << " ";
        // }
        // cout << endl;

        return count;
    }
};