// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums.size();
        int fast = nums.size();
        
        do
        {
            slow = nums[slow-1];
            fast = nums[nums[fast-1]-1];
        }while(slow != fast);
        
        slow = nums.size();
        
        while(slow != fast)
        {
            slow = nums[slow-1];
            fast = nums[fast-1];
        }
        
        return slow;
    }
};