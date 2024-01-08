#include "flight.h"

//====================================//

void createListMaskapai(listMaskapai &L){
    first(L) = NULL;
}

adrMaskapai newElmMaskapai(infotypeMas x){
    adrMaskapai P = new maskapai;
    info(P) = x;
    next(P) = NULL;
    nextRel(P) = NULL;
    return P;
}

void insertLastMaskapai(listMaskapai &L, infotypeMas x){
    adrMaskapai P = newElmMaskapai(x);
    adrMaskapai Q = first(L);
    if(first(L) == NULL){
        first(L) = P;
    }else{
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

adrMaskapai searchMaskapai(listMaskapai L, infotypeMas x){
    adrMaskapai P = first(L);
    while(next(P) != NULL && info(P).kode != x.kode){
        P = next(P);
    }
    if(info(P).kode == x.kode){
        return P;
    }else{
        return NULL;
    }
}

void showSearchMaskapai(listMaskapai L, infotypeMas x){
    adrMaskapai P = searchMaskapai(L, x);
    if(P != NULL){
        cout<<"`Maskapai dengan kode penerbangan "<<info(P).kode<<" ditemukan`"<<endl;
    }else{
        cout<<"`Maskapai dengan kode penerbangan "<<x.kode<<" tidak ditemukan`"<<endl;
    }
}

void showAllMaskapai(listMaskapai L){
    adrMaskapai P = first(L);
    int i = 1;
    cout<<"=======DATA MASKAPAI======="<<endl;
    while(P != NULL){
        cout<<i<<". Kode: "<<info(P).kode<<endl;
        cout<<"   Jenis: "<<info(P).jenis<<endl;
        cout<<"   Asal: "<<info(P).asal<<endl;
        cout<<"   Tujuan: "<<info(P).tujuan<<endl;
        P = next(P);
        i++;
    }
    cout<<"==========================="<<endl;
}

void deleteFirstMaskapai(listMaskapai &L, adrMaskapai P){
    adrMaskapai Q = first(L);
    if(first(L) == NULL){
        cout<<"`Tidak ada maskapai`"<<endl;
    }else if(next(Q) == NULL){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLastMaskapai(listMaskapai &L, adrMaskapai P){
    if(first(L) == NULL){
        cout<<"`Tidak ada maskapai`"<<endl;
    }else{
        adrMaskapai Q = first(L);
        while(next(Q) != P){
            Q = next(Q);
        }
        next(Q) = NULL;
    }
}

void deleteAfterMaskapai(listMaskapai &L, adrMaskapai Prec, adrMaskapai P){
    if(first(L) == NULL){
        cout<<"`Tidak ada maskapai`"<<endl;
    }else{
        Prec = first(L);
        while(next(Prec) != P){
            Prec = next(Prec);
        }
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

//====================================//

void createListPassenger(listPassenger &L){
    first(L) = NULL;
}

adrPassenger newElmPassenger(infotypePass x){
    adrPassenger P = new passenger;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertLastPassenger(listPassenger &L, infotypePass x){
    adrPassenger P = newElmPassenger(x);
    adrPassenger Q = first(L);
    if(first(L) == NULL){
        first(L) = P;
    }else{
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

adrPassenger searchPassenger(listPassenger L, infotypePass x){
    adrPassenger P = first(L);
    while(next(P) != NULL && info(P).NIK != x.NIK){
        P = next(P);
    }
    if(info(P).NIK == x.NIK){
        return P;
    }else{
        return NULL;
    }
}

void showSearchPassenger(listPassenger L, infotypePass x){
    adrPassenger P = searchPassenger(L, x);
    if(P != NULL){
        cout<<"`Penumpang dengan NIK "<<info(P).NIK<<" ditemukan`"<<endl;
    }else{
        cout<<"`Penumpang dengan NIK "<<x.NIK<<" tidak ditemukan`"<<endl;
    }
}

void showAllPassenger(listPassenger L){
    adrPassenger P = first(L);
    int i = 1;
    cout<<"=======DATA PENUMPANG======="<<endl;
    while(P != NULL){
        cout<<i<<". NIK: "<<info(P).NIK<<endl;
        cout<<"   Nama: "<<info(P).nama<<endl;
        cout<<"   Jenis Kelamin: "<<info(P).gender<<endl;
        P = next(P);
        i++;
    }
    cout<<"============================"<<endl;
}

void deleteFirstPassenger(listPassenger &L, adrPassenger P){
    adrPassenger Q = first(L);
    if(first(L) == NULL){
        cout<<"`Tidak ada penumpang`"<<endl;
    }else if(next(Q) == NULL){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

//====================================//

adrRelation newRelation(){
    adrRelation P = new relation;
    nextPass(P) = NULL;
    next(P) = NULL;
    return P;
}

void insertRelation(adrMaskapai &M, adrPassenger P){
    adrRelation R = newRelation();
    if(nextRel(M) == NULL){
        nextRel(M) = R;
        nextPass(R) = P;
    }else{
        adrRelation Q = nextRel(M);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = R;
        nextPass(R) = P;
    }
}

void showAllRelation(listMaskapai LM){
    cout<<"=======PENERBANGAN PENUMPANG======="<<endl;
    if(first(LM) == NULL){
        cout<<"`Tidak ada penumpang yang melakukan penerbangan`"<<endl;
    }else{
        adrMaskapai pM = first(LM);
        int i = 1;
        while(pM != NULL){
            cout<<i<<". Kode: "<<info(pM).kode<<endl;
            adrRelation rP = nextRel(pM);
            while(rP != NULL){
                cout<<"NIK Penumpang: "<<endl;
                cout<<"   -"<<info(nextPass(rP)).NIK<<endl;
                rP = next(rP);
            }
            i++;
            pM = next(pM);
            cout<<endl;
        }
    }
    cout<<"==================================="<<endl;
}

//====================================//

void searchPassengerFlights(listMaskapai LM, infotypeMas x){
    adrMaskapai pM = searchMaskapai(LM, x);
    if(pM != NULL){
        int i = 1;
        adrRelation rP = nextRel(pM);
        cout<<"Penerbangan penumpang "<<info(pM).kode<<": "<<endl;
        while(rP != NULL){
            cout<<i<<". "<<info(nextPass(rP)).NIK<<endl;
            cout<<"   -"<<info(nextPass(rP)).nama<<endl;
            cout<<"   -"<<info(nextPass(rP)).gender<<endl;
            i++;
            rP = next(rP);
        }
    }else{
        cout<<"`Maskapai yang ingin dicari data penumpangnya tidak ditemukan`"<<endl;
    }
}

void countPassengerFlights(listMaskapai LM, infotypeMas x){
    adrMaskapai pM = searchMaskapai(LM, x);
    if(pM != NULL){
        int i = 0;
        adrRelation rP = nextRel(pM);
        while(rP != NULL){
            i++;
            rP = next(rP);
        }
        cout<<"`Banyak penumpang pada maskapai "<<info(pM).kode<<": "<<i<<"`"<<endl;
    }else{
        cout<<"`Maskapai yang ingin dihitung banyak penumpangnya tidak ditemukan`"<<endl;
    }
}

void deleteAllRelation(listMaskapai LM, adrRelation &P, infotypeMas x){
    adrMaskapai pM = searchMaskapai(LM, x);
    if(pM != NULL){
        adrRelation rP = nextRel(pM);
        if(rP == NULL){
            cout<<"`"<<info(pM).kode<<" tidak melakukan penerbangan`"<<endl;
        }else if(next(rP) == NULL){
            nextRel(pM) = NULL;
        }else{
            while(rP != NULL){
                P = rP;
                next(P) = NULL;
                rP = next(rP);
            }
            nextRel(pM) = NULL;
        }
        cout<<"`Semua penumpang pada maskapai "<<info(pM).kode<<" telah dihapus`"<<endl;
    }else{
        cout<<"`Maskapai yang ingin dihapus semua relasi(penumpang)nya tidak ditemukan`"<<endl;
    }
}

void deleteAllData(listMaskapai &LM, listPassenger &LP, infotypeMas x){
    adrMaskapai pM = searchMaskapai(LM, x);
    if(pM != NULL){
        adrPassenger P, Prec;
        adrRelation rP = nextRel(pM);
        if(rP == NULL){
            cout<<info(pM).kode<<" tidak memiliki relasi`"<<endl;
        }else{
            while(rP != NULL){
                P = nextPass(rP);
                deleteFirstPassenger(LP, P);
                rP = next(rP);
            }
        }
        adrRelation R;
        deleteAllRelation(LM, R, x);
        adrMaskapai M, Mrec;
        M = first(LM);
        while(next(M) != NULL){
            M = next(M);
        }
        if(pM == first(LM)){
            deleteFirstMaskapai(LM, pM);
            cout<<"`Maskapai "<<info(pM).kode<<" telah dihapus`"<<endl;
        }else if(pM == M){
            deleteLastMaskapai(LM, pM);
            cout<<"`Maskapai "<<info(pM).kode<<" telah dihapus`"<<endl;
        }else{
            deleteAfterMaskapai(LM, Mrec, pM);
            cout<<"`Maskapai "<<info(pM).kode<<" telah dihapus`"<<endl;
        }
    }else{
        cout<<"`Maskapai yang ingin dihapus semua data(Maskapai-Relasi-Penumpang)nya tidak ditemukan`"<<endl;
    }
}

int selectionMenu(){
    cout<<"================ INFORMATION ================"<<endl;
    cout<<"1. Membuat data maskapai"<<endl;
    cout<<"2. Membuat data penumpang"<<endl;
    cout<<"3. Memambahkan data penerbangan penumpang"<<endl;
    cout<<"4. Menampilkan semua data maskapai"<<endl;
    cout<<"5. Menampilkan semua data penumpang"<<endl;
    cout<<"6. Menampilkan semua data penerbangan penumpang"<<endl;
    cout<<"7. Mencari dan menampilkan data maskapai"<<endl;
    cout<<"8. Mencari dan menampilkan data penumpang"<<endl;
    cout<<"9. Mencari dan menampilkan data penumpang pada maskapai tertentu"<<endl;
    cout<<"10. Menghitung dan menampilkan banyaknya penumpang pada maskapai tertentu"<<endl;
    cout<<"11. Mengahapus semua relasi (penumpang) pada maskapai tertentu"<<endl;
    cout<<"12. Mengahapus semua data maskapai (Maskapai-Relasi-Penumpang)"<<endl;
    cout<<"0. Selesai"<< endl;
    cout<<"Pilih menu: ";
    int input = 0;
    cin>>input;
    return input;
}
