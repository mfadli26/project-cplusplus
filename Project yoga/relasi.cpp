#include <cstdlib>
#include <iostream>
#include <conio.h>
#include "relasi.h"
#include "Linked.h"

void CreateListRelasi(relasi_list &Lrelasi){
    first(Lrelasi) = NULL;
};

address_relasi alokasiRelasi(address_ruangan Rk, address_mahasiswa M){
    address_relasi R = new elmlist_relasi;
    Ruangan(R) = Rk;
    next(R) = NULL;
    Mahasiswa(R) =  M;
    return R;
};

void dealokasiRelasi(address_relasi R){
    delete(R);
};

void insertRelasi(relasi_list &Lrelasi, address_relasi R){
    if(first(Lrelasi) == NULL){
        first(Lrelasi) = R;
        next(R) = first(Lrelasi);
    }
    else {
        address_relasi R2 = first(Lrelasi);
        do{
            R2 = next(R2);
        } while(next(R2) != first(Lrelasi));
        next(R2) = R;
        next(R) = first(Lrelasi);
    }
};

void printRuanganRelasiMahasiswa(list_ruangan Lruangan, relasi_list Lrelasi){
    if(first(Lruangan) == NULL){
        cout<<"Anda Belum Memasukkan Data Ruangan"<<endl;
    }
    else {
        address_ruangan Rk = first(Lruangan);
        while (Rk != NULL){
            cout<<endl;
            cout<<"Nama Ruangan = "<<info(Rk).nama_ruangan<<endl;
            cout<<"Dosen        = "<<info(Rk).dosen<<endl;
            cout<<"Kode Dosen   = "<<info(Rk).kode_dosen<<endl;
            cout<<"Jam Mulai    = "<<info(Rk).jam_mulai<<endl;
            cout<<"Jam Berakhir = "<<info(Rk).jam_berakhir<<endl;
            cout<<"Mahasiswa    = ";
            if(first(Lrelasi) != NULL){
                address_relasi R = first(Lrelasi);
                do{
                    if(Ruangan(R) == Rk){
                        cout<<info(Mahasiswa(R)).nama_m<<", ";
                    }
                    R = next(R);
                } while(R != first(Lrelasi));
            }
            Rk = next(Rk);
            cout<<endl;
        }
    }
    cout<<endl;
};

void printMahasiswaRelasiRuangan(list_mahasiswa Lmahasiswa, relasi_list Lrelasi){
    if(first(Lmahasiswa) == NULL){
        cout<<"Anda Belum Memasukkan Data Mahasiswa"<<endl;
    }
    else {
        address_mahasiswa Ma = first(Lmahasiswa);
        while (Ma != NULL){
            cout<<endl;
            cout<<"Nama Mahasiswa       = "<<info(Ma).nama_m<<endl;
            cout<<"NIM Mahasiswa        = "<<info(Ma).nim<<endl;
            cout<<"Asal Mahasiswa       = "<<info(Ma).asal<<endl;
            cout<<"Jurusan Mahasiswa    = "<<info(Ma).jurusan<<endl;
            cout<<"Angakatan Mahasiswa  = "<<info(Ma).angkatan<<endl;
            cout<<"Ruangan              = ";
            if(first(Lrelasi) != NULL){
                address_relasi R = first(Lrelasi);
                do{
                    if(Mahasiswa(R) == Ma){
                        cout<<info(Ruangan(R)).nama_ruangan<<", ";
                    }
                    R = next(R);
                } while(R != first(Lrelasi));
            }
            Ma = next(Ma);
            cout<<endl;
        }
    }
    cout<<endl;
};

void printMahasiswaRelasiTertentu(relasi_list Lrelasi, address_mahasiswa M){
    address_relasi Q = first(Lrelasi);
    cout<<endl;
    cout<<"Nama Mahasiswa : "<<info(M).nama_m<<endl;
    cout<<"Nim Mahasiswa  : "<<info(M).nim<<endl;
    cout<<"Kota Asal      : "<<info(M).asal<<endl;
    cout<<"Jurusan        : "<<info(M).jurusan<<endl;
    cout<<"angkatan       : "<<info(M).angkatan<<endl;

    cout<<"Ruang Kelas    :";
    do{
        if(Mahasiswa(Q) == M){
            cout<<info(Ruangan(Q)).nama_ruangan<<", ";
        }
        Q = next(Q);
    } while(Q != first(Lrelasi));
    cout<<endl<<"-----------------------"<<endl;
};

void printRuanganRelasiTertentu(relasi_list Lrelasi, address_ruangan Ru){
    address_relasi Q = first(Lrelasi);
    cout<<endl;
    cout<<"Nama Ruangan     : "<<info(Ru).nama_ruangan<<endl;
    cout<<"Dosen            : "<<info(Ru).dosen<<endl;
    cout<<"Kode Dosen       : "<<info(Ru).kode_dosen<<endl;
    cout<<"Jam Mulai        : "<<info(Ru).jam_mulai<<endl;
    cout<<"Jam Berakhir     : "<<info(Ru).jam_berakhir<<endl;

    cout<<"Nama Mahasiswa   :";
    do{
        if(Ruangan(Q) == Ru){
            cout<<info(Mahasiswa(Q)).nama_m<<", ";
        }
        Q = next(Q);
    } while(Q != first(Lrelasi));
    cout<<endl<<"-----------------------"<<endl;
};

address_relasi findRelasi(relasi_list Lrelasi, address_ruangan Rk, address_mahasiswa M){
    address_relasi R = first(Lrelasi);
    if (first(Lrelasi) == NULL){
        R = NULL;
        return R;
    }
    else {
        do{
            if(Ruangan(R) == Rk and Mahasiswa(R) == M){
                return R;
            }
            R = next(R);
        } while(R != first(Lrelasi));
    }
    return NULL;
};

address_relasi findRelasiMahasiswa(relasi_list Lrelasi, address_mahasiswa M){
    address_relasi R = first(Lrelasi);
    if (first(Lrelasi) == NULL){
        R = NULL;
        return R;
    }
    else {
        do{
            if(Mahasiswa(R) == M){
                return R;
            }
            R = next(R);
        } while(R != first(Lrelasi));
    }
    return NULL;
};

address_relasi findRelasiRuangan(relasi_list Lrelasi, address_ruangan Ru){
    address_relasi R = first(Lrelasi);
    if (first(Lrelasi) == NULL){
        R = NULL;
        return R;
    }
    else {
        do{
            if(Ruangan(R) == Ru){
                return R;
            }
            R = next(R);
        } while(R != first(Lrelasi));
    }
    return NULL;
};

void printRuanganYangDitempatiMahasiswa(relasi_list Lrelasi, address_ruangan Rk){
    if (first(Lrelasi) == NULL){
        cout<<"List Relasi Kosong"<<endl;
    }
    else {
        address_relasi Q = first(Lrelasi);
        do{
            if(Ruangan(Q) == Rk){
                cout<<"Nama Mahasiswa : "<<info(Mahasiswa(Q)).nama_m<<endl;
                cout<<"Nim Mahasiswa  : "<<info(Mahasiswa(Q)).nim<<endl;
                cout<<"Asal Kota      : "<<info(Mahasiswa(Q)).asal<<endl;
                cout<<"Jurusan        : "<<info(Mahasiswa(Q)).jurusan<<endl;
                cout<<"Angkata        : "<<info(Mahasiswa(Q)).angkatan<<endl<<endl;
            }
            Q = next(Q);
        } while(Q != first(Lrelasi));
        cout<<endl<<"-----------------------"<<endl;
    }
}

void deletefirstRelasi(relasi_list &Lrelasi){
    address_relasi R = first(Lrelasi);
    if(next(first(Lrelasi)) == first(Lrelasi)){
        first(Lrelasi) = NULL;
        dealokasiRelasi(R);
    }
    else{
        do{
            R = next(R);
        } while(next(R) != first(Lrelasi));
        next(R) = next(first(Lrelasi));
        R = first(Lrelasi);
        first(Lrelasi) = next(R);
        next(R) = NULL;
        dealokasiRelasi(R);
    }
}

void deletelastRelasi(relasi_list &Lrelasi){
    address_relasi R = first(Lrelasi);
    if(next(first(Lrelasi)) == first(Lrelasi)){
        first(Lrelasi) = NULL;
        dealokasiRelasi(R);
    }
    else{
        do{
            R = next(R);
        } while(next(next(R)) != first(Lrelasi));
        address_relasi R2 = next(R);
        next(R) = first(Lrelasi);
        next(R2) = NULL;
        dealokasiRelasi(R2);
    }
}

void deleteafterRelasi(relasi_list &Lrelasi, address_relasi &R){
    address_relasi R2 = first(Lrelasi);
    while(next(R2) != R){
        R = next(R);
    }
    next(R2) = next(R);
    next(R) = NULL;
    dealokasiRelasi(R);
}

void deleteRelasi(relasi_list &Lrelasi, address_relasi R){
    if (R == first(Lrelasi)){
        deletefirstRelasi(Lrelasi);
    }
    else if (next(R) == first(Lrelasi)){
        deletelastRelasi(Lrelasi);
    }
    else{
        deleteafterRelasi(Lrelasi, R);
    }
};

void deleteSemuaRelasiRuangan(relasi_list Lrelasi, address_ruangan Rk){
    address_relasi R = first(Lrelasi);
    do{
        if(Ruangan(R) == Rk){
            address_relasi R2 = next(R);
            deleteRelasi(Lrelasi, R);
            R = R2;
        }
        else{
            R = next(R);
        }
        if(first(Lrelasi) == NULL){
            R = NULL;
        }
    } while(R != first(Lrelasi) and R != NULL);
};

void deleteSemuaRelasiMahasiswa(relasi_list Lrelasi, address_mahasiswa M){
    address_relasi R = first(Lrelasi);
    do{
        if(Mahasiswa(R) == M){
            address_relasi R2 = next(R);
            deleteRelasi(Lrelasi, R);
            R = R2;
        }
        else{
            R = next(R);
        }
        if(first(Lrelasi) == NULL){
            R = NULL;
        }
    } while(R != first(Lrelasi) and R != NULL);
};

void updateRelasi(address_relasi &R, address_mahasiswa M, address_ruangan Rk){
    Ruangan(R) = Rk;
    Mahasiswa(R) = M;
};
