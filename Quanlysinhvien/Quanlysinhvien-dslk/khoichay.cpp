/*********************************************\
 * File khởi chạy chương trình 
 * Dùng để build và chạy sau mỗi lần sửa
\*********************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

int main(){
    SetConsoleOutputCP(65001); 
    SetConsoleCP(65001);

    system("cls");
    cout << "Đang khởi động chương trình! Vui lòng chờ ...\n" << endl;

    #ifdef _MSC_VER
        cout << "Đang biên dịch bằng MSVC" << endl;
        system("cl chuongtrinh.cpp quanlysinhvien.cpp dangnhap.cpp /Fe:chuongtrinh.exe /link winmm.lib");
    #elif __GNUC__
        cout << "Đang biên dịch bằng GNU/CLANG" << endl;
        system("g++ chuongtrinh.cpp quanlysinhvien.cpp dangnhap.cpp -o chuongtrinh.exe -lwinmm");
    #else 
        cout << "Trình biên dịch không được hỗ trợ !!!" << endl;
        return -1;
    #endif 

    system("chuongtrinh.exe");

    return 0;
}