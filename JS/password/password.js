function myPasswordFunc() {
    let myInputBox = document.getElementById("password");
    console.log(myInputBox.tagName);
    console.log(myInputBox.textContent);

    let passwordValue = myInputBox.value;

    myInputBox.addEventListener("pointerenter", showTipsFunc);
    function showTipsFunc() {
        document.querySelector(".checkForm").style.display="block";
    } 

    myInputBox.addEventListener("keyup", checkStrengthFunc);

    function checkStrengthFunc() {
        passwordValue = myInputBox.value;
        
        console.log(passwordValue);
        if (passwordValue.match(/[a-z]/) ) {
            let newMessageSmallCase = document.getElementById("smallCase");
            newMessageSmallCase.removeAttribute("text-danger");
            newMessageSmallCase.removeAttribute("unValid");
            newMessageSmallCase.classList.add("valid");
            newMessageSmallCase.setAttribute("class","text-success");
        }
        if (passwordValue.match(/[A-Z]/)) {
            let newMessageUpperCase = document.getElementById("upperCase");
            newMessageUpperCase.removeAttribute("text-danger");
            newMessageUpperCase.removeAttribute("unValid");
            newMessageUpperCase.classList.add("valid");
            newMessageUpperCase.setAttribute("class","text-success");
        }
        if (passwordValue.match(/\d/)) {
            let newMessageNumber = document.getElementById("numberPresent");
            newMessageNumber.removeAttribute("text-danger");
            newMessageNumber.removeAttribute("unValid");
            newMessageNumber.classList.add("valid");
            newMessageNumber.setAttribute("class","text-success");
        }
        if (passwordValue.length==8) {
            let newMessageEightLetters = document.getElementById("eightLetters");
            newMessageEightLetters.removeAttribute("text-danger");
            newMessageEightLetters.removeAttribute("unValid");
            newMessageEightLetters.classList.add("valid");
            newMessageEightLetters.setAttribute("class","text-success");
        }
} 
} 
