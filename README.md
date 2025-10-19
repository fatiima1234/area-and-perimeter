# Simple Geometry Calculator
A basic console program written in C++ that calculates the area and perimeter of a rectangle and a circle.

---

## Features
- Rectangle: calculate area and perimeter  
- Circle: calculate area and perimeter  
- Input validation for dimensions (rejects zero or negative values) 

---

## Author
Fatemeh HadavandMirzaee

---

## Version History
- **v1.1 (18 October 2025)** 
    - Introduced abstract Shape base class for OOP and polymorphism
    - Added input validation with exceptions and try-catch
    - Implemented clearBadInput() for non-numeric input handling
    - Replaced hardcoded shapes with interactive user menu
    - Improved const correctness and output formatting

- **v1.0 (16 October 2025)**  
    - Implemented `Rectangle` and `Circle` classes  
    - Added getters and setters with input validation  
    - Calculates area and perimeter for each shape  

---

## Usage
Compile and run the program using a C++ compiler:

```bash
g++ area_perimeter.cpp -o area_perimeter
./area_perimeter