#include "adminpage.h"

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