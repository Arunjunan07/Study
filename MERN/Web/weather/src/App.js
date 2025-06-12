// src/Weather.js
import React, { useState } from 'react';
import axios from 'axios';
import './App.css'; // Import the CSS file

const Weather = () => {
    const [city, setCity] = useState('');
    const [weatherData, setWeatherData] = useState(null);
    const [error, setError] = useState('');

    const API_KEY = '858c2a223e6ad172a02baf723d2ed182'; // Replace with your OpenWeatherMap API key

    const fetchWeather = async () => {
        if (!city) return;

        try {
            const response = await axios.get(
                `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${API_KEY}&units=metric`
            );
            setWeatherData(response.data);
            setError('');
        } catch (err) {
            setError('City not found');
            setWeatherData(null);
        }
    };

    const handleSubmit = (e) => {
        e.preventDefault();
        fetchWeather();
    };

    return (
        <div>
            <h1>Weather App</h1>
            <form onSubmit={handleSubmit}>
                <input
                    type="text"
                    value={city}
                    onChange={(e) => setCity(e.target.value)}
                    placeholder="Enter city"
                />
                <button type="submit">Get Weather</button>
            </form>
            {error && <p>{error}</p>}
            {weatherData && (
                <div>
                    <h2>{weatherData.name}</h2>
                    <p>Temperature: {weatherData.main.temp} °C</p>
                    <p>Weather: {weatherData.weather[0].description}</p>
                </div>
            )}
        </div>
    );
};

export default Weather;