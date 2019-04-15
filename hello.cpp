#include <iostream>
#include "Person.cpp"
#include "Shape.cpp"
#include "Print.cpp"
#include "Adder.cpp"
using namespace std;

class Box{
   public:
   double length; //长
   double width;  //款
   double height; //高
   static int objectCount; //静态成员
   double getVolum(void);
   void setLength(double l);
   void setWidth(double w);
   void setHeight(double h);
      bool compareWidth(Box box1){
      return this->width > box1.width;
   }
   Box(void);     //类构造函数
   // Box(double w = 1, double h = 1, double l = 1){
   //    width = w;
   //    height = h;
   //    length = l;
   //    objectCount++;
   // };

   //静态函数
   static int getObjectCount(void){
      return objectCount;
   };

   ~Box(void);    //类析构函数
   friend void printWidth(Box box);
};

//初始化静态变量
int Box::objectCount = 0;

double Box::getVolum(void){
   return length * width * height;
}

void Box::setLength(double l){
   length = l;
}

void Box::setHeight(double h){
   height = h;
}

void Box::setWidth(double w){
   width = w;
}

Box::Box(void){
   cout << "box is created" <<endl;
   objectCount++;
}

Box::~Box(void){
   cout << "box is deleted" <<endl;
}

void printWidth(Box box){
   cout << box.width <<endl;
}

void demo0(){
cout << "Please enter your name: ";
string name;
    cin >> name;
    cout << "Hello, " << name;
    cout << "\n";
}

void demo1(){
   cout << "Size of char : " << sizeof(char) << endl;
        cout << "Size of int : " << sizeof(int) << endl;
        cout << "Size of short int : " << sizeof(short int) << endl;
        cout << "Size of long int : " << sizeof(long int) << endl;
        cout << "Size of float : " << sizeof(float) << endl;
        cout << "Size of double : " << sizeof(double) << endl;
        cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
}

//指针
void demo2(){
   int a = 20;
   int *p;
   p = &a;
   cout << "a的地址为:" <<endl;
   cout << p << endl;
}

//引用
void demo3(){
   int i;
   double d;
   int& r = i;
   double& s = d;
   i = 5;
   cout << "value of i is " << i << endl;
   cout << "value of reference i is " << r << endl;
   d = 1.15;
   cout << "value of d is " << d << endl;
   cout << "value of reference d is " << s << endl;
}

void swap(int& a, int& b){
   int temp = a;
   a = b;
   b = temp;
}

//引用运用  
void demo4(){
   int a = 10; 
   int b = 20;
   cout << "交换前a = " << a <<endl;
   cout << "交换前b = " << b <<endl;
   swap(a,b);
   cout << "交换后a =" << a <<endl;
   cout << "交换后b =" << b <<endl;
}

void demo5(){
   Box box1;
   box1.setWidth(10);
   box1.setHeight(10);
   box1.setLength(20);
   double volumn = box1.getVolum();
   cout << "体积为:"<< volumn <<endl;
   cout << "********" <<endl;
   printWidth(box1);
}


//指向类的指针
void demo6(){
   Box box1;
   Box box2;
   Box *boxPtr;
   box1.setWidth(10);
   box1.setHeight(20);
   box1.setLength(10);

   box2.setWidth(20);
   box2.setHeight(20);
   box2.setLength(20);

   boxPtr = &box1;
   cout << "box1 体积为:" << boxPtr->getVolum() <<endl;
   boxPtr = &box2;
   cout << "box2 体积为:" << boxPtr->getVolum() <<endl;
}

//this关键字
void demo7(){
   Box box1;
   Box box2;
   box1.setWidth(30);
   box2.setWidth(20);
   if(box1.compareWidth(box2)){
      cout << "box1 宽度比 box2 大" <<endl;
   }
   else{
      cout << "box2 宽度比 box1 大" <<endl;
   }
}

//静态成员
void demo8(){
   Box box1;
   Box box2;
   cout << "box对象个数为:" << Box::getObjectCount() <<endl;
}

void demo9(){
   Person p1;
   // p1.name = "Shine";
   // p1.age = 10;
   cout << "p1.name is :" << p1.name <<endl;

}

void demo10(){
    Rectangle r1;
    r1.setWidth(10);
    r1.setHeight(20);
    cout << "r1体积为:" <<r1.getArea() <<endl;
}

//多继承
void demo11(){
    Rectangle r1;
    r1.setWidth(10);
    r1.setHeight(20);
    double area = r1.getArea();
    double cost = r1.getCost(area);
    cout <<"r1的花费是:" <<cost<<endl;
}

//函数重载
void demo12(){
    Print p1;
    p1.print(12);
    p1.print(2.34);
    p1.print("小强你好");
}

//运算符重载
void demo13(){
    Rectangle r1,r2,r3;
    r1.setWidth(10);
    r1.setHeight(10);
    r2.setWidth(20);
    r2.setHeight(20);
    r3 = r1+r2;
    cout <<"r3的体积为:" << r3.getArea() <<endl;

}

//多态
void demo14(){
    Shape *s1;
    Rectangle r1;
    Triangle t1;
    r1.setWidth(10);
    r1.setHeight(10);

    t1.setWidth(20);
    t1.setHeight(20);

    s1 = &r1;
    cout <<s1->area()<<endl;
    s1 = &t1;
    cout <<s1->area()<<endl;
}

//抽象
void demo15(){
    Adder adder;
    adder.add(10);
    adder.add(50);
    adder.add(20);
    cout<< adder.getTotal()<<endl;
}

int main()
{
   demo15();
   return 0;
}