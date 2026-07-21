// ========== NO API KEY NEEDED! USING FREE wttr.in API ==========

const cityInput = document.getElementById('cityInput');
const weatherCard = document.getElementById('weatherCard');
const status = document.getElementById('status');

function setStatus(msg, type = 'loading') {
    status.textContent = msg;
    status.className = 'status show ' + type;
    if (type === 'loading') {
        status.innerHTML = '<div class="spinner"></div>' + msg;
    }
}

function hideStatus() {
    status.className = 'status';
}

function getDay(dateStr) {
    return ['Sun','Mon','Tue','Wed','Thu','Fri','Sat'][new Date(dateStr).getDay()];
}

async function getWeather() {
    const city = cityInput.value.trim();
    if (!city) { 
        setStatus('⚠️ Please enter a city name', 'error');
        return; 
    }

    setStatus('🔄 Fetching weather for ' + city + '...', 'loading');
    weatherCard.classList.remove('show');

    try {
        // ========== USING FREE wttr.in API (NO API KEY NEEDED) ==========
        
        // Current Weather
        const weatherUrl = `https://wttr.in/${city}?format=j1`;
        console.log('📡 Fetching:', weatherUrl);
        
        const res = await fetch(weatherUrl);
        const data = await res.json();
        
        console.log('📡 Data received:', data);
        
        if (!data || !data.current_condition) {
            throw new Error('City not found! Please check spelling.');
        }

        const current = data.current_condition[0];
        const location = data.nearest_area[0];
        
        // Update Current Weather
        document.getElementById('cityName').textContent = location.areaName[0].value || city;
        document.getElementById('country').textContent = location.country[0].value || '';
        document.getElementById('temp').textContent = current.temp_C + '°C';
        document.getElementById('feelsLike').textContent = current.FeelsLikeC + '°C';
        document.getElementById('humidity').textContent = current.humidity + '%';
        document.getElementById('wind').textContent = current.windSpeedKmph + ' km/h';
        document.getElementById('pressure').textContent = current.pressure + ' hPa';
        document.getElementById('desc').textContent = current.weatherDesc[0].value;
        
        // Weather Icon
        const iconCode = current.weatherCode;
        const iconUrl = `https://cdn.weatherapi.com/weather/64x64/day/${iconCode}.png`;
        document.getElementById('icon').src = iconUrl;
        
        // ========== FORECAST (Next 5 days) ==========
        const forecastData = data.weather || [];
        const forecastHtml = forecastData.slice(0, 5).map(day => {
            const date = new Date(day.date);
            const dayName = date.toLocaleDateString('en', { weekday: 'short' });
            const iconCode = day.hourly[0]?.weatherCode || 113;
            const iconUrl = `https://cdn.weatherapi.com/weather/64x64/day/${iconCode}.png`;
            
            return `
                <div class="forecast-item">
                    <div class="day">${dayName}</div>
                    <img src="${iconUrl}" alt="weather">
                    <div class="ftemp">${day.avgtempC}°C</div>
                </div>
            `;
        }).join('');
        
        document.getElementById('forecast').innerHTML = forecastHtml || '<p>No forecast data available</p>';

        weatherCard.classList.add('show');
        setStatus('✅ Weather loaded successfully!', 'success');
        setTimeout(hideStatus, 3000);

    } catch(err) {
        console.error('❌ Error:', err);
        setStatus('❌ ' + err.message + ' | Try checking city name', 'error');
        weatherCard.classList.remove('show');
    }
}

// ========== LOCATION ==========
function getLocation() {
    if (!navigator.geolocation) {
        setStatus('❌ Geolocation not supported', 'error');
        return;
    }

    setStatus('📍 Getting your location...', 'loading');
    
    navigator.geolocation.getCurrentPosition(
        async (pos) => {
            try {
                // Reverse geocoding using free API
                const res = await fetch(
                    `https://api.bigdatacloud.net/data/reverse-geocode-client?latitude=${pos.coords.latitude}&longitude=${pos.coords.longitude}&localityLanguage=en`
                );
                const data = await res.json();
                
                if (data && data.city) {
                    cityInput.value = data.city;
                    getWeather();
                } else if (data && data.locality) {
                    cityInput.value = data.locality;
                    getWeather();
                } else {
                    setStatus('❌ Could not detect city', 'error');
                }
            } catch(err) {
                console.error('❌ Location error:', err);
                setStatus('❌ Could not get location', 'error');
            }
        },
        () => {
            setStatus('❌ Please allow location permission', 'error');
        }
    );
}

cityInput.addEventListener('keypress', (e) => {
    if (e.key === 'Enter') getWeather();
});

// ========== AUTO LOAD ==========
window.onload = () => {
    setTimeout(getWeather, 500);
};