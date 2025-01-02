const cells = document.querySelectorAll('.cell');
let dice;

function rollDice() {
    return Math.floor(Math.random() * 6) + 1;
}

document.querySelector("#roll-dice").addEventListener("click", () => {
    dice = rollDice();
    document.querySelector("#dice-result").innerText = `Dice Result : ${dice}`;
});

cells.forEach(cell => {
    cell.addEventListener('click', () => {
        const current = cell.getAttribute("id");
        const curr = parseInt(current.substring(4));
        const next = curr+dice;
        const nextCell = document.getElementById(`cell${next}`);

        if(cell.querySelector("img")) nextCell.appendChild(cell.querySelector("img"));
    });
});

