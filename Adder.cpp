#include <iostream>
using namespace std;
class Adder{
    public:

    //构造函数
    Adder(int i = 0){
        total = 0;
    }

    //对外的接口
    void add(int num){
        total += num;
    }

    //对外的接口
    int getTotal(){
        return total;
    }

    private:
    //对外隐藏的数据
    int total;
};