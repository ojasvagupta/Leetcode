class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=0;
        int b=0;
        vector<int> arr;
        if(m==0)
        {
            nums1=nums2;
        }
        else if(n==0)
        {
            nums1=nums1;
        }
        else{
        for(int i=0 ; i<(m+n);i++){
            if(i>=m)
            {
                nums1[i]=nums2[a];
                a++;
            }
        
        }
         sort(nums1.begin(),nums1.end());
        
    }
 }
};