let eventDate = new Date("January 1, 2027 00:00:00").getTime();

let timer;
let running = false;

function updateTimer() {

    let now = new Date().getTime();

    let distance = eventDate - now;

    if(distance <= 0){

        clearInterval(timer);

        document.getElementById("countdown").innerHTML =
        "🎉 Time's up!";

        running = false;
        return;
    }

    let days = Math.floor(distance / (1000*60*60*24));

    let hours = Math.floor(
        (distance % (1000*60*60*24))
        /(1000*60*60)
    );

    let minutes = Math.floor(
        (distance % (1000*60*60))
        /(1000*60)
    );

    let seconds = Math.floor(
        (distance % (1000*60))
        /1000
    );

    document.getElementById("countdown").innerHTML =
    `${days}d ${hours}h ${minutes}m ${seconds}s`;
}


function startCountdown(){

    if(!running){
        timer = setInterval(updateTimer,1000);
        running = true;
    }
}

function pauseCountdown(){

    clearInterval(timer);
    running = false;
}

updateTimer();



const quotes = [

"Success comes from consistency.",

"Believe in yourself.",

"Every expert was once a beginner.",

"Small steps every day lead to big results.",

"Never stop learning.",

"Dream big and work hard."
];

let quoteIndex = 0;

const quoteElement =
document.getElementById("quote");

function showQuote(){

    quoteElement.innerHTML =
    quotes[quoteIndex];
}

function nextQuote(){

    quoteIndex++;

    if(quoteIndex >= quotes.length){
        quoteIndex = 0;
    }

    showQuote();
}

function prevQuote(){

    quoteIndex--;

    if(quoteIndex < 0){
        quoteIndex = quotes.length - 1;
    }

    showQuote();
}

showQuote();



setInterval(nextQuote,4000);



let modal =
document.getElementById("modal");

let closeBtn =
document.getElementById("closeBtn");

setTimeout(() => {

    modal.style.display = "block";

},5000);

closeBtn.onclick = function(){

    modal.style.display = "none";
}

window.onclick = function(event){

    if(event.target == modal){

        modal.style.display = "none";
    }
}