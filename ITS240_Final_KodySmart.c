/*Kody Smart
ITS24000 Spring 2023
Final Project
5/2/23
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <ctype.h>

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
    FILE *inFile, *outFile;
    char priceIn[100], strDate[10], strChar[2];
    int commaPosition, i, j, dateCounter=0, messageLength;
    float currentSales=0, salesTotal=0, maxSales=0, minSales=9999999999;

    inFile = fopen("itemPricing.txt", "r");
    outFile = fopen("Transaction Report.txt", "a");

    while(fgets(priceIn, 99, inFile) != NULL)
    {
        printf("\nLine read from file:%s", priceIn);
        messageLength = strlen(priceIn)-2;

        //printf("\nmessageLength is : %d", messageLength);

        for(i=0; i<messageLength; i++)
        {
            if(priceIn[i] == ',')
                commaPosition = i;
        }

        //printf("\nComma is in position %d", commaPosition);

        for(j=commaPosition+1; j<messageLength; j++)
        {
            strChar[0] = priceIn[j];
            strChar[1]= '\0';
            strcat(strDate, strChar);
            //printf("\ncharacter is now %c", priceIn[j]);
        }
        currentSales = atof(strDate);

        if( currentSales > maxSales)
            maxSales = currentSales;
        if( currentSales < minSales)
            minSales = currentSales;

        salesTotal += currentSales;//sum up all the sales
        dateCounter++;//count the day processed

        printf("\nPrice is: %.2f", currentSales);
        printf("\n--------------------------\n\n");
        strcpy(strDate, "");//resets strDate back to an empty string
    }//end while()
      
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
