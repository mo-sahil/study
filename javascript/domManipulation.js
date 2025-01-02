// selecting with id
console.log("Previous header : " + document.getElementById("header").innerHTML);
document.getElementById("header").innerHTML = "Changed header using id as selector";
console.log("New header : " + document.getElementById("header").innerHTML);

// selecting with class
let paragraph = document.getElementsByClassName("para");
console.log("Previous Paragraph " + paragraph[0].innerHTML);
paragraph[0].innerHTML = "Changed Paragraph using class as selector";
console.log("New Paragraph " + paragraph[0].innerHTML);

// similarly we can use tagname document.getElementsByTagName

// using query selector
let first = document.querySelector("p"); // returns first match id or class or tags
console.log(first.innerHTML);

let elements = document.querySelectorAll("p"); // returns all matches
console.log(elements[0].innerHTML);

// getAttribute
let id = document.querySelector("h1").getAttribute("id");
console.log(id);

// style
document.body.style.background = "aqua";

// create
let el = document.createElement("div"); 
el.innerText = "Created Div";

// insert
// document.body.append(el); // appends at last
// document.body.prepend(el); // appends at first
// document.querySelector("h1").after(el); // adds after 
// similar for before


