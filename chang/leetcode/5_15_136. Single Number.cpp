class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int uniqueId = 0;
        for(int num : nums)
        {
        	uniqueId ^= num;
        }

        return uniqueId;
    }
};