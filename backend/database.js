const mysql = require('mysql2');

const connString = "mysql://netuser:netpass@localhost:3306/bankdb";
const connection = mysql.createPool(connString);

module.exports = connection;