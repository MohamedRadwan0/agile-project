#include "adminpage.h"

<<<<<<< HEAD
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


=======
void Make_transaction(int senderid,List *accounts){
    float money=10;

    printf("Enter the amount you want to transfer: \n");
    scanf("%f",&money);
    int rId;
    printf("inter receiver id:\n");
    scanf(" %d", &rId);
    listNode *senderPointer = search_acc(senderid,accounts);
    listNode *resiverPointer = search_acc(rId,accounts);
    if (senderPointer->entry.status ==0 && resiverPointer->entry.status ==0){
        if (senderPointer->entry.balance < money){
            printf("Sorry, you don't have enough money to send \n The transaction is cancelled");
        }

        else{
            senderPointer->entry.balance -= money;
            printf("Your new balance is: %f", senderPointer->entry.balance);
            resiverPointer->entry.balance +=money;
            //add to list of transactions
        }

        printf("\n\n");
    }
    else{
        printf("Sorry, your account is not active");
    }
}

void cahnge_account_status( listNode *node_pointer){
    printf("Enter the new status of your account: ");
    printf("\n1. Active");
    printf("\n2. Restricted status");
    printf("\n3. Closed");
    int status;
    scanf("%d", &status);
    if (status ==1 || status ==2 ||status ==3 ){
        node_pointer->entry.status = status;
    }
    if (status == 1){
        printf("Your account is now active");

    }
    else if (status == 2){
        printf("Your account is now restricted");
    }
    else if (status == 3){
        printf("Your account is now closed");
    }
    else{
        printf("Invalid input");
    }
>>>>>>> 870a95dcf381356df53a2a260f35856e42ef599c
}
void Get_cash(listNode *node_pointer)
{
    float money;
    printf("Enter the amount you want from this account:\n");
    scanf("%f", &money);
    printf("your balance is %f ",node_pointer->entry.balance );
    if ( node_pointer->entry.balance < money)
    {
        printf("Sorry, you don't have enough money in this account \n The transaction is cancelled");
    }
    else
    {
        node_pointer->entry.balance -= money;
        printf("The new balance is: %f", node_pointer->entry.balance);
    }
    printf("\n\n");

}
void Deposit(listNode *node_pointer)
{
    float money;
    printf("Enter the amount you want to deposit:\n");
    scanf("%f", &money);
    printf("done");
    node_pointer->entry.balance += money;

    printf("The new balance is: %f :  ", node_pointer->entry.balance);
    printf("\n\n");
}