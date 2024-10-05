let grid = document.querySelectorAll(".cell");
let move = 1;
let gameWon = false;
let totalMoves = 0;
let resultOverlay = document.querySelector(".result-overlay");
let messageDisplay = document.querySelector(".message");
let gridContainer = document.querySelector(".grid");
let winnerSymbol = "";

function initializeGame() {
    grid.forEach(cell => {
        cell.innerHTML = "";
        cell.style.pointerEvents = "auto";
        gameWon = false;
        totalMoves = 0;
        move = 1;
        resultOverlay.style.display = "none";
        gridContainer.style.visibility = "visible";
        winnerSymbol = "";

        cell.addEventListener("click", () => {
            if (!gameWon && cell.innerHTML === "") {
                if (move === 1) {
                    cell.innerHTML = `<img src="imgs/zero.jpg" style="width:100%; height:100%;" />`;
                    winnerSymbol = "O";
                    move = 2;
                } else {
                    cell.innerHTML = `<img src="imgs/cross.png" style="width:100%; height:100%;" />`;
                    winnerSymbol = "X";
                    move = 1;
                }
                totalMoves++;

                if (checkWinner()) {
                    gameWon = true;
                    showResult(`${winnerSymbol} is the Winner!`);
                } else if (totalMoves === 9) {
                    showResult("It's a draw!");
                }
            }
        }, { once: true });
    });
}

function checkWinner() {
    const winningCombinations = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],
        [0, 3, 6], [1, 4, 7], [2, 5, 8],
        [0, 4, 8], [2, 4, 6]
    ];

    for (let combination of winningCombinations) {
        const [a, b, c] = combination;
        if (grid[a].innerHTML !== "" && 
            grid[a].innerHTML === grid[b].innerHTML && 
            grid[a].innerHTML === grid[c].innerHTML) {
            return true;
        }
    }
    return false;
}

function showResult(result) {
    gridContainer.style.visibility = "hidden";
    messageDisplay.innerHTML = result;
    resultOverlay.style.display = "flex";
}

document.querySelector(".refresh").addEventListener("click", () => {
    initializeGame();
});

initializeGame();
