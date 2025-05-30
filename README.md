------------------------------------------------------------------------------------------------------------------
# Train_Ticket_Booking_App
------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------
📘 Overview
------------------------------------------------------------------------------------------------------------------
The Train Ticket Booking App is a console-based application developed in C that allows users to sign up, log in, and manage train reservations. This mini-project simulates a basic ticket booking system similar to real-world IRCTC services, providing essential features such as ticket booking, cancellation, and booking status checks.

--------------------------------------------------------------------------------------------------
Key Features
--------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------
🔐 User Authentication
--------------------------------------------------------------------------------------------------
Sign-Up with secure password validation

Login with limited retry attempts and timeout mechanism

Ensures unique usernames for each user

--------------------------------------------------------------------------------------------------
🚆 Train Management
--------------------------------------------------------------------------------------------------

View available trains with detailed info (train number, name, source, destination)

Admin (special user ID) can add new trains

Duplicate train entries are restricted

-----------------------------------------------------------------------------------------------------
🎟️ Ticket Booking
-----------------------------------------------------------------------------------------------------

Book tickets by selecting a train, date of journey, and entering passenger details

Automatic seat number allocation

Handles overbooking by limiting reservations to available seats

----------------------------------------------------------------------------------------------------
❌ Ticket Cancellation
----------------------------------------------------------------------------------------------------

Cancel specific seat numbers on a given train and date

Automatically updates booking records and seat availability

---------------------------------------------------------------------------------------------------
📄 View Booking Details
---------------------------------------------------------------------------------------------------

Retrieve passenger details based on seat numbers for a particular train and journey date

Technical Highlights

---------------------------------------------------------------------------------------------------
📂 File Handling
---------------------------------------------------------------------------------------------------

Persistent storage using flat files to save login credentials, train data, and booking details

Ensures all data is retained between sessions

---------------------------------------------------------------------------------------------------
🧠 Data Structures
---------------------------------------------------------------------------------------------------

Implements dynamic memory allocation using structure pointers

Uses Singly Linked List (SLL) for managing in-memory data

--------------------------------------------------------------------------------------------------
🔧 Modular Design
--------------------------------------------------------------------------------------------------

Each functionality (signup, booking, cancellation, etc.) is implemented in a separate .c file

Uses a Makefile to compile and link all modules

---------------------------------------------------------------------------------------------------
📆 Booking Validity
---------------------------------------------------------------------------------------------------

Restricts ticket booking to only 3 days from the current date to mimic real-world scenarios

Project Files
Source code files (.c) for individual features

Header file (.h) containing structure definitions

makefile for building the project

readme.txt for setup and usage instructions

---------------------------------------------------------------------------------------------------


Data files: usr_logins, trains_info, and dynamically generated passenger files
