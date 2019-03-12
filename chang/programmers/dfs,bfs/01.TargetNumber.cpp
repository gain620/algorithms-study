#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& numArr, int target, int targetSize, int& answer)
{
    if (targetSize == numArr.size())
    {
        int totalSum = 0;
        
        for(const auto& num : numArr)
        {
            totalSum += num;
        }
        
        if(totalSum == target) answer++;
        
        return -1;
    }
    else
    {
        numArr[targetSize] *= +1;
        dfs(numArr, target, targetSize + 1, answer);
        numArr[targetSize] *= -1;
        dfs(numArr, target, targetSize + 1, answer);
        
        return -1;
    }
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, answer);
    return answer;
}