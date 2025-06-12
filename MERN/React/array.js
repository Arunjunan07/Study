import React, { useState } from 'react';

const FruitsList = () => {
    const [fruits, setFruits] = useState([]);

    const addFruit = () => {
        if (inputValue) {
            setFruits([...fruits, inputValue]);
            document.getElementById('fruitInput') = "";
        }
    };

    const removeFruit = (index) => {
        setFruits(fruits.filter((_, i) => i !== index));
    };

    return (
        <div>
            <h1>Fruits List</h1>
            <input
                type="text"
                id="fruitInput"
                value={inputValue}
                onChange={(e) => setInputValue(e.target.value)}
                placeholder="Add a new fruit"
            />
            <button onClick={addFruit}>Add Fruit</button>
            <button onClick={clearAll}>Clear All</button>

            <ul>
                {fruits.map((fruit, index) => (
                    <li 
                        key={index} 
                        style={{ cursor: 'pointer' }} 
                        onClick={() => removeFruit(index)}
                    >
                        {fruit}
                    </li>
                ))}
            </ul>
        </div>
    );
};

export default FruitsList;