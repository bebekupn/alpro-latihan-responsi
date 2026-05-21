#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct DATA{
    string nama_mapel;
    string nilai_mapel;

};

DATA data1[100];
int total_data = 0;

void input_data() {
                int jumlah_1;
                cout << "berapa data yang ingin di input :";
                cin >> jumlah_1;
                for (int i = 0; i < jumlah_1; i++){
                    int p = total_data;
                    cout << "\ndata ke - " << p + 1 << ":\n";
                    cout << "nama mata pelajaran :"; getline(cin >> ws, data1[p].nama_mapel);
                    cout << "nilai mata pelajaran :"; getline(cin >> ws, data1[p].nilai_mapel);
                    total_data++;
                }
}

void tampilkan_data(){
    if(total_data == 0){
        cout << "data masih kosong.\n";
    }else{
        for(int i = 0; i < total_data; i++){
            DATA *ptr = &data1[i];
            cout << i + 1 << ". nama mata pelajaran :" << ptr->nama_mapel << endl;
            cout << "   " << "  nilai mata pelajaran :" << ptr->nilai_mapel << endl;
            cout << "===============================================================\n";
        }
        
    }

}

void edit_data() {
    if (total_data == 0) {
        cout << "Data masih kosong, tidak ada yang bisa diedit.\n";
        return;
    }

    string cari;
    bool ditemukan = false;
    
    cout << "Masukkan nama mata pelajaran yang ingin diedit: ";
    getline(cin >> ws, cari);

    for (int i = 0; i < total_data; i++) {
        DATA *prk = &data1[i];
        if (prk ->nama_mapel == cari) {
            cout << "\nData ditemukan!\n";
            cout << "Nama mata pelajaran lama: " << prk ->nama_mapel << endl;
            cout << "Nilai mata pelajaran lama: " << prk ->nilai_mapel << endl;
            
            cout << "\n--- Masukkan data baru ---\n";
            cout << "Nama mata pelajaran baru: ";
            getline(cin >> ws, prk ->nama_mapel);
            cout << "Nilai mata pelajaran baru: ";
            getline(cin >> ws, prk ->nilai_mapel);
            
            cout << "\nData berhasil diperbarui!\n";
            ditemukan = true;
            break; 
        }
    }

    if (!ditemukan) {
        cout << "Data dengan nama '" << cari << "' tidak ditemukan.\n";
    }
}

int fibonacci(int n){
    if(n <= 1){
        return n;
    }else{
        return fibonacci(n - 1) + (n - 2);
    }
}

int long long faktorial(int n){
    if(n <= 1){
        return n;
    }else{
        return n*faktorial(n-1);
    }

}  


void rekursi(){

    int pilih;
    cout << "\n=====menu rekursi=====\n";
    cout << "1. fibonacci\n";
    cout << "2. faktorial\n";
    cout << "pilih menu :";
    cin >> pilih;
    switch(pilih){
        case 1 :{
            int deret = 0;
            cout << "berapa deret suku pertama fibonacci :";cin >> deret;
            cout << "deret fibonacci untuk " << deret << "suku pertama :\n";
            for(int i = 0; i < deret ; i++){
                cout << fibonacci(i) << " ";
            } 
            cout << endl;
            break;
        }
        case 2 :{
            int n;
            cout << "masukkan angka faktorial :";cin >> n;
            cout << "faktorial dari " << n << " :" << faktorial(n) << endl; 
            break;
        }
        default:{
            cout << "input tidak valid.\n";
            break;
        }

    }

}

void bubbleSort(DATA arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].nama_mapel > arr[j + 1].nama_mapel) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(DATA arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].nama_mapel < arr[min_idx].nama_mapel) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

void insertionSort(DATA arr[], int n) {
    for (int i = 1; i < n; i++) {
        DATA key = arr[i];  
        int j = i - 1;
        while (j >= 0 && arr[j].nama_mapel > key.nama_mapel) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void shellSort(DATA arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            DATA temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].nama_mapel > temp.nama_mapel; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void sorting_data(){
    int menu;
    cout << "=======sorting menu=======\n";
    cout << "1. bubble sort \n";
    cout << "2. selection sort \n";
    cout << "3. insertion sort \n";
    cout << "4. shell sort \n";
    cout << "pilih menu :"; cin >> menu;
    switch(menu){
        case 1 :{
            cout << "==================\n";
            cout << "| sorting bubble |\n";
            cout << "==================\n";
            cout << "====sebelum sort====\n";
            tampilkan_data();
            cout << "====sesudah sort====\n";
            bubbleSort(data1,total_data);
            tampilkan_data();            
            break;
        }
        case 2 :{
            cout << "==================\n";
            cout << "| selection sort |\n";
            cout << "==================\n";
            cout << "====sebelum sort====\n";
            tampilkan_data();
            cout << "====sesudah sort====\n";
            selectionSort(data1,total_data);
            tampilkan_data();            
            break;
        }
        case 3 :{
            cout << "==================\n";
            cout << "| insertion sort |\n";
            cout << "==================\n";
            cout << "====sebelum sort====\n";
            tampilkan_data();
            cout << "====sesudah sort====\n";
            insertionSort(data1,total_data);
            tampilkan_data();  
            break;
        }
        case 4 :{
            cout << "==================\n";
            cout << "|   shell sort   |\n";
            cout << "==================\n";
            cout << "====sebelum sort====\n";
            tampilkan_data();
            cout << "====sesudah sort====\n";
            shellSort(data1,total_data);
            tampilkan_data();  
            break;
        }
        default :{
            cout << "input tidak valid.\n";
            break;
        }
    }

}

void sequentialSearch(DATA arr[], int n, string target) {
    bool ditemukan = false;
    
    for (int i = 0; i < n; i++) {
        if (arr[i].nama_mapel == target) {
            cout << "\nData ditemukan pada indeks ke-" << i + 1 << ":" << endl;
            cout << "Nama Mapel : " << arr[i].nama_mapel << endl;
            cout << "Nilai Mapel: " << arr[i].nilai_mapel << endl;
            ditemukan = true;
            break;
        }
    }
    
    if (!ditemukan) {
        cout << "\nData dengan nama '" << target << "' tidak ditemukan." << endl;
    }
}

void sequentialSearchSentinel(DATA arr[], int n, string target) {
    DATA temp = arr[n]; 
    arr[n].nama_mapel = target;
    int i = 0;
    while (arr[i].nama_mapel != target) {
        i++;
    }
    arr[n] = temp;
    if (i < n || arr[n].nama_mapel == target) {
        cout << "\nData ditemukan pada indeks ke-" << i + 1 << ":" << endl;
        cout << "Nama Mapel : " << arr[i].nama_mapel << endl;
        cout << "Nilai Mapel: " << arr[i].nilai_mapel << endl;
    } else {
        cout << "\nData dengan nama '" << target << "' tidak ditemukan." << endl;
    }
}

void binarySearch(DATA arr[], int n, string target) {
    int kiri = 0;
    int kanan = n - 1;
    bool ditemukan = false;
    shellSort(data1,total_data);

    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        if (arr[tengah].nama_mapel == target) {
            cout << "\nData ditemukan pada indeks ke-" << tengah + 1 << ":" << endl;
            cout << "Nama Mapel : " << arr[tengah].nama_mapel << endl;
            cout << "Nilai Mapel: " << arr[tengah].nilai_mapel << endl;
            ditemukan = true;
            break;
        }

        if (arr[tengah].nama_mapel < target) {
            kiri = tengah + 1;
        }else {
            kanan = tengah - 1;
        }
    }

    if (!ditemukan) {
        cout << "\nData dengan nama '" << target << "' tidak ditemukan." << endl;
    }
}

void search_data(){
    int menu;
    cout << "=====search ujian======\n";
    cout << "1. sequential non-sentinel\n";
    cout << "2. sequential sentinel\n";
    cout << "3. binary search\n";
    cout << "pilih menu :"; cin >> menu;
    switch(menu){
        case 1 :{
            if (total_data == 0) {
                cout << "Data masih kosong.\n";
            } else {
                string cari;
                cout << "Masukkan nama mata pelajaran yang dicari: ";
                getline(cin >> ws, cari);              
                sequentialSearch(data1, total_data, cari);
            }
            break;
        }
        case 2 :{
            if (total_data == 0) {
                cout << "Data masih kosong.\n";
            }else if (total_data >= 100) {
                cout << "Array penuh, tidak bisa menggunakan metode Sentinel.\n";
            }else {
                string cari;
                cout << "Masukkan nama mata pelajaran yang dicari: ";
                getline(cin >> ws, cari);              
                sequentialSearchSentinel(data1, total_data, cari);
            }
            break;
        }
        case 3 :{
            if (total_data == 0) {
                cout << "Data masih kosong.\n";
            } else {
                string cari;
                cout << "Masukkan nama mata pelajaran yang dicari: ";
                getline(cin >> ws, cari);              
                binarySearch(data1, total_data, cari);
            }
            break;
        }
        default :{
            cout << "pilihan tidak valid\n";
            break;
        }

    }
} 

void exportData(DATA arr[], int n) {
    ofstream file("data_siswa.txt");
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file << arr[i].nama_mapel << endl;
            file << arr[i].nilai_mapel << endl;
        }
        file.close();
        cout << "Data berhasil diexport ke 'data_siswa.txt'!\n";
    } else {
        cout << "Gagal membuka file!\n";
    }
}

void importData(DATA arr[], int &n) {
    ifstream file("data_siswa.txt");
    if (file.is_open()) {
        n = 0; 
        while (getline(file, arr[n].nama_mapel) && getline(file, arr[n].nilai_mapel)) {
            n++;
        }
        file.close();
        cout << "Data berhasil diimport dari 'data_siswa.txt'!\n";
    } else {
        cout << "File tidak ditemukan atau gagal dibuka!\n";
    }
}

void file(){
    int menu;
    cout << "1. export data \n";
    cout << "2. import data \n";
    cout << "pilih menu :"; cin >> menu;
    switch(menu){
        case 1 :{
            exportData(data1, total_data);
            break;
        }
        case 2 :{
            importData(data1, total_data);
            break;
        }

    }
}

int main(){
    int menu;

    while(true){
        cout << "================================\n";
        cout << "              menu\n";
        cout << "================================\n";
        cout << "1. input data\n";
        cout << "2. tampilkan data\n";
        cout << "3. edit data\n";
        cout << "4. rekursi\n";
        cout << "5. search data\n";
        cout << "6. sorting data\n";
        cout << "7. export dan import data\n";
        cout << "8. keluar\n";
        cout << "pilih menu :";
        cin >> menu;
        switch(menu){
            case 1 :{
                input_data();
                break;
            }
            case 2 :{
                cout << "\n===============================================================\n";
                cout << "                           data siswa\n";
                cout << "=================================================================\n";
                tampilkan_data();
                break;
            }
            case 3 :{
                edit_data();
                break;
            }
            case 4 :{
                rekursi();
                break;
            }
            case 5 :{
                search_data();
                break;
            }
            case 6 :{
                sorting_data();
                break;
            }
            case 7 :{
                file();
                break;
            }
            case 8 :{
                cout << "program will be determinate";
                return 1;
            }
            default :{
                cout << "input tidak valid\n";
                break;
            }

        }


    }
    return 0;
}