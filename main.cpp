#include <stdio.h>
#include "modul/linked_list.h"
#include <iostream>
#include <thread>
#include <chrono>

// int main(){
//     address awal, akhir;
//     address P, Q, R, S;
//     awal = NULL;
//     akhir = NULL;


//     printf("Node Saat ini:\n");
//     showNode(awal);

//     printf("\n\nPenambahan\n");
//     addNodeFirst(awal, akhir, P, 35);
//     showNode    (awal);

//     printf("\nPenambahan di Awal\n");
//     addNodeFirst(awal, akhir, Q, 11);
//     showNode    (awal);

//     printf("\nPenambahan di Tengah\n");
//     addNodeMiddle(awal, R, 23);
//     showNode    (awal);
    
//     printf("\nPenambahan di Akhir\n");
//     addNodeLast (awal, akhir, S, 110);
//     showNode    (awal);

//     printf("\n\nPenghapusan di awal\n");
//     removeNodeFirst (awal);
//     showNode        (awal);

//     printf("\n\nPenghapusan di tengah\n");
//     removeNodeMiddle(awal);
//     showNode        (awal);

//     printf("\n\nPenghapusan di akhir\n");
//     removeNodeLast  (awal,akhir);
//     showNode        (awal);

    // printf("\n\nSearching Node Info 23\n");
    // address search = searchingNode(awal, 23);
    // if (search == NULL){
    //     cout << "Maaf tidak ada Node dengan nilai " << 23 <<endl;
    // }
    // else{
    //     cout << "Node Ditemukan " <<endl;
    //     search -> info = 25;
    // }
    // showNode(awal);
    // cout <<endl;

//     removeNode(P);
//     removeNode(Q);
//     removeNode(R);
//     removeNode(S);
//     removeNode(search);

//     return 0;
// }


int main(){
    address awal, akhir, search;
    address P, Q, R, S;
    awal = NULL;
    akhir = NULL;
    int pilihan, nilai, nilai2, aksiSearch;
    
    do{
        system ("cls");
        cout << "\t============================================\n";
        cout << "\t              Node Saat ini:";
        showNode(awal);
        cout << "\n\t============================================\n";
        cout << "------------------------------------------------------------\n";
        cout << "| 1. Tambah Awal   || 4. Hapus Awal    || 7. Temukan Node  |\n";
        cout << "| 2. Tambah Tengah || 5. Hapus Tengah  || 0. Keluar        |\n";
        cout << "| 3. Tambah Akhir  || 6. Hapus Akhir   ||                  |\n";
        cout << "------------------------------------------------------------\n";
        cout << "  Lakukan Aksi Pada Node = "; cin >> pilihan;
        if (((pilihan <= 3) && (pilihan > 0))||( pilihan == 7)){
            cout << "  Masukkan Nilai = "; cin >> nilai;
        }
        cout << "------------------------------------------------------------\n";

        switch (pilihan){
            case 0:
                break;
            case 1: 
                addNodeFirst(awal, akhir, P, nilai);
                break;
            case 2:
                addNodeMiddle(awal, R, nilai);
                break;
            case 3:
                addNodeLast(awal, akhir, S, nilai);
                break;
            case 4:
                removeNodeFirst(awal);
                break;
            case 5:
                removeNodeMiddle(awal);
                break;
            case 6:
                removeNodeLast(awal, akhir);
                break;
            case 7:
                search = searchingNode(awal, nilai);
                if (search == NULL){
                    cout << " !! Maaf tidak ada Node dengan nilai !! " << nilai <<endl;
                }
                else{
                    cout << "         Node Ditemukan \n";
                    cout << "................................\n";
                    cout << "| 1. Edit Info Node            |\n";
                    cout << "| 2. Hapus Node                |\n";
                    cout << "| 0. Kembali                   |\n";
                    cout << "................................\n";
                    cout << "  Lakukan Aksi = "; cin >> aksiSearch;
                    if (aksiSearch == 1){
                        cout << "  Masukkan Nilai = "; cin >> nilai2;
                        search -> info = nilai2;
                    }
                    else if(aksiSearch == 2){
                        removeNodeAnywhere (awal, akhir, search);
                    }
                }
                this_thread::sleep_for(chrono::seconds(2));
                break;
            default:
                pilihan = 1;
                break;
        }
    }while (pilihan != 0);

    removeNode(P);
    removeNode(Q);
    removeNode(R);
    removeNode(S);
    removeNode(search);
    return 0;
}

