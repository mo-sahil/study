const http = require("http");
const fs = require("fs");

const server = http.createServer((req, res) => {
    fs.appendFile('log.txt', `${Date.now()}: ${req.url}: New Req Recieved\n`, (err, data) => {
        switch(req.url){
            case '/': res.end("HomePage");
            break;
            case '/about': res.end("About Page");
            break;
            default:
                res.end("404 not found");
        }
    });
});

server.listen(8000, () => console.log("Server Started"));