#include "thuvien.h"

___QuanLySinhVien___ {
    system("cls");
    SetConsoleOutputCP(65001); 
    SetConsoleCP(65001);

    string ten_file = "du_lieu_sinh_vien.txt";
    Nodeptr list;

    while(1){
        In_banner();
        Doc_du_lieu_tu_file(ten_file, list);
        cout << YELLOW;
        cout << "┌─────── MENU ───────" << endl; 
        cout << "├ 0 - Thong tin" << endl;
        cout << "├ 1 - In danh sach" << endl;
        cout << "├ 2 - Them" << endl;
        cout << "├ 3 - Sua" << endl;
        cout << "├ 4 - Xoa" << endl;
        cout << "├ 5 - Tim kiem" << endl;
        cout << "├ 6 - Sap xep" << endl;
        cout << "├ 7 - Thong ke" << endl;
        cout << "├ 8 - Sao luu" << endl;
        cout << "├ 9 - Thoat" << endl;
        cout << "└──────> ";
        cout << GREEN << "Nhap lenh: " << RESET;
        char lua_chon = getche();
        cout << endl;
        if(lua_chon == '0'){
            system("cls");
            //cout << GREEN << "\n[" << lua_chon << "] Thong tin chuong trinh" << RESET << "\n";
            Tacgia();
        }
        else if(lua_chon == '1'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] In danh sach sinh vien" << RESET << "\n\n";
            In_thong_tin_sinh_vien(list);
        } 
        else if(lua_chon == '2'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] Them sinh vien vao danh sach" << RESET << "\n\n";
            Them_thong_tin_sinh_vien(list, ten_file);
        }
        else if(lua_chon == '3'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] Sua thong tin sinh vien" << RESET << "\n\n";
            Sua_thong_tin_sinh_vien(list, ten_file);
        } 
        else if(lua_chon == '4'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] Xoa sinh vien khoi danh sach" << RESET << "\n\n";
            Xoa_thong_tin_sinh_vien(list, ten_file); 
        } 
        else if(lua_chon == '5'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] Tim kiem thong tin sinh vien" << RESET << "\n\n";
            Tim_kiem_thong_tin_sinh_vien(list);
        }
        else if(lua_chon == '6'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] Sap xep sinh vien tu danh sach" << RESET << "\n\n";
            Sap_xep_thong_tin_sinh_vien(list, ten_file);
        }
        else if(lua_chon == '7'){
            system("cls");
            cout << GREEN << "\n[" << lua_chon << "] Thong ke danh sach sinh vien" << RESET << "\n\n";
            Thong_ke_thong_tin_sinh_vien(list);
        } 
        else if(lua_chon == '8'){
            cout << GREEN << "\n[" << lua_chon << "] Sao luu du lieu" << "\n\n";
            Ghi_du_lieu_vao_file(ten_file, list);
        } 
        else if(lua_chon == '9'){
            system("cls");
            cout << GREEN << "[" << lua_chon << "] Ban da chon thoat chuong trinh" << RESET << endl;
            In_banner_tam_biet();
            break;
        }
        else {
            cout << RED << "\n(!)Nhap sai vui long nhap lai !" << RESET << endl;
        }
        Stop_chuong_trinh();
        system("cls");
    }

    return 0;
}
