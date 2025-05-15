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

    void transverse(){
        if(START == NULL){
            cout << "\nList is empty" << endl;
            return;
        }
        Node *currentNode = START;
        cout << "\nRecord in ascending order of roll number : \n";
        int i = 0;
        while(currentNode !=NULL){
            cout << i+1 << ". " << currentNode->noMhs << "" << endl;

        currentNode = currentNode->next;
            i++;
        }
       
    }

    void retraverse(){
        if(START == NULL){
            cout << "\nList is empty" << endl;
            return;
        }
        Node *currentNode = START;
        int i = 0;
        while(currentNode->next != NULL){
            currentNode = currentNode->next;
            i++;
        }
        cout << "\nRecord in descending order of roll number : \n";
        while(currentNode != NULL){
            cout << i+1 << ". " << currentNode->noMhs << "" << endl;

            currentNode = currentNode->prev;
            i--;
        }
    }

    void searchData(){
        if(START == NULL){
            cout << "\nList is empty" << endl;
            return;
        }
        int rollNO;
        cout << "\nEnter the roll number to search : ";
        cin >> rollNO;

        Node *current = START;

        while(current != NULL && current->noMhs != rollNO){
            current = current->next;
        }

        if(current == NULL){
            cout << "Record not found" << endl;;
        }
        else{
            cout << "\nRecord found" << endl;
            cout << "Roll number : " << current->noMhs << endl;
        }
        
    }
};

int main(){
    Doublelinkedlist list;
    int choice;
    do{
        cout << "\nMenu\n";
        cout << "1. Add record\n";
        cout << "2. Delete record\n";
        cout << "3. Display records in ascending order\n";
        cout << "4. Display records in descending order\n";
        cout << "5. Search record\n"; 
        cout << "6. Exit\n"; 
        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice){
            case 1:
                list.addNode();
                break;
            case 2:
                list.hapus();
                break;
            case 3:
                list.transverse();
                break;
            case 4:
                list.retraverse();
                break;
            case 5:
                list.searchData();
                break;
            case 6:
                return 0;
            default:
              cout << "Invalid option\n";
        }
        cout << "\nPress any key to continue...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
    }while(choice != 6);   
}