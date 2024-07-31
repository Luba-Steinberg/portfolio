function loadPage() {
    const btn = document.getElementById('send');
    btn.addEventListener('click', saveNameToLocalStorage);
    loadGreeting();

    function saveNameToLocalStorage() {
        let userName = document.getElementById('name').value;
        localStorage.setItem('savedName', userName);
        loadGreeting();
    }

    function loadGreeting() {
        const greeting = localStorage.getItem('savedName');
        if (greeting!=null) {
            document.getElementById('name').remove();
            document.getElementById('send').remove();
            // let myTitle = document.getElementsByTagName("h1");
            let myTitle = document.querySelector('h1');
            console.log(myTitle);
            myTitle.textContent = `Hello, ${greeting}!`
        }
    }
}