#include <iostream>
using namespace std;
class Print{
    public:
    //函数重载
    void print(int i){
        cout <<"整数:" << i <<endl;
    }

    void print(double d){
        cout <<"浮点数为:" << d <<endl;
    }

    void print(char *c){
        cout <<"字符串为:" << c <<endl;
    }
};