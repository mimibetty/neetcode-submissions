class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int preValue = -1e9;
        for (auto i : nums) {
            if (i == preValue) {
                return i;
            }
            preValue = i;
        }
    }
};
