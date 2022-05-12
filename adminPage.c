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

void open_exsisting_account(int account_id,List *accounts){

    int number ;

    listNode *node_pointer = search_acc(account_id,accounts);
    if (node_pointer != NULL){
        traverseList(accounts,display);
        printf("Choose of this features: ");
        printf("\n1. Make transaction");
        printf("\n2. Change account status");
        printf("\n3. Get cash");
        printf("\n4. Deposit in account");
        printf("\n5. Return to main menu");


        scanf("%d", &number);
        if (number == 1){

            Make_transaction(account_id,accounts);
        }

        else if (number == 2){
            cahnge_account_status(node_pointer);
        }

        else if (number == 3){
                printf("your balance is %f ",node_pointer->entry.balance );
            Get_cash(node_pointer);
        }

        else if (number == 4){
            Deposit(node_pointer);
        }

        else if (number == 5){
            int account_id ;
            scanf("%d", &account_id);
            open_exsisting_account(account_id,accounts);
        }
        else{
            printf("Invalid input");
        }


    }
    else{
        printf("The account ID is not correct");
    }
}