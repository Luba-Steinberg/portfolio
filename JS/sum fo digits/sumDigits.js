function mainsumDigits () {
    let sum;
    let num = prompt ("Enter a number");
    sum=sumDigits (num);
    alert ("The sum is " +sum);
    
}

function sumDigits (num) {
    sum=0;
    while (num>0) {
        let left;
        left=num%10;
        sum=sum+left;
        num=parseInt(num/10);
    }
    return (sum);
}

// function mainsumDigits () {
//     let sum;
//     let num = prompt ("Enter a number");
//     sum=0;
//     while (num>0) {
//         let left;
//         left=num%10;
//         sum=sum+left;
//         num=parseInt(num/10);
//     }
//     alert ("The sum is " +sum);
    
// }