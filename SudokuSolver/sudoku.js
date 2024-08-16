var TESTABLE = true;

var SudokuSolver = function(TESTABLE) {
    var solver;

    function solve(boardString) {
        var boardArray = boardString.split("");

        if (boardIsInvalid(boardArray)) return false;

        return recursiveSolve(boardString);
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
        var boxCol = Math.floor(i % 9 / 3);
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

    function recursiveSolve(boardString) {
        var boardArray = boardString.split("");
        if (boardIsSolved(boardArray)) return boardArray.join("");

        var cellPossibilities = getNextCellAndPossibilities(boardArray);
        var nextUnsolvedCellIndex = cellPossibilities.index;
        var possibilities = cellPossibilities.choices;
        for (var i = 0; i < possibilities.length; i++) {
            boardArray[nextUnsolvedCellIndex] = possibilities[i];
            var solvedBoard = recursiveSolve(boardArray.join(""));
            if (solvedBoard) return solvedBoard;
        }

        boardArray[nextUnsolvedCellIndex] = "-"; // Reset on backtrack
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
        return boardArray.indexOf("-") === -1;
    }

    return {
        solve: solve
    };
};

// Example usage:
var solver = SudokuSolver(TESTABLE);
var board = "53--7----6--195---98----6-8---6---34----8-3-17---2---6-6----28---419--5----8--79";
console.log(solver.solve(board));
