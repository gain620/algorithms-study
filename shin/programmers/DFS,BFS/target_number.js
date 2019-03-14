function solution(numbers, target) {
    var result = {answer : 0};
    Search(numbers,target,0,0,result);
    console.log(result.answer);
    return result.answer;
}
function Search(numbers,target,i,number,result){
    if(i==numbers.length && number==target){
        result.answer++;
        return;
       }
    if(i<numbers.length){
        Search(numbers,target,i+1,number+numbers[i],result);
        Search(numbers,target,i+1,number-numbers[i],result);
    }
}

solution([1,1,1,1,1],3);