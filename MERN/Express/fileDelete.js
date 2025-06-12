var fs = require('fs');
const data = "demo.txt";
fs.unlink(data, (err) => {
    if(err){
        console.log("Error on Deleting File :",err);
        return;
    }
    console.log("File has been deleted Successfully");
});


