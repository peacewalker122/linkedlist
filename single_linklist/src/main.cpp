#include <iostream>

using namespace std;
struct Book
{
    string author,title;
    Book *next;
};

Book *head, *newNode, *cur, *tail, *del, *before;

int Countnode(){
    cur = head;
    int jumlah = 0;
    while (cur != NULL)
    {
        cur = cur->next;
        jumlah++;
    }
    return jumlah;
}

void addNode(string test[2]){
    newNode = new Book;
    newNode->author = test[0];
    newNode->title = test[1];
    newNode->next = head;
    head = newNode;
}

void addLast(string test[2]){
    newNode = new Book;
    newNode->author = test[0];
    newNode->title = test[1];
    newNode->next = NULL;
    tail = newNode;
}

void addFirst(string test[2]){
    newNode = new Book;
    newNode->author = test[0];
    newNode->title = test[1];
    newNode->next = head;
    head = newNode;
}

void addMIddle(string test[2], int target){
    newNode = new Book;
    newNode->author = test[0];
    newNode->title = test[1];

    cur = head;
    int nomor = 1;
    while(nomor<target-1){
        cur = cur->next;
        nomor++;
    }
    newNode->next = cur->next;
    cur->next = newNode;
}

void deleteLast(){
    del = tail;
    cur = head;
    while(cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

void deleteFirst(){
    del = head;
    head = head->next;
    delete del;
}

void deleteMiddle(int target){
    cur = head;
    int nomor = 1;
    while(nomor <= target){
    if (nomor == target-1){
        before = cur;
    }
    if ( nomor == target){
        del = cur;
    }
        cur = cur->next;
        nomor++;
    }
    
    before->next = cur;
    delete del;
}

void printNode(){
    cout << Countnode() << endl;
    cur = head;
    while(cur != NULL){
        cout << cur->author <<  endl;
        cout << cur->title << endl;
        cout << endl;
        cur = cur->next;
    }
}

int main(){
    string test[2] ={"nofrian", "andai kau tahu"};
    addNode(test);
    printNode();

    string test1[2] ={"McTominay", "Divine of Wine"};
    addNode(test1);
    printNode();

    string test2[2] ={"Valentiona DeMatio", "fine of wine"};
    addFirst(test2);
    printNode();

    string test3[2] ={"Robby Mugebe", "Silk of lust"};
    addMIddle(test3,3);
    printNode();

    deleteMiddle(2);
    printNode();
}