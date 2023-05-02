#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *inFile, *outFile;
    char messageIn[100], strDate[10], strChar[2];
    int commaPosition, i, j, dateCounter=0, messageLength;
    float currentSales=0, salesTotal=0, avgSales=0, maxSales=0, minSales=9999999999;

    inFile = fopen("daily_sales_2022.txt", "r");
    outFile = fopen("annual_report_2022.txt", "a");

    while(fgets(messageIn, 99, inFile) != NULL)
    {
        printf("\nLine read from file:%s", messageIn);
        messageLength = strlen(messageIn)-2;

        printf("\nmessageLength is : %d", messageLength);

        for(i=0; i<messageLength; i++)
        {
            if(messageIn[i] == ',')
                commaPosition = i;
        }

        printf("\nComma is in position %d", commaPosition);

        for(j=commaPosition+1; j<messageLength; j++)
        {
            strChar[0] = messageIn[j];
            strChar[1]= '\0';
            strcat(strDate, strChar);
            printf("\ncharacter is now %c", messageIn[j]);
        }
        currentSales = atof(strDate);

        if( currentSales > maxSales)
            maxSales = currentSales;
        if( currentSales < minSales)
            minSales = currentSales;

        salesTotal += currentSales;//sum up all the sales
        dateCounter++;//count the day processed

        printf("\nSales is: %.2f", currentSales);
        printf("\n--------------------------\n\n");
        strcpy(strDate, "");//resets strDate back to an empty string
    }//end while()


    if( outFile == NULL)
    {
        printf("\noutFile Could Not Be Opened.");
        exit(1);
    }
    if(dateCounter != 0)
        avgSales = salesTotal / dateCounter;
    else
        avgSales = 0;

    fprintf(outFile,"\nAnnual Report for 2022");
    fprintf(outFile,"\nDays processed: %d", dateCounter-1);
    fprintf(outFile,"\nTotal Annual Sales:   $%12.2f", salesTotal);
    fprintf(outFile,"\nAverage daily Sales:  $%12.2f", avgSales);

    fclose(inFile);
    fclose(outFile);

    return 0;
}
