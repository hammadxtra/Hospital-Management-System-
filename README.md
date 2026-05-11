Project: C++ Hospital Management System

About the Project:
This is a console application I built in C++ to handle everyday hospital tasks digitally. It features a secure login system for four different types of users: Admins, Doctors, Operators, and Patients. Depending on the account, users can book appointments, update medical histories, manage hospital rooms, and automatically calculate and generate bills.

The Tech Behind It:
I focused heavily on strong Object-Oriented Programming (OOP) rules—like inheritance and polymorphism—to keep the code organized and easy to expand. Also, instead of setting up a heavy external database, I used C++ file handling (fstream) to safely save all the records directly to local files. This means all the patient and hospital data is securely saved and loaded every time you open or close the app.

How to Run It:
Because the code is cleanly split into multiple files (header, logic, and main), you just need to compile them together. Open your terminal and type g++ *.cpp -o hospital_system. After that, just run ./hospital_system (or hospital_system.exe if you are on Windows) to start the program
