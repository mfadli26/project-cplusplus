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
    infotype_mahasiswa Ma;
    Ru.nama_ruangan = "asd";
    Ma.nim = "zxc";
    insertMahasiswa(Lmahasiswa, alokasiMahasiswa(Ma));
    insertRuangan(Lruangan, alokasiRuangan(Ru));
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
                cout<<" Nama Ruangan    : ";cin>>Ru.nama_ruangan;
                cout<<" Dosen           : ";cin>>Ru.dosen;
                cout<<" Kode Dosen      : ";cin>>Ru.kode_dosen;
                cout<<" Jam Mulai       : ";cin>>Ru.jam_mulai;
                cout<<" Jam Berakhir    : ";cin>>Ru.jam_berakhir;
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
                    cout<<" Data Ditemukan"<<endl<<endl;
                    cout<<" Nama Ruangan : "<<info(R).nama_ruangan<<endl;
                    cout<<" Dosen        : "<<info(R).dosen<<endl;
                    cout<<" Kode Dosen   : "<<info(R).kode_dosen<<endl;
                    cout<<" Jam Mulai    : "<<info(R).jam_mulai<<endl;
                    cout<<" Jam Berakhir : "<<info(R).jam_berakhir<<endl;
                    cout<<endl<<" Tekan Apapun untuk melanjutkan";getch();
                    deleteSemuaRelasiRuangan(Lrelasi, R);
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
                    cout<<" Data Ditemukan"<<endl<<endl;
                    cout<<" Nama Ruangan : "<<info(R).nama_ruangan<<endl;
                    cout<<" Dosen        : "<<info(R).dosen<<endl;
                    cout<<" Kode Dosen   : "<<info(R).kode_dosen<<endl;
                    cout<<" Jam Mulai    : "<<info(R).jam_mulai<<endl;
                    cout<<" Jam Berakhir : "<<info(R).jam_berakhir<<endl;
                    cout<<endl<<"Update Data"<<endl;
                    cout<<" Nama Ruangan    : ";cin>>Ru.nama_ruangan;
                    cout<<" Dosen           : ";cin>>Ru.dosen;
                    cout<<" Kode Dosen      : ";cin>>Ru.kode_dosen;
                    cout<<" Jam Mulai       : ";cin>>Ru.jam_mulai;
                    cout<<" Jam Berakhir    : ";cin>>Ru.jam_berakhir;
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
                cout<<" Nama Mahasiswa        : ";cin>>Ma.nama_m;
                cout<<" Nim Mahasiswa         : ";cin>>Ma.nim;
                cout<<" Kota Asal             : ";cin>>Ma.asal;
                cout<<" Jurusan               : ";cin>>Ma.jurusan;
                cout<<" Angkatan              : ";cin>>Ma.angkatan;
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
                    cout<<endl<<"Data Ditemukan"<<endl;
                    cout<<"_________________"<<endl;
                    cout<<"Nama Mahasiswa   : "<<info(M).nama_m<<endl;
                    cout<<"Nim Mahasiswa    : "<<info(M).nim<<endl;
                    cout<<"Kota Asal        : "<<info(M).asal<<endl;
                    cout<<"Jurusan          : "<<info(M).jurusan<<endl;
                    cout<<"Angkatan         : "<<info(M).angkatan<<endl;
                    cout<<endl<<" Tekan Apapun untuk melanjutkan";getch();
                    deleteSemuaRelasiMahasiswa(Lrelasi, M);
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
                    cout<<endl<<"Data Ditemukan"<<endl;
                    cout<<"_________________"<<endl;
                    cout<<"Nama Mahasiswa   : "<<info(M).nama_m<<endl;
                    cout<<"Nim Mahasiswa    : "<<info(M).nim<<endl;
                    cout<<"Kota Asal        : "<<info(M).asal<<endl;
                    cout<<"Jurusan          : "<<info(M).jurusan<<endl;
                    cout<<"Angkatan         : "<<info(M).angkatan<<endl;
                    cout<<endl<<"Update Data Baru"<<endl;
                    cout<<"_____________________"<<endl;
                    cout<<" Nama Mahasiswa        : ";cin>>Ma.nama_m;
                    cout<<" Nim Mahasiswa         : ";cin>>Ma.nim;
                    cout<<" Kota Asal             : ";cin>>Ma.asal;
                    cout<<" Jurusan               : ";cin>>Ma.jurusan;
                    cout<<" Angkatan              : ";cin>>Ma.angkatan;
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
            cout<<"4. Lihat Ruang Kelas Dengan Mahasiswanya"<<endl;
            cout<<"5. Lihat Mahasiswa Dengan Ruang Kelasnya"<<endl;
            cout<<"6. Hapus Mahasiswa Yang Masuk Ruang Kelas"<<endl;
            cout<<"7. Cari Mahasiswa Yang Masuk Keruang Tertentu"<<endl;
            cout<<"8. Cari Ruangan Yang Memiliki Mahasiswa Tertentu"<<endl;
            cout<<"9. Back"<<endl;
            cout<<"___________________________________________________"<<endl;
            cout<<"Pilihan Anda : ";cin>>option;
            if(option == 1){
                system("cls");
                cout<<"Data Ruang Kelas"<<endl;
                cout<<"________________"<<endl;
                printRuangan(Lruangan);
                cout<<endl;
                if(first(Lruangan) != NULL){
                    cout<<"_______________________________"<<endl;
                    cout<<"Pilih Nama Ruang Kelas : ";cin>>Ru.nama_ruangan;
                    address_ruangan P =  findRuangan(Lruangan, Ru);
                    if(P != NULL){
                        pil_mahasiswa:
                        system("cls");
                        cout<<"Data Ruang Kelas Ditemukan"<<endl;
                        cout<<" Nama Ruangan : "<<info(P).nama_ruangan<<endl;
                        cout<<" Dosen        : "<<info(P).dosen<<endl;
                        cout<<" Kode Dosen   : "<<info(P).kode_dosen<<endl;
                        cout<<" Jam Mulai    : "<<info(P).jam_mulai<<endl;
                        cout<<" Jam Berakhir : "<<info(P).jam_berakhir<<endl;
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
                            cout<<" Nama Ruangan : "<<info(P).nama_ruangan<<endl;
                            cout<<" Dosen        : "<<info(P).dosen<<endl;
                            cout<<" Kode Dosen   : "<<info(P).kode_dosen<<endl;
                            cout<<" Jam Mulai    : "<<info(P).jam_mulai<<endl;
                            cout<<" Jam Berakhir : "<<info(P).jam_berakhir<<endl;
                            cout<<"___________________________"<<endl;
                            cout<<"Nama Mahasiswa   : "<<info(M).nama_m<<endl;
                            cout<<"Nim Mahasiswa    : "<<info(M).nim<<endl;
                            cout<<"Kota Asal        : "<<info(M).asal<<endl;
                            cout<<"Jurusan          : "<<info(M).jurusan<<endl;
                            cout<<"Angkatan         : "<<info(M).angkatan<<endl;
                            cout<<"___________________________"<<endl;
                            cout<<"Hubungkan kedua data ? [y/n] : ";cin>>pill1;
                            if(pill1 == "y" or pill1 == "Y"){
                                address_relasi R = findRelasi(Lrelasi, P, M);
                                if(R != NULL){
                                    cout<<"Relasi tidak dapat ganda, kedua data telah berelasi";getche();
                                    goto menu_relasi;
                                }
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
                        cout<<endl<<"Data Tidak Ditemukan....";getche();
                        goto menu_relasi;
                    }
                }
                else{
                    cout<<"Anda Belum Memasukkan Data Ruang Kelas"<<endl<<endl;
                    cout<<"Press Any Key To Back";getche();
                    goto menu_relasi;

                }

            }
            else if(option == 2){
                system("cls");
                cout<<"Data Mahasiswa"<<endl;
                printMahasiswa(Lmahasiswa);
                if(first(Lmahasiswa) != NULL){
                    cout<<"_______________________________"<<endl;
                    cout<<"Pilih Nim Mahasiswa : ";cin>>Ma.nim;
                    address_mahasiswa P =  findMahasiswa(Lmahasiswa, Ma);
                    if(P != NULL){
                        pil_ruangan:
                        system("cls");
                        cout<<"Data Mahasiswa Ditemukan"<<endl;
                        cout<<"Nama Mahasiswa   : "<<info(P).nama_m<<endl;
                        cout<<"Nim Mahasiswa    : "<<info(P).nim<<endl;
                        cout<<"Kota Asal        : "<<info(P).asal<<endl;
                        cout<<"Jurusan          : "<<info(P).jurusan<<endl;
                        cout<<"Angkatan         : "<<info(P).angkatan<<endl;
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
                            cout<<"Nama Mahasiswa   : "<<info(P).nama_m<<endl;
                            cout<<"Nim Mahasiswa    : "<<info(P).nim<<endl;
                            cout<<"Kota Asal        : "<<info(P).asal<<endl;
                            cout<<"Jurusan          : "<<info(P).jurusan<<endl;
                            cout<<"Angkatan         : "<<info(P).angkatan<<endl;
                            cout<<"___________________________"<<endl;
                            cout<<" Nama Ruangan : "<<info(M).nama_ruangan<<endl;
                            cout<<" Dosen        : "<<info(M).dosen<<endl;
                            cout<<" Kode Dosen   : "<<info(M).kode_dosen<<endl;
                            cout<<" Jam Mulai    : "<<info(M).jam_mulai<<endl;
                            cout<<" Jam Berakhir : "<<info(M).jam_berakhir<<endl;
                            cout<<"___________________________"<<endl;
                            cout<<"Hubungkan kedua data ? [y/n] : ";cin>>pill1;
                            if(pill1 == "y" or pill1 == "Y"){
                                address_relasi R = findRelasi(Lrelasi, M, P);
                                if(R != NULL){
                                    cout<<"Relasi tidak dapat ganda, kedua data telah berelasi";getche();
                                    goto menu_relasi;
                                }
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
                else{
                    cout<<"Anda Belum Memasukkan Data Mahasiswa"<<endl<<endl;
                    cout<<"Press Any Key To Back";getche();
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
                    address_relasi Rel = findRelasiMahasiswa(Lrelasi, Mh);
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
                cout<<"Lihat Ruang Kelas Dengan Mahasiswanya"<<endl;
                cout<<"______________________________"<<endl;
                printRuanganRelasiMahasiswa(Lruangan, Lrelasi);
                cout<<endl;
                cout<<"Press Any Key To Back";getche();
                goto menu_relasi;
            }
            else if(option == 5){
                system("cls");
                cout<<"Lihat Mahasiswa Dengan Ruang Kelasny"<<endl;
                cout<<"______________________________"<<endl;
                printMahasiswaRelasiRuangan(Lmahasiswa, Lrelasi);
                cout<<endl;
                cout<<"Press Any Key To Back";getche();
                goto menu_relasi;
            }
            else if(option == 6){
                string pil_6;
                menu_r6:
                system("cls");
                cout<<"Data Ruang Kelas Dan Mahasiswa"<<endl;
                cout<<"______________________________"<<endl;
                printRuanganRelasiMahasiswa(Lruangan, Lrelasi);
                cout<<endl;
                cout<<"______________________________"<<endl;
                cout<<"Masukkan Nama Ruangan : ";cin>>Ru.nama_ruangan;
                address_ruangan R = findRuangan(Lruangan, Ru);
                if(R != NULL){
                    pilih_r:
                    system("cls");
                    printRuanganYangDitempatiMahasiswa(Lrelasi, R);
                    cout<<"______________________"<<endl;
                    cout<<"masukkan Nim Mahasiswa : ";cin>>Ma.nim;
                    address_mahasiswa M = findMahasiswa(Lmahasiswa, Ma);
                    if(M != NULL){
                        system("cls");
                        cout<<"Data Ditemukan"<<endl;
                        cout<<"Nama Mahasiswa   : "<<info(M).nama_m<<endl;
                        cout<<"Nim Mahasiswa    : "<<info(M).nim<<endl;
                        cout<<"Kota Asal        : "<<info(M).asal<<endl;
                        cout<<"Jurusan          : "<<info(M).jurusan<<endl;
                        cout<<"Angkatan         : "<<info(M).angkatan<<endl;
                        cout<<"______________________________"<<endl;
                        cout<<" Nama Ruangan : "<<info(R).nama_ruangan<<endl;
                        cout<<" Dosen        : "<<info(R).dosen<<endl;
                        cout<<" Kode Dosen   : "<<info(R).kode_dosen<<endl;
                        cout<<" Jam Mulai    : "<<info(R).jam_mulai<<endl;
                        cout<<" Jam Berakhir : "<<info(R).jam_berakhir<<endl;
                        cout<<"______________________________"<<endl;
                        address_relasi Re = findRelasi(Lrelasi, R, M);
                        if(Re != NULL){
                            cout<<"Hapus Relasi ? [y/n] : ";cin>>pil_6;
                            if(pil_6 == "y" or pil_6 == "Y"){
                                deleteRelasi(Lrelasi, Re);
                                cout<<"Relasi Berhasil Dihapus"<<endl<<endl;
                                cout<<"Press Any Key To Back..";getche();
                                goto menu_relasi;
                            }
                            else{
                                goto menu_r6;
                            }
                        }
                        else{
                            cout<<"Data Tersedia, Tetapi Tidak Berelasi Satu Sama Lain"<<endl<<endl;
                            cout<<"Press Any Key To Back";getche();
                            goto menu_r6;
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
            else if(option == 7){
                system("cls");
                cout<<"Cari Mahasiswa Yang Masuk Ke Ruang Kelas Tertentu"<<endl;
                cout<<"_________________________________________________"<<endl;
                cout<<"Masukkan Nim Mahasiswa : ";cin>>Ma.nim;
                address_mahasiswa Mj = findMahasiswa(Lmahasiswa, Ma);
                if(Mj != NULL){
                    system("cls");
                    cout<<"Cari Mahasiswa Yang Masuk Ke Ruang Kelas Tertentu"<<endl;
                    cout<<"_________________________________________________"<<endl;
                    address_relasi R2 = findRelasiMahasiswa(Lrelasi, Mj);
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
            else if(option == 8){
                system("cls");
                cout<<"Cari Ruangan Yang Memiliki Mahasiswa Tertentu"<<endl;
                cout<<"_________________________________________________"<<endl;
                cout<<"Masukkan Nama Ruang Kelas : ";cin>>Ru.nama_ruangan;
                address_ruangan P = findRuangan(Lruangan, Ru);
                if(P != NULL){
                    system("cls");
                    cout<<"Cari Ruang Kelas Yang Memiliki Mahasiswa Tertentu"<<endl;
                    cout<<"_________________________________________________"<<endl;
                    address_relasi R2 = findRelasiRuangan(Lrelasi, P);
                    if(R2 != NULL){
                        printRuanganRelasiTertentu(Lrelasi, P);
                        cout<<"Press Any Key To Back..";getche();
                        goto menu_relasi;
                    }
                    else{
                        cout<<"Data Ruangan Ditemukan Tetapi Belum Memiliki Mahasiswa Manapun"<<endl<<endl;
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
            else if(option == 9){
                goto start;
            }
            else{
                cout<<"Pilihan Yang Anda Masukkan Salah";getche();
                goto menu_relasi;
            }
        }
    }
}
