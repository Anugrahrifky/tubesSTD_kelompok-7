#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED

#include <iostream>

using namespace std;

#define info(P) P->info
#define next(P) P->next
#define nextPass(P) P->nextPass
#define nextRel(P) P->nextRel
#define first(L) L.first

//====================================//

struct Pass{
    int NIK;
    string nama;
    string gender;
};

typedef Pass infotypePass;

typedef struct passenger *adrPassenger;
struct passenger{
    infotypePass info;
    adrPassenger next;
};

struct listPassenger{
    adrPassenger first;
};

//====================================//

typedef struct relation *adrRelation;
struct relation{
    adrPassenger nextPass;
    adrRelation next;
};

//====================================//


struct Mas{
    string kode;
    string jenis;
    string asal;
    string tujuan;
};

typedef Mas infotypeMas;

typedef struct maskapai *adrMaskapai;
struct maskapai{
    infotypeMas info;
    adrMaskapai next;
    adrRelation nextRel;
};

struct listMaskapai{
    adrMaskapai first;
};

//====================================//

void createListMaskapai(listMaskapai &L);
adrMaskapai newElmMaskapai(infotypeMas x);
void insertLastMaskapai(listMaskapai &L, infotypeMas x);
adrMaskapai searchMaskapai(listMaskapai L, infotypeMas x);
void showSearchMaskapai(listMaskapai L, infotypeMas x);
void showAllMaskapai(listMaskapai L);
void deleteFirstMaskapai(listMaskapai &L, adrMaskapai P);
void deleteLastMaskapai(listMaskapai &L, adrMaskapai P);
void deleteAfterMaskapai(listMaskapai &L, adrMaskapai Prec, adrMaskapai P);

//====================================//

void createListPassenger(listPassenger &L);
adrPassenger newElmPassenger(infotypePass x);
void insertLastPassenger(listPassenger &L, infotypePass x);
adrPassenger searchPassenger(listPassenger L, infotypePass x);
void showSearchPassenger(listPassenger L, infotypePass x);
void showAllPassenger(listPassenger L);
void deleteFirstPassenger(listPassenger &L, adrPassenger P);

//====================================//

adrRelation newRelation();
void insertRelation(adrMaskapai &M, adrPassenger P);
void showAllRelation(listMaskapai LM);

//====================================//

void searchPassengerFlights(listMaskapai LM, infotypeMas x);
void countPassengerFlights(listMaskapai LM, infotypeMas x);
void deleteAllRelation(listMaskapai LM, adrRelation &P, infotypeMas x);
void deleteAllData(listMaskapai &LM, listPassenger &LP, infotypeMas x);
int selectionMenu();

#endif // FLIGHT_H_INCLUDED
