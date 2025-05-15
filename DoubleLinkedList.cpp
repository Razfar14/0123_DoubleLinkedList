#include <iostream>
using namespace std;


class Node{
    public :
    int noMhs;
    Node *next;
    Node *prev;
};

class Doublelinkedlist{
    private: 
    Node *START;

    public:
    Doublelinkedlist(){
        START = NULL;
    }

    void addNode(){
        int nim;
        cout << "\nEnter the roll number of the student : ";
        cin >> nim;

        Node *newNode = new Node();
        newNode->noMhs = nim;

        if(START == NULL || nim <= START->noMhs){
            if(START != NULL && nim == START->noMhs){
                cout << "\nDuplicate number not allowed";
                return;
            }
            newNode->next = START;

            if(START != NULL){
                START->prev = newNode;

                newNode->prev = NULL;
                START = newNode;
                return;
            }
        }
        Node *current = START;
        while(current->next != NULL && current->next->noMhs < nim){
            current = current->next;
        }

        if(current->next!= NULL && nim == current->next->noMhs){
            cout << "\nDuplicate roll number not allowed";
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if(current->next != NULL){
            current->next->prev = newNode;
        }
            current->next = newNode;
        
    }

    void hapus(){
        if(START == NULL){
            cout << "\nList is empty" << endl;
            return;
        }
        cout << "\nMasukan NIM yang ingin dihapus : ";
        int rollNO;
        cin >> rollNO;

        Node *current = START;

        while(current != NULL && current->noMhs != rollNO){
            current = current->next;
        }

        if(current == NULL){
            cout << "Record not found" << endl;
            return;
        }

        if(current == START){
            START = current->next;
            if(START != NULL){
                START->prev = NULL;
            }
        }
        else{
            current->prev->next = current->next;
            if(current->next != NULL){
                current->next->prev = current->prev;
            }
        }
        delete current;
        cout << "Record with roll number" << rollNO <<"deleted" << endl;
    }
};
