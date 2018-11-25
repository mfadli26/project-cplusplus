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
            cout<<"Kapasitas = "<<info(Rk).kapasitas<<endl;
            cout<<"Mahasiswa = ";
            address_relasi R = first(Lrelasi);
            do{
                if(Ruangan(R) == Rk){
                    cout<<info(Mahasiswa(R)).nama<<", ";
                }
                R = next(R);
            } while(R != first(Lrelasi));
            Rk = next(B);
            cout<<endl;
        }
    }
    cout<<endl;
};

void printRuanganRelasiTertentu(relasi_list Lrelasi, address_ruangan Rk){
    address_relasi Q = first(Lrelasi);
    cout<<endl;
    cout<<"Nama Relasi : "<<info(Rk).nama_ruangan<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"Tahun Beasiswa : "<<info(Rk).Kapasitas<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"Mahasiswa : ";
    do{
        if(Ruangan(Q) == Rk){
            cout<<info(Mahasiswa(Q)).nama<<", ";
        }
        Q = next(Q);
    } while(Q != first(Lrelasi));
    cout<<endl<<"-----------------------"<<endl;
};

address_relasi findRelasi(relasi_list Lrelasi, address_relasi Rk, address_mahasiswa M){
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

void printRuanganYangDitempatiMahasiswa(relasi_list Lrelasi, address_ruangan Rk){
    address_relasi Q = first(Lrelasi);
    do{
        if(Ruangan(Q) == Rk){
            cout<<"Nama Mahasiswa : "<<info(Mahasiswa(Q)).nama<<endl;
            cout<<"Nim Mahasiswa : "<<info(Mahasiswa(Q)).nim<<endl<<endl;
        }
        Q = next(Q);
    } while(Q != first(Lrelasi));
    cout<<endl<<"-----------------------"<<endl;
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
