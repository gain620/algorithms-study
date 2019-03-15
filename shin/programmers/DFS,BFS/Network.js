function solution(n, computers) {
    var answer=0;
    const queue = [];
        for(let i=0;i<n;i++){  //n 개의 컴퓨터의 개수 만큼 반복문을 돕니다.
            if(computers[i][i]!==-1){   //computers[i][i]!== -1 이라는것은 해당 노드를 방문하지 않았다는 뜻 입니다.
                queue.push(i);         //i번째 노드를 방문 해야하므로 queue 에 push 합니다.
                Search(queue,computers); //Search 함수에 queue 와 computers 배열을 넘겨줍니다.
                answer++;               //Search 함수가 끝나면 하나의 네트워크가 형성됩니다.
            }
        }
    return answer;
}
function Search(queue,computers){
    if(queue[0]===undefined){  //순환이 끝나는부분,큐에 아무것도 없다면 순환을 끝냅니다.
        return;
    }
    var i = queue.shift();      //큐에서 첫번째 요소를 가져옵니다.(방문할 노드의 index)
    computers[i][i]=-1;         //노드를 방문 하였으므로 -1로 세팅합니다.
    for(let j=0;j<computers.length;j++){ //해당 노드의 연결된 노드의 index를 모두 queue 에 넣습니다. 
        if(computers[i][j]==1 && computers[j][j]!=-1){   //j 번째의 노드와 간선 연결되어있다면(1), j번째 노드를 방문하지 않았다면(-1이아니라면), 
            queue.push(j);//queue 에 push 합니다.
        }
    }
    Search(queue,computers); //넓이 우선 탐색(BFS)에서 queue 에 삽입된 첫번째 요소에 대한 작업이 끝났으므로 다음 탐색을위한 순환 부분 입니다.
}

solution(4,[[1, 1, 0, 0], [1, 1, 0, 1], [0, 0, 1, 0],[0,1,0,1]]);