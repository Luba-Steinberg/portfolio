function loadPage() {
    let c1 = new Car ("c1", "red");
    let c2 = new Car ("c2", "blue", 50);
    let c3 = new Car ("c3", "black");

    c1.changeSpeed(20);
    c3.changeSpeed(60);

    let race = new Race (c1, c2, c3);
    let fasterCar = race.fasterCar();

    log('And the winner is: ' +fasterCar.name);
}

function log(msg) {
    document.body.innerHTML += msg + '<br />';    
}

function Car(name, color, speed){
    this.name=name;
    this.color = color;
    this.speed= (speed || 0);
}

Car.prototype.changeSpeed = function (speed) {
    this.speed = speed;
}

function Race(c1, c2, c3){
    this.cars = [c1, c2, c3];
}

Race.prototype.fasterCar = function (){
    let fasterSpeed=0;
    let fasterName;
    for(let i=0; i<3; i++) {
        if (this.cars[i].speed>fasterSpeed) 
        {fasterSpeed= this.cars[i].speed;
            fasterName = this.cars[i];}
    }
    return fasterName;
    // let fasterCar = new Fastest (fasterCarSpeed, myfasterCarName);

    // function Fastest (fasterCarSpeed, myfasterCarName) {
    //     this.speed=fasterCarSpeed;
    //     this.name = myfasterCarName;
    // }
    
}

// function fasterCar(params) {
//     this.name =name;
//     this.
// }