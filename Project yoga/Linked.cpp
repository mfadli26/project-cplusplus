#include <cstdlib>
#include <iostream>
#include <conio.h>
#include "Linked.h"

void CreateRuangan(list_ruangan &Lruangan){
    first(Lruangan) = NULL;
    last(Lruangan) = NULL;
};

void CreateMahasiswa(list_mahasiswa &Lmahasiswa){
    first(Lmahasiswa) = NULL;
    last(Lmahasiswa) = NULL;
};

address_ruangan alokasiRuangan(infotype_ruangan X){
    address_ruangan P = new elmlist_ruangan;
    info(P).nama_ruangan = X.nama_ruangan;
    info(P).dosen = X.dosen;
    info(P).kode_dosen = X.kode_dosen;
    info(P).jam_mulai = X.jam_mulai;
    info(P).jam_berakhir = X.jam_berakhir;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
};

address_mahasiswa alokasiMahasiswa(infotype_mahasiswa X){
    address_mahasiswa P = new elmlist_mahasiswa;
    info(P).nama_m = X.nama_m;
    info(P).nim = X.nim;
    info(P).asal = X.asal;
    info(P).jurusan = X.jurusan;
    info(P).angkatan = X.angkatan;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
};

void dealokasiRuangan(address_ruangan P){
    delete P;
};

void dealokasiMahasiswa(address_mahasiswa P){
    delete P;
};

address_ruangan findRuangan(list_ruangan Lruangan, infotype_ruangan X){
    address_ruangan R = first(Lruangan);
    while (R != NULL){
        if(info(R).nama_ruangan == X.nama_ruangan){
            return R;
        }
        R = next(R);
    }
    return NULL;
};

address_mahasiswa findMahasiswa (list_mahasiswa Lmahasiswa, infotype_mahasiswa X){
    address_mahasiswa M = first(Lmahasiswa);
    while (M != NULL){
        if(info(M).nim == X.nim){
            return M;
        }
        M = next(M);
    }
    return NULL;
};

void insertRuangan(list_ruangan &Lruangan, address_ruangan P){
    if(first(Lruangan) == NULL){
        first(Lruangan) = P;
        last(Lruangan) = P;
    }
    else {
        next(last(Lruangan)) = P;
        prev(P) = last(Lruangan);
        last(Lruangan) = P;
    }
};

void insertMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa P){
    if(first(Lmahasiswa) == NULL){
        first(Lmahasiswa) = P;
        last(Lmahasiswa) = P;
    }
    else {
        next(last(Lmahasiswa)) = P;
        prev(P) = last(Lmahasiswa);
        last(Lmahasiswa) = P;
    }
};

void printRuangan(list_ruangan Lruangan){
    if(first(Lruangan) == NULL){
        cout<<" Data Ruangan Tidak Ada"<<endl;
    }
    else {
        address_ruangan R = first(Lruangan);
        while (R != NULL){
            cout<<endl;
            cout<<"Nama Ruangan       = "<<info(R).nama_ruangan<<endl;
            cout<<"Nama Dosen         = "<<info(R).dosen<<endl;
            cout<<"Kode Dosen         = "<<info(R).kode_dosen<<endl;
            cout<<"Jam Mulai          = "<<info(R).jam_mulai<<endl;
            cout<<"Jam Berakhir       = "<<info(R).jam_berakhir<<endl;
            R = next(R);
            cout<<endl;
        }
    }
};

void deleteFirstRuangan(list_ruangan &Lruangan, address_ruangan &P){
    if (first(Lruangan) == last(Lruangan)) {
        first(Lruangan) = NULL;
        last(Lruangan) = NULL;
        dealokasiRuangan(P);
    }
    else {
        P = first(Lruangan);
        first(Lruangan) = next(P);
        next(P) = NULL;
        prev(first(Lruangan)) = NULL;
        dealokasiRuangan(P);
    }
};
void deleteAfterRuangan(list_ruangan &Lruangan, address_ruangan &P){
    if (first(Lruangan) == last(Lruangan)) {
        first(Lruangan) = NULL;
        last(Lruangan) = NULL;
        dealokasiRuangan(P);
    }
    else {
        address_ruangan Prec = prev(P);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
        dealokasiRuangan(P);
    }
};
void deleteLastRuangan(list_ruangan &Lruangan, address_ruangan &P){
    if (first(Lruangan) == last(Lruangan)) {
        first(Lruangan) = NULL;
        last(Lruangan) = NULL;
        dealokasiRuangan(P);
    }
    else {
        P = last(Lruangan);
        last(Lruangan) = prev(P);
        next(last(Lruangan)) = NULL;
        prev(P) = NULL;
        dealokasiRuangan(P);
    }
};

void deleteRuangan(list_ruangan &Lruangan, address_ruangan P){
    if (P == first(Lruangan)){
        deleteFirstRuangan(Lruangan, P);
    }
    else if (P == last(Lruangan)){
        deleteLastRuangan(Lruangan, P);
    }
    else{
        deleteAfterRuangan(Lruangan, P);
    }
};

void updateDataRuangan(address_ruangan &R, infotype_ruangan Ru){
    info(R).nama_ruangan = Ru.nama_ruangan;
    info(R).dosen = Ru.dosen;
    info(R).kode_dosen = Ru.kode_dosen;
    info(R).jam_mulai = Ru.jam_mulai;
    info(R).jam_berakhir = Ru.jam_berakhir;
};

void printMahasiswa(list_mahasiswa Lmahasiswa){
    if(first(Lmahasiswa) == NULL){
        cout<<" Data mahasiswa Tidak Ada"<<endl;
    }
    else {
        address_mahasiswa M = first(Lmahasiswa);
        while (M != NULL){
            cout<<endl;
            cout<<"Nama mahasiswa       = "<<info(M).nama_m<<endl;
            cout<<"Nim mahasiswa        = "<<info(M).nim<<endl;
            cout<<"Kota Asal            = "<<info(M).asal<<endl;
            cout<<"Jurusan              = "<<info(M).jurusan<<endl;
            cout<<"Angkatan             = "<<info(M).angkatan<<endl;
            M = next(M);
            cout<<endl;
        }
    }
};

void deleteFirstMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa &P){
    if (first(Lmahasiswa) == last(Lmahasiswa)) {
        first(Lmahasiswa) = NULL;
        last(Lmahasiswa) = NULL;
        dealokasiMahasiswa(P);
    }
    else {
        P = first(Lmahasiswa);
        first(Lmahasiswa) = next(P);
        next(P) = NULL;
        prev(first(Lmahasiswa)) = NULL;
        dealokasiMahasiswa(P);
    }
};
void deleteAfterMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa &P){
    if (first(Lmahasiswa) == last(Lmahasiswa)) {
        first(Lmahasiswa) = NULL;
        last(Lmahasiswa) = NULL;
        dealokasiMahasiswa(P);
    }
    else {
        address_mahasiswa Prec = prev(P);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
        dealokasiMahasiswa(P);
    }
};
void deleteLastMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa &P){
    if (first(Lmahasiswa) == last(Lmahasiswa)) {
        first(Lmahasiswa) = NULL;
        last(Lmahasiswa) = NULL;
        dealokasiMahasiswa(P);
    }
    else {
        P = last(Lmahasiswa);
        last(Lmahasiswa) = prev(P);
        next(last(Lmahasiswa)) = NULL;
        prev(P) = NULL;
        dealokasiMahasiswa(P);
    }
};

void deleteMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa P){
    if (P == first(Lmahasiswa)){
        deleteFirstMahasiswa(Lmahasiswa, P);
    }
    else if (P == last(Lmahasiswa)){
        deleteLastMahasiswa(Lmahasiswa, P);
    }
    else{
        deleteAfterMahasiswa(Lmahasiswa, P);
    }
};

void updateDataMahasiswa(address_mahasiswa &R, infotype_mahasiswa Ru){
    info(R).nama_m = Ru.nama_m;
    info(R).nim = Ru.nim;
    info(R).asal = Ru.asal;
    info(R).jurusan = Ru.jurusan;
    info(R).angkatan = Ru.angkatan;
};
