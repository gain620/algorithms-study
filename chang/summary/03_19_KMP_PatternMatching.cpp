// KMP String Pattern Matching (Substring search)
// https://www.youtube.com/watch?v=GTJr8OvyEVQ

#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<int> calcTempArray(const string& subStr)
{
    vector<int> tempArr(subStr.size(), 0);
    int idx = 0;
    
    for (int i = 1; i < subStr.size();)
    {
        if(subStr[i] == subStr[idx])
        {
            tempArr[i] = idx + 1;
            idx++;
            i++;
        }
        else
        {
            if(idx != 0)
            {
                idx = tempArr[idx-1];
            }
            else
            {
                tempArr[i] = 0;
                i++;
            }
        }
    }
    
    
    return tempArr;
}

bool KMP(const string& wholeStr, const string& subStr)
{
    vector<int> tempArr = calcTempArray(subStr);
    int i = 0;
    int j = 0;
    
    while(i < wholeStr.size() && j < subStr.size())
    {
        if(wholeStr[i] == subStr[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j != 0)
            {
                j = tempArr[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    
    if(j == subStr.size())
    {
        return true;
    }
    
    return false;
}

int main()
{
    string wholeStr = "abcxabcdabcdabcy";
    string subStr = "abcdabcy";
    
    if(KMP(wholeStr, subStr))
    {
        cout<< "Substring : " << subStr <<  " exists in " << wholeStr << endl;
    } 
    else
    {
        cout << "Substring does not match!" << endl;
    }
    

    return 0;
}
