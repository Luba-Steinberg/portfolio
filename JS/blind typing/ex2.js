var myStringLength = 10;
let timeOne;
let flag = 0;
let myTimer=0;
let myTimeMessage;

function loadPage() {
    let btnPause = document.getElementById("pause");
    btnPause.disabled = true;
    btnPause.addEventListener ("click", myPauseFunc); 
    let btnNew = document.getElementById("new");
    btnNew.addEventListener ("click", newTextFunc);
    let btnCHeck = document.getElementById("check");
    btnCHeck.addEventListener ("click", checkFunc);
    
    function newTextFunc() {
        clearTimeout(timeOne);
        myClear();
        myTimeMessage = document.getElementById("typingTimer");
        generateString(myStringLength, myTimer, myTimeMessage);
        btnPause.textContent = "Pause";
        btnPause.disabled = false;
    }

    function myClear() {
        let myRandomText=document.getElementById("text");
        myRandomText.textContent=" ";
    }

    function generateString(myStringLength, myTimer, myTimeMessage) {
        console.log(myStringLength);
        let myCharacters = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        console.log(myCharacters.length);
        let myResult="";
        let myCharactersLength = myCharacters.length;
        console.log(myCharactersLength);
        for (let i=0; i<myStringLength; i++){
            myResult += myCharacters.charAt(Math.floor(Math.random()*myCharactersLength));
        };
        let myRandomText=document.getElementById("text");
        myRandomText.textContent = myResult; 
        timeOne = setInterval (changeTimeOnScreen, 1000);
        myStringLength+=2;
        return myStringLength;        
    }

    function myPauseFunc() {
        flag ++;
        console.log("Hi");
               
        if (flag%2==1) {
            btnPause.textContent = "Continue";
            clearTimeout(timeOne);  
        }
        else {
            btnPause.textContent = "Pause";
            timeOne = setInterval (changeTimeOnScreen, 1000);
            changeTimeOnScreen();
        }
    }

    function checkFunc() {
        console.log(timeOne);
        clearTimeout(timeOne);
        let givenText = document.getElementById("text").textContent;
        console.log (givenText);
        let resultText = document.getElementById("typedText").value;
        console.log (resultText);  
        // let myLastLine = document.getElementById("typingTimer");
        // console.log(myLastLine);
        if (resultText===givenText) {
            let congratulationText = "You succeeded in "+ myTimer + "seconds";
            document.body.append(congratulationText);
        }
        else {
            let badNewsText = "You should try more";
            document.body.insertBefore(badNewsText, document.body.lastChild);
        }
    }

    function changeTimeOnScreen () {
        myTimer++;
        console.log(myTimeMessage.textContent);
        myTimeMessage.textContent = "Time: "+myTimer;
    };
}

