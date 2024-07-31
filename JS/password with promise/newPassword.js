function passwordFunc() {
    let users = [
        { id: 123456789, password: "Aa1234567" }, { id: 234567891, password: "Bb2345678" }, { id: 345678912, password: "Cc3456789" }
    ]
    let myOldInput;
    let myIndex;
    let myIdValue;
    let myNewInput;

    
    let myId = document.getElementById("userName");
    myId.addEventListener("keyup", idValidation);

    let myOldPassword = document.getElementById("oldPassword");
    myOldPassword.addEventListener("keyup", oldPassValidation);

    let myNewPassword = document.getElementById("newPassword");
    myNewPassword.addEventListener("keyup", newPassValidation);

    function idValidation() {
        console.log("Hi");
        myIdValue = document.getElementById("userName").value;
        console.log(myIdValue);
        if (myIdValue.length == 9) {
            checkId()
                .then((data) => {
                    document.getElementById("idValidationText").innerHTML = (data);
                })
                .catch((err) => {
                    document.getElementById("idValidationText").innerHTML = (err);
                })
        }
    }

    const checkId = () => {
        console.log("Hi");
        return new Promise((resolve, reject) => {
            for (let index = 0; index < users.length; index++) {
                if (users[index].id == myIdValue) {
                    myIndex = index;
                    resolve(`Welcome ${myIdValue}, now enter your old password`);
                }
                else reject(`The id doesn't exist`);
            }
        })
    }

    const oldPasswordCheck = () => {
        myOldInput = document.getElementById("oldPassword").value;
        console.log(myOldInput);
        return new Promise ((resolve, reject) => {
            if (myOldInput.length == 9) {
                if (users[myIndex].password == myOldInput)
                    resolve(`Great, now enter you new password`)
                else
                    reject(`The password isn't correct, try again.`);
            }
            

        })
    }

    function oldPassValidation() {
        console.log("Hi");
        oldPasswordCheck()
            .then((data) => {
                document.getElementById("oldPassValidationText").innerHTML = (data);
                // return newPassValidation()
                // .then ((data)=> {
                //     document.append(p).textContent(data);
                // })   
            })
            .catch((err) => {
                document.getElementById("oldPassValidationText").innerHTML = (err);
            })
    }

    function newPassValidation() {
        console.log("Hi");
        myNewInput = document.getElementById("newPassword").value;
        console.log(myNewInput);
        if (myNewInput.match(/[a-z]/)) {
            let newMessageSmallCase = document.getElementById("smallCase");
            newMessageSmallCase.removeAttribute("text-danger");
            newMessageSmallCase.removeAttribute("unValid");
            newMessageSmallCase.classList.add("valid");
            newMessageSmallCase.setAttribute("class", "text-success");
        }
        if (myNewInput.match(/[A-Z]/)) {
            let newMessageUpperCase = document.getElementById("upperCase");
            newMessageUpperCase.removeAttribute("text-danger");
            newMessageUpperCase.removeAttribute("unValid");
            newMessageUpperCase.classList.add("valid");
            newMessageUpperCase.setAttribute("class", "text-success");
        }
        if (myNewInput.match(/\d/)) {
            let newMessageNumber = document.getElementById("numberPresent");
            newMessageNumber.removeAttribute("text-danger");
            newMessageNumber.removeAttribute("unValid");
            newMessageNumber.classList.add("valid");
            newMessageNumber.setAttribute("class", "text-success");
        }
        if (myNewInput.length == 8) {
            let newMessageEightLetters = document.getElementById("eightLetters");
            newMessageEightLetters.removeAttribute("text-danger");
            newMessageEightLetters.removeAttribute("unValid");
            newMessageEightLetters.classList.add("valid");
            newMessageEightLetters.setAttribute("class", "text-success");
        }
    }



}