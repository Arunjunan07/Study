//src/App.js
import React from 'react';
import FruitItem from './FruitItem';

function App() {
  const fruits = [
    "Apple",
    "Banana",
    "Cherry",
    "Date",
    "Fig",
    "Grape",
  ];

  return (
    <div>
      <h1>Welcome to the Fruit List</h1>
      <h2>Fruits:</h2>
      <ul>
        {fruits.map((fruit, index) => (
          <FruitItem 
            key={index} 
            fruit={fruit} 
          />
        ))}
      </ul>
    </div>
  );
}

export default App;


//src/FruitItem.js
import React from 'react';

function FruitItem(props) {
  return (
    <li>
      {props.fruit}
    </li>
  );
}

export default FruitItem;