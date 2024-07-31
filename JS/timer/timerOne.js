
function timesButtons() {
    let btnStart = document.getElementById("start");
    let btnPause = document.getElementById("pause");
    let btnReset = document.getElementById("reset");
    btnStart.addEventListener("click", startFunc);
    btnPause.addEventListener("click", pauseFunc);
    btnReset.addEventListener("click", resetFunc);
    let resultOnScreen = document.getElementById("result");
    let index = 0;
    let timer;
    function startFunc() {
        document.getElementById("start").disabled = true;
        timer=setInterval(changeTimeOnScreen, 1000);
        function changeTimeOnScreen () {
            index++;
            resultOnScreen.textContent = index;
        }
    };  

    function resetFunc(){
        document.getElementById("start").disabled = false;
        clearInterval(timer);
        console.log(timer);
        resultOnScreen.textContent = 0;
        index = 0;
    }

    function pauseFunc(){
        document.getElementById("start").disabled = false;
        clearInterval(timer);
    }
}