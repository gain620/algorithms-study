// https://programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#include <iostream>

using namespace std;

bool compareStrDesc(const string& a, const string& b)
{
    if((a+b).compare(b+a) > 0)
    {
        return true;
    } else
    {
        return false;   
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numStrVec;
    numStrVec.reserve(numbers.size());

    ostringstream ostr;
    for(const auto& num : numbers)
    {
        ostr.str("");
        ostr.clear();
        
        ostr << num;
        numStrVec.push_back(ostr.str());
    }
    
    sort(numStrVec.begin(), numStrVec.end(), compareStrDesc);
    
    for(const auto& num : numStrVec)
    {
        answer += num;
    }
    
    // check if the answer is "0000..."
    // convert answer to "0"
    int tempNum = 0;
    istringstream istr(answer);
    istr >> tempNum;
    if(tempNum == 0) answer = "0";
    
    
    return answer;
}