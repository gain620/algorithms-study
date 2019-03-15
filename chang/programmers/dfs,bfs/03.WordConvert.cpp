#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int checkDifference(string a, string b)
{
    int diff = 0;
    
    for(int i = 0; i<a.size(); i++)
    {
        if(a[i] != b[i]) diff++;
    }
    
    return diff;
}

int BFS(string begin, string& target, const vector<string>& words)
{
    int result = 0;
    queue<string> myQueue;
    myQueue.push(begin);

    map<string, int> depth;

    // initialize map by every words
    for (const auto& word : words)
    {
        // set init value to -1, to check if this word is visited
        // 방문 확인을 위해 초기값 -1로 세팅
        depth[word] = -1;
    }

    depth[begin] = 0;
    
    while(!myQueue.empty())
    {
        //int queueSize = myQueue.size();
        string tmp = myQueue.front();
        myQueue.pop();
        
        for(int i = 0; i < words.size(); i++)
        {
            // if (checked[i]) continue;
            
            int diff = checkDifference(tmp, words[i]);
            if(depth[words[i]] == -1 && diff == 1)
            {
                myQueue.push(words[i]);
                depth[words[i]] = depth[tmp] +1; 
                //checked[i] = true;
                
                if(words[i] == target)
                {
                    return depth[words[i]];
                }
            }
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    // bool checked[] = { false };
    
    answer = BFS(begin, target, words);
    return answer;
}