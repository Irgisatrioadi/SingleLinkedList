#include<iostream>

using namespace std;

 struct singellinked{ //struct
    
    int Number;
    singellinked* next; 
};
singellinked *first, *last, *cur ,*add, *del,*addBf,*after;

//deklarasi node awal 
void buatlinkedlist (int Num){
    first = new singellinked;   
    first->Number = Num;
    first->next = NULL;
    last = first;
}
//insert awal
void Addfirst (int Num){
    add = new singellinked;
    add->Number = Num;
    add->next = first;
    first = add;
} 
//insert akhir
void Addlast (int Num){
    add = new singellinked;
    add->Number= Num;
    add->next = NULL;
    last->next = add;
}
//insert before
void Addmiddle(int Num){
    addBf = new singellinked;
    addBf->Number = Num;

    cur = first;
    Num = 1 ;
    while (Num < -1 ){
        cur = cur->next;
        Num++;       
    }
    addBf->next = cur->next;
    cur->next = addBf;   
}
//delete awal
void dellFirst (){
    del = first;
    first = first->next;
    delete del;   
}
//delete akhir
void dellLast (){ 
    singellinked* second_last = first;
    while (second_last->next->next != NULL){
        second_last = second_last->next;  
    }    
    delete (second_last->next);
    second_last->next = NULL;
}
//delete tengah
void delMiddle(int poss){
 int nomor = 1;
    cur = first;
    while( nomor <= poss ){
      if( nomor == poss-1 ){
        after = cur;
      }
      if( nomor == poss ){
        del = cur;
      }
      cur = cur->next;
      nomor++;
    }
    after->next = cur;
    delete del;
  }
//search sequential
int searchNumber(int key){
    singellinked* p = first;
    int i = 1;
    while (p->Number != key){
        p = p->next;
        i++;
    }
    return i;
}
//print data
void printlikedlist(){ 
    cur = first;
    while (cur != NULL){
        cout << cur-> Number << " ";
        cur = cur->next;
    }
    cout<<endl;
}

int main(){
    buatlinkedlist(2); //deklarasi node awal
    printlikedlist(); //print
   
    Addfirst(4); //insert first
    printlikedlist();//print

    Addfirst(8);//insert first
    printlikedlist();
    
    Addmiddle(5);//insert before
    printlikedlist();//print

    Addmiddle(9);//insert before
    printlikedlist();//print

    Addlast(7);//insert last
    printlikedlist();//print

    dellFirst();//delete fisrt
    printlikedlist();//print

    dellLast();//delete last
    printlikedlist();//print

    delMiddle(2);//delete after
    printlikedlist();//print

    int key = 4; //key search
    cout<<"data " << key << " di urutan ke- "<< searchNumber(key); //search
}   