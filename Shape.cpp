#include <iostream>
using namespace std;
class Shape{
    public:
    void setWidth(double w){
        width = w;
    }

    void setHeight(double h){
        height = h;
    }

    //虚函数
    // virtual int area(){
    //     cout << "Shape area is called" <<endl;
    //     return 0;
    // }

    //Or 纯虚函数
    virtual int area() = 0;

    protected:
    double width;
    double height;
};

class PaintCost{
    public:
    double getCost(int area){
        return area * 70;
    }
};

//多继承
class Rectangle:public Shape, public PaintCost{
    public:
    double getArea(){
      return (width * height);
    }

    int area(){
        cout <<"Rectangle area is called" <<endl;
        return (width * height);
    }

    Rectangle operator+(const Rectangle &s){
        Rectangle rec;
        rec.width = s.width + this->width;
        rec.height = s.height + this->height;
        return rec;
    }
};

class Triangle:public Shape{
    public:
    int area(){
        cout << "Triangle area is called" <<endl;
        return (width * height);
    }

};