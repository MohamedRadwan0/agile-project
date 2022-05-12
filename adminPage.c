#include "adminpage.h"

void account_creation(char *name,int age,char *address,int accountid,int status,
                      float balance,List *l)
{

    Account account;
    account.name = name;
    account.age = age;
    account.address = address;
    account.accountid = accountid;
    account.status = status;
    account.balance = balance;
    insertList (0,account,l);


}