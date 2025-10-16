// Simple OOP Geometry Program
// Author: Fatemeh HadavandMirzaee
// Description: A basic code calculating area and perimeter of a rectangle and a circle.
// Demonstrates encapsulation and input validation
// Date: 16 October 2025

#include <iostream>

constexpr double pi = 3.14159265;

class Rectangle{
public:
    Rectangle(double width, double length){
        setWidth(width);
        setLength(length);
    }

    double getWidth(){
        return width_;
    }

    void setWidth(double width){
        if (width <= 0 ) {
            throw std::invalid_argument("width error \n");
        }
            width_ = width;
    }

    double getLength(){
        return length_;
    }

    void setLength(double length){
        if (length <= 0 ){
            throw std::invalid_argument("length error \n");
        }
        length_ = length;
    }

    double getArea(){
        return width_*length_;
    }

    double getPerimeter(){
        return 2*(length_ + width_);
    }

private:
    double width_; 
    double length_;
};

class Circle{
public:
    Circle(double radius){
        setRadius(radius);
    }

    double getRadius(){
        return radius_;
    }

    void setRadius(double radius){
        if ( radius <=0 ){
            throw std::invalid_argument("radius error \n");
        }
        radius_ = radius;
    }  

    double getArea(){
        return (pi * radius_ * radius_);
    }

    double getPerimeter(){
        return (2 * pi * radius_);
    }

private:
    double radius_;
};

int main() {

    Rectangle rect(4,5);
    std::cout << "Rectangle:\n";
    std::cout << "Area: " << rect.getArea() << " units^2 \n";
    std::cout << "Perimeter: " << rect.getPerimeter() << " units  \n\n";


    Circle circ(2);
    std::cout << "Circle:\n";
    std::cout << "Area: " << circ.getArea() << " units^2 \n";
    std::cout << "Perimeter: " << circ.getPerimeter() << " units  \n\n";

    return 0;
}