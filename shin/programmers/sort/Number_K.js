function solution(array, commands) {
    var answer = [];
    commands.forEach(command=>{
        let sliced = array.slice(command[0]-1,command[1]);
        sliced.sort(function(a,b){  //sort() 함수는 문자열을 정리 하므로 콜백함수 를 넣어 숫자열 정렬로 바꾼다
            return a-b;     
        });
        answer.push(sliced[command[2]-1]);
    })
    return answer;
}


solution([1, 5, 2, 6, 3, 7, 4],[[2, 5, 3], [4, 4, 1], [1, 7, 3]]);