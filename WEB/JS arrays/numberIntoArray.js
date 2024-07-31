function numberIsArray(){
    let a = prompt ("Enter a three digit number");
    let b=a;
    let myArray=new Array(3);
    myArray[3]=a%10;
    a=(a-a%10)/10;
    myArray[2]=a%10;
    a=(a-a%10)/10;
    myArray[1]=a;
    console.table(myArray);
    b++;
    console.log (b);
    alert (b);
    let myArrayB=new Array(3);
    myArrayB[3]=b%10;
    b=(b-b%10)/10;
    myArrayB[2]=b%10;
    b=(b-b%10)/10;
    myArrayB[1]=b;
    console.table(myArrayB);
}