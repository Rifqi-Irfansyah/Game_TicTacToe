// 231511066 Afriza Mu'ammar
// 231511089 Rifqi Irfansyah
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdlib.h>
#include<stdio.h>
#include<string>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

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


// void addNodeFirst   (address &awal, address &akhir,address &newNode, infotype nilai);    // Afriza
// void addNodeLast    (address &awal, address &akhir,address &newNode, infotype nilai);    // Rifqi
// void addNodeMiddle  (address &awal,address &newNode, infotype nilai);                    // Rifqi

void removeNodeFirst    (address &awal);                                            // Afriza
void removeNodeLast     (address &awal, address &akhir);                            // Rifqi
void removeNodeMiddle   (address &awal);                                            // Afriza
void removeNodeAnywhere (address &awal, address &akhir, address &node);             // Rifqi

void removeNode(address &node);                                                     // Rifqi
void showNode  (address awal);                                                      // Afriza
int countNode  (address awal);                                                      // Afriza

address createBoard(int size_board);
address searchingNode(address Head, infotype nilai);                                     // Rifqi
void showBoard(address Head, int size_board);
int menu();
void warnateks(int warna);
void judul();
void gotoxy(int x, int y);
void readRecords(const char* filename, address& head);
void saveRecords(const char* filename, address head);
bool checkBoard(address Head);
bool checkEmptyBoard(address Head);
bool checkWin(address node, int streak, infotype nilai);

#include"body.cpp"

#endif