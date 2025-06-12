const express = require('express');
const fs = require('fs');
const router = express.Router();

const filePath = './consumers.json';

// Utility functions to read and write data
const readData = () => JSON.parse(fs.readFileSync(filePath));
const writeData = (data) => fs.writeFileSync(filePath, JSON.stringify(data, null, 2));

// Consumer module

// Create consumer
const createConsumer = (req, res) => {
  const consumers = readData();
  const newConsumer = { id: Date.now(), ...req.body, bills: [] };
  consumers.push(newConsumer);
  writeData(consumers);
  res.status(201).json(newConsumer);
};

// Get all consumers
const getAllConsumers = (req, res) => {
  res.json(readData());
};

// Get consumer by ID
const getConsumerById = (req, res) => {
  const consumer = readData().find(c => c.id == req.params.id);
  consumer ? res.json(consumer) : res.status(404).send('Consumer not found');
};

// Update consumer
const updateConsumer = (req, res) => {
  const consumers = readData();
  const index = consumers.findIndex(c => c.id == req.params.id);
  if (index !== -1) {
    consumers[index] = { ...consumers[index], ...req.body };
    writeData(consumers);
    res.json(consumers[index]);
  } else {
    res.status(404).send('Consumer not found');
  }
};

// Delete consumer
const deleteConsumer = (req, res) => {
  const consumers = readData().filter(c => c.id != req.params.id);
  writeData(consumers);
  res.send('Consumer deleted');
};

// Set up routes for Consumer module
router.post('/consumers', createConsumer);
router.get('/consumers', getAllConsumers);
router.get('/consumers/:id', getConsumerById);
router.put('/consumers/:id', updateConsumer);
router.delete('/consumers/:id', deleteConsumer);

module.exports = router;
