# 📅 Personal Agenda – Menu System in C

This project is a **console-based personal agenda application** developed in **C**, designed to help users manage their daily activities through a clear and structured **menu-driven interface**.

The program allows the management of **events, appointments, and reminders**, with persistent storage handled through **binary files**.

---

## 🧭 Main Menu

At startup, the application displays a **main menu** that guides the user through the available features of the agenda.

The main menu allows the user to:
- Access **Event Management**
- Access **Appointment Management**
- Access **Reminder Management**
- Perform **record search**
- Exit the program

User input is validated to prevent invalid selections and ensure correct program flow.

---

## 📌 Event Management Menu

The **Event Management** section handles all operations related to events, which are stored in a binary file (`Eventi.dat`).

Available features:
- Add a new event
- Modify an existing event
- Display the list of events in tabular form
- Delete an event
- View event statistics
- Return to the main menu

---

## 📆 Appointment Management Menu

The **Appointment Management** menu is dedicated to handling appointments stored in `Appuntamento.dat`.

Available features:
- Add a new appointment
- Modify an appointment
- Display all appointments
- Delete an appointment
- View appointment statistics
- Return to the main menu

---

## ⏰ Reminder Management Menu

The **Reminder Management** menu allows users to manage reminders stored in `Promemoria.dat`.

Available features:
- Add a new reminder
- Modify a reminder
- Display all reminders
- Delete a reminder
- View reminder statistics
- Return to the main menu

---

## 🔍 Search Functionality

The program includes a **search system** that allows users to search for specific records across the stored agenda data, improving usability and information retrieval.

---

## 📊 Statistics

For each category (events, appointments, reminders), the application provides **statistical information**, offering summaries and aggregated data useful for analyzing stored records.

---

## 💾 File Handling and Input Validation

- All data is stored using **binary `.dat` files** to ensure persistence between executions.
- Input validation functions are used to control menu choices and prevent invalid inputs.
- The project follows a **modular structure**, separating logic across multiple source and header files.

---

## 🛠 Technologies Used

- **Programming Language:** C
- **Application Type:** Console-based
- **Data Storage:** Binary files
- **Paradigm:** Procedural programming

---

## 🎓 Project Purpose

This project was developed as an **academic exercise** to practice:
- File handling in C
- Modular program design
- Menu-based user interfaces
- Input validation and data management
