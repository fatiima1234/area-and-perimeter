// Simple OOP Geometry Program
// Author: Fatemeh HadavandMirzaee
// Description: A basic code calculating area and perimeter of a rectangle and a circle.
// Demonstrates encapsulation and input validation
// Version 1.1
// Changes:
//   - Added abstract Shape base class for OOP and polymorphism
//   - Added input validation with exceptions and try-catch
//   - Added clearBadInput() for non-numeric input handling
//   - Replaced hardcoded shapes with interactive user menu
//   - Improved const correctness and output formatting
// Date: 18 October 2025

#include <iostream>
#include <limits>

constexpr double pi = 3.14159265;

void clearBadInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class Shape {

public:
    virtual void getInfo() const = 0;
    virtual double getArea() const = 0;
    virtual void printArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void printPerimeter() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {

public:
    Rectangle(double width, double length) {
        if (width <= 0 && length <= 0) {
            throw std::invalid_argument("Width and length error\n");
        } else if (width <= 0) {
            throw std::invalid_argument("Width error\n");
        } else if (length <= 0) {
            throw std::invalid_argument("Length error\n");
        }
        width_ = width; 
        length_ = length;
    }

    double getWidth() const {
        return width_;
    }

    double getLength() const {
        return length_;
    }

    void getInfo() const {
        std::cout << "\nRectangle with width " << width_ << " and length " << length_ << " units.\n";
    }

    double getArea() const {
        return width_ * length_;
    }

    void printArea() const {
        std::cout << "Area: " << getArea() << " units^2\n";
    }

    double getPerimeter() const {
        return 2 * (width_ + length_);
    }

    void printPerimeter() const {
        std::cout << "Perimeter: " << getPerimeter() << " units\n\n";
    }

private:
    double width_; 
    double length_;
};

class Circle : public Shape {
public:
    Circle(double radius) {
        if (radius <= 0){
            throw std::invalid_argument("Radius error\n");
        }
        radius_ = radius;
    }

    double getRadius() const {
        return radius_;
    }

    void getInfo() const {
        std::cout << "\nCircle with radius of: " << radius_ << " units.\n";
    }

    double getArea() const {
        return pi * radius_ * radius_;
    }

    void printArea() const {
        std::cout << "Area: " << getArea() << " units^2\n";
    }

    double getPerimeter() const {
        return 2 * pi * radius_;
    }
    
     void printPerimeter() const {
        std::cout << "Perimeter: " << getPerimeter() << " units\n\n";
    }

private:
    double radius_;
};

int main() {
    while(true) {
        std::cout << "Choose a shape: 1 for rectangle, 2 for circle, or 10 to exit: ";
        int choice;
        if (!(std::cin >> choice)) {
            clearBadInput();
            std::cout << "Invalid input. ";
            continue;
        } else {
            if (choice == 1) {
                double width, length;
                while(true) {
                    std::cout << "Enter width and length (with space between them): ";
                    if (!(std::cin >> width >> length)) {
                        clearBadInput();
                        std::cout << "Invalid input. Try again.\n";
                        continue;
                    } 
                    try {
                        Shape* shape = new Rectangle(width, length);
                        shape->getInfo();
                        shape->printArea();
                        shape->printPerimeter();
                        delete shape;
                        break;   
                    } catch(const std::invalid_argument& ex) {
                        std::cout << ex.what();
                    }
                    continue;
                }

            } else if (choice == 2){
                double radius;
                while(true){
                    std::cout << "Enter the radius: ";
                    if (!(std::cin >> radius)) {
                        clearBadInput();
                        std::cout << "Invalid input. Try again.\n";
                        continue;
                    } 
                    try {
                        Shape* shape = new Circle(radius);
                        shape->getInfo();
                        shape->printArea();
                        shape->printPerimeter();
                        delete shape;
                        break;
                    } catch(const std::invalid_argument& ex) {
                        std::cout << ex.what();
                        continue;
                    }
                }      

            } else if(choice == 10) {
                std::cout << "Exiting the program. . .\n";
                break;

            } else {
                std::cout << "Invalid choice. " ;
            }
        }
    }

    return 0;
}