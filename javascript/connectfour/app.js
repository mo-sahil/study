let boxes = document.querySelectorAll(".box");
let moveX = true;
let reset = document.querySelector(".reset");
let winningCombos = [
    [0, 1, 2 ,3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15],
    [0, 4, 8, 12], [1, 5, 9, 13], [2, 6, 10, 14], [3, 7, 11, 15],
    [0, 5, 10, 15], [3, 6, 9, 12]
];
let winner = document.querySelector(".winner");
let newGame = document.querySelector(".newGame");
let moves = 0;

boxes.forEach((box) => {
    box.addEventListener("click", () => {
        if(moveX) {
            box.innerText = "X";
            moveX = false;
        } else {
            box.innerText = "O";
            moveX = true;
        }
        box.disabled = true;
        moves++;
        if(moves === 16) {
            showDraw();
        }
        showWinner();
    });
});

reset.addEventListener("click", () => {
    boxes.forEach((box) => {
        box.disabled = false;
        box.innerText = "";
    });
    moveX = true;
});

newGame.addEventListener("click", () => {
    boxes.forEach((box) => {
        box.disabled = false;
        box.innerText = "";
    });
    moveX = true;
    winner.classList.add("hide");
    moves = 0;
});

let showWinner = () => {
    winningCombos.forEach((win) => {
        if(boxes[win[0]].innerText != "" 
            && boxes[win[0]].innerText == boxes[win[1]].innerText 
            && boxes[win[1]].innerText == boxes[win[2]].innerText 
            && boxes[win[2]].innerText == boxes[win[3]].innerText 
        ) {
            winner.classList.remove("hide");
            document.querySelector(".msg").innerText = `Congratulation ${moveX ? "O" : "X"} won!`;
            disableAll();
        }
    });
}

let showDraw = () => {
    winner.classList.remove("hide");
    document.querySelector(".msg").innerText = `This is a draw`;
    moveX = true;
    moves = 0;
}

let disableAll = () => {
    boxes.forEach((box) => {
        box.disabled = true;
    });
}
