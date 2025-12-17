#include <iostream>
using namespace std;

const int MAX = 10;

/* Struct Data Siswa */
struct Siswa {
    string student_id;
    string nama;
    char gender;
    int usia;
    float nilai;
    string status;
};

/* Queue */
Siswa queueSiswa[MAX];
int front = 0;
int rear = -1;

/* Cek Queue Kosong */
bool isEmpty() {
    return rear < front;
}

/* Cek Queue Penuh */
bool isFull() {
    return rear == MAX - 1;
}

/* 1. Tambah Data Siswa */
void tambahDataSiswa() {
    if (isFull()) {
        cout << "Queue penuh!\n";
        return;
    }

    Siswa data;
    cout << "ID Siswa       : ";
    cin >> data.student_id;
    cout << "Nama           : ";
    cin >> data.nama;
    cout << "Gender (L/P)   : ";
    cin >> data.gender;
    cout << "Usia           : ";
    cin >> data.usia;
    cout << "Nilai          : ";
    cin >> data.nilai;

    if (data.nilai >= 75)
        data.status = "Lulus";
    else
        data.status = "Tidak Lulus";

    rear++;
    queueSiswa[rear] = data;

    cout << "Data berhasil ditambahkan.\n";
}

/* 2. Hapus Data Siswa */
void hapusDataSiswa() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "Data siswa " << queueSiswa[front].nama << " dihapus.\n";
    front++;
}

/* 3. Cari Data Siswa */
void cariSiswa() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
        return;
    }

    string id;
    cout << "Masukkan ID Siswa: ";
    cin >> id;

    for (int i = front; i <= rear; i++) {
        if (queueSiswa[i].student_id == id) {
            cout << "Data ditemukan:\n";
            cout << "Nama   : " << queueSiswa[i].nama << endl;
            cout << "Nilai  : " << queueSiswa[i].nilai << endl;
            cout << "Status : " << queueSiswa[i].status << endl;
            return;
        }
    }
    cout << "Data tidak ditemukan.\n";
}

/* 4. Tampilkan Siswa Lulus */
void tampilkanSiswaLulus() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "Daftar Siswa Lulus:\n";
    for (int i = front; i <= rear; i++) {
        if (queueSiswa[i].status == "Lulus") {
            cout << queueSiswa[i].student_id << " - "
                 << queueSiswa[i].nama << endl;
        }
    }
}

/* 5. Hitung Rata-Rata Nilai */
void hitungRataNilai() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
        return;
    }

    float total = 0;
    int jumlah = 0;

    for (int i = front; i <= rear; i++) {
        total += queueSiswa[i].nilai;
        jumlah++;
    }

    cout << "Rata-rata nilai siswa: " << total / jumlah << endl;
}

/* Menu Utama */
int main() {
    int pilihan;
    do {
        cout << "\n=== MENU DATASET PENDIDIKAN ===\n";
        cout << "1. Tambah Data Siswa\n";
        cout << "2. Hapus Data Siswa\n";
        cout << "3. Cari Data Siswa\n";
        cout << "4. Tampilkan Siswa Lulus\n";
        cout << "5. Hitung Rata-rata Nilai\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahDataSiswa(); break;
            case 2: hapusDataSiswa(); break;
            case 3: cariSiswa(); break;
            case 4: tampilkanSiswaLulus(); break;
            case 5: hitungRataNilai(); break;
            case 0: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}