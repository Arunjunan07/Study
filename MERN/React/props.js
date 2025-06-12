//src/App.js
import React from 'react';
import Hello from './Hello';

function App() {

    const getGreeting = () => {
    return "Hello,";
  };

  const name = "Alice";
  const age = 28;

  return (
    <div>
      <h1>Welcome to React</h1>
      <Hello 
        name={name} 
        age={age} 
        greeting={getGreeting}
      />
      <Hello 
        name="Bob" 
        age={32} 
        greeting={getGreeting} 
      />

    </div>
  );
}

export default App;


//src/Hello.js
import React from 'react';

function Hello(props) {
  return (
    <h2>
      {props.greeting()} {props.name} {props.age && `(${props.age} years old)!`}
    </h2>
  );
}

export default Hello;