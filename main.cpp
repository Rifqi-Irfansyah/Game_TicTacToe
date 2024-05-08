#include <stdio.h>
#include "modul/linked_list.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string.h>
#include <Windows.h>

int main(){
    address awal, search, Head;
    awal = NULL;
    int pilihan, giliran = 0;
    int info_simbol;
    int size_board = 3;
    bool loop = true;
    string player1, player2;

    pilihan = menu();

    switch(pilihan){
        case 1:
            do{
                loop = false;
                system("cls");
                SetConsoleOutputCP(CP_UTF8);
                cout << "	❎\xE2\x9D\x8E";
                cout << "----------------------------------------\n";
                cout << "| 1. 3 X 3   || 4. 6 X 6   || 0. Back   |\n";
                cout << "| 2. 4 X 4   || 5. 7 X 7   ||           |\n";
                cout << "| 3. 5 X 5   || 6. 8 x 8   ||           |\n";
                cout << "----------------------------------------\n";
                cout << "Insert Size Board = ";
                cin >> size_board;
                cout << "Insert Name Player 1 = ";
                cin >> player1;
                cout << "Insert Name Player 2 = ";
                cin >> player2;

                if(size_board < 0 || size_board > 6){
                    cout << " !! The Input is Wrong, Press Enter to Insert Again !! ";
                    cin.ignore();
                    cin.get();
                    loop = true;
                }
            }while(loop == true);

            size_board = size_board + 2;
            Head = createBoard(size_board);

            do{
                showBoard(Head, size_board);
                if(giliran == 0){
                    cout << player1 << ", Insert the Number = ";
                    giliran = -1;
                }
                else{
                    cout << player2 << ", Insert the Number = ";
                    giliran = 0;
                }
                cin >> info_simbol;
                search = searchingNode(Head, info_simbol);

                if (search != nullptr){
                    search -> info = giliran;
                }
                else{
                    if (giliran == 0){
                        giliran = -1;
                    }
                    else {
                        giliran = 0;
                    }
                    cout << " !! Sorry, Dosen't exist the number " << info_simbol << " , Press Enter to Insert Again !! ";
                    cin.ignore();
                    cin.get();
                }
                loop = checkBoard(Head);
            }while(loop);
            showBoard(Head, size_board);

            break;
        
        case 2:
            system("CLS");
            // instructions();
            break;

        case 3:
            system("CLS");
            // aboutus();
            break;

        case 0:
            exit(1);
            break;

        default:
            menu();
            break;
	}



    saveRecords("game_records.dat", awal);
    readRecords("game_records.dat", awal);


    return 0;
}