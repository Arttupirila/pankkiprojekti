const mysql=require('mysql2');

const conn="mysql://uniuser:unipass@127.0.0.1:3306/bankdb";

const connection=mysql.createPool(conn);

module.exports=connection;