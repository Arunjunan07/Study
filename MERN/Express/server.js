const express = require('express');
const fs = require('fs');
const app = express();

app.use(express.json()); // Middleware to parse JSON request bodies

const FILE_PATH = 'demo.txt';

// Route to Read File
app.get('/read', (req, res) => {
    fs.readFile(FILE_PATH, 'utf8', (err, data) => {
        if (err) return res.status(500).send('Error reading file');
        res.send({ content: data });
    });
});

// Route to Write to File
app.post('/write', (req, res) => {
    const { text } = req.body;
    fs.writeFile(FILE_PATH, text, (err) => {
        if (err) return res.status(500).send('Error writing to file');
        res.send('File written successfully!');
    });
});

// Route to Append Data to File
app.post('/append', (req, res) => {
    const { text } = req.body;
    fs.appendFile(FILE_PATH, `\n${text}`, (err) => {
        if (err) return res.status(500).send('Error appending to file');
        res.send('Data appended successfully!');
    });
});

// Route to Delete File
app.delete('/delete', (req, res) => {
    fs.unlink(FILE_PATH, (err) => {
        if (err) return res.status(500).send('Error deleting file');
        res.send('File deleted successfully!');
    });
});

// Start Server
const PORT = 3000;
app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});
