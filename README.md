# 💰 Personal Finance Tracker (CLI)

A command-line based Personal Finance Tracker built in C++ that helps users manage income, expenses, budgets, and savings goals efficiently.

---

## 📌 Features

### 📊 Dashboard

* View total income, expenses, and balance
* Real-time financial summary

### 💸 Transactions

* Add income and expense entries
* Store category, amount, and date
* View transaction history
* Persistent storage using files

### 📉 Budget Management

* Set budget for each category
* Automatically tracks spending
* Alerts:

  * ⚠ 80% → Near limit
  * 🚨 100%+ → Over budget

### 🎯 Goals (Savings Tracker)

* Set financial goals (Laptop, Trip, etc.)
* Add savings
* Track progress percentage

### 📚 Financial Tips

* 50/30/20 Rule
* Emergency fund
* Smart spending habits
* Investment basics

---

## 🛠️ Tech Stack

* Language: **C++**
* File Handling: **ifstream / ofstream**
* Data Storage: **Text Files (.txt)**
* Platform: **CLI (Command Line Interface)**

---

## 📁 Project Structure

```
FinanceTracker/
│
├── main.cpp
└── data/
    ├── transactions.txt
    ├── budgets.txt
    └── goals.txt
```

---

## 🚀 How to Run

### 1. Compile

```
g++ main.cpp -o tracker
```

### 2. Run

```
./tracker
```

(Windows)

```
tracker.exe
```

---

## 🧠 Concepts Used

* File Handling (persistent storage)
* Data Structures (vectors, structs)
* Conditional Logic
* Modular Programming
* User Input Validation

---

## 🔄 System Workflow

1. Load data from files
2. Display menu
3. Perform user-selected operation
4. Update data
5. Save back to files

---

## 📊 Example Usage

```
1. Dashboard
2. Add Transaction
3. View Transactions
4. Set Budget
5. View Budget
6. Goals
7. Tips
8. Exit
```

---

## 🎯 Future Enhancements

* OOP-based design
* CSV/JSON support
* Graphical UI (Flutter/Web)
* User authentication
* Data visualization (charts)

---

## 🎤 Viva Explanation

This project is a CLI-based personal finance management system that allows users to track income, manage expenses, set category-wise budgets, and monitor savings goals. It uses file handling for persistent data storage and provides real-time financial insights.

---

## 👨‍💻 Author

**Lakshay Srivastava**
B.Tech CSE, VIT Bhopal University

---

## ⭐ Acknowledgment

Built as a college project to demonstrate financial tracking, budgeting, and data persistence using C++.

---
