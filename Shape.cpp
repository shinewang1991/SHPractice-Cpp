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

    //加了const的引用(常量引用),既避免了拷贝，有避免了函数对值的修改
    // void changeWidth(const Triangle &t){
    //     t.width = 30;   //会报错。修改不了
    // }

    //加static修饰的函数,无法修改成员变量
    //  static void changeWidth(){
    //     width = 20;
    // }

};