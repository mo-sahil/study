document.getElementById("board").addEventListener("keyup", function (event) {
    if (event.target && event.target.nodeName == "TD") {
        var validNum = /[1-9]/;
        var tdEl = event.target;
        if (tdEl.innerText.length > 0 && validNum.test(tdEl.innerText[0])) {
            tdEl.innerText = tdEl.innerText[0];
            tdEl.classList.add("highlight"); 
        } else {
            tdEl.innerText = "";
            tdEl.classList.remove("highlight"); 
        }
    }
});

document.getElementById("solve").addEventListener("click", async function (event) {
    var boardString = boardToString();
    var solution = await solve(boardString);
    if (solution) {
        stringToBoard(solution);
    } else {
        alert("Invalid Board!");
    }
});

document.getElementById("clear").addEventListener("click", clearBoard);

function clearBoard() {
    var tds = document.getElementsByTagName("td");
    for (var i = 0; i < tds.length; i++) {
        tds[i].innerText = "";
        tds[i].classList.remove("highlight");
        tds[i].classList.remove("solving"); 
    }
}

function boardToString() {
    var string = "";
    var validNum = /[1-9]/;

    var tds = document.getElementsByTagName("td");

    for (var i = 0; i < tds.length; i++) {
        if (validNum.test(tds[i].innerText[0])) {
            string += tds[i].innerText[0];
        } else {
            string += '-';
        }
    }

    return string;
}

function stringToBoard(string) {
    var currentCell;
    var validNum = /[1-9]/;
    var cells = string.split('');
    var tds = document.getElementsByTagName("td");

    for (var i = 0; i < tds.length; i++) {
        currentCell = cells.shift();
        if (validNum.test(currentCell)) {
            tds[i].innerText = currentCell;
            tds[i].classList.add("highlight");
        } else {
            tds[i].innerText = "";
            tds[i].classList.remove("highlight"); 
        }
    }
}

async function solve(boardString) {
    var boardArray = boardString.split("");
    if (boardIsInvalid(boardArray)) return false;

    return await recursiveSolve(boardArray);
}

function boardIsInvalid(boardArray) {
    return !boardIsValid(boardArray);
}

function boardIsValid(boardArray) {
    return allRowsValid(boardArray) && allColumnsValid(boardArray) && allBoxesValid(boardArray);
}

function allRowsValid(boardArray) {
    return [0, 9, 18, 27, 36, 45, 54, 63, 72].map(function (i) {
        return getRow(boardArray, i);
    }).reduce(function (validity, row) {
        return collectionIsValid(row) && validity;
    }, true);
}

function getRow(boardArray, i) {
    var startingEl = Math.floor(i / 9) * 9;
    return boardArray.slice(startingEl, startingEl + 9);
}

function allColumnsValid(boardArray) {
    return [0, 1, 2, 3, 4, 5, 6, 7, 8].map(function (i) {
        return getColumn(boardArray, i);
    }).reduce(function (validity, column) {
        return collectionIsValid(column) && validity;
    }, true);
}

function getColumn(boardArray, i) {
    var startingEl = i % 9;
    return [0, 1, 2, 3, 4, 5, 6, 7, 8].map(function (num) {
        return boardArray[startingEl + num * 9];
    });
}

function allBoxesValid(boardArray) {
    return [0, 3, 6, 27, 30, 33, 54, 57, 60].map(function (i) {
        return getBox(boardArray, i);
    }).reduce(function (validity, box) {
        return collectionIsValid(box) && validity;
    }, true);
}

function getBox(boardArray, i) {
    var boxCol = Math.floor(i / 3) % 3;
    var boxRow = Math.floor(i / 27);
    var startingIndex = boxCol * 3 + boxRow * 27;

    return [0, 1, 2, 9, 10, 11, 18, 19, 20].map(function (num) {
        return boardArray[startingIndex + num];
    });
}

function collectionIsValid(collection) {
    var numCounts = {};
    for (var i = 0; i < collection.length; i++) {
        if (collection[i] != "-") {
            if (numCounts[collection[i]] === undefined) {
                numCounts[collection[i]] = 1;
            } else return false;
        }
    }

    return true;
}

async function recursiveSolve(boardArray) {
    if (boardIsSolved(boardArray)) return boardArray.join("");

    var cellPossibilities = getNextCellAndPossibilities(boardArray);
    var nextUnsolvedCellIndex = cellPossibilities.index;
    var possibilities = cellPossibilities.choices;

    if (nextUnsolvedCellIndex === -1) return false;

    for (var i = 0; i < possibilities.length; i++) {
        boardArray[nextUnsolvedCellIndex] = possibilities[i];
        updateBoard(boardArray);
        await delay(10);

        var solvedBoard = await recursiveSolve(boardArray);
        if (solvedBoard) return solvedBoard;
    }

    boardArray[nextUnsolvedCellIndex] = "-";
    updateBoard(boardArray);
    await delay(10);

    return false;
}

function getNextCellAndPossibilities(boardArray) {
    for (var i = 0; i < boardArray.length; i++) {
        if (boardArray[i] === "-") {
            var existingValues = getAllIntersections(boardArray, i);
            var choices = ["1", "2", "3", "4", "5", "6", "7", "8", "9"].filter(function (num) {
                return existingValues.indexOf(num) < 0;
            });

            return { index: i, choices: choices };
        }
    }

    return { index: -1, choices: [] };
}

function getAllIntersections(boardArray, i) {
    return getRow(boardArray, i).concat(getColumn(boardArray, i)).concat(getBox(boardArray, i));
}

function boardIsSolved(boardArray) {
    for (var i = 0; i < boardArray.length; i++) {
        if (boardArray[i] === "-") {
            return false;
        }
    }
    return true;
}

function delay(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

function updateBoard(boardArray) {
    var tds = document.getElementsByTagName("td");
    for (var i = 0; i < boardArray.length; i++) {
        tds[i].innerText = boardArray[i] !== "-" ? boardArray[i] : "";
        if (boardArray[i] === "-") {
            tds[i].classList.remove("solving");
        } else {
            tds[i].classList.add("solving");
        }
    }
}