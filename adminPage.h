#ifndef ADMINPAGE_H_INCLUDED
#define ADMINPAGE_H_INCLUDED
void account_creation(char *name,int age,char *address,int accountid,int status,


void Make_transaction(int senderid,List *accounts);
void cahnge_account_status( listNode *node_pointer);
void Get_cash(listNode *node_pointer);
void Deposit(listNode *node_pointer);
#endif // ADMINPAGE_H_INCLUDED
