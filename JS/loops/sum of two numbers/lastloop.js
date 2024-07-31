function negativePrint() {
    let num = prompt ("Enter a negative number");
    let numofNumber=0;
    if (num<0) {
        for (; numofNumber<9 && num<0; numofNumber++){
            num = prompt ("Enter a number");
        }
    }
    alert (numofNumber*1+1);
}