var fs = require('fs');

fs.readFile('demo.txt', (err,data)  => {
    if(err){
        console.log("Error on Reading File :",err);
        return;
    }
    console.log("File Content :" + data);
});


