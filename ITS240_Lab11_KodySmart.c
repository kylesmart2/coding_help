/*Kody Smart
ITS24000 Spring 2023
Chapter 11 Lab
4/16/23
*/



#include <stdio.h>

#define ARRAYSIZE 12

int main()
{
    float monthlySales[ARRAYSIZE] = {26543.01, 30254.91, 29584.86, 18254.23, 20852.25, 21753.15, 19179.30, 17213.88, 25871.44, 26841.97, 33528.77, 34796.51 };
    char * months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    float annualSales=0, maxMonthlySales=0, minMonthlySales=0, avgMonthlySales=0;
    int i, maxSalesIndex=0, minSalesIndex=0;
    float *ptrSales;
    
    ptrSales = &monthlySales[0];

    //declare a float pointer variable to store the address of the monthlySales[] array

    //assign the address of the first element in monthlySales to the pointer

    //these assignment statements use array notation, convert them to pointer notation using the pointer you declared
    maxMonthlySales = *ptrSales;
    minMonthlySales = *ptrSales;

    for(i=0; i < ARRAYSIZE; i++)
    {
        //this if() condition uses array notation, convert this to pointer notation using the pointer you declared
        if( *(ptrSales + i) < minMonthlySales)
        {
            //this assignment statement uses array notation, convert it to pointer notation using the pointer you declared
            minMonthlySales = *(ptrSales + i);
            minSalesIndex = i;
        }

        //this if() condition uses array notation, convert this to pointer notation using the pointer you declared
        if( *(ptrSales + i) > maxMonthlySales)
        {
            //this assignment statement uses array notation, convert it to pointer notation using the pointer you declared
            maxMonthlySales = *(ptrSales + i);
            maxSalesIndex = i;
        }
        //this calculation uses array notation, convert it to pointer notation using the pointer you declared
        annualSales = annualSales + *(ptrSales + i);
    }

    avgMonthlySales = annualSales / 12;
    
    printf("Total Annual Sales:    \t$%10.2f\n", annualSales);
    printf("Average Montly Sales:  \t$%10.2f\n", avgMonthlySales);
    printf("Highest Monthly Sales was: %s $%10.2f\n", *(months + maxSalesIndex), maxMonthlySales);
    printf("Lowest Monthly Sales was: %s $%10.2f\n", *(months + minSalesIndex), minMonthlySales);

    return 0;
}
