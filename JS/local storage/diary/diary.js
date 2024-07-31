function loadPage(params) {
    document.getElementById('theDate').value = new Date().toISOString().slice(0, 10);
    let allStories = {};

    let mySaveButton = document.getElementById('save');
    mySaveButton.addEventListener("click", saveStoryFunction);
    let myFindButton = document.getElementById('find');
    myFindButton.addEventListener("click", findAndShowStoryFunction);
    let myClearButton = document.getElementById('clear');
    myClearButton.addEventListener("click", clearStiryFunction);

    function saveStoryFunction() {
        let myStory = document.getElementById("theStory").value;
        let myDate = document.getElementById("theDate").value;
        allStories[myDate] = myStory;
        console.log(allStories);
    }

    function findAndShowStoryFunction() {
        let data = document.getElementById("theDate").value;
        console.log(data);
        console.log(allStories[data]);
        let myStory = document.getElementById("theStory");
        myStory.value = allStories[data];
    }
     
    function clearStiryFunction() {
        let myStory = document.getElementById("theStory");
        myStory.value = "";
    }
}

