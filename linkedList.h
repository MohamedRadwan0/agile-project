#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
typedef struct Account {
    int ssid;
    char *name;
    int age;
    char *address;
    int accountid;
    char *guardian;
    char *gid;
    int status;
    float balance;
    int password;

}Account;

typedef Account ListEntry;


typedef struct listnode{

    ListEntry entry;
    struct listnode *next;

}listNode ;

typedef struct list{

    listNode *top;
    int size;
}List;

void creatList (List *);
int listEmpty(List *);
int listFull(List *);
int listSize (List *);
void destroyList(List *);
void insertList (int,ListEntry,List *);
void deletList (int,ListEntry *,List *);
void traverseList (List * ,void (*pf)(ListEntry));
void retrieveList(int,ListEntry *,List *);
void replaceList(int,ListEntry,List *);
void joinList(List *, List *);
listNode *search_acc(int id,List *pl);
#endif // LINKEDLIST_H_INCLUDED
