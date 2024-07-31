function changeTitleColor(){
    let allMyButtons = document.querySelectorAll('.coloringBtn');
    for (i=0; i<=2; i++) {
        allMyButtons[i].addEventListener('click', changeFinally);
    }
}

function changeFinally(event) {
        
    let btnThatWasClicked = event.target;
    // console.log(btnThatWasClicked);
    let wantedColor = btnThatWasClicked.textContent;
    // console.log(wantedColor);
    let myTitle = document.querySelector('h1');
    myTitle.style.backgroundColor = wantedColor;
}