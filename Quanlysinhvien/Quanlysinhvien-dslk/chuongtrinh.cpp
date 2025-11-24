/*********************************************\
 * QUẢN LÝ DANH SÁCH SINH VIÊN
 * Tác giả: Nguyễn Trường Chinh
 *
 * Chức năng chính:
 *  • Tài khoản quản lý:
 *      - Đăng ký, Đăng nhập, Xóa 
 *  • Quản lý sinh viên:
 *      - Thêm, Xóa, Sửa, Tìm kiếm, Hiển thị
 *      - Sắp xếp, Thống kê, Xuất file CSV
 *  • Đăng xuất tài khoản
\*********************************************/


#include "quanlysinhvien.h"

// Định nghĩa nguyên mẫu hàm - tránh lỗi “undeclared identifier”
void ___DangKyDangNhap___(string ten_file, string ten_file_csv, Nodeptr list, int so_giay_dem_nguoc);
void ___QuanLySinhVien___(string ten_file, string ten_file_csv, Nodeptr list, int so_giay_dem_nguoc, string _TENNGUOIDUNG);

// Phần đăng nhập 
void ___DangKyDangNhap___(string ten_file, string ten_file_csv, Nodeptr list, int so_giay_dem_nguoc){
    while(1){
        system("cls");
        In_banner_dang_nhap();
        cout << YELLOW << endl;
        cout << "┌─────── MENU ───────" << endl; 
        cout << "├ 0 - Thong tin" << endl;
        cout << "├ 1 - Dang ky" << endl;
        cout << "├ 2 - Dang nhap" << endl;
        cout << "├ 3 - Xoa tai khoan" << endl;
        cout << "├ 4 - Thoat" << endl;
        cout << "└──────> ";
        cout << GREEN << "Nhap lenh: " << RESET;
        char lua_chon = getche();
        cout << endl;
        if(lua_chon == '0'){
            system("cls");
            Tacgia();
        } 
        else if(lua_chon == '1'){
            if(!Kiem_tra_file_tai_khoan_rong(ten_file_tai_khoan)){
                cout << RED << "\n\t(!) Tai khoan da duoc tao, Vui long dang nhap !" << RESET << endl;
                Stop_chuong_trinh();
                continue;
            }
            cout << GREEN << "\n\t (+) DANG KY TAI KHOAN" << RESET << endl;
            TaiKhoanDangKy taikhoan;
            if(Nhap_thong_tin_dang_ky(taikhoan)){
                cout << GREEN << "\t\t(*) Dang ky tai khoan thanh cong !" << RESET << endl;
                Ghi_tai_khoan_dang_ky_vao_file(taikhoan, ten_file_tai_khoan);
            }
        }
        else if(lua_chon == '2'){
            if(Kiem_tra_file_tai_khoan_rong(ten_file_tai_khoan)){
                cout << RED << "\n\t(!) Tai khoan chua duoc tao, Vui long dang ky !" << RESET << endl;
                Stop_chuong_trinh();
                continue;
            }
            cout << GREEN << "\n\t(+) DANG NHAP TAI KHOAN" << RESET << endl;
            TaiKhoanDangNhap taikhoan;
            if(Nhap_thong_tin_tai_khoan(taikhoan)){
                string _TENNGUOIDUNG = taikhoan.ten_dang_nhap;
                cout << GREEN << "\t\t(*) Dang nhap thanh cong !" << RESET << endl;
                Cho_sau_khi_nhap_thanh_cong(so_giay_dem_nguoc);
                ___QuanLySinhVien___(ten_file, ten_file_csv, list, so_giay_dem_nguoc, _TENNGUOIDUNG);
            }
        }
        else if(lua_chon == '3'){
            Xoa_tai_khoan_trong_file(ten_file_tai_khoan);
        }
        else if(lua_chon == '4'){
            system("cls");
            In_banner_tam_biet();
            exit(0);
        }
        else {
            cout << RED << "\n(!) NHAP SAI VUI LONG NHAP LAI !" << RESET << endl;
        }
        Stop_chuong_trinh();
    }
}

// Chương trình chính 
void ___QuanLySinhVien___(string ten_file, string ten_file_csv, Nodeptr list, int so_giay_dem_nguoc, string _TENNGUOIDUNG) {
    while(1){
        system("cls");
        In_banner();
        Doc_du_lieu_tu_file(ten_file, list);
        Chuyen_hoa_ky_tu_dau(_TENNGUOIDUNG);
        cout << YELLOW << "┌──────────────────────────┐" << RESET << endl;
        cout << YELLOW << "│(-) Tai khoan: " << GREEN << left << setw(11) <<  _TENNGUOIDUNG <<  YELLOW << "│" << endl;
        cout << YELLOW << "└──────────────────────────┘" << "\n\n";
        cout << "┌────────── MENU ──────────" << endl; 
        cout << "├ 1 - In danh sach" << endl;
        cout << "├ 2 - Them" << endl;
        cout << "├ 3 - Sua" << endl;
        cout << "├ 4 - Xoa" << endl;
        cout << "├ 5 - Tim kiem" << endl;
        cout << "├ 6 - Sap xep" << endl;
        cout << "├ 7 - Thong ke" << endl;
        cout << "├ 8 - Xuat file.csv" << endl;
        cout << "├ 9 - Dang xuat" << endl;
        cout << "└──────────> ";
        cout << GREEN << "Nhap lenh: " << RESET;
        char lua_chon = getche();
        cout << endl;
        if(lua_chon == '1'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] IN DANH SACH SINH VIEN" << RESET << "\n\n";
            In_thong_tin_sinh_vien(list);
        } 
        else if(lua_chon == '2'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] THEM SINH VIEN VAO DANH SACH" << RESET << "\n\n";
            Them_thong_tin_sinh_vien(list, ten_file);
        }
        else if(lua_chon == '3'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] SUA THONG TIN SINH VIEN" << RESET << "\n\n";
            Sua_thong_tin_sinh_vien(list, ten_file);
        } 
        else if(lua_chon == '4'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] XOA SINH VIEN KHOI DANH SACH" << RESET << "\n\n";
            Xoa_thong_tin_sinh_vien(list, ten_file); 
        } 
        else if(lua_chon == '5'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] TIM KIEM THONG TIN SINH VIEN" << RESET << "\n\n";
            Tim_kiem_thong_tin_sinh_vien(list);
        }
        else if(lua_chon == '6'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] SAP XEP SINH VIEN TU DANH SACH" << RESET << "\n\n";
            Sap_xep_thong_tin_sinh_vien(list, ten_file);
        }       
        else if(lua_chon == '7'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] THONG KE DANH SACH SINH VIEN" << RESET << "\n\n";
            Thong_ke_thong_tin_sinh_vien(list);
        } 
        else if(lua_chon == '8'){
            cout << GREEN << "\n[" << lua_chon << "] SAO LUU DU LIEU RA FILE.CSV" << "\n\n";
            Ghi_du_lieu_vao_file_csv(ten_file_csv, list);
        } 
        else if(lua_chon == '9'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] BAN DA CHON QUAY LAI TRANG DANG NHAP !" << RESET << "\n\n";
            Cho_sau_khi_nhap_thanh_cong(so_giay_dem_nguoc);
            ___DangKyDangNhap___(ten_file, ten_file_csv, list, so_giay_dem_nguoc);
        }
        else {
            cout << RED << "\n(!) NHAP SAI VUI LONG NHAP LAI !" << RESET << endl;
        }
        Stop_chuong_trinh();
    }
}

// Main
___TruongChinh___ {
    system("cls");
    
    // Dùng để in ký tự đặc biệt - tránh lỗi font 
    SetConsoleOutputCP(65001); 
    SetConsoleCP(65001);

    string ten_file = "dulieusinhvien.txt";
    string ten_file_csv = "dulieusinhvien.csv";
    Nodeptr list; 
    int so_giay_dem_nguoc = 3; 
    ___DangKyDangNhap___(ten_file, ten_file_csv, list, so_giay_dem_nguoc);
    return 0;
}