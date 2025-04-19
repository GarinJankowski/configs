#include <iostream>
#include <vector>
#include <string>
#include <cmath>

// Macro
#define PI 3.14159

// Template
template<typename T>
T square(T value) {
    return value * value;
}

// Class
class Shape {
public:
    virtual double area() const = 0;
    virtual std::string name() const { return "Shape"; }
    virtual ~Shape() = default;
};

// Inheritance
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return PI * square(radius);
    }

    std::string name() const override {
        return "Circle";
    }
};

// Function with control flow and STL usage
void printAreas(const std::vector<Shape