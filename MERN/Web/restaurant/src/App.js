import React, { useState, useEffect } from 'react';
import './App.css';

const mockApiUrl = 'https://restaurant.free.beeceptor.com/menu/';

function MenuItem({ item, onAddToCart }) {
  return (
    <div className="card">
      <img src={item.imageUrl} alt={item.name} />
      <h2>{item.name}</h2>
      <p>{item.description}</p>
      <p>₹{item.price}</p>
      <button className="button" onClick={() => onAddToCart(item)}>
        Add to Cart
      </button>
    </div>
  );
}

function Cart({ cart, onRemoveFromCart, onPlaceOrder }) {
  const total = cart.reduce((sum, item) => sum + item.price, 0);

  return (
    <div className="cart">
      <h2>Your Cart</h2>
      {cart.length === 0 ? (
        <p>No items in cart.</p>
      ) : (
        <>
          <ul>
            {cart.map((item, index) => (
              <li key={index}>
                <span>{item.name}</span>
                <span>₹{item.price}</span>
                <button onClick={() => onRemoveFromCart(index)}>❌</button>
              </li>
            ))}
          </ul>
          <p>Total: ₹{total.toFixed(2)}</p>
          <button className="button" onClick={onPlaceOrder}>
            Place Order
          </button>
        </>
      )}
    </div>
  );
}

function App() {
  const [menu, setMenu] = useState([]);
  const [cart, setCart] = useState([]);

  useEffect(() => {
    fetch(mockApiUrl)
      .then(res => res.json())
      .then(data => setMenu(data.menu))
      .catch(err => console.error('Error loading menu:', err));
  }, []);

  const addToCart = (item) => {
    setCart([...cart, item]);
  };

  const removeFromCart = (index) => {
    const newCart = [...cart];
    newCart.splice(index, 1);
    setCart(newCart);
  };

  const placeOrder = () => {
    alert('Order placed successfully!');
    setCart([]);
  };

  return (
    <div className="container">
      <h1>Restaurant Menu</h1>
      <div className="menu">
        {menu.map(item => (
          <MenuItem key={item.id} item={item} onAddToCart={addToCart} />
        ))}
      </div>
      <Cart cart={cart} onRemoveFromCart={removeFromCart} onPlaceOrder={placeOrder} />
    </div>
  );
}

export default App;
