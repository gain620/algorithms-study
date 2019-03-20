#include <string>
#include <vector>

using namespace std;

int COUNT = 0;

void DFS(int ID,vector<vector<int>>& computers, vector<bool>& visit)
{
    // if(count == computers.size())
    // {
    //     return;
    // }
    
    visit[ID] = true;
    
    for (int j = 0; j < computers[ID].size(); j++)
    {
        if(visit[j]==false && computers[ID][j])
        {
            visit[j] = true;
            DFS(j, computers, visit);
        }
    }
    
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visit(computers.size(), false);
    
    // A is the start node
    //visit[0] = true;
    //DFS(0,computers, visit, COUNT);
    
    
    for(int i = 0; i < computers.size(); i++)
    {
        if(!visit[i])
        {
            // DFS 끊어진 경우,
            // 새로운 네트워크 생성
            COUNT++;
            DFS(i, computers, visit);
        }
    }
    
    return COUNT;
}