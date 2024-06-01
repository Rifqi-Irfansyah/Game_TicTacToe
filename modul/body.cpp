// 231511066 Afriza Mu'ammar
// 231511089 Rifqi Irfansyah
#include "linked_list.h"

void gotoxy(int x, int y){ 
	HANDLE hConsoleOutput;  
	COORD dwCursorPosition;  
	dwCursorPosition.X = x;  
	dwCursorPosition.Y = y;  
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);   
}

void warnateks(int warna){ 
	HANDLE hConsole; 
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, warna);
}

void setFullScreen() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE); // Maksimalkan jendela konsol
    ShowWindow(hwnd, SW_SHOWMAXIMIZED); // Tampilkan jendela yang sudah dimaksimalkan
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxyColor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printWithColor(const char* text, int width, int line, int color) {
    if(width != 0 && line != 0){
        gotoxyColor(width, line);
    }
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] == '[' || text[i] == ']') {
            setColor(color);
            cout << " ";
        }
        else if(text[i] == '_'){
            setColor(BACKGROUND_LIGHTBLUE|FOREGROUND_BLUE);
            cout << "=";
        }
        else {
            setColor(BACKGROUND_LIGHTBLUE|FOREGROUND_BLACK);
            cout << text[i];
        }
        i++;
    }
}

void judul(){ 
    int width;
    width = 1;

    printWithColor("   [[][][][]  [[]  [][][][]   [][][][]   [][][]     [][][][]  [[][][][] []][][][]  [][][][] \n", width, 3, BACKGROUND_BLACK);
    printWithColor("      []]     [[]  []]          [[]     []]  []]    [[]          [[]    []]   []]  []]      \n", width, 4, BACKGROUND_BLACK);
    printWithColor("      []]     [[]  []]          [[]    [][][][][]   [[]          [[]    []]   []]  [][][][] \n", width, 5, BACKGROUND_BLACK);
    printWithColor("      []]     [[]  []]          [[]    []]    [[]   [[]          [[]    []]   []]  []]       \n", width, 6, BACKGROUND_BLACK);
    printWithColor("      []]     [[]  [][][][]     [[]    []]    [[]   [][][][]     [[]    [][[][][]  [][][][] \n", width, 7, BACKGROUND_BLACK);


	width = 98;
    printWithColor("[][][]        [][][] \n", width, 3, BACKGROUND_RED);
    printWithColor(" [][][]      [][][]  \n", width, 4, BACKGROUND_RED);
    printWithColor("  [][][]    [][][]   \n", width, 5, BACKGROUND_RED);
	printWithColor("   [][][]  [][][]    \n", width, 6, BACKGROUND_RED);
	printWithColor("    [][][][][][]      \n", width, 7, BACKGROUND_RED);
	printWithColor("     [][][][][]       \n", width, 8, BACKGROUND_RED);
	printWithColor("    [][][][][][]      \n", width, 9, BACKGROUND_RED);
	printWithColor("   [][][]  [][][]    \n", width, 10, BACKGROUND_RED);
	printWithColor("  [][][]    [][][]   \n", width, 11, BACKGROUND_RED);
    printWithColor(" [][][]      [][][]  \n", width, 12, BACKGROUND_RED);
    printWithColor("[][][]        [][][] \n", width, 13, BACKGROUND_RED);
	
    printWithColor("  [][][][][][][][][] \n", width, 17, BACKGROUND_WHITE);
    printWithColor(" [][][][][][][][][][] \n", width, 18, BACKGROUND_WHITE);
    printWithColor("[][][]          [][][] \n", width, 19, BACKGROUND_WHITE);
    printWithColor("[][][]          [][][] \n", width, 20, BACKGROUND_WHITE);
    printWithColor("[][][]          [][][] \n", width, 21, BACKGROUND_WHITE);
    printWithColor("[][][]          [][][] \n", width, 22, BACKGROUND_WHITE);
    printWithColor("[][][]          [][][] \n", width, 23, BACKGROUND_WHITE);
    printWithColor("[][][]          [][][] \n", width, 24, BACKGROUND_WHITE);
    printWithColor("[][][]          [][][] \n", width, 25, BACKGROUND_WHITE);
    printWithColor(" [][][][][][][][][][] \n", width, 26, BACKGROUND_WHITE);
    printWithColor("  [][][][][][][][][] \n", width, 27, BACKGROUND_WHITE);
}

void winner(char* player, int size_board){ 
    int width, height;
    width = 1;
    height = 12 + 4*size_board;

    printWithColor("   []]  []   [[]  [[]  [][][][][]  [][][][][]  [][][][]  [[][][]]             \n", width, height, BACKGROUND_BLACK);
    printWithColor("   []]  []   [[]  []]  []]    []]  [[]    []]  []]       [[]  []]    [][][][]  \n", width, height + 1, BACKGROUND_BLACK);
    printWithColor("   []]  []   [[]  []]  []]    []]  [[]    []]  [][][]    [[][][]]             \n", width, height + 2, BACKGROUND_BLACK);
    printWithColor("   []]  []   [[]  []]  []]    []]  [[]    []]  [[]       [[] []]     [][][][]  \n", width, height + 3, BACKGROUND_BLACK);
    printWithColor("   [][][][[[][]]  [[]  []]    []]  [[]    []]  [[][][]]  []]  []]             \n", width, height + 4, BACKGROUND_BLACK);

    gotoxy(78, height + 2);
    cout << "\t" <<player;
}

void draw(int size_board){ 
    int width, height;
    width = 1;
    height = 12 + 4*size_board;

    printWithColor("   []][][[]    [][][][]    [][][]    []]   []   []]       \n", width, height  , BACKGROUND_BLACK);
    printWithColor("   []]   [[]   []]  []]   []]  [[]   []]   []   []]       \n", width, height + 1, BACKGROUND_BLACK);
    printWithColor("   []]   []]   []][]][]  []][][][]]  []]   []   []]       \n", width, height + 2, BACKGROUND_BLACK);
    printWithColor("   []]   [[]   []] ]]    []]    [[]  []]   []   [[]       \n", width, height + 3, BACKGROUND_BLACK);
    printWithColor("   [][][][]    [[]  ]]   []]    [[]  [][][][[[][]]]       \n", width, height + 4, BACKGROUND_BLACK);

}

int menu() { 
	int pilih_menu, i = 22;
	judul();
	printWithColor(" [][][][][][][][][][][][][][][][][][][][][][][]\n", i, 18, BACKGROUND_BLUE);
   	printWithColor(" []                 MAIN MENU                []\n", i, 19, BACKGROUND_BLUE);
   	printWithColor(" []                                          []\n", i, 20, BACKGROUND_BLUE);
   	printWithColor(" []   (1) PLAY NOW !                         []\n", i, 21, BACKGROUND_BLUE);
   	printWithColor(" []   (2) INSTRUCTIONS                       []\n", i, 22, BACKGROUND_BLUE);
   	printWithColor(" []   (3) THE CREATOR                        []\n", i, 23, BACKGROUND_BLUE);
   	printWithColor(" []   (0) Exit                               []\n", i, 24, BACKGROUND_BLUE);
   	printWithColor(" []                                          []\n", i, 25, BACKGROUND_BLUE);
   	printWithColor(" []   CHOOSE :                               []\n", i, 26, BACKGROUND_BLUE);
   	printWithColor(" []                                          []\n", i, 27, BACKGROUND_BLUE);
   	printWithColor(" [][][][][][][][][][][][][][][][][][][][][][][]\n", i, 28, BACKGROUND_BLUE);
	gotoxy(37,26);
    scanf("%d",&pilih_menu);
   	return pilih_menu;
}

void instructions(){
    system("cls");
    int i = 22, height = 2;
	printWithColor(" [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n", i, height+1, BACKGROUND_BLUE);
   	printWithColor(" []                          INSTRUCTIONS                            []\n", i, height+2, BACKGROUND_BLUE);
   	printWithColor(" []                                                                  []\n", i, height+3, BACKGROUND_BLUE);
   	printWithColor(" []   (1) GAME SETUP                                                 []\n", i, height+4, BACKGROUND_BLUE);
   	printWithColor(" []       - TicTacToe is Played on 3x3 - 8x8 grid                    []\n", i, height+5, BACKGROUND_BLUE);
   	printWithColor(" []       - There is 2 Player, one uses 'X' and other uses 'O'       []\n", i, height+6, BACKGROUND_BLUE);
   	printWithColor(" []                                                                  []\n", i, height+7, BACKGROUND_BLUE);
   	printWithColor(" []   (2) TAKING TURNS                                               []\n", i, height+8, BACKGROUND_BLUE);
   	printWithColor(" []       - Players take turns placing their marks (X or O)          []\n", i, height+9, BACKGROUND_BLUE);
   	printWithColor(" []         in an empty square                                       []\n", i, height+10, BACKGROUND_BLUE);
   	printWithColor(" []       - Player 1 which uses 'X' always goes first                []\n", i, height+11, BACKGROUND_BLUE);
   	printWithColor(" []                                                                  []\n", i, height+12, BACKGROUND_BLUE);
   	printWithColor(" []   (3) WINNING GAMES                                              []\n", i, height+13, BACKGROUND_BLUE);
   	printWithColor(" []       - A player wins by getting 'some' marks in a row           []\n", i, height+14, BACKGROUND_BLUE);
   	printWithColor(" []         >> 3x3 grid            = 3 marks in a row                []\n", i, height+15, BACKGROUND_BLUE);
   	printWithColor(" []         >> 4x4 & 5x5 grid      = 4 marks in a row                []\n", i, height+16, BACKGROUND_BLUE);
   	printWithColor(" []         >> 6x6, 7x7 & 8x8 grid = 5 marks in a row                []\n", i, height+17, BACKGROUND_BLUE);
   	printWithColor(" []       - The row can be horizontal, vertical, or diagonal         []\n", i, height+18, BACKGROUND_BLUE);
   	printWithColor(" []                                                                  []\n", i, height+19, BACKGROUND_BLUE);
   	printWithColor(" []   (4) ENDING GAMES                                               []\n", i, height+20, BACKGROUND_BLUE);
   	printWithColor(" []       - The game ends if one of the players wins or              []\n", i, height+21, BACKGROUND_BLUE);
   	printWithColor(" []         all the boxes are filled which is considered a draw      []\n", i, height+22, BACKGROUND_BLUE);
   	printWithColor(" []                                                                  []\n", i, height+23, BACKGROUND_BLUE);
   	printWithColor(" []                      Press Enter to Back                         []\n", i, height+24, BACKGROUND_BLUE);
   	printWithColor(" []                                                                  []\n", i, height+25, BACKGROUND_BLUE);
   	printWithColor(" [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n", i, height+26, BACKGROUND_BLUE);
	gotoxy(67,height+24);
    cin.ignore();
    cin.get();
}

void creator(){
    int i = 22, height = 2;
	printWithColor(" [][][][][][][][][][][][][][][][][][][][][][][][][][]\n", i, height+1, BACKGROUND_BLUE);
   	printWithColor(" []                    CREATORS                    []\n", i, height+2, BACKGROUND_BLUE);
   	printWithColor(" []                                                []\n", i, height+3, BACKGROUND_BLUE);
   	printWithColor(" []             This Game Created By:              []\n", i, height+4, BACKGROUND_BLUE);
   	printWithColor(" []          AFRIZA MU'AMMAR || 231511066          []\n", i, height+5, BACKGROUND_BLUE);
   	printWithColor(" []          RIFQI IRFANSYAH || 231511089          []\n", i, height+6, BACKGROUND_BLUE);
   	printWithColor(" []                                                []\n", i, height+7, BACKGROUND_BLUE);
   	printWithColor(" []                  1C-JTK 2024                   []\n", i, height+8, BACKGROUND_BLUE);
   	printWithColor(" []                                                []\n", i, height+9, BACKGROUND_BLUE);
   	printWithColor(" []              Press Enter to Back               []\n", i, height+10, BACKGROUND_BLUE);
   	printWithColor(" []                                                []\n", i, height+11, BACKGROUND_BLUE);
   	printWithColor(" [][][][][][][][][][][][][][][][][][][][][][][][][][]\n", i, height+12, BACKGROUND_BLUE);
	gotoxy(i+36,height+10);
    cin.ignore();
    cin.get();
}

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
    setColor(BACKGROUND_LIGHTBLUE|FOREGROUND_BLACK);
    printWithColor("\n\t" , 0, 0, BACKGROUND_BLUE);

    for(int i=1; i<=size_board; i++){
        printWithColor("[][][][]" , 0, 0, BACKGROUND_BLUE);
    }
    printWithColor ("[][][][][][][]" , 0, 0, BACKGROUND_BLUE);

    for(int j=1; j<=3; j++){
        printWithColor("\n\t[]" , 0, 0, BACKGROUND_BLUE);
        for(int i=1; i<=size_board; i++){
            printWithColor ("        " , 0, 0, BACKGROUND_BLUE);
        }
        printWithColor("          []" , 0, 0, BACKGROUND_BLUE);
    }


    printWithColor ("\n\t[]__________" , 0, 0, BACKGROUND_BLUE);
    for(int i=1; i<=size_board; i++){
        printWithColor("________" , 0, 0, BACKGROUND_BLUE);
    }
    printWithColor ("[]" , 0, 0, BACKGROUND_BLUE);

    printWithColor("\n\t[]    " , 0, 0, BACKGROUND_BLUE);

    for(int i=1; i<=size_board; i++){
        printWithColor ("--------" , 0, 0, BACKGROUND_BLUE);
    }
    printWithColor ("-     []" , 0, 0, BACKGROUND_BLUE);

    address temp = Head;
    address temp_start;
    
    for(int i=1; i<=size_board; i++){
        temp_start = temp;
        printWithColor("\n\t[]    " , 0, 0, BACKGROUND_BLUE);
        for (int j=1; j<= size_board; j++){
            printWithColor ("|       " , 0, 0, BACKGROUND_BLUE);
        }
        printWithColor ("|     []\n\t[]    " , 0, 0, BACKGROUND_BLUE);

    
        for (int j=1; j<= size_board; j++){
            if (temp -> info == 0){
                printWithColor ("|" , 0, 0, BACKGROUND_BLUE);
                setColor(BACKGROUND_LIGHTBLUE|WHITE);
                cout <<"   O   ";
            }
            else if (temp -> info == -1){
                printWithColor ("|" , 0, 0, BACKGROUND_BLUE);
                setColor(BACKGROUND_LIGHTBLUE|FOREGROUND_RED);
                cout <<"   X   ";
            }
            else if (temp->info <= 9){
                printWithColor ("|",0,0,BACKGROUND_BLUE);
                printf("   %d   ", temp -> info);
            }
            else{
                printWithColor ("|",0,0,BACKGROUND_BLUE);
                printf("   %d  ", temp -> info);
            }
            temp = temp->next;
        }

        printWithColor ("|     []\n\t[]    " , 0, 0, BACKGROUND_BLUE);
        for (int j=1; j<= size_board; j++){
            printWithColor ("|       " , 0, 0, BACKGROUND_BLUE);
        }
        printWithColor ("|     []\n\t[]    " , 0, 0, BACKGROUND_BLUE);

        for(int i=1; i<=size_board; i++){
            printWithColor ("--------" , 0, 0, BACKGROUND_BLUE);
        }
        printWithColor ("-     []" , 0, 0, BACKGROUND_BLUE);


        temp = temp_start->down;
    }

    printWithColor ("\n\t[][][][][][][]" , 0, 0, BACKGROUND_BLUE);
    for(int i=1; i<=size_board; i++){
        printWithColor("[][][][]" , 0, 0, BACKGROUND_BLUE);
    }

    for(int j=1; j<=2; j++){
        printWithColor("\n\t[]" , 0, 0, BACKGROUND_BLUE);
        for(int i=1; i<=size_board; i++){
            printWithColor ("        " , 0, 0, BACKGROUND_BLUE);
        }
        printWithColor("          []" , 0, 0, BACKGROUND_BLUE);
    }

    printWithColor ("\n\t[][][][][][][]" , 0, 0, BACKGROUND_BLUE);
    for(int i=1; i<=size_board; i++){
        printWithColor("[][][][]" , 0, 0, BACKGROUND_BLUE);
    }

    showChoosen(Head, size_board);
}

void showChoosen(address Head, int size_board){
    address temp = Head;
    address temp_start;
    for(int i=1; i<=size_board; i++){
        temp_start = temp;
        for (int j=1; j<= size_board; j++){
            if (temp -> info == 0){
                int x = 15 + 8*j - 8;
                int y = 7 + 4*i - 4;
                printWithColor(" []][] ", x, y, BACKGROUND_WHITE );
                printWithColor(" [] [] ", x, y+1, BACKGROUND_WHITE );
                printWithColor(" []][] ", x, y+2, BACKGROUND_WHITE );

                setColor(BACKGROUND_LIGHTBLUE|WHITE);
            }
            else if (temp -> info == -1){
                int x = 15 + 8*j - 8;
                int y = 7 + 4*i - 4;
                printWithColor(" []  []", x, y, BACKGROUND_RED );
                printWithColor("   []", x, y+1, BACKGROUND_RED );
                printWithColor(" []  []", x, y+2, BACKGROUND_RED );

                setColor(BACKGROUND_LIGHTBLUE|WHITE);
            }
            temp = temp->next;
        }
        temp = temp_start->down;
    }
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

void saveRecords(const char* filename, address head, int size_board, int giliran, char player1[50], char player2[50]) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    outFile.write(reinterpret_cast<char*>(&size_board), sizeof(int));
    outFile.write(reinterpret_cast<char*>(&giliran), sizeof(int));
    outFile.write(reinterpret_cast<char*>(player1), sizeof(char[50]));
    outFile.write(reinterpret_cast<char*>(player2), sizeof(char[50]));

    
    address temp = head;
    address temp_start;
    for(int i=1; i<=size_board; i++){
        temp_start = temp;
        for (int j=1; j<= size_board; j++){
            outFile.write(reinterpret_cast<char*>(&temp->info), sizeof(int));
            temp = temp->next;
        }
        temp = temp_start->down;
    }
    outFile.close();
}

int readRecords(const char* filename, address& head, int& giliran, char (&player1)[50], char (&player2)[50]) {
    int size_board;
    ifstream inFile(filename, ios::binary);
    head = NULL;
    if (!inFile) {
        return 0;
    }

    inFile.read(reinterpret_cast<char*>(&size_board), sizeof(int));
    inFile.read(reinterpret_cast<char*>(&giliran), sizeof(int));
    inFile.read(reinterpret_cast<char*>(&player1), sizeof(char[50]));
    inFile.read(reinterpret_cast<char*>(&player2), sizeof(char[50]));

    address rowStart = NULL;
    address upNode = NULL;
    address temp_last = NULL;


    for(int i=1; i<=size_board; i++){

        for(int i=1; i<=size_board; i++){
            address newNode = (address) malloc(sizeof (tElmtlist));

            if (newNode == NULL){
                printf("Memori Full");
            }
            else{
                inFile.read(reinterpret_cast<char*>(&newNode->info), sizeof(int));
                
                newNode -> next = NULL;
                newNode -> prev = NULL;
                newNode -> up   = NULL;
                newNode -> down = NULL;
            }

            if (head == NULL){
                head = newNode;
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
    inFile.close();
    return size_board;

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

bool gameplay(address Head, int size_board, int &giliran, char* player1, char* player2){
    address search;
    char giliran_player[50];
    int info_simbol, quit;
    bool win = false;
    bool loop = true;

    setColor(BACKGROUND_LIGHTBLUE|FOREGROUND_BLACK);
    gotoxy((size_board-2)*8+ 19,2);
    if (size_board == 3){
        cout << " 3 STREAK TO WIN ";                
    }
    else if(size_board == 4 || size_board == 5){
        cout << " 4 STREAK TO WIN ";
    }
    else{
        cout << " 5 STREAK TO WIN ";
    }

    gotoxy((size_board-2)*8+ 12,3);
    cout << "Press -1 to Instructions";
    gotoxy((size_board-2)*8+ 21,4);
    cout << "Press 0 to Exit";

    int height = (size_board * 4) + 8;
    gotoxy(11, height);
    
    if(giliran == 0){
        setColor(BACKGROUND_RED|FOREGROUND_BLACK);
        strcpy(giliran_player, player1);
        cout << giliran_player ;
    }
    else{
        setColor(BACKGROUND_WHITE|FOREGROUND_BLACK);
        strcpy(giliran_player, player2);
        cout << giliran_player ;
    }

    gotoxy(11, height+1);
    setColor(BACKGROUND_LIGHTBLUE|FOREGROUND_BLACK);
    cout << "Insert The Number = ";
    cin >> info_simbol;
    
    if (info_simbol == 0){
        cout << "\n\n\t Want to Quit? Game will be saved  ";
        cout << "\n\t 1. yes";
        cout << "\n\t 2. no";
        cout << "\n\t Choose = ";
        cin >> quit;

        if (quit == 1){
            saveRecords("game_records.dat", Head, size_board, giliran, player1, player2);
            loop = false;
        }
    }
    else if (info_simbol == -1){
        instructions();
    }
    else{
        search = searchingNode(Head, info_simbol);

        if (search == nullptr){
            setColor(WHITE|BACKGROUND_RED);
            cout << "\n\n\t !! Sorry, Dosen't exist the number " << info_simbol << " , Press Enter to Insert Again !! ";
            cin.ignore();
            cin.get();
            setColor(BACKGROUND_LIGHTBLUE|FOREGROUND_BLACK);
        }
        else{
            if (giliran == 0){
                giliran = -1;
            }
            else {
                giliran = 0;
            }

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
            loop = checkEmptyBoard(Head);
            if(!loop){
                system("cls");
                showBoard(Head, size_board);
                draw(size_board);
                cin.ignore();
                cin.get();
                removeFile();
            }
        }
        else{
            system("cls");
            showBoard(Head, size_board);
            winner(giliran_player, size_board);
            cin.ignore();
            cin.get();
            removeFile();
            loop = false;
        }
    }
    return loop;
}

void removeFile() {
    remove("game_records.dat");
}

void deleteBoard(address Head){
    address rowStart = Head;
    address node = rowStart;
    address temp;

    // loop down
    while(rowStart != NULL){
        // loop right
        node = rowStart;
        while(node != NULL){
            temp = node;
            node = node->next;
            free(temp);
        }
        rowStart = rowStart->down;
    }
}