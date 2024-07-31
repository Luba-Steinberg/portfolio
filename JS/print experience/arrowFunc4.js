function arrowWorker() {
    let myWorker = new Worker ();
    let btn = document.getElementById("addYearBTN");
    btn.addEventListener("click", myWorker.addYearFunc)
}

function Worker () {
    this.name="Libi";
    this.job="technitian";
    this.salary="90";
    this.experience = 2;
    this.addYearFunc = () => {
        this.experience++;
        console.log(this.experience);
        let myExperience = document.createElement("p");
        myExperience.innerHTML = "Your experience is now "+this.experience + " years";
        console.log(myExperience);
        document.body.appendChild(myExperience);
    }
}

