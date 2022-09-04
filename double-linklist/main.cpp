#include <iostream>

using namespace std;

struct Book
  {
    string author, title;
    Book *next;
    Book *prev;
  };
  
  Book *head, *tail, *cur, *Newnode, *del, *afterNode;

  int countDoubleLinkedList()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cur = head;
    int jumlah = 0;
    while( cur != NULL ){
      jumlah++;      
      //step
      cur = cur->next;
    }
    return jumlah;
  }
}

  void insert(string test[2]){
    head = new Book();
    head->author = test[0];
    head->title = test[1];
    head->next = NULL;
    head->prev = NULL;
    tail =head;
  }

  void Addfirst( string data[2] ){
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    Newnode = new Book();
    Newnode->author = data[0];
    Newnode->title = data[1];
    Newnode->prev = NULL;
    Newnode->next = head;
    head->prev = Newnode;
    head = Newnode;
  }
}

  void Addlast(string test[2]){
    Newnode = new Book();
    Newnode->author = test[0];
    Newnode->title = test[1];
    Newnode->prev = tail;
    Newnode->next = NULL;
    tail->next = Newnode;
    tail = Newnode;
  }

    void Addmiddle(string test[2], int target){
      Newnode = new Book;
      Newnode->author = test[0];
      Newnode->title = test[1];

      cur = head;
      int nomor = 1;
      while(nomor<target-1){
        cur = cur->next;
        nomor++;
      }
      afterNode = cur->next;
      Newnode->prev = cur;
      Newnode->next = afterNode;
      afterNode->prev = Newnode;
      cur->next = Newnode;
    }

  void removefirst(){
    del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
  }

  void removelast(){
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
  }

  void removeMiddle(int target){
    cur = head;
    int nomor =1;
    while(nomor < target-1){
      cur=cur->next;
      nomor++;
    }
    del = cur->next;
    afterNode = del->next;
    afterNode->prev = cur;
    cur->next = afterNode;
    delete del;
  }

  void Printnode(){
    cout << countDoubleLinkedList() << endl;
    cur = head;
    while(cur != NULL){
      cout << cur->author << endl;
      cout << cur->title << endl;
      cout << "\n";
      cur = cur->next;
    }
  }

int main(){
string test[2] = {"ucup", "test1"};
insert(test);
Printnode();
  
string test1[2] = {"rudi", "test2"};
Addfirst(test1);
Printnode();

string test2[2] = {"ruth" ,"test3"};
Addlast(test2);
Printnode();


// removefirst();
// Printnode();

// removelast();
// Printnode();

string test3[2] ={"bobi", "utopia"};
Addmiddle(test3,2);
Printnode();

//removeMiddle(2);
//Printnode();

return 0;
}