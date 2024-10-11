let grid = document.querySelectorAll(".cell");
let color = true;
let cells = 0;
let draggedPiece = null;
let startCellIndex = null;
let currentPlayer = 'white';  // White starts the game

// Initialize the chess board with alternating colors
grid.forEach((cell) => {
    if (color) {
        cell.style.backgroundColor = "white";
        color = false;
    } else {
        cell.style.backgroundColor = "grey";
        color = true;
    }
    cells++;
    if (cells === 8) {
        color = color ? false : true;
        cells = 0;
    }
});

// Drag and Drop functionality
grid.forEach((cell, index) => {
    // Start dragging a piece
    cell.addEventListener('dragstart', function (e) {
        let piece = this.querySelector("img");

        // Only allow dragging if it's the current player's piece
        if (piece && isCurrentPlayerPiece(piece)) {
            draggedPiece = piece;
            startCellIndex = index;
        } else {
            draggedPiece = null; // Block dragging if it's not the player's turn
        }
    });

    // Allow dragover for valid cells
    cell.addEventListener('dragover', function (e) {
        e.preventDefault();
    });

    // Handle dropping a piece
    cell.addEventListener('drop', function (e) {
        e.preventDefault();
        let targetCell = this;
        let endCellIndex = index;

        if (draggedPiece && validateMove(startCellIndex, endCellIndex, draggedPiece)) {
            if (!isSameTeam(startCellIndex, endCellIndex)) {
                // Move the piece
                targetCell.innerHTML = '';
                targetCell.appendChild(draggedPiece);
                grid[startCellIndex].innerHTML = '';
                
                // Switch player turn
                currentPlayer = currentPlayer === 'white' ? 'black' : 'white';
                updateTurnIndicator();
                draggedPiece = null;
            } else {
                console.log("Cannot take your own piece");
            }
        } else {
            console.log("Invalid move");
        }
    });
});

// Function to check if the piece belongs to the current player
function isCurrentPlayerPiece(piece) {
    return (currentPlayer === 'white' && piece.classList.contains('white')) ||
           (currentPlayer === 'black' && piece.classList.contains('black'));
}

// Optional: Update UI to show whose turn it is
function updateTurnIndicator() {
    let turnIndicator = document.getElementById('turn-indicator');
    turnIndicator.innerText = `Current Player: ${currentPlayer}`;
}

// Rest of the code remains the same for move validation (e.g., validateMove, validatePawnMove, etc.)

function validateMove(start, end, piece) {
    if (piece.classList.contains('black_rook') || piece.classList.contains('white_rook')) {
        return validateRookMove(start, end);
    } else if (piece.classList.contains('black_knight') || piece.classList.contains('white_knight')) {
        return validateKnightMove(start, end);
    } else if (piece.classList.contains('black_bishop') || piece.classList.contains('white_bishop')) {
        return validateBishopMove(start, end);
    } else if (piece.classList.contains('black_queen') || piece.classList.contains('white_queen')) {
        return validateQueenMove(start, end);
    } else if (piece.classList.contains('black_king') || piece.classList.contains('white_king')) {
        return validateKingMove(start, end);
    } else if (piece.classList.contains('black_pawn') || piece.classList.contains('white_pawn')) {
        return validatePawnMove(start, end, piece);
    }
    return false;
}

function validatePawnMove(start, end, piece) {
    let startRow = Math.floor(start / 8);
    let endRow = Math.floor(end / 8);
    let startCol = start % 8;
    let endCol = end % 8;

    if (piece.classList.contains('white_pawn')) {
        if (startRow === 6 && startRow - endRow === 2 && startCol === endCol && endCellEmpty(end)) {
            return true;
        } else if (startRow - endRow === 1 && startCol === endCol && endCellEmpty(end)) {
            return true;
        } else if (startRow - endRow === 1 && Math.abs(startCol - endCol) === 1 && !endCellEmpty(end)) {
            return true;
        }
    } else if (piece.classList.contains('black_pawn')) {
        if (startRow === 1 && endRow - startRow === 2 && startCol === endCol && endCellEmpty(end)) {
            return true;
        } else if (endRow - startRow === 1 && startCol === endCol && endCellEmpty(end)) {
            return true;
        } else if (endRow - startRow === 1 && Math.abs(startCol - endCol) === 1 && !endCellEmpty(end)) {
            return true;
        }
    }
    return false;
}

function validateRookMove(start, end) {
    let startRow = Math.floor(start / 8);
    let endRow = Math.floor(end / 8);
    let startCol = start % 8;
    let endCol = end % 8;

    if (startRow === endRow || startCol === endCol) {
        return pathIsClear(start, end);
    }
    return false;
}

function validateKnightMove(start, end) {
    let startRow = Math.floor(start / 8);
    let endRow = Math.floor(end / 8);
    let startCol = start % 8;
    let endCol = end % 8;

    return (Math.abs(startRow - endRow) === 2 && Math.abs(startCol - endCol) === 1) ||
           (Math.abs(startRow - endRow) === 1 && Math.abs(startCol - endCol) === 2);
}

function validateBishopMove(start, end) {
    let startRow = Math.floor(start / 8);
    let endRow = Math.floor(end / 8);
    let startCol = start % 8;
    let endCol = end % 8;

    if (Math.abs(startRow - endRow) === Math.abs(startCol - endCol)) {
        return pathIsClear(start, end);
    }
    return false;
}

function validateQueenMove(start, end) {
    return validateRookMove(start, end) || validateBishopMove(start, end);
}

function validateKingMove(start, end) {
    let startRow = Math.floor(start / 8);
    let endRow = Math.floor(end / 8);
    let startCol = start % 8;
    let endCol = end % 8;

    return Math.abs(startRow - endRow) <= 1 && Math.abs(startCol - endCol) <= 1;
}

function endCellEmpty(index) {
    return grid[index].innerHTML === '';
}

function isSameTeam(start, end) {
    let startPiece = grid[start].querySelector("img");
    let endPiece = grid[end].querySelector("img");

    if (startPiece && endPiece) {
        let startClass = startPiece.classList;
        let endClass = endPiece.classList;
        return (startClass.contains('black') && endClass.contains('black')) || 
               (startClass.contains('white') && endClass.contains('white'));
    }
    return false;
}

function pathIsClear(start, end) {
    let startRow = Math.floor(start / 8);
    let endRow = Math.floor(end / 8);
    let startCol = start % 8;
    let endCol = end % 8;

    let rowStep = startRow === endRow ? 0 : (endRow > startRow ? 1 : -1);
    let colStep = startCol === endCol ? 0 : (endCol > startCol ? 1 : -1);

    let currentRow = startRow + rowStep;
    let currentCol = startCol + colStep;

    while (currentRow !== endRow || currentCol !== endCol) {
        let currentIndex = currentRow * 8 + currentCol;
        if (!endCellEmpty(currentIndex)) {
            return false;
        }
        currentRow += rowStep;
        currentCol += colStep;
    }

    return true;
}
