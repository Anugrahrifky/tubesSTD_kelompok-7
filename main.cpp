#include "flight.h"

int main()
{
    //====================================//

    listMaskapai LM;
    createListMaskapai(LM);
    adrMaskapai mP;
    infotypeMas dataMaskapai;

    //====================================//

    listPassenger LP;
    createListPassenger(LP);
    adrPassenger pP;
    infotypePass dataPassanger;

    //====================================//

    adrRelation rP;

    char YN;

    int input = selectionMenu();
    while(input != 0){
        switch(input){
        case 1:
            cout<<"Input kode maskapai: ";
            cin>>dataMaskapai.kode;
            cout<<"Input jenis maskapai: ";
            cin>>dataMaskapai.jenis;
            cout<<"Input asal maskapai: ";
            cin>>dataMaskapai.asal;
            cout<<"Input tujuan maskapai: ";
            cin>>dataMaskapai.tujuan;
            insertLastMaskapai(LM, dataMaskapai);
            cout<<endl;
            break;
        case 2:
            cout<<"input NIK penumpang: ";
            cin>>dataPassanger.NIK;
            cout<<"input nama penumpang: ";
            cin>>dataPassanger.nama;
            cout<<"input jenis kelamin penumpang: ";
            cin>>dataPassanger.gender;
            insertLastPassenger(LP, dataPassanger);
            cout<<endl;
            break;
        case 3:
            cout<<"Kode maskapai: ";
            cin>>dataMaskapai.kode;
            cout<<"NIK penumpang: ";
            cin>>dataPassanger.NIK;
            mP = searchMaskapai(LM, dataMaskapai);
            pP = searchPassenger(LP, dataPassanger);
            insertRelation(mP, pP);
            cout<<endl;
            break;
        case 4:
            cout<<endl;
            showAllMaskapai(LM);
            cout<<endl;
            break;
        case 5:
            cout<<endl;
            showAllPassenger(LP);
            cout<<endl;
            break;
        case 6:
            cout<<endl;
            showAllRelation(LM);
            cout<<endl;
            break;
        case 7:
            cout<<"Masukkan kode maskapai yang dicari: ";
            cin>>dataMaskapai.kode;
            cout<<endl;
            showSearchMaskapai(LM, dataMaskapai);
            cout<<endl;
            break;
        case 8:
            cout<<"Masukkan NIK penumpang yang dicari: ";
            cin>>dataPassanger.NIK;
            cout<<endl;
            showSearchPassenger(LP, dataPassanger);
            cout<<endl;
            break;
        case 9:
            cout<<"Masukkan kode maskapai yang ingin dicari data penumpangnya: ";
            cin>>dataMaskapai.kode;
            cout<<endl;
            searchPassengerFlights(LM, dataMaskapai);
            cout<<endl;
            break;
        case 10:
            cout<<"Masukkan kode maskapai yang ingin dihitung banyak penumpangnya: ";
            cin>>dataMaskapai.kode;
            cout<<endl;
            countPassengerFlights(LM, dataMaskapai);
            cout<<endl;
            break;
        case 11:
            cout<<"Masukkan kode maskapai yang ingin dihapus semua relasi(penumpang)nya: ";
            cin>>dataMaskapai.kode;
            cout<<endl;
            deleteAllRelation(LM, rP, dataMaskapai);
            cout<<endl;
            break;
        case 12:
            cout<<"Masukkan kode maskapai yang ingin dihapus semua data(maskapai-Relasi-Penumpang)nya: ";
            cin>>dataMaskapai.kode;
            cout<<endl;
            deleteAllData(LM, LP, dataMaskapai);
            cout<<endl;
            break;
        }
        input = selectionMenu();
    }
    return 0;
}
