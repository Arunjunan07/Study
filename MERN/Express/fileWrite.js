var fs = require('fs');
const data = "Hello World\n";
fs.writeFile('demo.txt', data , (err)  => {
    if(err){
        console.log("Error on Writing File :",err);
        return;
    }
    console.log("File has been Written Successfully");
});


