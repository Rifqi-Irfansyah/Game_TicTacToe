#include <stdio.h>
#include "modul/linked_list.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string.h>
#include <Windows.h>

int main(){
    address Head;
    int pilihan, giliran = 0, pilihan_game;
    int size_board;
    bool loop = true, loopLuar;
    char player1[50], player2[50];

    do{
        system("cls");
        Head = NULL;
        giliran = 0;
        loop = true;
        loopLuar = true;
        pilihan = menu();

        size_board = readRecords("game_records.dat", Head, giliran, player1, player2);
        if(pilihan == 0){
            loopLuar = false;
        }
        else if (pilihan == 1 && size_board != 0){
            gotoxy(37,30); cout << " 1. Play New Game"<<endl;
            gotoxy(37,31); cout << " 2. Continue Game"<<endl;
            gotoxy(37,32); cout << " Insert Choice : ";
            cin >> pilihan_game;
            if(pilihan_game == 2){
                pilihan = 7;
            }
        }

        switch(pilihan){
            case 1:
                do{
                    loop = false;
                    system("cls");
                    SetConsoleOutputCP(CP_UTF8);
                    cout << "----------------------------------------\n";
                    cout << "| 1. 3 X 3   || 4. 6 X 6   || 0. Back   |\n";
                    cout << "| 2. 4 X 4   || 5. 7 X 7   ||           |\n";
                    cout << "| 3. 5 X 5   || 6. 8 x 8   ||           |\n";
                    cout << "----------------------------------------\n";
                    cout << "Insert Size Board = ";
                    cin >> size_board;
                    if(size_board < 0 || size_board > 6){
                        cout << " !! The Input is Wrong, Press Enter to Insert Again !! ";
                        cin.ignore();
                        cin.get();
                        loop = true;
                    }
                    else if (size_board != 0){
                        cout << "Insert Name Player 1 = ";
                        cin.ignore();
                        cin.getline(player1, 50);
                        cout << "Insert Name Player 2 = ";
                        cin.ignore();
                        cin.getline(player2, 50);
                    }
                }while(loop == true);

                if(size_board != 0){
                    size_board = size_board + 2;
                    Head = createBoard(size_board);
                    do{
                        showBoard(Head, size_board);
                        loop = gameplay(Head, size_board, giliran, player1, player2);
                    }while(loop);
                }
                else{
                    loopLuar = true;
                }
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

    }while(loopLuar);




    
    


    return 0;
}