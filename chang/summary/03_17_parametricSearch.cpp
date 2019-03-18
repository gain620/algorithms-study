// https://leetcode.com/problems/first-bad-version/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

    	if (isBadVersion(1)) {
			return 1;
		}


        int low = 1;
        int high = n;
        
        while(low < high)
        {
            int mid = (low + (high-low)) / 2;
            if(isBadVersion(mid))
            {
                high = mid - 1;
            }
            else 
            {
                low = mid + 1;    
            }
        }
        
        return low;
    }
};