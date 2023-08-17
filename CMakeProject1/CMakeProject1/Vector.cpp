#include <iostream>
#include"Vector.h"

using std::cout;
using std::endl;
//重载运算符测试
void Vector_cal_test() {
    Vector<int> v1;
    Vector<int> v2;
    v1.push_back(4);
    v2.push_back(3);
    cout << "v1现值：" << v1[0] <<endl;
    cout << "v2现值：" << v2[0] << endl;
    cout << "=运算符重载测试" << endl;
    v1 = v2;
    cout << "v1赋值后值：" << v1[0] << endl;

    
    cout << "v1==v2运算符重载测试" << endl;
    if (v1 == v2) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

//增删实例化对象
void Vector_io_test() {
    Vector<char> v3;
    Vector<char> v4;
    v3.push_back('a');
    v3.push_back('a');
    v3.push_back('a');
    v3.insert(v3.begin(), 'b');
    v3.erase(v3.begin()+1 );
    cout <<"第一个对象：" << v3.front() << endl;
    
    v3.pop_back();
    cout << "最后一个对象：" << v3.back() << endl;
    for (auto c : v3) {
        cout << c;
    }
    cout << endl;

}

//提取vector信息
void Vector_inf_test() {
    Vector<int> v1;
    Vector<int> v2;
    if (v1.empty()) {
        cout << "空" << endl;
    }
    else {
        cout << "非空" << endl;
    }
    v1.push_back(1);
    v1.push_back(2);
    cout <<"对象个数" << v1.size() << endl;
    cout << "Vector容量"<<v1.capacity() << endl;
}