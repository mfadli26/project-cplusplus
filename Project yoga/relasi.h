#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#define first(Lruangan) Lruangan.first
#define last(Lruangan) Lruangan.last

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_ruangan Ruangan;
    address_relasi next;
    address_mahasiswa Mahasiswa;
};

struct relasi_list{
    address_relasi first;
};

void CreateListRelasi(relasi_list &Lrelasi);
address_relasi alokasiRelasi(address_ruangan Rk, address_mahasiswa M);
void dealokasiRelasi(address_relasi R);
void insertRelasi(relasi_list &Lrelasi, address_relasi R);

address_relasi findRelasi(relasi_list Lrelasi, address_ruangan Rk, address_mahasiswa M);

void printRuanganRelasiMahasiswa(list_ruangan Lruangan, relasi_list Lrelasi);
void printRuanganRelasiTertentu(relasi_list Lrelasi, address_ruangan Rk);
void printRuanganYangDitempatiMahasiswa(relasi_list Lrelasi, address_ruangan Rk);

void deletefirstRelasi(relasi_list &Lrelasi);
void deletelastRelasi(relasi_list &Lrelasi);
void deleteafterRelasi(relasi_list &Lrelasi, address_relasi &R);
void deleteRelasi(relasi_list &Lrelasi, address_relasi R);
void deleteSemuaRelasiRuangan(relasi_list Lrelasi, address_ruangan Rk);
void deleteSemuaRelasiMahasiswa(relasi_list Lrelasi, address_mahasiswa M);

#endif // RELASI_H_INCLUDED
