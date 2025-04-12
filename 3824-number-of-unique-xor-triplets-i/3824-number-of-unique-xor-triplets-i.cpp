class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()<3) return n;
        int count=0;
        while(n>0)
            {
                n=n>>1;
                count++;
            }
        int answer=1;
        for(int i=0;i<count;i++)
            {
                answer=answer*2;
            }
        return answer;
    }
};