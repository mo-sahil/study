const morgan = require('morgan'); // third party middleware
const express = require('express');
const app = express();
const userModel = require('./models/user');
const dbConnection = require('./config/db');

app.use(morgan('dev'));

// builtin middlewares
app.use(express.json());
app.use(express.urlencoded({extended : true}));
app.use(express.static('public'));

app.set("view engine", 'ejs');

//custom middleware
app.use((req, res, next) => {
    console.log("Middleware");
    return next();
})

app.get('/', (req, res) => {
    res.render("index");
})

app.get('/about', (req, res) => {
    res.send('About Page');
})

app.get('/profile', (req, res) => {
    res.send("profile page");
})

app.post('/get-form-data', (req, res) => {
    console.log(req.body);
    res.send('data recieved');
})

app.get('/register', (req, res) => {
    res.render('register');
})

app.post('/register', async (req, res) => {
    const {username, email, password} = req.body;
    await userModel.create({
        username: username,
        email: email,
        password: password
    });

    res.send('user registered');
});

app.get('/get-users', (req, res) => {
    userModel.find(
        {password: '123'}
    ).then((users) => {
        res.send(users);
    })
});

app.get('/update-users', async (req, res) => {
    await userModel.findOneAndUpdate({
        password: '123'
    }, {
        password: '456'
    })

    res.send("user updated");
})

app.get('/delete-user', async (req, res) => {
    await userModel.findOneAndDelete({
        password: 456
    })

    res.send("user deleted");
})

app.listen(3000);