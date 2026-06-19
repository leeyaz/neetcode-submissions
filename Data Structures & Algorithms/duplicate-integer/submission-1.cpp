class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            int num = nums[i];
            nums.erase(nums.begin() + i);
            if (find(nums.begin(), nums.end(), num) != nums.end()) {
                return true;
            }
            nums.insert(nums.begin() + i, num);
        }

        return false;
    }
};