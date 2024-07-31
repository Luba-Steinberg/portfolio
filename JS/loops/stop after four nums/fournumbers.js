function fourNumbers () {
    let num = 4;
    let numBig=0;
    let numUser;
    for (; num>=1; num--) {
        numUser = prompt ("Enter a number.");
        if (numUser > 10) numBig=numBig*1+1;
    }
console.log ("Number of numbers bigger than 10 is " +numBig);
}