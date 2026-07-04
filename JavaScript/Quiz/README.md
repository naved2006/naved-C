# 🚀 Frontend Quiz App

## 🔹 Project Overview

This project is a modern **Frontend Quiz Application** built using **HTML, CSS, and JavaScript**. It allows users to test their Frontend Development knowledge through multiple-choice questions with a countdown timer, progress tracking, score calculation, and a responsive Glassmorphism UI.

---

## 🔹 Features

### 📝 Interactive Quiz

* 10 Frontend Development MCQ Questions
* Four options for each question
* One answer can be selected at a time
* Previous & Next navigation
* Finish Quiz button on the last question

### ⏱️ Countdown Timer

* 30-second timer for every question
* Timer starts automatically
* Automatically moves to the next question when time is over
* Timer resets for every new question

### 📊 Progress Tracking

* Displays current question number
* Shows total number of questions
* Animated progress bar updates after every question

### 🎉 Result Screen

* Displays final score
* Shows total correct answers
* Shows total wrong answers
* Restart Quiz button to play again

### ⌨️ Keyboard Support

* **Enter** → Next Question
* **Right Arrow (→)** → Next Question
* **Left Arrow (←)** → Previous Question

### 📱 Responsive Design

* Fully responsive on Desktop
* Tablet friendly
* Mobile friendly
* Smooth animations and modern UI

---

## 🔹 How This Project is Made

* HTML is used to create the complete quiz structure.
* CSS is used to design a modern Glassmorphism interface with responsive layouts and animations.
* JavaScript is used to manage quiz logic, timer, score calculation, navigation, and dynamic content rendering.

### JavaScript Implementation

#### Quiz Questions

* Questions are stored inside an array of objects.
* Each object contains:

  * Question
  * Options
  * Correct Answer
* Questions are displayed dynamically using JavaScript.

#### Option Selection

* Users can select one option for each question.
* Selected answers are stored inside an array.
* Users can change their answers before finishing the quiz.

#### Countdown Timer

* Each question has a 30-second timer.
* Timer updates every second using `setInterval()`.
* Automatically moves to the next question when time reaches zero.
* `clearInterval()` is used to stop the timer before loading the next question.

#### Navigation

* Previous button navigates to the previous question.
* Next button loads the next question.
* Finish Quiz button appears on the last question.

#### Progress Bar

* Progress percentage is calculated dynamically.
* Progress bar width updates after every question.

#### Result Calculation

* Selected answers are compared with correct answers.
* Final score is calculated.
* Correct and wrong answer counts are displayed on the result screen.

#### Restart Quiz

* Resets all quiz data.
* Clears previous answers.
* Returns to the start screen.

---

## 🔹 Technologies Used

* HTML5
* CSS3
* JavaScript (ES6)

---

## 📂 Project Structure

```plaintext
Frontend-Quiz-App/
│
├── index.html
├── Quiz.css
├── Quiz.js
└── README.md
```

---

## 🔹 Project Explanation Video

(https://drive.google.com/file/d/1CWKPq73jsar90mUwlrCR2BajAHvoFeBm/view?usp=sharing)

---


## 🎯 Learning Outcomes

After completing this project, you will learn:

* DOM Manipulation
* JavaScript Arrays & Objects
* Event Handling
* Dynamic Content Rendering
* Timer using `setInterval()`
* `clearInterval()`
* Progress Bar Logic
* Conditional Statements
* Functions
* Responsive Web Design
* Keyboard Event Handling
* Score Calculation Logic

---

## 💡 Future Improvements

* Add Multiple Quiz Categories
* Random Question Generator
* Shuffle Options
* Difficulty Levels
* Dark & Light Theme
* Sound Effects
* High Score System
* Local Storage Support
* Review Answers After Quiz
* Leaderboard

---

## 🤗 Thank You

Thank you for checking out this project!
