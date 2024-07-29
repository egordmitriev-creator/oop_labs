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
    virtual float per(){
        return 0;
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

    ~line(){}

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

    ~square(){}

    void input() override{
        figure::input();
        cout << "Enter side length: ";
        cin >> side;
    }

    void display() override{
        figure::display();
        cout << "Side lenght: " << side << endl;
    }

    float per(){
        return 4 * side;
    }

    int area() const{
        return side * side;
    } 
};

class rectangle : public square{
    static inline unsigned count1;
    static inline unsigned count2;
    public:

    rectangle() : square(){
        height = rand() % 50 + 1;
        count1++;
        count2++;
    }

    rectangle(int x, int y, int width, int height) : square(x, y, width), height(height){
        count1++;
        count2++;
    }

    ~rectangle(){
        count2--;
    }

    void input() override{
        square::input();
        cout << "Enter height: ";
        cin >> height;
    }
    void display() override{
        square::display();
        cout << "Height: " << height << endl;
    }

    float per(){
        return 2 * (side * height);
    }

    int area() const{
        return side * height;
    }
    int show_count(){
    cout << "Count of creating objects: " << count1 << endl;
    cout << "Count of existing objects: " << count2 << endl;
};

    private:
    int height;
};

class circle : public figure {
    public:
    circle() : figure() {
        radius = rand() % 50 + 1;
    }

    circle(int x, int y, int radius) : figure(x, y), radius(radius) {}

    ~circle(){}

    void input() override {
        figure::input();
        cout << "Enter radius: ";
        cin >> radius;
    }

    void display() override {
        figure::display();
        cout << "Radius: " << radius << endl;
    }
    float per(){
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

    ~ellipse(){}

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
    float per(){
        return 4 * (((3.14 * semiMajorAxis * semiMinorAxis) + ((semiMajorAxis - semiMinorAxis) * (semiMajorAxis - semiMinorAxis))) / (semiMajorAxis + semiMinorAxis));
    }

    private:
    int semiMajorAxis, semiMinorAxis;
};

int main(){
    system("clear");
    srand(time(NULL));

    cout << "1" << endl;

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

    rectangle_default.show_count();
    cout << endl;

    cout << "2" << endl;
    rectangle *Rptr;
    rectangle_default.show_count();
    cout << endl;
    
    cout << "3" << endl;
    Rptr = new rectangle();
    rectangle_default.show_count();
    cout << endl;

    cout << "4" << endl;
    figure* figureArr[4];
    figureArr[0] = new square();
    figureArr[1] = new rectangle();
    figureArr[2] = new circle();
    figureArr[3] = new ellipse();
    rectangle_default.show_count();
    cout << endl;
    for(int i = 0; i < 4; i++){
        cout << "Perimetr " << i + 1 << " : " << figureArr[i] -> per() << endl;
    }
    cout << endl;

    cout << "5" << endl;
    for(int i = 0; i < 4; i++){
        delete figureArr[i];
    }
    rectangle_default.show_count();
    cout << endl;

    return 0;
}