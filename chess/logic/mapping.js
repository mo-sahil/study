// selecting files using dom and storing in array

const arrayOfFiles = document.querySelectorAll('.files');

const fileNamesArray = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'];

//counter for filesarray
let file = 0;

for (const i of arrayOfFiles) {
    // counter for ranks
    let counter = 8;
    for (const j of i.children) {
        j.setAttribute("id", fileNamesArray[file] + counter);
        counter--;
    }
    file++;
}