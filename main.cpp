#include <stdio.h>
#include "modul/linked_list.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string.h>
#include <Windows.h>

int main(){
    address search, Head;
    int pilihan, giliran = 0;
    int info_simbol;
    int size_board;
    bool loop = true;
    bool win = false;
    string player1, player2, giliran_player;

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
                if (size_board == 3){
                    cout << " Menang = 3 Streak ";                
                }
                else if(size_board == 4 || size_board == 5){
                    cout << " Menang = 4 Streak ";
                }
                else{
                    cout << " Menang = 5 Streak ";
                }
                cout << "\n Press 0 to Exit \n";
                if(giliran == 0){
                    warnateks(BLUE);
                    cout << player1 << ", Insert the Number = ";
                    warnateks(WHITE);
                    giliran = -1;
                    giliran_player = player1;
                }
                else{
                    warnateks(GREEN);
                    cout << player2 << ", Insert the Number = ";
                    warnateks(WHITE);
                    giliran = 0;
                    giliran_player = player2;
                }
                cin >> info_simbol;
                if (info_simbol == 0){
                    saveRecords("game_records.dat", Head, size_board);
                    loop = false;
                }
                else{
                    search = searchingNode(Head, info_simbol);

                    if (search == nullptr){
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
                    else{
                        search -> info = giliran;
                        if (size_board == 3){
                            win = checkWin(search, 3, giliran);
                        }
                        else if(size_board == 4 || size_board == 5){
                            win = checkWin(search, 4, giliran);
                        }
                        else{
                            win = checkWin(search, 5, giliran);
                        }
                    }

                    if(!win){
                        loop = checkBoard(Head);
                    }
                    else{
                        showBoard(Head, size_board);
                        cout << " Kamu Menang, " << giliran_player;
                        cin.ignore();
                        cin.get();
                        loop = false;
                    }
                }
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
            size_board = readRecords("game_records.dat", Head);
            showBoard(Head, size_board);
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