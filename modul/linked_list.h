#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;

typedef int infotype;                   
typedef struct tElmtlist *address;     
typedef struct tElmtlist {          
    infotype info; 
    address next; 
} ElmtList;

void addNodeFirst   (address &awal, address &akhir,address &newNode, int nilai);
void addNodeLast    (address &awal, address &akhir,address &newNode, int nilai);
void addNodeMiddle  (address &awal,address &newNode, int nilai);

void removeNodeFirst    (address &awal);
void removeNodeLast     (address &awal, address &akhir);
void removeNodeMiddle   (address &awal);
void removeNodeAnywhere (address &awal, address &akhir, address &node);

void removeNode(address &node);
void showNode  (address awal);
int countNode  (address awal);
address searchingNode(address awal, int nilai);

#include"body.cpp"

#endif