const mysql = require('mysql2');
const connectionString = 'mysql://netuser:netpass@127.0.0.1:3306/bankdb';
const connection = mysql.createPool(connectionString);
module.exports = connection;