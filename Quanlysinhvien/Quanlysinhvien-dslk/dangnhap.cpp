#include "dangnhap.h"

// Mã hash của tên đăng nhập và mật khẩu 
string _TENDANGNHAP, _MATKHAU; 

bool Kiem_tra_file_tai_khoan_rong(const string &ten_file_tai_khoan){
    ifstream file(ten_file_tai_khoan);
    if(!file.is_open()){
        return false;
    }
    return file.peek() == ifstream::traits_type::eof();
}

bool xac_thuc_ten_dang_ky(string ten_dang_ky){
    if(ten_dang_ky.length() < 4){
        cout << RED << "\t\t\t(!) Ten dang ky phai tu 4 ky tu tro len !" << RESET << endl;
        return false;
    }
    return true;
}

bool Xac_thuc_mat_khau_dang_ky(string mat_khau_dang_ky){
    if(mat_khau_dang_ky.length() < 5){
        cout << RED << "\t\t\t(!) Mat khau dang ky phai tu 5 ky tu tro len !" << RESET << endl;
        return false;
    }
    return true;
}

bool Nhap_thong_tin_dang_ky(TaiKhoanDangKy& taikhoan){
    do {
        cout << YELLOW << "\t\t(?) Ten dang ky: " << RESET;
        getline(cin, taikhoan.ten_dang_ky);
        if(taikhoan.ten_dang_ky.empty()){
            cout << RED << "\t\t\t(!) Ten dang ky khong hop le !" << RESET << endl;
            return false;
        }
    } while(taikhoan.ten_dang_ky.empty() || !xac_thuc_ten_dang_ky(taikhoan.ten_dang_ky));

    do {
        cout << YELLOW << "\t\t(?) Nhap mat khau: " << RESET;
        getline(cin, taikhoan.mat_khau_dang_ky);
        if(taikhoan.mat_khau_dang_ky.empty()){
            cout << RED << "\t\t\t(!) Mat khau khong hop le !" << RESET << endl;
            return false;
        }
    } while(taikhoan.mat_khau_dang_ky.empty() || !Xac_thuc_mat_khau_dang_ky(taikhoan.mat_khau_dang_ky));

    return true;
}

void Ghi_tai_khoan_dang_ky_vao_file(TaiKhoanDangKy taikhoan, const string& ten_file_tai_khoan){
    ofstream file(ten_file_tai_khoan);
    if(!file.is_open()){
        cout << RED << "\t(!) Khong mo duoc file: " << ten_file_tai_khoan << endl;
        return;
    }
    json j;
    j["ten_dang_nhap"] = Ma_hoa_thong_tin(taikhoan.ten_dang_ky);
    j["mat_khau"] = Ma_hoa_thong_tin(taikhoan.mat_khau_dang_ky);
    file << j.dump(4);
    file.close();
    cout << GREEN << "\t(*) Da luu thong tin dang ky !" << RESET << endl;
}

void Xoa_tai_khoan_trong_file(const string &ten_file_tai_khoan){
    ifstream file1(ten_file_tai_khoan);
    if(file1.peek() == ifstream::traits_type::eof()){  
        cout << RED << "\n\t(!) Khong co tai khoan de xoa !" << RESET << endl;
        return;
    }
    file1.close();
    ofstream file(ten_file_tai_khoan, ios::trunc);
    if(!file.is_open()){
        cout << RED << "\n\t(!) Khong mo duoc file: " << ten_file_tai_khoan << endl;
        return;
    }
    cout << GREEN << "\n\t(*) Da xoa tai khoan !" << RESET << endl;
}

string Lay_ten_dang_nhap_trong_file(){
    if (Kiem_tra_file_tai_khoan_rong(ten_file_tai_khoan))
        return "";
    ifstream file(ten_file_tai_khoan);
    json j;
    file >> j;
    return j["ten_dang_nhap"].get<string>();
}

string Lay_mat_khau_trong_file(){
    if (Kiem_tra_file_tai_khoan_rong(ten_file_tai_khoan))
        return "";
    ifstream file(ten_file_tai_khoan);
    json j;
    file >> j;
    return j["mat_khau"].get<string>();
}

string Ma_hoa_thong_tin(const string &thong_tin){
    return picosha2::hash256_hex_string(thong_tin);
}

bool Xac_thuc_ten_dang_nhap(string ten_dang_nhap){
    _TENDANGNHAP = Lay_ten_dang_nhap_trong_file();
    if(Ma_hoa_thong_tin(ten_dang_nhap) != _TENDANGNHAP){
        cout << RED << "\t\t\t(!) Ten dang nhap khong hop le !" << RESET << endl;
        return false;
    }
    return true;
}

bool Xac_thuc_mat_khau(string mat_khau){
    _MATKHAU = Lay_mat_khau_trong_file();
    if(Ma_hoa_thong_tin(mat_khau) != _MATKHAU){
        cout << RED << "\t\t\t(!) Mat khau khong hop le !" << RESET << endl;
        return false;
    }
    return true;
}

bool Nhap_thong_tin_tai_khoan(TaiKhoanDangNhap &taikhoan){
    do {
        cout << YELLOW << "\t\t(?) Nhap ten dang nhap: " << RESET; 
        getline(cin, taikhoan.ten_dang_nhap);
        if(taikhoan.ten_dang_nhap.empty()){
            cout << RED << "\t\t\t(!) Ten dang nhap khong hop le !" << RESET << endl; 
            return false;
        }
    } while(taikhoan.ten_dang_nhap.empty() || !Xac_thuc_ten_dang_nhap(taikhoan.ten_dang_nhap));

    do {
        cout << YELLOW << "\t\t(?) Nhap mat khau: " << RESET;
        getline(cin, taikhoan.matkhau);
        if(taikhoan.matkhau.empty()){
            cout << RED << "\t\t\t(!) Mat khau khong hop le !" << RESET << endl;
            return false;
        }
    } while(taikhoan.ten_dang_nhap.empty() || !Xac_thuc_mat_khau(taikhoan.matkhau));
    return true;
}

void Cho_sau_khi_nhap_thanh_cong(int so_giay) {
    const char ky_tu[] = {'/', '-', '\\', '|'};
    int vi_tri = 0;

    for (int i = so_giay; i > 0; i--) {
        cout << YELLOW
             //<< "\r\t(" << ky_tu[vi_tri] << ") Vui long cho " << i << " giay ..." 
             << "\r\t(" << ky_tu[vi_tri] << ") Vui long cho trong giay lat..." 
             << RESET;
        cout.flush();

        vi_tri = (vi_tri + 1) % 4; 
        Sleep(1000);
    }
}
