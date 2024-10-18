class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        
        // Edge case: empty array
        if (nums.size() == 0) return -1;

        // Check if the array is already sorted (no rotation)
        if (nums[start] <= nums[end]) {
            return binarySearch(nums, target, start, end);
        }
        
        // Binary search in rotated sorted array
        while (start <= end) {
            int mid = start + (end - start) / 2;

            // If the target is found, return the index
            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[start] <= nums[mid]) {
                // Target is in the sorted left half
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            // Right half is sorted
            else {
                // Target is in the sorted right half
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        // Target not found
        return -1;
    }

private:
    // Helper function for binary search in a sorted portion of the array
    int binarySearch(vector<int>& nums, int target, int start, int end) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
};
