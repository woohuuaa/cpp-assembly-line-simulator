# OOP345-Works

Coursework and final project for Seneca College's OOP345 course, focused on object-oriented programming in C++.

## Main Project: Assembly Line Workflow Simulator

The main project is a configurable assembly-line simulator that processes customer orders through a chain of workstations. Each workstation manages one inventory item, assigns serial numbers, fills matching order items when stock is available, and passes the order to the next station. At the end of the line, orders are separated into completed and incomplete queues based on whether all requested items were filled.

## Features

- Loads station inventory, customer orders, and assembly-line routing from text files.
- Parses delimited records with a reusable `Utilities` module.
- Models stations, customer orders, workstations, and line orchestration as separate C++ classes.
- Tracks inventory levels, serial numbers, filled items, completed orders, and incomplete orders.
- Uses queue-based workflow processing to move orders through the assembly line one iteration at a time.

## Technical Highlights

- Object-oriented design with encapsulated modules for parsing, inventory, order state, and line management.
- Inheritance through `Workstation`, which extends `Station`.
- Dynamic memory management for customer order item lists.
- Move constructor and move assignment support for transferring `CustomerOrder` objects safely through queues.
- STL containers and algorithms, including `std::vector`, `std::deque`, `std::copy_if`, `std::find_if`, and `std::none_of`.
- Exception handling for invalid input and file loading errors.

## Project Structure

    Project/
      CustomerOrder.h/.cpp   Customer order state, item fulfillment, move operations
      LineManager.h/.cpp     Assembly-line setup, station ordering, processing loop
      Station.h/.cpp         Station inventory, serial numbers, formatted display
      Utilities.h/.cpp       Delimited text parsing and field-width tracking
      Workstation.h/.cpp     Queue-based workstation processing
      ms3.cpp                Final project tester
      Stations1.txt          Station data using comma-delimited records
      Stations2.txt          Station data using pipe-delimited records
      CustomerOrders.txt     Customer order input data
      AssemblyLine.txt       Workstation routing configuration

## How to Run

Open `Project/Project.sln` in Visual Studio and run the project with the following command-line arguments:

    Stations1.txt Stations2.txt CustomerOrders.txt AssemblyLine.txt

The expected final milestone output is included in:

    Project/ms3_output.txt

## Resume Summary

Built a configurable C++ assembly-line simulator using OOP/OOD, STL containers, move semantics, dynamic memory management, file parsing, and exception handling to process customer orders through linked workstations.
