#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "tacgia.h"
using namespace std;

// Định nghĩa hàm main 
#define ___QuanLySinhVien___ signed main()

// Định nghĩa sinh viên
struct SinhVien {
    string ho_ten;
    int tuoi;
    string gioi_tinh;
    string ma_so;
    float diem;
};

// Định nghĩa Node
struct Node {
    SinhVien data;
    Node* link;
};

typedef Node* Nodeptr;

// Định nghĩa màu để in cùng cout
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33;1m"

// Các hàm phụ
int Lay_chieu_rong_terminal();
void In_giua_man_hinh(const string& cau, string mau);
void In_banner();
void In_banner_tam_biet();
void Stop_chuong_trinh();

// Các hàm tạo danh sách lien kết
void Khoi_tao_list(Nodeptr& list);
bool Kiem_tra_rong(Nodeptr& list);
int Kiem_tra_so_luong_node(Nodeptr& list);
Nodeptr Khoi_tao_node(SinhVien& sv);
bool Nhap_thong_tin_sinh_vien(SinhVien& sv);
void Xuat_thong_tin_sinh_vien(SinhVien& sv, int stt);
void Them_vao_cuoi_list(Nodeptr& list, Nodeptr& p);
void Xoa_node_dau_list(Nodeptr& list);
void Xoa_node_sau_Q(Nodeptr& list, Nodeptr& q);

// Hàm in bảng danh sách
void In_tieu_de_bang();
void In_chan_bang();
void In_bang_khong_co_sinh_vien();

// Phân tích tên 
string Lay_ten_cuoi(string ho_ten);
void Chuyen_ve_ky_tu_thuong(string& ho_ten);
void Chuyen_hoa_ky_tu_dau(string& gioi_tinh);

// Các hàm chính
void Tacgia(); 
void Doc_du_lieu_tu_file(string& ten_file, Nodeptr& list);
void Ghi_du_lieu_vao_file(string& ten_file, Nodeptr& list);
void In_thong_tin_sinh_vien(Nodeptr& list);
void Them_thong_tin_sinh_vien(Nodeptr& list, string& ten_file);
void Sua_thong_tin_sinh_vien(Nodeptr& list, string& ten_file);
void Xoa_thong_tin_sinh_vien(Nodeptr& list, string& ten_file);
void Tim_kiem_thong_tin_sinh_vien(Nodeptr& list);
void Sap_xep_thong_tin_sinh_vien(Nodeptr& list, string& ten_file);
void Thong_ke_thong_tin_sinh_vien(Nodeptr& list);
