#include <stdio.h>
#include "modul/linked_list.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string.h>
#include <Windows.h>

int main(){
    address Head;
    int pilihan, giliran = 0;
    int size_board;
    bool loop = true;
    char player1[50], player2[50];

    pilihan = menu();


    switch(pilihan){
        case 1:
            do{
                loop = false;
                system("cls");
                SetConsoleOutputCP(CP_UTF8);
                cout << "----------------------------------------\n";
                cout << "| 1. 3 X 3   || 4. 6 X 6   || 0. Back   |\n";
                cout << "| 2. 4 X 4   || 5. 7 X 7   || 7. Resume |\n";
                cout << "| 3. 5 X 5   || 6. 8 x 8   ||           |\n";
                cout << "----------------------------------------\n";
                cout << "Insert Size Board = ";
                cin >> size_board;
                cout << "Insert Name Player 1 = ";
                cin.ignore();
                cin.getline(player1, 50);
                cout << "Insert Name Player 2 = ";
                cin.ignore();
                cin.getline(player2, 50);

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
                loop = gameplay(Head, size_board, giliran, player1, player2);
            }while(loop);
            break;
        
        case 2:
            system("CLS");
            
            // instructions();
            break;

        case 3:
            system("CLS");
            // aboutus();
            break;

        case 7:
            size_board = readRecords("game_records.dat", Head, giliran, player1, player2);
            do{
                showBoard(Head, size_board);
                gameplay(Head, size_board, giliran, player1, player2);
            }while(loop);

            break;

        case 0:
            exit(1);
            break;

        default:
            menu();
            break;
	}



    
    


    return 0;
}