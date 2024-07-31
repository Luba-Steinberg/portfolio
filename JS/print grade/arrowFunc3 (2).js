function arrowStudent() {
    
    let btn = document.getElementById("changeGrades");
    btn.addEventListener("click", myStudent.changeGradesFunc);
}

let myStudent = new Student ();

function Student () {
    this.name="you";
    this.grade=0;
    this.changeGradesFunc = () => {
        let grade = document.getElementById("grade").value;
        this.grade=grade;
        let myPar = document.createElement("p");
        myPar.innerHTML = "Your grade is now "+this.grade;
        console.log(myPar);
        document.body.appendChild(myPar);
    }
}