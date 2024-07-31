function payment () {
    let price = prompt ("Enter the price.");
    let amount = prompt ("Enter the amount");
    let dicount = prompt ("Write yes if you got discount. Write no if you didn't");
    let paymentSum=price*amount;
    if (dicount="yes") {paymentSum = paymentSum-paymentSum*0.18}
     else if (dicount="no") paymentSum = paymentSum*1;
    alert ("You paid " +paymentSum);
}