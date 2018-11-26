#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Linked.cpp"
#include "relasi.cpp"

using namespace std;

int main()
{
    int menu;
    int option;
    string pilyesno;
    list_ruangan Lruangan;
    list_mahasiswa Lmahasiswa;
    relasi_list Lrelasi;
    CreateRuangan(Lruangan);
    CreateMahasiswa(Lmahasiswa);
    CreateListRelasi(Lrelasi);
    infotype_ruangan Ru;
    Ru.nama_ruangan = "asd";
    Ru.kapasitas = 12;
    insertRuangan(Lruangan, alokasiRuangan(Ru));
    Ru.nama_ruangan = "dsa";
    Ru.kapasitas = 31;
    insertRuangan(Lruangan, alokasiRuangan(Ru));
    infotype_mahasiswa Ma;
    Ma.nama = "fadli";
    Ma.nim = "asd123";
    insertMahasiswa(Lmahasiswa, alokasiMahasiswa(Ma));
    Ma.nama = "gg";
    Ma.nim = "123z";
    insertMahasiswa(Lmahasiswa, alokasiMahasiswa(Ma));
    start:
    system("cls");
    cout<<endl;
    cout<<"          Pendaftaran Ruangan         "<<endl;
    cout<<"/////////////////////////////////////////"<<endl;
    cout<<"//                                     //"<<endl;
    cout<<"//                 Daftar              //"<<endl;
    cout<<"//           1. Menu Ruangan           //"<<endl;
    cout<<"//           2. Menu Mahasiswa         //"<<endl;
    cout<<"//           3. Menu Relasi            //"<<endl;
    cout<<"//           4. Keluar Aplikasi        //"<<endl;
    cout<<"//                                     //"<<endl;
    cout<<"/////////////////////////////////////////"<<endl;
    cout<<"Pilihan anda : ";cin>>menu;
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
        case 3:{
            menu_relasi:
            system("cls");
            cout<<"                  Menu Relasi"<<endl;
            cout<<"1. Pilih Ruang Kelas Untuk Mahasiswa"<<endl;
            cout<<"2. Pilih Mahasiswa Untuk Dimasukkan Ke Ruang Kelas"<<endl;
            cout<<"3. Pindah Mahasiswa Ke Raung Kelas Lain"<<endl;
            cout<<"4. Lihat Ruang Kelas Dan Mahasiswa"<<endl;
            cout<<"5. Hapus Mahasiswa Yang Masuk Ruang Kelas"<<endl;
            cout<<"6. Cari Mahasiswa Yang Masuk Keruang Tertenru"<<endl;
            cout<<"7. Back"<<endl;
            cout<<"___________________________________________________"<<endl;
            cout<<"Pilihan Anda : ";cin>>option;
            if(option == 1){
                system("cls");
                cout<<"Data Ruang Kelas"<<endl;
                printRuangan(Lruangan);
                cout<<"_______________________________"<<endl;
                cout<<"Pilih Nama Ruang Kelas : ";cin>>Ru.nama_ruangan;
                address_ruangan P =  findRuangan(Lruangan, Ru);
                if(P != NULL){
                    pil_mahasiswa:
                    system("cls");
                    cout<<"Data Ruang Kelas Ditemukan"<<endl;
                    cout<<"Nama Ruang Kelas : "<<info(P).nama_ruangan<<endl;
                    cout<<"Kapasitas        : "<<info(P).kapasitas<<endl;
                    cout<<"______________________"<<endl;
                    cout<<"Data Mahasiswa Yang Tersedia"<<endl;
                    printMahasiswa(Lmahasiswa);
                    cout<<"________________________"<<endl;
                    cout<<"Masukkan Nim Mahasiswa :";cin>>Ma.nim;
                    address_mahasiswa M = findMahasiswa(Lmahasiswa, Ma);
                    if(M != NULL){
                        string pill1;
                        system("cls");
                        cout<<"Data Ditemukan"<<endl;
                        cout<<"Nama Raung Kelas    : "<<info(P).nama_ruangan<<endl;
                        cout<<"Kapasitas           : "<<info(P).kapasitas<<endl;
                        cout<<"___________________________"<<endl;
                        cout<<"Nama Mahasiswa      : "<<info(M).nama<<endl;
                        cout<<"Nim Mahasiswa       : "<<info(M).nim<<endl;
                        cout<<"___________________________"<<endl;
                        cout<<"Hubungkan kedua data ? [y/n] : ";cin>>pill1;
                        if(pill1 == "y" or pill1 == "Y"){
                            insertRelasi(Lrelasi, alokasiRelasi(P,M));
                            cout<<"Data Berhasil Dihubungkan"<<endl<<endl;
                            cout<<"Press Any Key To Back";getche();
                            goto menu_relasi;
                        }
                        else{
                            cout<<"Press Any Key To Back";getche();
                            goto menu_relasi;
                        }
                    }
                    else{
                        cout<<"Data Tidak Ditemukan...."<<endl<<endl;
                        cout<<"Masukkan Data Mahasiswa Kembali ? [y/n] : ";cin>>pilyesno;
                        if(pilyesno == "y" or pilyesno == "Y"){
                            goto pil_mahasiswa;
                        }
                        else{
                            goto menu_relasi;
                        }
                    }
                }
                else{
                    cout<<"Data Tidak Ditemukan....";getche();
                    goto menu_relasi;
                }

            }
            else if(option == 2){
                system("cls");
                cout<<"Data Mahasiswa"<<endl;
                printMahasiswa(Lmahasiswa);
                cout<<"_______________________________"<<endl;
                cout<<"Pilih Nim Mahasiswa : ";cin>>Ma.nim;
                address_mahasiswa P =  findMahasiswa(Lmahasiswa, Ma);
                if(P != NULL){
                    pil_ruangan:
                    system("cls");
                    cout<<"Data Mahasiswa Ditemukan"<<endl;
                    cout<<"Nama Mahasiswa : "<<info(P).nama<<endl;
                    cout<<"Nim            : "<<info(P).nim<<endl;
                    cout<<"______________________"<<endl;
                    cout<<"Data Ruang Kelas Yang Tersedia"<<endl;
                    printRuangan(Lruangan);
                    cout<<"________________________"<<endl;
                    cout<<"Masukkan Nama Ruang Kelas :";cin>>Ru.nama_ruangan;
                    address_ruangan M = findRuangan(Lruangan, Ru);
                    if(M != NULL){
                        string pill1;
                        system("cls");
                        cout<<"Data Ditemukan"<<endl;
                        cout<<"Nama Mahasiswa      : "<<info(P).nama<<endl;
                        cout<<"Nim                 : "<<info(P).nim<<endl;
                        cout<<"___________________________"<<endl;
                        cout<<"Nama Ruang Kelas    : "<<info(M).nama_ruangan<<endl;
                        cout<<"Kapasistas          : "<<info(M).kapasitas<<endl;
                        cout<<"___________________________"<<endl;
                        cout<<"Hubungkan kedua data ? [y/n] : ";cin>>pill1;
                        if(pill1 == "y" or pill1 == "Y"){
                            insertRelasi(Lrelasi, alokasiRelasi(M,P));
                            cout<<"Data Berhasil Dihubungkan"<<endl<<endl;
                            cout<<"Press Any Key To Back";getche();
                            goto menu_relasi;
                        }
                        else{
                            cout<<"Press Any Key To Back";getche();
                            goto menu_relasi;
                        }
                    }
                    else{
                        cout<<"Data Tidak Ditemukan...."<<endl<<endl;
                        cout<<"Masukkan Data Ruang Kelas Kembali ? [y/n] : ";cin>>pilyesno;
                        if(pilyesno == "y" or pilyesno == "Y"){
                            goto pil_ruangan;
                        }
                        else{
                            goto menu_relasi;
                        }
                    }
                }
                else{
                    cout<<"Data Tidak Ditemukan....";getche();
                    goto menu_relasi;
                }
            }
            else if(option == 3){
                menu_r3:
                system("cls");
                cout<<"Pindah Mahasiswa Ke Ruang Kelas Lain"<<endl;
                cout<<"____________________________________"<<endl;
                cout<<"Masukkan Nim Mahasiswa : ";cin>>Ma.nim;
                address_mahasiswa Mh = findMahasiswa(Lmahasiswa, Ma);
                if(Mh != NULL){
                    pilih_r3:
                    system("cls");
                    cout<<"Pindah Mahasiswa Ke Ruang Kelas Lain"<<endl;
                    cout<<"____________________________________"<<endl;
                    cout<<"Data Ditemukan"<<endl;
                    address_relasi Rel = findRelasiTertentu(Lrelasi, Mh);
                    if(Rel != NULL){
                        printMahasiswaRelasiTertentu(Lrelasi, Mh);
                        cout<<"____________________________________"<<endl;
                        cout<<"Masukkan Ruang Kelas Yang Ingin Diganti : ";cin>>Ru.nama_ruangan;
                        address_ruangan Rg = findRuangan(Lruangan, Ru);
                        if(Rg != NULL){
                            cout<<endl;
                            address_relasi cek_r = findRelasi(Lrelasi, Rg, Mh);
                            if(cek_r != NULL){
                                cout<<"Masukkan Ruang Kelas Baru : ";cin>>Ru.nama_ruangan;
                                address_ruangan Rg2 = findRuangan(Lruangan, Ru);
                                if(Rg2 != NULL){
                                    cout<<endl;
                                    cout<<"Data Ruang Kelas Baru Ditemukan"<<endl<<endl;
                                    address_relasi Rj = findRelasi(Lrelasi, Rg2, Mh);
                                    if(Rj != NULL){
                                        system("cls");
                                        cout<<"Data Telah Terelasi Satu Sama Lain"<<endl<<endl;
                                        cout<<"Press Any Key To Back...";getche();
                                        goto menu_relasi;
                                    }
                                    else{
                                        cout<<"Apakah Anda Ingin Mengubah Ruang Kelas Baru [y/n] : ";cin>>pilyesno;
                                        if(pilyesno == "Y" or pilyesno == "y"){
                                            updateRelasi(cek_r, Mh, Rg2);
                                            cout<<endl;
                                            cout<<"Relasi Berhasil Diupdate"<<endl<<endl;
                                            cout<<"Press Any Key To Back...";getche();
                                            goto menu_relasi;
                                        }
                                        else{
                                            cout<<"Press Any Key To Back...";getche();
                                            goto menu_relasi;
                                        }
                                    }
                                }
                                else{
                                    cout<<"Data Ruang Kelas Tidak Ditemukan..."<<endl<<endl;
                                    cout<<"Masukkan Data Kelas Kembali ? [y/n] : ";cin>>pilyesno;
                                    if(pilyesno == "y" or pilyesno == "Y"){
                                        goto pilih_r3;
                                    }
                                    else{
                                        goto menu_relasi;
                                    }
                                }
                            }
                            else{
                                cout<<"Data Tersedia, Tetapi Tidak Berelasi Satu Sama Lain"<<endl<<endl;
                                cout<<"Press Any Key To Back";getche();
                                goto menu_r3;
                            }
                        }
                        else{
                            cout<<"Data Ruang Kelas Tidak Ditemukan..."<<endl<<endl;
                            cout<<"Masukkan Data Ruang Kelas Kembali ? [y/n] : ";cin>>pilyesno;
                            if(pilyesno == "y" or pilyesno == "Y"){
                                goto pilih_r3;
                            }
                            else{
                                goto menu_relasi;
                            }
                        }
                    }
                    else{
                        cout<<endl;
                        cout<<"Mahasiswa Belum Memasuki Ruang Manapun"<<endl<<endl;
                        cout<<"Press Any Key To Back...";getche();
                        goto menu_relasi;

                    }
                }
                else{
                    cout<<"Data Mahasiswa Tidak Ditemukan"<<endl<<endl;
                    cout<<"Press Any Key To Back..";getche();
                    goto menu_relasi;
                }
            }
            else if(option == 4){
                system("cls");
                cout<<"Data Ruang Kelas Dan Mahasiswa"<<endl;
                cout<<"______________________________"<<endl;
                printRuanganRelasiMahasiswa(Lruangan, Lrelasi);
                cout<<endl;
                cout<<"Press Any Key To Back";getche();
                goto menu_relasi;
            }
            else if(option == 5){
                string pil_5;
                menu_r5:
                system("cls");
                cout<<"Data Ruang Kelas Dan Mahasiswa"<<endl;
                cout<<"______________________________"<<endl;
                printRuanganRelasiMahasiswa(Lruangan, Lrelasi);
                cout<<endl;
                cout<<"______________________________"<<endl;
                cout<<"Masukkan Nim Mahasiswa : ";cin>>Ma.nim;
                address_mahasiswa Mx = findMahasiswa(Lmahasiswa, Ma);
                if(Mx != NULL){
                    pilih_r:
                    system("cls");
                    cout<<"Data Mahasiswa Ditemukan"<<endl;
                    cout<<"Nama Mahasiswa : "<<info(Mx).nama<<endl;
                    cout<<"Nim            : "<<info(Mx).nim<<endl;
                    cout<<"______________________"<<endl;
                    cout<<"Masukkan Nama Ruang Kelas : ";cin>>Ru.nama_ruangan;
                    address_ruangan R = findRuangan(Lruangan, Ru);
                    if(R != NULL){
                        system("cls");
                        cout<<"Data Ditemukan"<<endl;
                        cout<<"Nama Mahasiswa : "<<info(Mx).nama<<endl;
                        cout<<"Nim            : "<<info(Mx).nim<<endl;
                        cout<<"______________________________"<<endl;
                        cout<<"Nama Ruang Kelas    : "<<info(R).nama_ruangan<<endl;
                        cout<<"Kapasistas          : "<<info(R).kapasitas<<endl;
                        cout<<"______________________________"<<endl;
                        address_relasi Re = findRelasi(Lrelasi, R, Mx);
                        if(Re != NULL){
                            cout<<"Hapus Relasi ? [y/n] : ";cin>>pil_5;
                            if(pil_5 == "y" or pil_5 == "Y"){
                                deleteRelasi(Lrelasi, Re);
                                cout<<"Relasi Berhasil Dihapus"<<endl<<endl;
                                cout<<"Press Any Key To Back..";getche();
                                goto menu_relasi;
                            }
                            else{
                                goto menu_r5;
                            }
                        }
                        else{
                            cout<<"Data Tersedia, Tetapi Tidak Berelasi Satu Sama Lain"<<endl<<endl;
                            cout<<"Press Any Key To Back";getche();
                            goto menu_r5;
                        }
                    }
                    else{
                        cout<<"Data Ruang Kelas Tidak Ditemukan..."<<endl<<endl;
                        cout<<"Masukkan Data Mahasiswa Kembali ? [y/n] : ";cin>>pilyesno;
                        if(pilyesno == "y" or pilyesno == "Y"){
                            goto pilih_r;
                        }
                        else{
                            goto menu_relasi;
                        }
                    }
                }
                else{
                    cout<<"Data Mahasiswa Tidak Ditemukan"<<endl<<endl;
                    cout<<"Press Any Key To Back..";getche();
                    goto menu_relasi;
                }
            }
            else if(option == 6){
                system("cls");
                cout<<"Cari Mahasiswa Yang Masuk Ke Ruang Kelas Tertentu"<<endl;
                cout<<"_________________________________________________"<<endl;
                cout<<"Masukkan Nim Mahasiswa : ";cin>>Ma.nim;
                address_mahasiswa Mj = findMahasiswa(Lmahasiswa, Ma);
                if(Mj != NULL){
                    system("cls");
                    cout<<"Cari Mahasiswa Yang Masuk Ke Ruang Kelas Tertentu"<<endl;
                    cout<<"_________________________________________________"<<endl;
                    address_relasi R2 = findRelasiTertentu(Lrelasi, Mj);
                    if(R2 != NULL){
                        printMahasiswaRelasiTertentu(Lrelasi, Mj);
                        cout<<"Press Any Key To Back..";getche();
                        goto menu_relasi;
                    }
                    else{
                        cout<<"Data Mahasiswa Ditemukan Tetapi Belum Masuk Ke Ruang Kelas Manapun"<<endl<<endl;
                        cout<<"Press Any Key To Back..";getche();
                        goto menu_relasi;
                    }
                }
                else{
                    cout<<"Data Mahasiswa Tidak Ditemukan"<<endl<<endl;
                    cout<<"Press Any Key To Back..";getche();
                    goto menu_relasi;
                }
            }
            else if(option == 7){
                goto start;
            }
            else{
                cout<<"Pilihan Yang Anda Masukkan Salah";getche();
                goto menu_relasi;
            }
        }
    }
}
