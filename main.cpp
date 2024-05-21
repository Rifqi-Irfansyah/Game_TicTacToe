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
        setColor(BACKGROUND_LIGHTBLUE|FOREGROUND_BLACK);
        setFullScreen();
        system("cls");
        Head = NULL;
        loop = true;
        loopLuar = true;
        pilihan = menu();

        size_board = readRecords("game_records.dat", Head, giliran, player1, player2);
        if(pilihan == 0){
            loopLuar = false;
        }
        else if (pilihan == 1 && size_board != 0){
            system("cls");
            int i = 22;
	        judul();
            warnateks(WHITE);
            printWithColor(" [][][][][][][][][][][][][][][][][][][][][][][]\n", i, 18, BACKGROUND_BLUE);
            printWithColor(" []                 CONTINUE GAME?           []\n", i, 19, BACKGROUND_BLUE);
            printWithColor(" []                                          []\n", i, 20, BACKGROUND_BLUE);
            printWithColor(" []   (1) PLAY NEW GAME                      []\n", i, 21, BACKGROUND_BLUE);
            printWithColor(" []   (2) CONTINUE GAME                      []\n", i, 22, BACKGROUND_BLUE);
            printWithColor(" []   (0) BACK                               []\n", i, 23, BACKGROUND_BLUE);
            printWithColor(" []                                          []\n", i, 24, BACKGROUND_BLUE);
            printWithColor(" []   CHOOSE :                               []\n", i, 25, BACKGROUND_BLUE);
            printWithColor(" []                                          []\n", i, 26, BACKGROUND_BLUE);
            printWithColor(" [][][][][][][][][][][][][][][][][][][][][][][]\n", i, 27, BACKGROUND_BLUE);
            gotoxy(37,25);
    
            cin >> pilihan_game;
            if(pilihan_game == 2){
                pilihan = 7;
            }
            else if(pilihan_game == 0){
                pilihan = 0;
            }
        }

        switch(pilihan){
            case 1:
                do{
                    loop = false;
                    system("cls");
                    int i = 5;
                    printWithColor(" [][][][][][][][][][][][][][][][][][][][][][][]\n", i, 3, BACKGROUND_BLUE);
                    printWithColor(" []                SIZE BOARD                []\n", i, 4, BACKGROUND_BLUE);
                    printWithColor(" []                                          []\n", i, 5, BACKGROUND_BLUE);
                    printWithColor(" []   (1) SIZE 3x3           (5) SIZE 6x6    []\n", i, 6, BACKGROUND_BLUE);
                    printWithColor(" []   (2) SIZE 4x4           (6) SIZE 7x7    []\n", i, 7, BACKGROUND_BLUE);
                    printWithColor(" []   (3) SIZE 5x5           (0) BACK        []\n", i, 8, BACKGROUND_BLUE);
                    printWithColor(" []   (4) SIZE 6x6                           []\n", i, 9, BACKGROUND_BLUE);
                    printWithColor(" []                                          []\n", i, 10, BACKGROUND_BLUE);
                    printWithColor(" []   CHOOSE :                               []\n", i, 11, BACKGROUND_BLUE);
                    printWithColor(" []                                          []\n", i, 12, BACKGROUND_BLUE);
                    printWithColor(" []                                          []\n", i, 13, BACKGROUND_BLUE);
                    printWithColor(" []                                          []\n", i, 14, BACKGROUND_BLUE);
                    printWithColor(" [][][][][][][][][][][][][][][][][][][][][][][]\n", i, 15, BACKGROUND_BLUE);
                    gotoxy(i+15,11); cin >> size_board;

                    gotoxy(i+6,12);
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
                        gotoxy(i+6,13); cout << "Insert Name Player 2 = ";
                        cin.getline(player2, 50);
                    }
                }while(loop == true);

                if(size_board != 0){
                    size_board = size_board + 2;
                    Head = createBoard(size_board);
                    giliran = 0;
                    do{
                        system("cls");
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
                    system ("cls");
                    setColor(BACKGROUND_LIGHTBLUE|FOREGROUND_BLACK);
                    showBoard(Head, size_board);
                    loop = gameplay(Head, size_board, giliran, player1, player2);
                }while(loop);

                break;

            case 0:
                break;

            default:
                menu();
                break;
        }

    }while(loopLuar);
    
    deleteBoard(Head);
    return 0;
}