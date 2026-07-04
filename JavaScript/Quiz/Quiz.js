//  QUESTIONS

const questions = [
  {
    question: "What does HTML stand for?",
    options: [
      "Hyper Text Markup Language",
      "High Text Machine Language",
      "Hyper Transfer Markup Language",
      "Home Tool Markup Language"
    ],
    answer: 0
  },
  {
    question: "Which HTML tag is used to create a hyperlink?",
    options: ["<a>", "<link>", "<href>", "<url>"],
    answer: 0
  },
  {
    question: "Which CSS property changes the text color?",
    options: ["font-color", "text-color", "color", "foreground"],
    answer: 2
  },
  {
    question: "Which CSS layout system is one-dimensional?",
    options: ["Grid", "Flexbox", "Float", "Table"],
    answer: 1
  },
  {
    question: "Which keyword declares a variable in JavaScript?",
    options: ["int", "var", "define", "new"],
    answer: 1
  },
  {
    question: "Which method selects an element by ID?",
    options: [
      "querySelectorAll()",
      "getElementById()",
      "getElementsByClassName()",
      "findElement()"
    ],
    answer: 1
  },
  {
    question: "Which operator checks strict equality?",
    options: ["=", "==", "===", "!="],
    answer: 2
  },
  {
    question: "Which method prints output in the browser console?",
    options: [
      "console.print()",
      "print()",
      "console.log()",
      "echo()"
    ],
    answer: 2
  },
  {
    question: "Which HTML tag is used to insert an image?",
    options: ["<picture>", "<img>", "<image>", "<src>"],
    answer: 1
  },
  {
    question: "Which CSS property adds space inside an element?",
    options: ["margin", "spacing", "padding", "border"],
    answer: 2
  }
];

//  ELEMENTS


const startScreen = document.querySelector(".start-screen");
const quizScreen = document.querySelector(".quiz-screen");
const resultScreen = document.querySelector(".result-screen");

const startBtn = document.getElementById("startBtn");
const nextBtn = document.getElementById("nextBtn");
const prevBtn = document.getElementById("prevBtn");
const restartBtn = document.getElementById("restartBtn");

const questionEl = document.getElementById("question");
const optionsEl = document.getElementById("options");

const currentQuestionEl = document.getElementById("currentQuestion");
const totalQuestionEl = document.getElementById("totalQuestion");

const progress = document.getElementById("progress");

const timerEl = document.getElementById("time");

const scoreEl = document.getElementById("score");
const correctEl = document.getElementById("correct");
const wrongEl = document.getElementById("wrong");
const percentageEl = document.getElementById("percentage");

// VARIABLES

let currentQuestion = 0;
let score = 0;
let selectedAnswer = null;
let answers = [];

let timeLeft = 30;
let timer;

// START QUIZ

startBtn.addEventListener("click", () => {

    startScreen.classList.remove("active");
    quizScreen.classList.add("active");

    totalQuestionEl.innerText = questions.length;

    loadQuestion();

});

// LOAD QUESTION

function loadQuestion(){

    clearInterval(timer);

    timeLeft = 30;

    timerEl.innerText = timeLeft;

    startTimer();

    selectedAnswer = answers[currentQuestion] ?? null;

    currentQuestionEl.innerText = currentQuestion + 1;

    progress.style.width =
        ((currentQuestion + 1) / questions.length) * 100 + "%";

    const q = questions[currentQuestion];

    questionEl.innerText = q.question;

    optionsEl.innerHTML = "";

    q.options.forEach((option,index)=>{

        const div = document.createElement("div");

        div.classList.add("option");

        div.innerText = option;

        if(selectedAnswer === index){

            div.classList.add("selected");

        }

        div.onclick = ()=>selectOption(index);

        optionsEl.appendChild(div);

    });

    updateButtons();

}

// SELECT OPTION

function selectOption(index){

    selectedAnswer = index;

    answers[currentQuestion] = index;

    document.querySelectorAll(".option").forEach((item)=>{

        item.classList.remove("selected");

    });

    document.querySelectorAll(".option")[index]
    .classList.add("selected");

}

// TIMER

function startTimer(){

    timer = setInterval(()=>{

        timeLeft--;

        timerEl.innerText = timeLeft;

        if(timeLeft <= 0){

            clearInterval(timer);

            nextQuestion();

        }

    },1000);

}

// NEXT QUESTION

nextBtn.addEventListener("click", () => {
    nextQuestion();
});

function nextQuestion() {

    if (currentQuestion < questions.length - 1) {

        currentQuestion++;
        loadQuestion();

    } else {

        finishQuiz();

    }

}

// PREVIOUS QUESTION

prevBtn.addEventListener("click", () => {

    if (currentQuestion > 0) {

        currentQuestion--;
        loadQuestion();

    }

});

// FINISH QUIZ

function finishQuiz() {

    clearInterval(timer);

    score = 0;

    answers.forEach((answer, index) => {

        if (answer === questions[index].answer) {

            score++;

        }

    });

    const wrong = questions.length - score;
    const percentage = Math.round((score / questions.length) * 100);

    quizScreen.classList.remove("active");
    resultScreen.classList.add("active");

    scoreEl.innerText = `${score}/${questions.length}`;
    correctEl.innerText = score;
    wrongEl.innerText = wrong;
    percentageEl.innerText = percentage + "%";

}

// RESTART QUIZ

restartBtn.addEventListener("click", restartQuiz);

function restartQuiz() {

    currentQuestion = 0;
    score = 0;
    answers = [];
    selectedAnswer = null;

    clearInterval(timer);

    resultScreen.classList.remove("active");
    startScreen.classList.add("active");

}

// AUTO FINISH

document.addEventListener("keydown", (e) => {

    if (!quizScreen.classList.contains("active")) return;

    if (e.key === "ArrowRight" || e.key === "Enter") {

        nextQuestion();

    }

    if (e.key === "ArrowLeft") {

        if (currentQuestion > 0) {

            currentQuestion--;
            loadQuestion();

        }

    }

});

// DISABLE PREVIOUS BUTTON

function updateButtons() {

    prevBtn.disabled = currentQuestion === 0;

    if (currentQuestion === questions.length - 1) {

        nextBtn.innerText = "Finish Quiz";

    } else {

        nextBtn.innerText = "Next";

    }

}
