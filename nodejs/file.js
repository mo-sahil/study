const fs = require("fs");

// Sync...
// fs.writeFileSync('./text.txt', "Learning file handling using nodejs");

// Async...
// fs.writeFile("./text.txt", "Hello World Async", (err) => {});

// const result = fs.readFileSync("./contact.txt", "utf-8");
// console.log(result);

// fs.readFile("./contact.txt", "utf-8", (err, result) => {
//     if(err) {
//         console.log("Error", err);
//     } else {
//         console.log(result);
//     }
// });

// fs.appendFileSync("./text.txt", 'Hey there');

const os = require("os");
console.log(os.cpus().length);