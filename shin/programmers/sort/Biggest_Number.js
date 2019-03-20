let sorted = [];

function solution(numbers) { 
    var answer = '';
    merge_sort(numbers,0,numbers.length-1);  //변형된 merge_sort, 참조되면서 merge가 되면 인자로 주어진 left_index ~ right_index 까지가 정렬된다.
    for(let i=0; i <numbers.length; i++){
        answer += String(numbers[i]);
    }
    if(Number(answer)==0){
        return "0";
    }
    console.log(answer);
    return answer;
}

function merge_sort(numbers,left_index,right_index){
    if(left_index<right_index){         //왼쪽의 index 가 오른쪽 index 보다 작다면 (순환이 끝나는부분) 
        let mid_index=parseInt((left_index+right_index)/2); // mid_index 를 설정한다.
        merge_sort(numbers, left_index, mid_index);  //왼쪽을 merge_sort 한다 
        merge_sort(numbers,mid_index+1,right_index); //오른쪽을 merge_sort 한다 
        merge(numbers, left_index, mid_index, right_index); //merge 한다 
    }
}
function merge(numbers,left_index,mid_index,right_index){
    let i,j,k,l;           //i,j,k 는 numbers 의 index 저장한다.
    i = left_index; j=mid_index+1; k=left_index;
    while(i<=mid_index && j<=right_index){      //두 number를 합친 String 을 비교하여 더큰 문자를 sorted 배열에 넣는다  
        if(String(numbers[i])+String(numbers[j])>String(numbers[j])+String(numbers[i])){ 
            sorted[k++]=numbers[i++];
        }else{
            sorted[k++]=numbers[j++];
        }
    }
    if(i>mid_index){ //왼쪽부분에 대한 정렬이 끝났다면 오른쪽 부분을 일괄적으로 sorted 배열에 삽입(남은 부분은 모두 정렬 되어있다.)
        for(l=j; l<=right_index; l++){
            sorted[k++]=numbers[l];
        }
    }
    else{   //오른쪽 부분에 대한 정렬이 끝났다면 왼쪽부분을 일괄적으로 sorted배열에 삽입
        for(l=i; l<=mid_index; l++){
            sorted[k++]=numbers[l];
            }
        }
    for(l=left_index; l<=right_index; l++){   //합병정렬해서 저장했던 sorted 를 해당하는 numbers 부분에대입 (실질적으로 numbers에 정렬이되는부분)
        numbers[l]=sorted[l];
    }
}

solution([3, 30, 34, 5, 9]);