function solution(begin, target, words) {
    var result = {answer:0}; 
    var queue = [{begin:begin,depth:0}];
    Search(target,words,queue,result);
    return result.answer;
}
function Search(target,words,queue,result){
    var word = queue.shift()
    if(word==undefined){
        return;
    }
    var depth = word.depth;
    var begin = word.begin;
    if(begin==target ){
        result.answer = depth;
        return;
    }
    for(var i=0;i<words.length;i++){
        if(compare_word(begin,words[i])){
            var word = words[i]
            words[words.indexOf(words[i])]='';
            queue.push({begin:word,depth:depth+1});
        }
    }
    Search(target,words,queue,result);
}
function compare_word(begin,word){
    var count=0;
    for(var i=0; i<begin.length;i++){
        if(begin.charAt(i) != word.charAt(i)){
            count++;
        }
    }
    if(count==1){
        return true;
    }
    return false;
}
solution('hit',"cog",["hot", "dot", "dog", "lot", "log", "cog"])