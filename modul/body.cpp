// 231511066 Afriza Mu'ammar
// 231511089 Rifqi Irfansyah
#include "linked_list.h"
#include <iostream>
#include <fstream>
#include <string>

address createBoard(int size_board){
    address Head = NULL;
    address rowStart = NULL;
    address upNode = NULL;
    address temp_last = NULL;
    int j = 1;

    for(int i=1; i<=size_board; i++){

        for(int i=1; i<=size_board; i++){
            address newNode = (address) malloc(sizeof (tElmtlist));
            if (newNode == NULL){
                printf("Memori Full");
            }
            else{
                newNode -> info = j;
                j++;
                
                newNode -> next = NULL;
                newNode -> prev = NULL;
                newNode -> up   = NULL;
                newNode -> down = NULL;
            }

            if (Head == NULL){
                Head = newNode;
            }
            if (rowStart == NULL){
                rowStart = newNode;
            }
            else{
                newNode -> prev = temp_last;
                temp_last -> next = newNode;
            }

            if(upNode != NULL){
                upNode -> down = newNode;
                newNode -> up = upNode;
                upNode = upNode -> next;
            }
            temp_last = newNode;
        }

        upNode = rowStart;
        rowStart = NULL;
    }

    return Head;
}

void showBoard(address Head, int size_board){
    system ("cls");
    printf("\t");
    for(int i=1; i<=size_board; i++){
        printf ("--------");
    }
    printf ("-\n");

    address temp = Head;
    address temp_start;
    
    for(int i=1; i<=size_board; i++){
        temp_start = temp;
        printf("\t");
        for (int j=1; j<= size_board; j++){
            printf ("|       ");
        }
        printf ("|\n\t");

    
        for (int j=1; j<= size_board; j++){
            if (temp -> info == 0){
                printf ("|");
                warnateks(GREEN);
                printf ("   O   ");
                warnateks(WHITE);
            }
            else if (temp -> info == -1){
                printf ("|");
                warnateks(BLUE);
                printf ("   X   ");
                warnateks(WHITE);
            }
            else if (temp->info <= 9){
                printf ("|   %d   ", temp -> info);
            }
            else{
                printf ("|   %d  ", temp -> info);
            }
            temp = temp->next;
        }
        printf ("|\n\t");
        

        for (int j=1; j<= size_board; j++){
            printf ("|       ");
        }
        printf ("|\n\t");
        for(int i=1; i<=size_board; i++){
            printf ("--------");
        }
            printf ("-\n");

        temp = temp_start->down;
    }
}

void showNode(address awal){
    if (awal == NULL){
        printf ("\n\t\t !! List node kosong !!");
    }
    else{
        address node = awal;
        int i = 1;
        while (node != NULL) {
            printf ("\n\t > Node %i = %d ",i, node -> info);
            node = node->next;
            i++;
        }
    }
    
}

int countNode (address awal){
    if (awal == NULL){
        return 0;
    }
    else{
        address node = awal;
        int i = 1;
        while (node -> next != NULL){
            node = node -> next;
            i++;
        }
        return i;
    }
}

void removeNodeFirst(address &awal){
    if (awal == NULL){
        printf ("Maaf penghapusan gagal, tidak ada node");
    }
    else{
        address temp;
        temp = awal;
        awal = awal -> next;
        removeNode(temp);
    }
}

void removeNodeLast(address &awal, address &akhir){
    if ((akhir == NULL) || (awal == NULL)){
        printf ("Maaf penghapusan gagal, tidak ada node");
    }
    else{
        int count = countNode(awal);
        if(count == 1){
            removeNode(awal);
            removeNode(akhir);
        }
        else{
            address before_last, temp;
            before_last = awal;
            for (int i=1; i<(count-1); i++){
                before_last = before_last -> next;
            }
            temp = akhir;
            akhir = before_last;
            before_last -> next = NULL;
            removeNode(temp);
        }
    }
}

void removeNodeMiddle(address &awal){
    address before_mid, mid;
    address node = awal;
    int count = countNode(awal);
    
    if (count <= 2){
        printf("Maaf penghapusan gagal, total node harus > 2");
    }
    else{
        int i = 1;
        while(i <= (count/2)){  //Searching middle node
            before_mid = node;
            node = node -> next;
            i++;
        }

        mid = before_mid -> next;
        before_mid -> next = NULL;
        before_mid -> next = mid -> next;
        mid -> next = NULL;
        removeNode(mid);
    }
}

void removeNodeAnywhere(address &awal, address &akhir, address &node){
    if (node == awal){
        removeNodeFirst(awal);
    }
    else if (node == akhir){
        removeNodeLast(awal, akhir);
    }
    else{
        address temp = node;
        while (temp -> next != node){
            temp = temp -> next;
        }
        temp -> next = NULL;
        temp -> next = node -> next;
        removeNode(node);
    }
}

void removeNode(address &node){
    cout << " # Menghapus Node -> Nilai = " << node->info<<endl;
    if (node != NULL){
        node = NULL;
    }
    free(node);
}

address searchingNode(address Head, infotype nilai){
    address rowStart = NULL;
    address node = Head;
    address result = NULL;

    // loop down
    while(node != NULL){
        // loop right
        while(node != NULL){
            if (node -> info == nilai){
                result = node;
                return result;
            }
            
            if (rowStart == NULL){
                rowStart = node;
            }
            node = node -> next;
        }
        node = rowStart -> down;
        rowStart = NULL;
    }
    return result;
}

void saveRecords(const char* filename, address head) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    address current = head;
    while (current != nullptr) {
        // Write each member of Memo to the file
        outFile.write(reinterpret_cast<char*>(&current->info), sizeof(int));

        current = current->next;
    }

    outFile.close();
}

void readRecords(const char* filename, address& head) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    // Initialize head pointer
    head = nullptr;
    address current = nullptr;
    while (inFile.peek() != EOF) {


        // Create a new Memo object
        address newNode = new ElmtList;

        // Read data from file into the new Memo object
        inFile.read(reinterpret_cast<char*>(&newNode->info), sizeof(int));

        // Link the new node to the linked list
        if (!head) {
            head = newNode;
        } else {
            current->next = newNode;
            // newNode->prev = current;
        }
        current = newNode;
        current->next = NULL;
    }

    inFile.close();
}

void gotoxy(int x, int y) //modul untuk memfungsikan fungsi gotoxy
{ 
	HANDLE hConsoleOutput;  
	COORD dwCursorPosition;  
	dwCursorPosition.X = x;  
	dwCursorPosition.Y = y;  
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);   
}

void warnateks(int warna) //modul yang berfungsi untuk memberi warna ke karakter
{ 
	HANDLE hConsole; 
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, warna);
}

void judul()//sebagai tampilan awal program
{ 
	warnateks(LIGHT_BLUE);
	gotoxy(8,1); printf("  ����������  ��   �����             ����������   ����    ����� \n");
	printf("              ��      ��  ��                     ��      ��  ��  ��     \n");
	printf("              ��      ��  ��                     ��      ��  ��  ��     \n");
	printf("              ��      ��  ��                     ��      ������  ��     \n");
	printf("              ��      ��  ��                     ��      ��  ��  ��     \n");
	printf("              ��      ��   �����                 ��      ��  ��   ����� \n \n\n\n");
	
	printf("      		           ����������  �����   ����� \n");
	printf("	 	               ��     ��   ��  �     \n");
	printf("		               ��     ��   ��  ����� \n");
	printf("		               ��     ��   ��  � \n");
	printf("                               ��     ��   ��  �     \n");
	printf("		               ��      �����   ����� \n");
	
	warnateks(LIGHT_GREEN);
	gotoxy(9,18); printf("��       �� \n");
	gotoxy(9,19); printf("  ��   �� \n");
	gotoxy(9,20); printf("    ��� \n");
	gotoxy(9,21); printf("    ��� \n");
	gotoxy(9,22); printf("  ��   �� \n");
	gotoxy(9,23); printf("��       �� \n");	
	warnateks(YELLOW);
	gotoxy(61,18); printf("    ����  \n");
	gotoxy(61,19); printf("  ��    �� \n");
	gotoxy(61,20); printf("  ��    �� \n");
	gotoxy(61,21); printf("  ��    �� \n");
	gotoxy(61,22); printf("  ��    �� \n");
	gotoxy(61,23); printf("    ���� \n");	
}

int menu() { 
	int pilih_menu, i = 28;
	judul();
	warnateks(WHITE);
	gotoxy(i,18);printf(" [�����������������������ͻ\n");
   	gotoxy(i,19);printf(" �      MAIN MENU        �\n");
   	gotoxy(i,20);printf(" �                       �\n");
   	gotoxy(i,21);printf(" �   [1] PLAY NOW !      �\n");
   	gotoxy(i,22);printf(" �   [2] INSTRUCTIONS    �\n");
   	gotoxy(i,23);printf(" �   [3] THE CREATOR     �\n");
   	gotoxy(i,24);printf(" �   [0] Exit            �\n");
   	gotoxy(i,25);printf(" �                       �\n");
   	gotoxy(i,26);printf(" �����������������������ͼ\n");
	gotoxy(i,28);printf("    Choose :            \n");
   	gotoxy(41,28);scanf("%d",&pilih_menu);
   	return pilih_menu;
}

bool checkBoard(address Head){
    bool checkEmpty = checkEmptyBoard(Head);

    if (!checkEmpty){
        return false;
    }
    else{
        return true;
    }
}

bool checkEmptyBoard(address Head){
    address rowStart = NULL;
    address node = Head;

    // loop down
    while(node != NULL){
        // loop right
        while(node != NULL){
            if (node -> info != -1 && node -> info != 0){
                return true;
            }
            
            if (rowStart == NULL){
                rowStart = node;
            }
            node = node -> next;
        }
        node = rowStart -> down;
        rowStart = NULL;
    }
    return false;
}

bool checkWin(address node, int streak, infotype nilai){
    int count = 1;
    address temp;
    
    // check horizontal
    temp = node->prev;
    while(temp != nullptr){
        if(temp->info == nilai){
            count ++;
        }
        temp = temp->prev;
    }
    
    temp = node->next;
    while(temp != nullptr){
        if(temp->info == nilai){
            count ++;
        }
        temp = temp->next;
    }
    if(count >= streak){
        return true;
    }
    else{
        //check vertical
        count = 1;
        temp = node->down;
        while(temp != nullptr){
            if(temp->info == nilai){
                count ++;
            }
            temp = temp->down;
        }
        temp = node->up;
        while(temp != nullptr){
            if(temp->info == nilai){
                count ++;
            }
            temp = temp->up;
        }
        if(count >= streak){
            return true;
        }
        else{
            //check diagonal main (ke kanan menurun)
            count = 1;
            temp = node->prev;
            if(temp!= nullptr){temp = temp->up;}
            while(temp != nullptr){
                if(temp->info == nilai){
                    count ++;
                }
                temp = temp->prev;
                if(temp!= nullptr){temp = temp->up;}
                else{break;}
            }

            temp = node->next;
            if(temp!=nullptr){temp = temp->down;}
            while(temp != nullptr){
                if(temp->info == nilai){
                    count ++;
                }
                temp = temp->next;
                if(temp!=nullptr){temp = temp->down;}
                else{break;}
            }

            if(count >= streak){
                return true;
            }
            else{
                //check diagonal sekunder (ke kanan menurun)
                count = 1;
                temp = node->next;
                if(temp!= nullptr){temp = temp->up;}
                while(temp != nullptr){
                    if(temp->info == nilai){
                        count ++;
                    }
                    temp = temp->next;
                    if(temp!= nullptr){temp = temp->up;}
                    else{break;}
                }

                temp = node->prev;
                if(temp!=nullptr){temp = temp->down;}
                while(temp != nullptr){
                    if(temp->info == nilai){
                        count ++;
                    }
                    temp = temp->prev;
                    if(temp!=nullptr){temp = temp->down;}
                    else{break;}
                }

                if(count >= streak){
                    return true;
                }
                else{
                    return false;
                }
            }

        }

    }
}