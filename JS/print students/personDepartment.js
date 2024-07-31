function personFunc() {
    let p1 = new Person('Mike');
    let p2 = new Person('Jim');

    p1.hello();

    p1.growUp();

    p1.hello();

    p2.hello();

}

function log(msg) {
    document.body.innerHTML += msg + '<br/>';
}


function Person(myName) {
    this.name = myName;
    this.age = 1;
}


Person.prototype.hello = function () {
    let msg = "<p>" + "My name is " + this.name + " and I am " + this.age + " years old.";
    log(msg);
}

// function hello() {
//     document.body.innerHTML += "<p>" + "My name is " + this.name + " and I am " + this.age + " years old." + '<br/>';
// }

Person.prototype.growUp = function () {
    let msg = this.age++;
}