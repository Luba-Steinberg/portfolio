function changeTitle(params) {
    let textBox = document.querySelector('input');
    textBox.addEventListener('input', finallyChange);
}

function finallyChange(event) {
    // let inputText = event.target.value;
    document.querySelector('h1').textContent=event.target.value;
    document.querySelector('h1').style.backgroundColor=event.target.value;
}