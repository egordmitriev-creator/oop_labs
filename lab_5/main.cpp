#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

class figure{
    public:
    figure(){
        x = rand() % 100;
        y = rand() % 100;
    }
    
    figure(int x, int y) : x(x), y(y) {}
    
    virtual ~figure(){}

    virtual void input(){
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    virtual void display(){
        cout << "Coordinates: (" << x << "," << y << ")" << endl;
    }

    protected:
    int x, y;
};

class line : public figure{
    public:
    line() : figure(){
        len = 0;
        calculateLen();
    }

    line(int x1, int y1, int x2, int y2) : figure(x1, y1), x2(x2), y2(y2){
        calculateLen();
    }

    ~line() override{}

    void input() override{
        figure::input();
        cout << "Enter x2: ";
        cin >> x2;
        cout << "Enter y2: ";
        cin >> y2;
        calculateLen();
    }

    void display() override{
        figure::display();
        cout << "End coordiates: (" << x2 << "," << y2 << ")" << endl;
        cout << "Length: " << len << endl; 
    }

    private:
    int x2, y2;
    double len;

    void calculateLen(){
        len = sqrt(pow(x2 - x, 2) + pow(y2 - y,2));
    }
};

class square : public line{
    public:
    int side;
    square() : line(){
        side = rand() % 50 + 1;
    }

    square(int x, int y, int side) : line(x, y, x + side, y), side(side){}

    ~square() override{}

    void input() override{
        figure::input();
        cout << "Enter side length: ";
        cin >> side;
    }

    void display() override{
        figure::display();
        cout << "Side lenght: " << side << endl;
    }

    int per() const{
        return 4 * side;
    }

    int area() const{
        return side * side;
    } 
};

class rectangle : public square{
    public:
    rectangle() : square(){
        height = rand() % 50 + 1;
    }

    rectangle(int x, int y, int width, int height) : square(x, y, width), height(height){}

    ~rectangle() override{}

    void input() override{
        square::input();
        cout << "Enter height: ";
        cin >> height;
    }
    void display() override{
        square::display();
        cout << "Height: " << height << endl;
    }

    int per() const{
        return 2 * (side * height);
    }

    int area() const{
        return side * height;
    }

    private:
    int height;
};

class circle : public figure {
    public:
    circle() : figure() {
        radius = rand() % 50 + 1;
    }

    circle(int x, int y, int radius) : figure(x, y), radius(radius) {}

    ~circle() override {}

    void input() override {
        figure::input();
        cout << "Enter radius: ";
        cin >> radius;
    }

    void display() override {
        figure::display();
        cout << "Radius: " << radius << endl;
    }

    double per() const{
        return 2 * radius * 3.14;
    }

    protected:
    int radius;
};

class ellipse : public circle {
    public:
    ellipse() : circle() {
        semiMajorAxis = rand() % 50 + 1;
        semiMinorAxis = rand() % 50 + 1;
    }

    ellipse(int x, int y, int semiMajorAxis, int semiMinorAxis) : circle(x, y, semiMajorAxis), semiMajorAxis(semiMajorAxis), semiMinorAxis(semiMinorAxis) {}

    ~ellipse() override {}

    void input() override {
        circle::input();
        cout << "Enter semi-major axis: ";
        cin >> semiMajorAxis;
        cout << "Enter semi-minor axis: ";
        cin >> semiMinorAxis;
    }

    void display() override {
        circle::display();
        cout << "Semi-major axis: " << semiMajorAxis << endl;
        cout << "Semi-minor axis: " << semiMinorAxis << endl;
    }
    double per(){
        return 4 * (((3.14 * semiMajorAxis * semiMinorAxis) + ((semiMajorAxis - semiMinorAxis) * (semiMajorAxis - semiMinorAxis))) / (semiMajorAxis + semiMinorAxis));
    }

    private:
    int semiMajorAxis, semiMinorAxis;
};

int main(){
    srand(time(NULL));
    
    line line_default;
    line line_par(10, 20, 30, 40);

    square square_default;
    square square_par(70, 80, 30);
    
    rectangle rectangle_default;
    rectangle rectangle_par(90, 100, 35, 45);
    
    circle circle_default;
    circle circle_par(50, 60, 25);

    ellipse ellipse_default;
    ellipse ellipse_par(35, 55, 20, 15);

    cout << "line" << endl;
    line_default.input();
    line_default.display();
    line_par.display();
    cout << endl;
    
    cout << "square" << endl;
    square_default.input();
    cout << endl;
    square_default.display();
    cout << "Perimetr: " << square_default.per() << endl;
    cout << "Area: " << square_default.area() << endl;
    cout << endl;

    cout << "rectangle" << endl;
    rectangle_default.input();
    cout << endl;
    rectangle_default.display();
    cout << "Perimetr: " << rectangle_default.per() << endl;
    cout << "Area: " << rectangle_default.area() << endl;

    rectangle *rectArr = new rectangle[3]{
        rectangle(110, 120, 15,30),
        rectangle(130, 140, 20, 40),
        rectangle(150, 160, 25, 50)
    };

    for(int i = 0; i < 3; i++){
        cout << "rectangle " << i << endl;
        rectArr[i].display();
        cout << "Perimetr: " << rectArr[i].per() << endl;
        cout << "Area: " << rectArr[i].area() << endl;
    }
    delete[] rectArr;

    return 0;
}