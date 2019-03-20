#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer;

void PrintVectors(vector<vector<string>>& tickets)
{
    for(const auto& inner : tickets)
    {
        for(const auto& city : inner)
        {
            cout << city << ", ";
        }
        cout << endl;
    }
}

bool DFS(const string from, vector<vector<string>>& tickets,vector<bool>& visit, int count)
{
    answer.push_back(from);
    
    // count = 0...tickets.size()
    if(count == tickets.size())
    {
        return true;
    }
    
    for(int i = 0; i < tickets.size(); i++)
    {
        if(visit[i]==true)
        {
            continue;
        }
        else if(from == tickets[i][0] && visit[i] == false)
        {
            visit[i] = true;
            if(DFS(tickets[i][1], tickets, visit, count + 1))
            {
                return true;
            }
            else // 경로 막힌 경우
            {
                visit[i] = false;
            }
        }
        
    }
    
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    // sort tickets by alhpabet order
    sort(tickets.begin(), tickets.end());
    vector<bool> visit(tickets.size(), false);
    //DFS(tickets[0][0], )
    // int count = 0;
    DFS("ICN", tickets, visit, 0);
   
    
    return answer;
}