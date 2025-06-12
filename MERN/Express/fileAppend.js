var fs = require('fs');
const newLine = "This line was Added";
fs.appendFile('demo.txt', newLine , (err)  => {
    if(err){
        console.log("Error on Appending File :",err);
        return;
    }
    console.log("Content appended Successfully");
});


