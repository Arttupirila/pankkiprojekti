const db = require('../database.js');
const bcrypt = require('bcryptjs');

const card ={
    getAllCards(callback){
        return db.query('SELECT * FROM card', callback)
    },
    getOneCard(iC, callback){
        return db.query('SELECT * FROM card WHERE idCard=?',[iC],callback);
    },
    addCard(addData, callback){
        bcrypt.hash(addData.PIN, 10, function(err, hashedPIN){
            return db.query('INSERT INTO card VALUES(?,?,?)',[addData.idCard, hashedPIN, addData.cardValid], callback);
        });
    },
    updateCard(iC, updateData, callback){
        bcrypt.hash(updateData.PIN, 10, function(err, hashedPIN){
            return db.query('UPDATE card SET idCard=?, PIN=?, cardValid=? WHERE idCard=?',
            [updateData.idCard, hashedPIN, updateData.cardValid, iC], callback);
        })
    },
    deleteCard(iC, callback){
        return db.query('DELETE FROM card WHERE idCard=?',[iC],callback);
    },

    login(cardNo, callback){
        return db.query('SELECT cardPin FROM card WHERE idCard=?',[cardNo],callback);
    }

}

module.exports=card;