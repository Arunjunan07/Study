const express = require('express');
const fs = require('fs');
const router = express.Router();

const filePath = './consumers.json';

// Utility functions to read and write data
const readData = () => JSON.parse(fs.readFileSync(filePath));
const writeData = (data) => fs.writeFileSync(filePath, JSON.stringify(data, null, 2));

// Bill module

// Add bill
const addBill = (req, res) => {
  const consumers = readData();
  const consumer = consumers.find(c => c.id == req.params.id);
  if (consumer) {
    const newBill = { billId: Date.now(), ...req.body };
    consumer.bills.push(newBill);
    writeData(consumers);
    res.status(201).json(newBill);
  } else {
    res.status(404).send('Consumer not found');
  }
};

// Get all bills for a consumer
const getAllBills = (req, res) => {
  const consumer = readData().find(c => c.id == req.params.id);
  consumer ? res.json(consumer.bills) : res.status(404).send('Consumer not found');
};

// Get specific bill
const getBillById = (req, res) => {
  const consumer = readData().find(c => c.id == req.params.id);
  if (consumer) {
    const bill = consumer.bills.find(b => b.billId == req.params.billId);
    bill ? res.json(bill) : res.status(404).send('Bill not found');
  } else {
    res.status(404).send('Consumer not found');
  }
};

// Update bill
const updateBill = (req, res) => {
  const consumers = readData();
  const consumer = consumers.find(c => c.id == req.params.id);
  if (consumer) {
    const index = consumer.bills.findIndex(b => b.billId == req.params.billId);
    if (index !== -1) {
      consumer.bills[index] = { ...consumer.bills[index], ...req.body };
      writeData(consumers);
      res.json(consumer.bills[index]);
    } else {
      res.status(404).send('Bill not found');
    }
  } else {
    res.status(404).send('Consumer not found');
  }
};

// Delete bill
const deleteBill = (req, res) => {
  const consumers = readData();
  const consumer = consumers.find(c => c.id == req.params.id);
  if (consumer) {
    consumer.bills = consumer.bills.filter(b => b.billId != req.params.billId);
    writeData(consumers);
    res.send('Bill deleted');
  } else {
    res.status(404).send('Consumer not found');
  }
};

// Set up routes for Bill module
router.post('/consumers/:id/bills', addBill);
router.get('/consumers/:id/bills', getAllBills);
router.get('/consumers/:id/bills/:billId', getBillById);
router.put('/consumers/:id/bills/:billId', updateBill);
router.delete('/consumers/:id/bills/:billId', deleteBill);

module.exports = router;
