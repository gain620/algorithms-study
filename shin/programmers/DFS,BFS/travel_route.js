function solution(tickets) {
    var result ={answer:[]};
    var path = [];
    var start_index = -1;
   for(var i=0;i<tickets.length;i++){
       if(tickets[i][0]=='ICN'){
           if(start_index==-1){
               start_index=i;
           }else if(start_index != -1 && tickets[start_index][1].charAt(0) > tickets[i][1].charAt(0)){
                start_index = i;
           }
        }
    }
    path = tickets[start_index].join(' ');
    tickets.splice(start_index,1);
    Search(tickets,tickets.length,result,path);
    result.answer.sort();
    return result.answer[0].split(' ');
}
function Search(tickets,depth,result,path){
var dest = path.substring(path.length-3);
    if(depth==0){
        result.answer.push(path);
        return;
    }
    for(var i=0; i <tickets.length; i++){
        if(tickets[i][0]==dest){
            var _tickets = tickets.slice();   //deep_copy
            var _path = path+' '+(_tickets[i][1]);
            _tickets.splice(i,1);
            Search(_tickets,depth-1,result,_path);
        }
    }
}
solution([['ICN', 'SFO'], ['ICN', 'ATL'], ['SFO', 'ATL'], ['ATL', 'ICN'], ['ATL','SFO']]);