/*Kody Smart
ITS24000 Spring 2023
Final Project
5/2/23
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Order
{
    double totalCost;
    double discount;
    double subtotal;
    double tax;
    double total;
};

void printReceipt();

int main()
{
      
    return 0;
}

void printReceipt(struct Order receipt)
{
    printf("Total item costs: $%8.2f\n", receipt.totalCost);
    printf("Discount:         $%8.2f\n", receipt.discount);
    printf("Tax:              $%8.2f\n", receipt.tax);
    printf("Subtotal:         $%8.2f\n", receipt.subtotal);
    printf("Total:            $%8.2f\n", receipt.total);
}//end of printReceipt()
