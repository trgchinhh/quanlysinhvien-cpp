#include <iostream>
#include <string>
#include <windows.h>
#include "picosha2.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::ordered_json;

// Định nghĩa màu
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33;1m"

// Định nghĩa tên đăng nhập và mật khẩu 

string Lay_ten_dang_nhap_trong_file();
string Lay_mat_khau_trong_file();

// Định nghĩa struct tài khoản
struct TaiKhoanDangKy {
    string ten_dang_ky;
    string mat_khau_dang_ky;
};

struct TaiKhoanDangNhap {
    string ten_dang_nhap;
    string matkhau;
};

const string ten_file_tai_khoan = "taikhoan.json";

bool Kiem_tra_file_tai_khoan_rong(const string &ten_file_tai_khoan);

// Đăng ký
bool Cac_thuc_ten_dang_ky(string ten_dang_ky);
bool Xac_thuc_mat_khau_dang_ky(string mat_khau_dang_ky);
bool Nhap_thong_tin_dang_ky(TaiKhoanDangKy& taikhoan);
void Ghi_tai_khoan_dang_ky_vao_file(TaiKhoanDangKy taikhoan, const string &ten_file_tai_khoan);
void Xoa_tai_khoan_trong_file(const string &ten_file_tai_khoan);

// Đăng nhập và kiểm tra 
string Ma_hoa_thong_tin(const string& thong_tin);
bool Xac_thuc_ten_dang_nhap(string ten_dang_nhap);
bool Xac_thuc_mat_khau(string mat_khau);
bool Nhap_thong_tin_tai_khoan(TaiKhoanDangNhap& taikhoan);
void Cho_sau_khi_nhap_thanh_cong(int so_giay);