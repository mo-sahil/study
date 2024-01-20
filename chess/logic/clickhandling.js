const allSquares = document.getElementsByClassName("square");

const clickedElements = [];

for (const x of allSquares) {
  x.addEventListener("click", function () {
    if (clickedElements.length > 0){
        clickedElements[0].removeAttribute("style");
        clickedElements.length = 0;
    }
    clickedElements.push(x);
    
    const idOfElement = x.getAttribute("id");
    const innerHTMLOfElement = document.getElementById(idOfElement).innerHTML;
    if(innerHTMLOfElement.includes("black") || innerHTMLOfElement.includes("white")){
        document.getElementById(idOfElement).style.backgroundColor = '#eeff0055';
    };
    });
}