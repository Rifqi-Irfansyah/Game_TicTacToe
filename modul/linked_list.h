// 231511066 Afriza Mu'ammar
// 231511089 Rifqi Irfansyah
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define BOLD 1000
#define BLACK           0
#define DARK_BLUE       1
#define GREEN           2
#define TURQUOISE       3
#define DARK_RED        4
#define PURPLE          5
#define FOREST_GREEN    6
#define LIGHT_GRAY      7
#define GRAY            8
#define BLUE            9
#define LIGHT_GREEN    10
#define LIGHT_BLUE     11
#define RED            12
#define PINK           13
#define YELLOW         14
#define WHITE          15
#define STDALERT      140
#define STDHEADER     143
#define STDBACKGROUND 159
#define BACKGROUND_BLACK 0x0000       // Warna hitam
#define BACKGROUND_CYAN 0x0030        // Warna cyan
#define BACKGROUND_MAGENTA 0x0050     // Warna magenta
#define BACKGROUND_BROWN 0x0060       // Warna coklat
#define BACKGROUND_LIGHTGRAY 0x0070   // Warna abu-abu muda
#define BACKGROUND_DARKGRAY 0x0080    // Warna abu-abu gelap
#define BACKGROUND_LIGHTBLUE 0x0090   // Warna biru muda
#define BACKGROUND_LIGHTGREEN 0x00A0  // Warna hijau muda
#define BACKGROUND_LIGHTCYAN 0x00B0   // Warna cyan muda
#define BACKGROUND_LIGHTRED 0x00C0    // Warna merah muda
#define BACKGROUND_LIGHTMAGENTA 0x00D0// Warna magenta muda
#define BACKGROUND_YELLOW 0x00E0      // Warna kuning
#define BACKGROUND_WHITE 0x00F0       // Warna putih
#define BACKGROUND_PURPLE 0x0050       // Warna ungu
#define FOREGROUND_BLACK 0x00

using namespace std;

typedef char infotype;                   
typedef struct tElmtlist *address;     
typedef struct tElmtlist {          
    infotype info; 
    address next; 
    address prev;
    address up;
    address down;
} ElmtList;

void setFullScreen();
void setColor       (int color);
void gotoxyColor    (int x, int y);
void gotoxy         (int x, int y);
void printWithColor (const char* text, int width, int line, int color);
void warnateks      (int warna);
void judul();
void winner         (char* player);
void draw();

int menu();
address createBoard     (int size_board);
address searchingNode   (address Head, infotype nilai);                                                                                      
void showBoard          (address Head, int size_board);
bool gameplay           (address Head, int size_board, int &giliran, char* player1, char* player2);
bool checkEmptyBoard    (address Head);
bool checkWin           (address node, int streak, infotype nilai);
void removeFile();
int readRecords         (const char* filename, address& head, int& giliran, char (&player1)[50], char (&player2)[50]);
void saveRecords        (const char* filename, address head, int size_board, int giliran, char player1[50], char player2[50]);
void deleteBoard(address Head);

#include"body.cpp"

#endif