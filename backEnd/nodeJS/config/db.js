const mongoose = require('mongoose');

const connection = mongoose.connect('mongodb://0.0.0.0/database').then(() => {
    console.log('Connected to database');
});

module.exports = connection;