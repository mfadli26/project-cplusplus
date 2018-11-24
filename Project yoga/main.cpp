#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Linked.cpp"

using namespace std;

int main()
{
    int menu;
    int option;
    list_ruangan Lruangan;
    list_mahasiswa Lmahasiswa;
    CreateRuangan(Lruangan);
    CreateMahasiswa(Lmahasiswa);
    infotype_ruangan Ru;
    Ru.nama_ruangan = "asd";
    Ru.kapasitas = 12;
    insertRuangan(Lruangan, alokasiRuangan(Ru));
    infotype_mahasiswa Ma;
    start:
    system("cls");
    cout<<endl;
    cout<<"          Pendaftaran Ruangan         "<<endl;
    cout<<"///////////////////////////////////////"<<endl;
    cout<<"/                                     /"<<endl;
    cout<<"/      Daftar                         /"<<endl;
    cout<<"/  1. Menu Ruangan                    /"<<endl;
    cout<<"/  2. Menu Mahasiswa                  /"<<endl;
    cout<<"/  3. Menu Relasi                     /"<<endl;
    cout<<"/  20. Keluar Aplikasi                /"<<endl;
    cout<<"/                                     /"<<endl;
    cout<<"///////////////////////////////////////"<<endl;
    cout<<"Pilihan anda --> ";cin>>menu;
    system("cls");
    switch(menu){
        case 1:{
            menu_ruangan:
            system("cls");

            cout<<" Menu Milik Ruangan "<<endl<<endl;
            cout<<" 1. Tambah Ruangan"<<endl;
            cout<<" 2. Hapus Ruangan "<<endl;
            cout<<" 3. Update Ruangan "<<endl;
            cout<<" 4. Lihat Ruangan "<<endl;
            cout<<" 5. Back"<<endl<<endl;
            cout<<" Anda Ingin Melakukan Apa ? : ";cin>>option;
            system("cls");
            if(option == 1){
                cout<<" Menambahkan Data Ruangan "<<endl<<endl;
                cout<<" Nama Ruangan        : ";cin>>Ru.nama_ruangan;
                cout<<" Kapasistas Ruangan  : ";cin>>Ru.kapasitas;
                address_ruangan cekruangan = findRuangan(Lruangan, Ru);
                if(cekruangan == NULL){
                    insertRuangan(Lruangan, alokasiRuangan(Ru));
                    cout<<" Data Ruangan Telah Ditambahkan ";getch();
                    goto menu_ruangan;
                }
                else{
                    cout<<" Nama Ruangan Telah Dipakai ";getch();
                    goto menu_ruangan;
                }
            }
            else if(option == 2){
                cout<<" Menghapus Data Ruangan"<<endl<<endl;
                cout<<" Masukkan Nama Ruangan : ";cin>>Ru.nama_ruangan;
                address_ruangan R = findRuangan(Lruangan, Ru);
                if(R != NULL){
                    cout<<endl<<" Nama Ruangan Adalah      : "<<info(R).nama_ruangan<<endl;
                    cout<<" Kualitas Ruangan Adalah       : "<<info(R).kapasitas<<endl;
                    cout<<endl<<" Tekan Apapun untuk melanjutkan";getch();
                    deleteRuangan(Lruangan, R);
                    cout<<endl<<" Data Berhasil Dihapus"<<endl;
                    cout<<endl<<" Back to menu...";getch();
                }
                else{
                    cout<<"Data Tidak Ditemukan...";getch();
                }
                goto menu_ruangan;
            }
            else if(option == 3){
                cout<<" Mengupdate Data Ruangan"<<endl<<endl;
                cout<<" Masukkan Nama Ruangan : ";cin>>Ru.nama_ruangan;
                address_ruangan R = findRuangan(Lruangan, Ru);
                if(R != NULL){
                    cout<<endl<<" Nama Ruangan Adalah      : "<<info(R).nama_ruangan<<endl;
                    cout<<" Kapasitas Ruangan Adalah : "<<info(R).kapasitas<<endl;
                    cout<<endl<<" Nama Ruangan Menjadi      : ";cin>>Ru.nama_ruangan;
                    cout<<" Kapasitas Ruangan Menjadi : ";cin>>Ru.kapasitas;
                    updateDataRuangan(R, Ru);
                    cout<<endl<<" Data Berhasil DiUpdate"<<endl;
                    cout<<endl<<" Back to menu...";getch();
                }
                else{
                    cout<<"Data Tidak Ditemukan...";getch();
                }
                goto menu_ruangan;
            }
            else if(option == 4){
                printRuangan(Lruangan);
                getch();
                goto menu_ruangan;
            }
            else if(option == 5){
                goto start;
            }
            else{
                cout<<"Pilihan Menu Salah"<<endl;
                getch();
                goto menu_ruangan;
            }
        }
        case 2:{
            menu_mahasiswa:
            system("cls");
            cout<<" Menu Milik Mahasiswa "<<endl<<endl;
            cout<<" 1. Tambah Mahasiswa"<<endl;
            cout<<" 2. Hapus Mahasiswa "<<endl;
            cout<<" 3. Update Mahasiswa "<<endl;
            cout<<" 4. Lihat Mahasiswa "<<endl;
            cout<<" 5. Back"<<endl<<endl;
            cout<<" Anda Ingin Melakukan Apa ? : ";cin>>option;
            system("cls");
            if(option == 1){
                cout<<" Menambahkan Data Mahasiswa "<<endl<<endl;
                cout<<" Nama Mahasiswa        : ";cin>>Ma.nama;
                cout<<" Nim Mahasiswa         : ";cin>>Ma.nim;
                address_mahasiswa cekMahasiswa = findMahasiswa(Lmahasiswa, Ma);
                if(cekMahasiswa == NULL){
                    insertMahasiswa(Lmahasiswa, alokasiMahasiswa(Ma));
                    cout<<" Data Mahasiswa Telah Ditambahkan ";getch();
                    goto menu_mahasiswa;
                }
                else{
                    cout<<" Nim Mahasiswa Telah Dipakai ";getch();
                    goto menu_mahasiswa;
                }
            }
            else if(option == 2){
                cout<<" Menghapus Data Mahasiswa"<<endl<<endl;
                cout<<" Masukkan Nim Mahasiswa : ";cin>>Ma.nim;
                address_mahasiswa M = findMahasiswa(Lmahasiswa, Ma);
                if(M != NULL){
                    cout<<endl<<" Nama Mahasiswa Adalah      : "<<info(M).nama<<endl;
                    cout<<" Nim Mahasiswa Adalah       : "<<info(M).nim<<endl;
                    cout<<endl<<" Tekan Apapun untuk melanjutkan";getch();
                    deleteMahasiswa(Lmahasiswa, M);
                    cout<<endl<<" Data Berhasil Dihapus"<<endl;
                    cout<<endl<<" Back to menu...";getch();
                }
                else{
                    cout<<"Data Tidak Ditemukan...";getch();
                }
                goto menu_mahasiswa;
            }
            else if(option == 3){
                cout<<" Mengupdate Data Mahasiswa"<<endl<<endl;
                cout<<" Masukkan Nim Mahasiswa : ";cin>>Ma.nim;
                address_mahasiswa M = findMahasiswa(Lmahasiswa, Ma);
                if(M != NULL){
                    cout<<endl<<" Nama Mahasiswa Adalah      : "<<info(M).nama<<endl;
                    cout<<" Nim Mahasiswa Adalah       : "<<info(M).nim<<endl;
                    cout<<endl<<" Nama Mahasiswa Menjadi     : ";cin>>Ma.nama;
                    cout<<" Nim Mahasiswa Menjadi      : ";cin>>Ma.nim;
                    updateDataMahasiswa(M, Ma);
                    cout<<endl<<" Data Berhasil DiUpdate"<<endl;
                    cout<<endl<<" Back to menu...";getch();
                }
                else{
                    cout<<"Data Tidak Ditemukan...";getch();
                }
                goto menu_mahasiswa;
            }
            else if(option == 4){
                printMahasiswa(Lmahasiswa);
                getch();
                goto menu_mahasiswa;
            }
            else if(option == 5){
                goto start;
            }
            else{
                cout<<"Pilihan Menu Salah"<<endl;
                getch();
                goto menu_mahasiswa;
            }
        }
    }
}
