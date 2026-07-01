class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = BinarySearch(nums, target, true);
        int last = BinarySearch(nums, target, false);

        return {first, last};
    }

    int BinarySearch(vector<int>& nums, int target, bool first) {
        int left = 0;
        int right = nums.size() - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                answer = mid;

                if (first)
                    right = mid - 1;   // keep searching left
                else
                    left = mid + 1;    // keep searching right
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return answer;
    }
};