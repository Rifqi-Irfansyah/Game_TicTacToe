#include "linked_list.h"
#include <iostream>
#include <fstream>
#include <string>

void addNodeFirst(address &awal, address &akhir, address &newNode, int nilai){
    newNode = (address) malloc(sizeof (tElmtlist));
    if (newNode == NULL){
        printf("Memori Full");
    }
    else{
        newNode -> info = nilai;
        newNode -> next = NULL;
    }
    
    if ((awal == NULL) && (akhir == NULL)){
        akhir = newNode;
    }
    else{
        newNode -> next = awal;
    }
    awal = newNode;
}

void addNodeLast(address &awal, address &akhir, address &newNode, int nilai){
    newNode = (address) malloc(sizeof (tElmtlist));
    if (newNode == NULL){
        printf("Memori Full");
    }
    else{
        newNode -> info = nilai;
        newNode -> next = NULL;
    }
    
    if ((awal == NULL) && (akhir == NULL)){
        awal = newNode;
    }
    else{
        akhir -> next = newNode;
    }
    akhir = newNode;
}

void addNodeMiddle(address &awal, address &newNode, int nilai){
    address node = awal;
    address node_1, node_2;
    int count = 0;

    while (node != NULL) {
        node = node->next;
        count++;
    }

    if (count < 2){
        printf("Maaf, Tidak dapat menambahkan node ditengah\nTotal node harus >= 2\n");
        exit(1);
    }
    else{
        newNode = (address) malloc(sizeof (tElmtlist));

        if (newNode == NULL){
            printf("Memori Full");
        }
        else{
            newNode -> info = nilai;
            newNode -> next = NULL;

            node = awal;
            int i = 1;
            while(i <= (count/2)){  //Searching middle node
                node_1 = node;
                node = node -> next;
                i++;
            }

            node_2 = node_1 -> next;
            node_1 -> next = NULL;
            node_1 -> next = newNode;
            newNode -> next = node_2;
        }
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
    address node = awal;
    int i = 1;
    while (node -> next != NULL){
        node = node -> next;
        i++;
    }
    return i;
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

address searchingNode(address awal, int nilai){
    address result = NULL;
    if (awal != NULL){
        address node = awal;
        int count = countNode(awal);
        for (int i=1; i <= count; i++){
            if (node -> info == nilai){
                result = node;
                break;
            }
            node = node -> next;
        }
    }
    return result;
}