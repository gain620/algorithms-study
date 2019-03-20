// https://programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++ ) {
        vector<int> tempVec;
        tempVec.resize(commands[i][1] - commands[i][0] + 1);
        
        copy(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1], tempVec.begin()); // -> O(N)
        
        sort(tempVec.begin(), tempVec.end()); // sorting -> O(logN)
        answer.push_back(tempVec[commands[i][2] - 1]); // select desired element
    }
    
    
    return answer;
}