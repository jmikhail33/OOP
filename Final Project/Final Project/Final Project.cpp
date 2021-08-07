/* Final project for class : CIS - 2541.

The following code represents inheritance, encapsulation concepts using c++ programming language.
In which 3 subclasses: (circle, Cube, Square) inherit from the parent class: Geometry.
Each subclass contains a constructor with hardcoded values, 
accessors and mutators methods in order to access the private attributes of the subclass.
the program creates random objects depending on a random choosen number from {1,2,3} 
then it appends the object into a static array.
After that, using looping concept, the program iterates through the static array to output the results.
the user has two choices to depict the results, either on the console screen, or to write it into a file.

Name: JOHN MIKHAIL*/

#include <iostream>
#include <numeric>
#include <cmath>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Geometry {

public:
    string color = " Blue";
    Geometry() {

    }
    void printColor() {
        cout << " Color: " << color << endl;
    }

    virtual string calArea() {
        return "Area = 0\n Shape: Unknown";

    }
};

class Circle:public Geometry{
private:
    double Radius;
public:
    Circle(double radius = 5) {
        Radius = radius;
    }
    void setRadius(double radius) {
        Radius = radius;
    }
    double getRadius() {
        return Radius;
    }
    string calArea() {
        double area = double(3.14) * (pow(Radius, 2));
        return "\n Shape Type: Circle\n Radius = " + to_string(Radius).substr(0, 3)
            + " cm\n Area: " + to_string(area).substr(0, 5);
    }
};


class Cube:public Geometry {
private:
    double Length, Height, Width;
public:
    Cube(double length = 6,double height =6,double width =6) {
        Length = length;
        Height = height;
        Width = width;
    }
    void setLength(double length) {
        Length = length;
    }
    double getLength() {
        return Length;
    }
    void setHeight(double height) {
        Height = height;
    }
    double getHeight() {
        return Height;
    }
    void setWidth(double width) {
        Width = width;
    }
    double getWidth() {
        return Width;
    }
    string calArea() {
        double area = (2 * Length * Width) + (4 * Length * Height);
        return "\n Shape Type: Cube"
            "\n Length = " + to_string(Length).substr(0,3) +
            " cm\n Width = " + to_string(Width).substr(0,3) +
            " cm\n Height = "+to_string(Height).substr(0,3) +
            " cm\n Area = "+ to_string(area).substr(0,5)+" cm^2";
    }
};


class Square :public Geometry {
private:
    double Side;
public:
    Square(double side = 5.3) {
        Side = side;
    }
    void setSide(double side) {
        Side = side;
    }
    double getSide() {
        return Side;
    }
    string calArea() {
        double area = (pow(Side, 2));
        return "\n Shape Type: Square\n Side = "
            + to_string(Side).substr(0,3) +
            "cm\n Area = " + to_string(area).substr(0,4) + " cm^2";
    }
};

int main()
{
    const int Cap = 10;
    Geometry* Shapes[Cap];
    srand(time(0));
    for (int i = 0; i < Cap; i++) {
        int randomIndex = (rand() % 3) + 1;

        if (randomIndex == 3) {
            Shapes[i] = new Cube();
        }

        else if (randomIndex == 1) {
            Shapes[i] = new Circle();
        }

        else if (randomIndex == 2) {
            Shapes[i] = new Square();
        }

    }

    int input;
    cout << " Enter:"
    "\n <1> to Print the results on the screen"
    "\n <2> to save the results into a file ";
    cin >> input;

    if (input == 1) {
        for (int i = 0; i < Cap; i++) {
            cout << Shapes[i]->calArea();
            cout << "\n" << endl;
        }
    }

    else {
        string fileName;
        cout << "\n Enter the file name: ";
        cin >> fileName;
        fstream resultsFile;
        resultsFile.open(fileName, ios::out);
        if (resultsFile.is_open()) {

            for(int i = 0 ; i < Cap ; i++){
                resultsFile << Shapes[i]->calArea();
                resultsFile << "\n" << endl;
            }
        } 
    }
    system("pause>0");
}
