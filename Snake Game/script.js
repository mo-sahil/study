const canvas = document.getElementById('gameCanvas');
const ctx = canvas.getContext('2d');
const scoreDisplay = document.getElementById('score');
const restartButton = document.getElementsByClassName('restartButton');
const speedSelect = document.getElementById('speed');
const menu = document.getElementById('menu');
const finalScoreDisplay = document.getElementById('finalScore');
const upButton = document.getElementById('up');
const downButton = document.getElementById('down');
const leftButton = document.getElementById('left');
const rightButton = document.getElementById('right');

const box = 20;

let snake;
let food;
let score = 0;
let direction;
let game;
let gameSpeed = 10;

document.addEventListener('keydown', changeDirection);
restartButton[0].addEventListener('click', restartGame);
upButton.addEventListener('click', () => changeDirection({ keyCode: 38 }));
downButton.addEventListener('click', () => changeDirection({ keyCode: 40 }));
leftButton.addEventListener('click', () => changeDirection({ keyCode: 37 }));
rightButton.addEventListener('click', () => changeDirection({ keyCode: 39 }));

function init() {
    snake = [];
    snake[0] = {
        x: 9 * box,
        y: 10 * box
    };

    food = {
        x: Math.floor(Math.random() * 19 + 1) * box,
        y: Math.floor(Math.random() * 19 + 1) * box
    };

    direction = null;
    scoreDisplay.innerHTML = "Score: " + score;

    if (game) {
        clearInterval(game);
    }

    game = setInterval(draw, gameSpeed);
    menu.classList.add('hidden');
    canvas.classList.remove('hidden');
    scoreDisplay.classList.remove('hidden');
}

function changeDirection(event) {
    let key = event.keyCode;
    if (key == 37 && direction != 'RIGHT') {
        direction = 'LEFT';
    } else if (key == 38 && direction != 'DOWN') {
        direction = 'UP';
    } else if (key == 39 && direction != 'LEFT') {
        direction = 'RIGHT';
    } else if (key == 40 && direction != 'UP') {
        direction = 'DOWN';
    }
}

function draw() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    for (let i = 0; i < snake.length; i++) {
        ctx.fillStyle = (i === 0) ? 'green' : 'white';
        ctx.fillRect(snake[i].x, snake[i].y, box, box);

        ctx.strokeStyle = 'red';
        ctx.strokeRect(snake[i].x, snake[i].y, box, box);
    }

    ctx.fillStyle = 'red';
    ctx.fillRect(food.x, food.y, box, box);

    let snakeX = snake[0].x;
    let snakeY = snake[0].y;

    if (direction === 'LEFT') snakeX -= box;
    if (direction === 'UP') snakeY -= box;
    if (direction === 'RIGHT') snakeX += box;
    if (direction === 'DOWN') snakeY += box;

    if (snakeX === food.x && snakeY === food.y) {
        score++;
        scoreDisplay.innerHTML = "Score: " + score;
        food = {
            x: Math.floor(Math.random() * 19 + 1) * box,
            y: Math.floor(Math.random() * 19 + 1) * box
        };
    } else {
        snake.pop();
    }

    let newHead = {
        x: snakeX,
        y: snakeY
    };

    if (snakeX < 0 || snakeX >= canvas.width || snakeY < 0 || snakeY >= canvas.height || collision(newHead, snake)) {

        clearInterval(game);
        finalScoreDisplay.innerHTML = score;
        menu.classList.remove('hidden');
        canvas.classList.add('hidden');
        return;
    }

    snake.unshift(newHead);
}

function collision(head, array) {
    for (let i = 0; i < array.length; i++) {
        if (head.x === array[i].x && head.y === array[i].y) {
            return true;
        }
    }
    return false;
}

function restartGame() {
    gameSpeed = parseInt(speedSelect.value);
    score = 0;
    init();
}

init();