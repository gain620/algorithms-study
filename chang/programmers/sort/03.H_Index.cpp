// https://programmers.co.kr/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// hIndex = max([...min(i, f(i))...])
int solution(vector<int> citations) {
    int answer = 0;
    int vecSize = citations.size();
    
    // sort the citations in descending order
    sort(citations.begin(), citations.end(), greater<int>());
    
    vector<int> minVec;
    for(int i = 0; i < vecSize; i++) {
        minVec.push_back(min(i+1, citations[i]));
    }
    
    sort(minVec.begin(), minVec.end(), greater<int>());
    
    answer = minVec[0];
    
    return answer;
}