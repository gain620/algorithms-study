function solution(bridge_length, weight, truck_weights) {
    var answer = 0;
    var bridge = [];
    while(1){
        var trucks_weight = 0;
         bridge.forEach(function(truck){
            trucks_weight+=truck.weight;
        });
        // 다리위에 있는 트럭의 총 중량
        if( truck_weights[0]!=undefined && trucks_weight+truck_weights[0] <= weight){
            bridge.push({weight:truck_weights.shift(),count:0}); 
        }
        answer++;
        bridge.forEach(function(truck){
            truck.count++;
        })
        if(truck_weights[0]==undefined && bridge[0]==undefined){
            break;
        } // 다리에 트럭이없고 대기 트럭이 없다면 반복문을 나간다.
        if(bridge[0]!=undefined && bridge[0].count==bridge_length){
            bridge.shift();
        } // 트럭이 bridge_length 만큼 이동했다면 bridge 배열에서 제거한다.      
    }
    return answer;
}
solution(2,10,[7,4,5,6]);