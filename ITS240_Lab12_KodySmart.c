/*Kody Smart
ITS24000 Spring 2023
Chapter 12 Lab
4/16/23
*/

#include <stdio.h>
#define TAXRATE 0.07

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
    struct Order ORDER;
    struct Order shit;

    ORDER.totalCost = 789.23;
    ORDER.discount = (ORDER.totalCost * 0.15);
    ORDER.subtotal = (ORDER.totalCost - ORDER.discount);
    ORDER.tax = (ORDER.subtotal * TAXRATE);
    ORDER.total = (ORDER.subtotal + ORDER.tax);
    
    printReceipt(ORDER);
    
    shit.totalCost = 59237.23;
    shit.discount = (shit.totalCost * 0.15);
    shit.subtotal = (shit.totalCost - shit.discount);
    shit.tax = (shit.subtotal * TAXRATE);
    shit.total = (shit.subtotal + shit.tax);
    
    //printReceipt(shit);

    return 0;
}//end of main()

void printReceipt(struct Order receipt)
{
    printf("Total item costs: $%8.2f\n", receipt.totalCost);
    printf("Discount:         $%8.2f\n", receipt.discount);
    printf("Tax:              $%8.2f\n", receipt.tax);
    printf("Subtotal:         $%8.2f\n", receipt.subtotal);
    printf("Total:            $%8.2f\n", receipt.total);
}//end of printReceipt()