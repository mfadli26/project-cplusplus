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
    info(P).kapasitas = X.kapasitas;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
};

address_mahasiswa alokasiMahasiswa(infotype_mahasiswa X){
    address_mahasiswa P = new elmlist_mahasiswa;
    info(P).nama = X.nama;
    info(P).nim = X.nim;
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
            cout<<"Kapasistas Ruangan = "<<info(R).kapasitas<<endl;
            R = next(R);
            cout<<endl;
        }
    }
};

void deleteFirstRuangan(list_ruangan &Lruangan, address_ruangan &P){
    if (first(Lruangan) == last(Lruangan)) {
        first(Lruangan) = NULL;
        last(Lruangan) = NULL;
    }
    else {
        P = first(Lruangan);
        first(Lruangan) = next(P);
        next(P) = NULL;
        prev(first(Lruangan)) = NULL;
    }
};
void deleteAfterRuangan(list_ruangan &Lruangan, address_ruangan &P){
    if (first(Lruangan) == last(Lruangan)) {
        first(Lruangan) = NULL;
        last(Lruangan) = NULL;
    }
    else {
        address_ruangan Prec = prev(P);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
};
void deleteLastRuangan(list_ruangan &Lruangan, address_ruangan &P){
    if (first(Lruangan) == last(Lruangan)) {
        first(Lruangan) = NULL;
        last(Lruangan) = NULL;
    }
    else {
        P = last(Lruangan);
        last(Lruangan) = prev(P);
        next(last(Lruangan)) = NULL;
        prev(P) = NULL;
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
    info(R).kapasitas = Ru.kapasitas;
};

void printMahasiswa(list_mahasiswa Lmahasiswa){
    if(first(Lmahasiswa) == NULL){
        cout<<" Data mahasiswa Tidak Ada"<<endl;
    }
    else {
        address_mahasiswa M = first(Lmahasiswa);
        while (M != NULL){
            cout<<endl;
            cout<<"Nama mahasiswa       = "<<info(M).nama<<endl;
            cout<<"Nim mahasiswa        = "<<info(M).nim<<endl;
            M = next(M);
            cout<<endl;
        }
    }
};

void deleteFirstMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa &P){
    if (first(Lmahasiswa) == last(Lmahasiswa)) {
        first(Lmahasiswa) = NULL;
        last(Lmahasiswa) = NULL;
    }
    else {
        P = first(Lmahasiswa);
        first(Lmahasiswa) = next(P);
        next(P) = NULL;
        prev(first(Lmahasiswa)) = NULL;
    }
};
void deleteAfterMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa &P){
    if (first(Lmahasiswa) == last(Lmahasiswa)) {
        first(Lmahasiswa) = NULL;
        last(Lmahasiswa) = NULL;
    }
    else {
        address_mahasiswa Prec = prev(P);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
};
void deleteLastMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa &P){
    if (first(Lmahasiswa) == last(Lmahasiswa)) {
        first(Lmahasiswa) = NULL;
        last(Lmahasiswa) = NULL;
    }
    else {
        P = last(Lmahasiswa);
        last(Lmahasiswa) = prev(P);
        next(last(Lmahasiswa)) = NULL;
        prev(P) = NULL;
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
    info(R).nama = Ru.nama;
    info(R).nim = Ru.nim;
};
