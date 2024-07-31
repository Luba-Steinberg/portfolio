function keyboardFunc() {
    let word= prompt ("Enter a word");
    let myArray = new Array (3);
    myArray[0]=['q','w','e','r','t','y','u','i','o','p'];
    myArray[1]=['a','s','d','f','g','h','j','k','l'];
    myArray[2]=['z','x','c','v','b','n','m'];
    let arrayTrue = new Array();
    for (let i=0; i<word.length; i++){
        arrayTrue[i]=[];
    }
    for (let i=0; i<word.length; i++){
        for (let j=0; j<=2; j++){
            for (let k=0; k<myArray[j].length; k++){
                if (word.charAt(i) === myArray[j][k]){
                    arrayTrue[i]=j;
                    break;
                } 
                    
            }
        }
    }
    let trueVar = true;
    for (let i=0; i<word.length-1; i++){
        if (arrayTrue[i]!==arrayTrue[i+1]){
            trueVar=false;
            alert ("The word can't be typed in one keyboardline");
            break;
        }
    }
    let lineNumber=arrayTrue[0]+1;
    if (trueVar==true) 
        alert ("The word can be typed in keyboardline number "+lineNumber);
}