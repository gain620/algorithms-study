#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int answer = 0;

void MixFoods()
{
    int tempA, tempB, result;
    tempA = pq.top();
    pq.pop();
    
    tempB = pq.top();
    pq.pop();
    
    result = tempA + tempB * 2;
    pq.push(result);
    answer++;
}

int solution(vector<int> scoville, int K) {
    
    for(const auto& num : scoville)
    {
        pq.push(num);
    }
    
    
    // untill all foods satisfy "K"
    while(pq.top() < K)
    {
        if(pq.empty() || pq.size() == 1)
        {
            return -1;
        }
        
        MixFoods();
    }
    
    return answer;
}
