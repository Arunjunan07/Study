const express = require('express');
const bodyParser = require('body-parser');
const consumerController = require('./controllers/consumer'); 
const billController = require('./controllers/bill');

const app = express();
const PORT = 3000;

app.use(bodyParser.json());
app.use(consumerController);  
app.use(billController);

app.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`);
});
