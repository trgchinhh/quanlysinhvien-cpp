#include "quanlysinhvien.h"

int Lay_chieu_rong_terminal(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int chieu_rong;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)){
        chieu_rong = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return chieu_rong;
}

void In_giua_man_hinh(const string& cau, string mau) {
    int chieu_rong = Lay_chieu_rong_terminal();  
    int do_dai = cau.length();
    int khoang_trang = (chieu_rong - do_dai) / 2;
    if (khoang_trang < 0) khoang_trang = 0;
    cout << mau << string(khoang_trang, ' ') << cau << RESET;
}

void In_banner_dang_nhap(){
    string banner = R"(DANH SACH LIEN KET DON C++
 _____          _   _  _____    _   _ _    _          _____  
|  __ \   /\   | \ | |/ ____|  | \ | | |  | |   /\   |  __ \ 
| |  | | /  \  |  \| | |  __   |  \| | |__| |  /  \  | |__) |
| |  | |/ /\ \ | . ` | | |_ |  | . ` |  __  | / /\ \ |  ___/ 
| |__| / ____ \| |\  | |__| |  | |\  | |  | |/ ____ \| |     
|_____/_/    \_\_| \_|\_____|  |_| \_|_|  |_/_/    \_\_|     
    )";
    stringstream ss(banner);
    string line;
    cout << endl;
    while (getline(ss, line)) {
        In_giua_man_hinh(line, YELLOW);
        cout << endl;
        Sleep(10);
    }
}

void In_banner(){
    string banner = R"(DANH SACH LIEN KET DON C++
  ____  _    _         _   _    _  __     __   _____ _____ _   _ _    _   __      _______ ______ _   _ 
 / __ \| |  | |  /\   | \ | |  | | \ \   / /  / ____|_   _| \ | | |  | |  \ \    / /_   _|  ____| \ | |
| |  | | |  | | /  \  |  \| |  | |  \ \_/ /  | (___   | | |  \| | |__| |   \ \  / /  | | | |__  |  \| |
| |  | | |  | |/ /\ \ | . ` |  | |   \   /    \___ \  | | | . ` |  __  |    \ \/ /   | | |  __| | . ` |
| |__| | |__| / ____ \| |\  |  | |____| |    _ ___) |_| |_| |\  | |  | |     \  /   _| |_| |____| |\  |
 \___\_\\____/_/    \_\_| \_|  |______|_|    |_____/|_____|_| \_|_|  |_|      \/   |_____|______|_| \_|
    )";
    stringstream ss(banner);
    string line;
    cout << endl;
    while (getline(ss, line)) {
        In_giua_man_hinh(line, YELLOW);
        cout << endl;
        Sleep(10);
    }
}

void In_banner_tam_biet(){
    string banner = R"(DANH SACH LIEN KET DON C++
 _    _ ______ _   _     _____          _____     _               _____ 
| |  | |  ____| \ | |   / ____|   /\   |  __ \   | |        /\   |_   _|
| |__| | |__  |  \| |  | |  __   /  \  | |__) |  | |       /  \    | |  
|  __  |  __| | . ` |  | | |_ | / /\ \ |  ___/   | |      / /\ \   | |  
| |  | | |____| |\  |  | |__| |/ ____ \| |       | |____ / ____ \ _| |_ 
|_|  |_|______|_| \_|   \_____/_/    \_\_|       |______/_/    \_\_____|
    )";
    stringstream ss(banner);
    string line;
    cout << endl;
    while (getline(ss, line)) {
        In_giua_man_hinh(line, YELLOW);
        cout << endl;
        Sleep(10);
    }
}

void Stop_chuong_trinh(){
    cout << GREEN << "\n\tNhan phim bat ky de tiep tuc..." << RESET;
    getch();
}

void Khoi_tao_list(Nodeptr& list){
    list = NULL;
}

bool Kiem_tra_rong(Nodeptr& list){
    return list == NULL;
}

Nodeptr Khoi_tao_node(SinhVien& sv){
    Nodeptr p = new Node();
    p->data = sv;
    p->link = NULL;
    return p; 
}

int Kiem_tra_so_luong_node(Nodeptr& list){
    Nodeptr p = list;
    int cnt = 0;
    while(p != NULL){ 
        cnt++;
        p=p->link;
    }
    return cnt;
}

bool Nhap_thong_tin_sinh_vien(SinhVien& sv){
    cin.ignore();
    cout << GREEN << "\t\t(?) Nhap ten: " << RESET; getline(cin, sv.ho_ten);
    if(sv.ho_ten.empty()){
        cout << RED << "\t\t(!) Ten sinh vien khong duoc de trong !" << RESET << endl;
        return false;
    }
    cout << GREEN << "\t\t(?) Nhap tuoi: " << RESET; cin >> sv.tuoi;
    if(sv.tuoi < 18 || sv.tuoi > 40){
        cout << RED << "\t\t(!) Tuoi sinh vien phai tu 18 -> 40 !" << RESET << endl;
        return false;
    } 
    cout << GREEN << "\t\t(?) Nhap gioi tinh (nam/nu): " << RESET; cin >> sv.gioi_tinh;
    Chuyen_hoa_ky_tu_dau(sv.gioi_tinh);
    if(sv.gioi_tinh.empty() && sv.gioi_tinh != "Nam" && sv.gioi_tinh != "Nu"){
        cout << RED << "\t\t(!) Gioi tinh sinh vien phai la nam hoac nu !" << RESET << endl;
        return false;
    } 
    cin.ignore();
    cout << GREEN << "\t\t(?) Nhap ma so: " << RESET; getline(cin, sv.ma_so);
    if(sv.ma_so.empty()){
        cout << RED << "\t\t(!) Ma so sinh vien khong duoc de trong !" << RESET << endl;
        return false;
    }
    cout << GREEN << "\t\t(?) Nhap diem: " << RESET; cin >> sv.diem;
    if(sv.diem > 10 || sv.diem < 0){
        cout << RED << "\t\t(!) Diem sinh vien phai tu 0 -> 10 !" << RESET << endl;
        return false;
    } 
    return true;
}

void Xuat_thong_tin_sinh_vien(SinhVien& sv, int stt){
    cout << YELLOW << "\t│ " << setw(3) << stt++ << " │ "
     << setw(25) << left << sv.ho_ten << " │ "
     << setw(4) << left << sv.tuoi << " │ "
     << setw(5) << left << sv.gioi_tinh << " │ "
     << setw(12) << left << sv.ma_so << " │ "
     << setw(5) << fixed << setprecision(1) << sv.diem << " │\n" << RESET;
    Sleep(10);
}

void Them_vao_cuoi_list(Nodeptr& list, Nodeptr& p){
    if(Kiem_tra_rong(list)){
        list = p;
        return;
    }
    Nodeptr q = list;
    while(q->link != NULL){
        q = q->link;
    }
    q->link = p;
}

void Xoa_node_dau_list(Nodeptr& list){
    if(!Kiem_tra_rong(list)){
        Nodeptr p = list;
        list = list ->link;
        delete p;
    }
}

void Xoa_node_sau_Q(Nodeptr& list, Nodeptr& q){
    Nodeptr p = q->link;
    if(p != NULL){
        q->link = p->link;
        delete p;
    }
}

void Doc_du_lieu_tu_file(string& ten_file, Nodeptr& list){
    ifstream file(ten_file);
    if(!file.is_open()){
        cout << RED << "\t(!) Khong the tai du lieu tu file: " << ten_file << RESET << endl;
        return;
    }
    SinhVien sv; Nodeptr p;
    Khoi_tao_list(list);
    string line;
    while(getline(file, line)){
        if(line.empty()) continue;
        stringstream ss(line);
        string tuoi_str, diem_str;
        getline(ss, sv.ho_ten, '-');     
        getline(ss, tuoi_str, '-'); 
        getline(ss, sv.gioi_tinh, '-');      
        getline(ss, sv.ma_so, '-');       
        getline(ss, diem_str, '-');       

        sv.tuoi = stoi(tuoi_str);
        sv.diem = stof(diem_str);

        p = Khoi_tao_node(sv);
        Them_vao_cuoi_list(list, p);
    }
    file.close();
}

void Ghi_du_lieu_vao_file(string& ten_file, Nodeptr& list){
    ofstream file(ten_file);
    if(!file.is_open() || Kiem_tra_rong(list)){
        cout << RED << "\t(!) Khong the ghi vao file: " << ten_file << RESET << endl;
    }
    Nodeptr p = list;
    int co_luu = 0;
    while(p != NULL){
        file << p->data.ho_ten << '-' << p->data.tuoi << '-' << p->data.gioi_tinh << '-' << p->data.ma_so << '-' << p->data.diem << "\n";
        p = p->link;
        co_luu = 1;
    }
    if(co_luu){
        cout << GREEN << "\t(*) Da luu du lieu vao file !" << RESET << endl;
    }
}

void Ghi_du_lieu_vao_file_csv(string &ten_file_csv, Nodeptr &list){
    ofstream file(ten_file_csv);
    if(!file.is_open() || Kiem_tra_rong(list)){
        cout << RED << "\t(!) Khong co noi dung de ghi vao file: " << ten_file_csv << RESET << endl;
    }
    file << "STT,Ho Ten,Tuoi,Gioi tinh,Ma so sinh vien,Diem" << endl;
    Nodeptr p = list; int stt = 0;
    while(p != NULL){
        file << ++stt << ",";
        file << p->data.ho_ten << ",";
        file << p->data.tuoi << ",";
        file << p->data.gioi_tinh << ",";
        file << p->data.ma_so << ",";
        file << p->data.diem << "\n";
        p=p->link;
    }
    file.close();
    cout << GREEN << "\t(*) Da tao file: " << ten_file_csv << " thanh cong !" << RESET << endl;
}

void Xoa_file_csv(string &ten_file_csv){
    ifstream file(ten_file_csv);
    if(!file){
        cout << RED << "\t(!) Khong co file.csv nao de xoa !" << endl;
        return;
    }
    file.close();
    if(remove(ten_file_csv.c_str()) == 0){
        cout << GREEN << "\t(*) Da xoa file: " << ten_file_csv << " thanh cong !" << RESET << endl;
    } else {
        cout << RED  << "\t(!) Khong the xoa file: " << ten_file_csv << " vi co chuong trinh thu 3 can thiep !" << RESET << endl;
    }
}

void In_thong_tin_sinh_vien(Nodeptr& list){
    In_tieu_de_bang();
    int stt = 1;
    if(Kiem_tra_rong(list)){
        In_bang_khong_co_sinh_vien();
    } else {
        Nodeptr p = list;
        while(p != NULL){
            Xuat_thong_tin_sinh_vien(p->data, stt);
            p=p->link; 
            stt++;
        }
    }
    In_chan_bang();
}

void In_tieu_de_bang(){
    cout << YELLOW 
         << "\t┌─────┬───────────────────────────┬──────┬───────┬──────────────┬───────┐\n";
    cout << "\t│ STT │ Ho Ten                    │ Tuoi │  GT   │ MSSV         │ Diem  │\n";
    cout << "\t├─────┼───────────────────────────┼──────┼───────┼──────────────┼───────┤\n";
    cout << RESET;
}

void In_chan_bang(){
    cout << YELLOW 
         << "\t└─────┴───────────────────────────┴──────┴───────┴──────────────┴───────┘\n" << RESET;
}


void In_bang_khong_co_sinh_vien(){
    string msg = "Khong co sinh vien nao";
    int chieu_rong_bang = 71;  
    int khoang_cach_trai = (chieu_rong_bang - msg.length()) / 2;
    int khoang_cach_phai = chieu_rong_bang - msg.length() - khoang_cach_trai;
    cout << YELLOW << "\t|" << RESET  
         << string(khoang_cach_trai, ' ') 
         << RED << msg << RESET 
         << string(khoang_cach_phai, ' ') 
         << YELLOW << "|\n" << RESET;
}

string Lay_ten_cuoi(string ho_ten){
    stringstream ss(ho_ten);
    string word, ten;
    while(ss >> word){
        ten = word; 
    }
    return ten;
}

void Chuyen_ve_ky_tu_thuong(string& ho_ten){
    transform(ho_ten.begin(), ho_ten.end(), ho_ten.begin(), ::tolower);
}

void Chuyen_hoa_ky_tu_dau(string& gioi_tinh){
    for(char &gt : gioi_tinh){
        gt = toupper(gt);
        break;
    }
}

void Them_thong_tin_sinh_vien(Nodeptr& list, string& ten_file){
    cout << GREEN << "\t(?) Nhap so luong sinh vien muon them: " << RESET; 
    int so_luong; cin >> so_luong;
    int so_luong_tat_ca_sinh_vien = Kiem_tra_so_luong_node(list);
    for(int i = 0; i < so_luong; i++){
        cout << GREEN << "\t(?) Nhap sinh vien thu " << i + 1 + so_luong_tat_ca_sinh_vien << RESET << endl;
        SinhVien sv; 
        bool nhap_dung = Nhap_thong_tin_sinh_vien(sv);
        if(!nhap_dung){
            cout << "\t(!) Nhap sai du lieu, khong the then vao danh sach" << endl;
            return;
        }
        Nodeptr q = Khoi_tao_node(sv);
        Them_vao_cuoi_list(list, q);
    }
    cout << GREEN << "\t(*) Da cap nhat " << so_luong << " sinh vien moi vao danh sach !" << RESET << endl;
    Ghi_du_lieu_vao_file(ten_file, list);
}

void Sua_thong_tin_sinh_vien(Nodeptr& list, string& ten_file){
    In_thong_tin_sinh_vien(list);
    cout << GREEN << "\t(?) Nhap so thu tu muon sua thong tin: " << RESET;
    int stt; cin >> stt;
    int max_stt = Kiem_tra_so_luong_node(list);
    if(stt > max_stt || stt < 1){
        cout << RED << "\t\t(!) So thu tu khong hop le !" << RESET << endl;
        return;
    } 
    Nodeptr p = list;
    int cnt = 0;
    while(p != NULL){
        cnt++;
        if(cnt == stt){
            cout << GREEN << "\t(#) Sua thong tin: " << YELLOW<< p->data.ho_ten << RESET << endl;
            cin.ignore();
            cout << GREEN << "\t\t(?) Nhap ten moi (Nhap enter neu khong sua): " << RESET;
            string ten_moi; getline(cin, ten_moi);
            if(!ten_moi.empty()){
                p->data.ho_ten = ten_moi;
            } 
            cout << GREEN << "\t\t(?) Nhap tuoi moi (Nhap 0 neu khong sua): " << RESET;
            int tuoi_moi; cin >> tuoi_moi;
            if(tuoi_moi >= 18 && tuoi_moi < 80){
                p->data.tuoi = tuoi_moi;
            }
            cin.ignore();
            cout << GREEN << "\t\t(?) Nhap gioi tinh moi (Nhap enter neu khong sua): " << RESET;
            string gioi_tinh_moi; getline(cin, gioi_tinh_moi);
            if(!gioi_tinh_moi.empty()){
                p->data.gioi_tinh = gioi_tinh_moi;
            }
            cout << GREEN << "\t\t(?) Nhap ma so moi (Nhap enter neu khong sua): " << RESET;
            string ma_so_moi; getline(cin, ma_so_moi);
            if(!ma_so_moi.empty()){
                p->data.ma_so = ma_so_moi;
            }
            cout << GREEN << "\t\t(?) Nhap diem moi (Nhap 0 neu khong sua): " << RESET;
            float diem_moi; cin >> diem_moi;
            if(diem_moi > 0 && diem_moi <= 10){
                p->data.diem = diem_moi;
            } 
            cout << GREEN << "\t(*) Da cap nhat thong tin moi cho sinh vien [" << p->data.ho_ten << "]" << RESET << endl;
            break;
        }
        p=p->link;
    }
    Ghi_du_lieu_vao_file(ten_file, list);
}

void Xoa_thong_tin_sinh_vien(Nodeptr& list, string& ten_file){
    if(Kiem_tra_rong(list)){
        cout << RED << "\t(!) Khong co thong tin sinh vien de xoa !" << RESET << endl;
        return;
    }
    In_thong_tin_sinh_vien(list);
    cout << GREEN << "\t(?) Nhap so thu tu sinh vien muon xoa: " << RESET;
    int stt; cin >> stt;
    int so_luong_tat_ca_sinh_vien = Kiem_tra_so_luong_node(list);
    if(stt < 0 || stt > so_luong_tat_ca_sinh_vien){
        cout << RED << "\t\t(!) So thu tu khong hop le !" << RESET << endl;
        return;
    }
    string ten_sinh_vien_bi_xoa;
    if(stt == 1){
        Xoa_node_dau_list(list);
    } else {
        int cnt = 1;
        Nodeptr p = list;
        while(cnt < stt-1){
            p=p->link;
            cnt++;
        }
        Nodeptr q = p->link;
        ten_sinh_vien_bi_xoa = q->data.ho_ten;
        p->link = q->link;
        delete q;
    }
    cout << GREEN << "\t(*) Da xoa du lieu sinh vien " << YELLOW << ten_sinh_vien_bi_xoa << RESET << endl;
    Ghi_du_lieu_vao_file(ten_file, list);
}   

void Tim_kiem_thong_tin_sinh_vien(Nodeptr& list){
    if(Kiem_tra_rong(list)){
        cout << GREEN << "\t(!) Khong co thong tin sinh vien de tim kiem !" << RESET << endl;
        return;
    }
    In_thong_tin_sinh_vien(list);
    cout << YELLOW <<"\t1 - Tim kiem theo so thu tu" << endl;
    cout << "\t2 - Tim kiem theo ky tu ten" << endl;
    cout << "\t3 - Tim kiem theo tuoi" << endl;
    cout << "\t4 - Tim kiem theo gioi tinh" << endl;
    cout << "\t5 - Tim kiem theo ma so" << endl;
    cout << "\t6 - Tim kiem theo diem so" << RESET << endl;
    cout << GREEN << "\t(?) Lua chon: " << RESET; int lua_chon; cin >> lua_chon;
    if(lua_chon == 1){
        cout << GREEN << "\t\t(?) Nhap so thu tu muon tim kiem: " << RESET;
        int stt; cin >> stt;
        int so_luong_tat_ca_sinh_vien = Kiem_tra_so_luong_node(list);
        if(stt < 0 || stt > so_luong_tat_ca_sinh_vien){
            cout << RED << "\t\t(!) So thu tu khong hop le !" << RESET << endl;
            return;
        }
        Nodeptr p = list; bool co_sinh_vien = false; int cnt = 0;
        In_tieu_de_bang();
        while(p != NULL){
            cnt++;
            if(cnt == stt){
                co_sinh_vien = true;
                Xuat_thong_tin_sinh_vien(p->data, stt);
            }
            p=p->link;
        }
        if(!co_sinh_vien) In_bang_khong_co_sinh_vien();
        In_chan_bang();
    } else if(lua_chon == 2){
        cin.ignore();
        cout << GREEN << "\t\t(?) Nhap ten muon tim kiem (ky tu): " << RESET;
        string ky_tu_muon_tim; getline(cin, ky_tu_muon_tim);
        Nodeptr p = list; bool co_sinh_vien = false; int stt = 0;
        In_tieu_de_bang();
        while(p != NULL){
            stt++;
            string ho_ten_sinh_vien = p->data.ho_ten;
            Chuyen_ve_ky_tu_thuong(ho_ten_sinh_vien);
            Chuyen_ve_ky_tu_thuong(ky_tu_muon_tim);
            if(ho_ten_sinh_vien.find(ky_tu_muon_tim) != string::npos){
                co_sinh_vien = true;
                Xuat_thong_tin_sinh_vien(p->data, stt);
            }
            p=p->link;
        }
        if(!co_sinh_vien) In_bang_khong_co_sinh_vien();
        In_chan_bang();
    } else if(lua_chon == 3){
        cout << GREEN << "\t\t(?) Nhap tuoi ban muon tim kiem: " << RESET;
        int tuoi; cin >> tuoi;
        Nodeptr p = list; bool co_sinh_vien = false; int stt = 0;
        In_tieu_de_bang();
        while(p != NULL){
            stt++;
            if(p->data.tuoi == tuoi){
                co_sinh_vien = true;
                Xuat_thong_tin_sinh_vien(p->data, stt);
            }
            p=p->link;
        }
        if(!co_sinh_vien) In_bang_khong_co_sinh_vien();
        In_chan_bang();
    } else if(lua_chon == 4){
        cout << GREEN << "\t\t(?) Nhap gioi tinh ban muon tim kiem: " << RESET;
        string gioi_tinh; cin >> gioi_tinh; 
        Chuyen_hoa_ky_tu_dau(gioi_tinh);
        Nodeptr p = list; bool co_sinh_vien = false; int stt = 0;
        In_tieu_de_bang();
        while(p != NULL){
            stt++;
            if(p->data.gioi_tinh == gioi_tinh){
                co_sinh_vien = true;
                Xuat_thong_tin_sinh_vien(p->data, stt);
            }
            p=p->link;
        }
        if(!co_sinh_vien) In_bang_khong_co_sinh_vien();
        In_chan_bang();
    } else if(lua_chon == 5){
        cin.ignore();
        cout << GREEN <<"\t\t(?) Nhap ma so muon tim kiem (ky tu so): " << RESET;
        string ma_so_muon_tim; getline(cin, ma_so_muon_tim);
        Nodeptr p = list; bool co_sinh_vien = false; int stt = 0;
        In_tieu_de_bang();
        while(p != NULL){
            stt++;
            string ma_so_sinh_vien = p->data.ma_so;
            if(ma_so_sinh_vien.find(ma_so_muon_tim) != string::npos){
                co_sinh_vien = true;
                Xuat_thong_tin_sinh_vien(p->data, stt);
            }
            p=p->link;
        }
        if(!co_sinh_vien) In_bang_khong_co_sinh_vien();
        In_chan_bang();
    } else if(lua_chon == 6){
        cout << GREEN << "\t\t(?) Nhap diem so muon tim: " << RESET;
        float diem_muon_tim; cin >> diem_muon_tim;
        if(diem_muon_tim < 0 || diem_muon_tim > 10){
            cout << RED << "\t\t(!) Diem khong hop le !" << RESET << endl;
            return;
        }
        Nodeptr p = list; bool co_sinh_vien = false; int stt = 0;
        In_tieu_de_bang();
        while(p != NULL){
            stt++;
            if(p->data.diem == diem_muon_tim){
                co_sinh_vien = true;
                Xuat_thong_tin_sinh_vien(p->data, stt);    
            } 
            p=p->link;
        }
        if(!co_sinh_vien) In_bang_khong_co_sinh_vien();
        In_chan_bang();
    } else cout << RED << "\t(!) Vui long chon tu 1 -> 4 !" << RESET << endl;
}

void Sap_xep_thong_tin_sinh_vien(Nodeptr& list, string& ten_file){
    if(Kiem_tra_rong(list)){
        cout << RED << "\t(!) Khong co thong tin sinh vien de sap xep !" << RESET << endl;
        return;
    }
    In_thong_tin_sinh_vien(list);
    cout << YELLOW << "\t1 - Sap xep theo ten (A -> Z)" << endl;
    cout << "\t2 - Sap xep theo ten (Z -> A)" << endl;
    cout << "\t3 - Sap xep theo tuoi (Thap -> Cao)" << endl;
    cout << "\t4 - Sap xep theo tuoi (Cao -> Thap)" << endl;
    cout << "\t5 - Sap xep theo diem (Thap -> Cao)" << endl;
    cout << "\t6 - Sap xep theo diem (Cao -> Thap)" << RESET << endl;
    cout << GREEN << "\t(?) Lua chon: " << RESET; int lua_chon; cin >> lua_chon;
    if(lua_chon == 1){
        for(Nodeptr p = list; p->link != NULL; p=p->link){
            for(Nodeptr q = p->link; q != NULL; q=q->link){
                string ten_p = Lay_ten_cuoi(p->data.ho_ten);
                string ten_q = Lay_ten_cuoi(q->data.ho_ten);
                Chuyen_ve_ky_tu_thuong(ten_p);
                Chuyen_ve_ky_tu_thuong(ten_q);
                if(ten_p > ten_q){
                    swap(p->data, q->data);
                }
            }
        }
        cout << GREEN << "\t(*) Da sap xep ten sinh vien (A -> Z)" << RESET << endl;
    } else if(lua_chon == 2){
        for(Nodeptr p = list; p->link != NULL; p=p->link){
            for(Nodeptr q = p->link; q != NULL; q=q->link){
                string ten_p = Lay_ten_cuoi(p->data.ho_ten);
                string ten_q = Lay_ten_cuoi(q->data.ho_ten);
                Chuyen_ve_ky_tu_thuong(ten_p);
                Chuyen_ve_ky_tu_thuong(ten_q);
                if(ten_p < ten_q){
                    swap(p->data, q->data);
                }
            }
        }
        cout << GREEN << "\t(*) Da sap xep ten sinh vien (Z -> A)" << RESET << endl;
    } else if(lua_chon == 3){
        for(Nodeptr p = list; p->link != NULL; p=p->link){
            for(Nodeptr q = p->link; q != NULL; q=q->link){
                if(p->data.tuoi > q->data.tuoi){
                    swap(p->data, q->data);
                }
            }
        }
        cout << GREEN << "\t(*) Da sap xep tuoi sinh vien (Thap -> Cao)" << RESET << endl;
    } else if(lua_chon == 4){
        for(Nodeptr p = list; p->link != NULL; p=p->link){
            for(Nodeptr q = p->link; q != NULL; q=q->link){
                if(p->data.tuoi < q->data.tuoi){
                    swap(p->data, q->data);
                }
            }
        }
        cout << GREEN << "\t(*) Da sap xep tuoi sinh vien (Cao -> Thap)" << RESET << endl;
    } else if(lua_chon == 5){
        for(Nodeptr p = list; p->link != NULL; p=p->link){
            for(Nodeptr q = p->link; q != NULL; q=q->link){
                if(p->data.diem > q->data.diem){
                    swap(p->data, q->data);
                }
            }
        }
        cout << GREEN << "\t(*) Da sap xep diem sinh vien (Thap -> Cao)" << RESET << endl;
    } else if(lua_chon == 6){
        for(Nodeptr p = list; p->link != NULL; p=p->link){
            for(Nodeptr q = p->link; q != NULL; q=q->link){
                if(p->data.diem < q->data.diem){
                    swap(p->data, q->data);
                }
            }
        }
        cout << GREEN << "\t(*) Da sap xep diem sinh vien (Cao -> Thap)" << RESET << endl;
    } else {
        cout << RED << "\t(!) Vui long chon tu 1 -> 4 !" << RESET << endl;
        return;
    }
    In_thong_tin_sinh_vien(list);
    cout << GREEN << "\t(?) Ghi du lieu sau khi sap xep vao file (y/n): " << RESET;
    char c; cin >> c;
    if(c == 'y'){
        Ghi_du_lieu_vao_file(ten_file, list);
    }
}

void Thong_ke_thong_tin_sinh_vien(Nodeptr& list){
    int svg = 0, svk = 0, svtb = 0, svy = 0, sv_nam = 0, sv_nu = 0;
    float tong_diem_ca_lop = 0, diem_cao_nhat = 0, diem_thap_nhat = 10;
    int so_luong_tat_ca_sinh_vien = Kiem_tra_so_luong_node(list);
    Nodeptr p = list;
    while(p != NULL){
        if(p->data.diem >= 8) svg++;
        else if(p->data.diem >= 6.5 && p->data.diem < 8) svk++;
        else if(p->data.diem >= 4.0 && p->data.diem < 6.5) svtb++;
        else svy++;
        tong_diem_ca_lop += p->data.diem;
        if(p->data.diem > diem_cao_nhat) diem_cao_nhat = p->data.diem;
        if(p->data.diem < diem_thap_nhat) diem_thap_nhat = p->data.diem;
        if(p->data.gioi_tinh == "Nam") sv_nam ++;
        else sv_nu ++;
        p=p->link;
    }
    Nodeptr q = list;
    int slsv_cao_diem_nhat = 0, slsv_thap_diem_nhat = 0; 
    while(q != NULL){
        if(q->data.diem == diem_cao_nhat) slsv_cao_diem_nhat++;
        if(q->data.diem == diem_thap_nhat) slsv_thap_diem_nhat++;
        q=q->link;
    }
    float diem_tbcl = (float)(tong_diem_ca_lop / so_luong_tat_ca_sinh_vien);
    float tyle_svg = ((float)svg / so_luong_tat_ca_sinh_vien) * 100;
    float tyle_svk = ((float)svk / so_luong_tat_ca_sinh_vien) * 100;
    float tyle_svtb = ((float)svtb / so_luong_tat_ca_sinh_vien) * 100;
    float tyle_svy = ((float)svy / so_luong_tat_ca_sinh_vien) * 100;
    cout << YELLOW << "\t┌• " << GREEN << "(*) Diem trung binh ca lop: " << fixed << setprecision(2) << diem_tbcl << YELLOW << endl;
    cout << "\t├ (&) So luong sinh vien: " << so_luong_tat_ca_sinh_vien << endl;
    cout << "\t├ (&) Sinh vien nam: " << sv_nam  << endl;
    cout << "\t├ (&) Sinh vien nu: " << sv_nu  << endl;
    cout << "\t├ (&) Diem cao nhat lop: " << diem_cao_nhat << " - " << slsv_cao_diem_nhat << " sinh vien" << endl;
    cout << "\t├ (&) Diem thap nhat lop: " << diem_thap_nhat << " - " << slsv_thap_diem_nhat << " sinh vien" << endl;
    cout << "\t│\n" << RESET;
    cout << YELLOW << "\t├• " << GREEN << "(*) Ty le hoc luc" << YELLOW << endl;
    cout << "\t├ (%) Ty le sinh vien gioi: " << fixed << setprecision(2) << tyle_svg << " %" << endl;
    cout << "\t├ (%) Ty le sinh vien kha: " << fixed << setprecision(2) << tyle_svk << " %" << endl;
    cout << "\t├ (%) Ty le sinh vien trung binh: " << fixed << setprecision(2) << tyle_svtb << "%" << endl;
    cout << "\t├ (%) Ty le sinh vien yeu: " << fixed << setprecision(2) << tyle_svy << " %" << endl;
    cout << "\t│\n";

    vector<SinhVien> dssv;
    Nodeptr k = list;
    while(k != NULL){
        dssv.push_back(k->data);
        k = k->link;
    }
    sort(dssv.begin(), dssv.end(), [](SinhVien a, SinhVien b){
        return a.diem > b.diem;
    });
    int so_luong_sinh_vien_hien_bieu_do = 5;
    int n = min(so_luong_sinh_vien_hien_bieu_do, (int)dssv.size());
    float top_diem_cao_nhat = dssv[0].diem;
    int chieu_cao_toi_da_cot = 35;
    cout << YELLOW <<"\t├• " << GREEN << "(*) Bieu do " << n << " sinh vien co diem cao nhat lop" << RESET << endl;
    int stt_top_10 = 0;
    for(int i = 0; i < n; i++){
        int chieu_cao = (dssv[i].diem / top_diem_cao_nhat) * chieu_cao_toi_da_cot;
        cout << YELLOW << "\t│ " << ++stt_top_10 << " - " << setw(20) << left << dssv[i].ho_ten << " [ ";
        for(int j = 0; j < chieu_cao; j++){
            // ▇
            cout << "▇";
            Sleep(5);
        }
        for(int j = chieu_cao; j < chieu_cao_toi_da_cot; j++){
            cout << " ";
        }
        cout << " ]  (" << fixed << setprecision(1) << dssv[i].diem << ")" << endl;
    }
    cout << "\t│\n" << RESET;

    cout << YELLOW << "\t└• " << GREEN << "(*) Danh sach cac sinh vien co diem cao nhat lop" << RESET << endl;
    Nodeptr l = list; bool co_sinh_vien = false; int stt = 0;
    In_tieu_de_bang();

    int cnt = 0;
    for(int i = 0; i < so_luong_sinh_vien_hien_bieu_do; i++){
        cnt++; co_sinh_vien = true;
        Xuat_thong_tin_sinh_vien(dssv[i], cnt);
    }
    if(!co_sinh_vien) In_bang_khong_co_sinh_vien();
    In_chan_bang();
}

void Tacgia() {
    cout << endl;
    cout << GREEN << "(◉) BAN QUYEN MA NGUON" << endl;
    stringstream ss(Noi_Dung_Tac_Gia);
    string line;
    while(getline(ss, line)){
        cout << YELLOW << "\t" << line << RESET << endl;
        Sleep(10);
    }
}
