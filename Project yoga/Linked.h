#ifndef LINKED_H_INCLUDED
#define LINKED_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <conio.h>

#define first(Lruangan) Lruangan.first
#define last(Lruangan) Lruangan.last

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev

using namespace std;

struct infotype_ruangan{
    string nama_ruangan;
    string dosen;
    string kode_dosen;
    string jam_mulai;
    string jam_berakhir;
};
struct infotype_mahasiswa{
    string nim;
    string nama_m;
    string asal;
    string jurusan;
    string angkatan;
};

typedef struct elmlist_ruangan *address_ruangan;
typedef struct elmlist_mahasiswa *address_mahasiswa;

struct elmlist_ruangan{
    infotype_ruangan info;
    address_ruangan next;
    address_ruangan prev;
};

struct elmlist_mahasiswa{
    infotype_mahasiswa info;
    address_mahasiswa next;
    address_mahasiswa prev;
};

struct list_ruangan{
    address_ruangan first;
    address_ruangan last;
};

struct list_mahasiswa{
    address_mahasiswa first;
    address_mahasiswa last;
};

void CreateRuangan(list_ruangan &Lruangan);
void CreateMahasiswa(list_mahasiswa &Lmahasiswa);

address_ruangan alokasiRuangan(infotype_ruangan X);
address_mahasiswa alokasiMahasiswa(infotype_mahasiswa X);

void dealokasiRuangan(address_ruangan P);
void dealokasiMahasiswa(address_mahasiswa P);

address_ruangan findRuangan(list_ruangan Lruangan, infotype_ruangan X);
address_mahasiswa findMahasiswa (list_mahasiswa Lmahasiswa, infotype_mahasiswa X);

void insertRuangan(list_ruangan &Lruangan, address_ruangan P);
void insertMahasiswa(list_mahasiswa &Lmahasiswa, address_mahasiswa P);

void printRuangan(list_ruangan Lruangan);

void deleteFirstRuangan(list_ruangan &Lruangan, address_ruangan &P);
void deleteAfterRuangan(list_ruangan &Lruangan, address_ruangan &P);
void deleteLastRuangan(list_ruangan &Lruangan, address_ruangan &P);
void deleteRuangan(list_ruangan &Lruangan, address_ruangan P);

void updateDataRuangan(address_ruangan &R, infotype_ruangan Ru);

#endif // LINKED_H_INCLUDED
