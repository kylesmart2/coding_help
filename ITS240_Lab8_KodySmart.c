/*Kody Smart
ITS24000 Spring 2023
Chapter 8 Lab
3/20/23
*/

#include <stdio.h>
#define taxRate 0.07

void welcome();
void showMenu();
int getSelect();    
void showItem(int);
float threeItems(int count, float item1, float item2, float item3, float *discount);
float compareItems(float item1, float item2);
void receipt(float *, int);
float getPrice(int);  // function to get price and return its value  
float * inputPrice(int, int *); // function to put numbers in an array

int main()
{
    float *prices; // pointer to retain values of array from inputPrice function  
    static int count = 0; // counter variable for getSelect function
    int item, end = 9;
    
    welcome();
    showMenu();

    do 
    {
        item = getSelect();
        inputPrice(item, &count);
        count++;
        
        if(item == 11)
        {
            count -= 1;
        }

        printf("\nYou have selected %d items.", count);
        
    } while (item != 11);

    prices = inputPrice(0,&end);
    
    receipt(prices, count);

    return 0;
}

void welcome()
{
    printf("Hello!\n\n");
    printf("Welcome to Kody's Reptile Store!\n");
    int month = 1;
    int day = 22;
    int year = 2023;
    printf("\nDate created: %d-%d-%d\n\n", month, day, year);
    
    return;
}//end of welcome()

void showMenu()
{
    printf("********************************");
    printf("\n***Menu of Supplies/Animals:***");
    printf("\n1 - Bedding              $16.99");
    printf("\n2 - Starter Cage        $199.99");
    printf("\n3 - 40-Gallon Terrarium  $99.99");
    printf("\n4 - Baby Gecko           $49.99");
    printf("\n5 - Juvenile Gecko       $69.99");
    printf("\n6 - Adult Gecko          $99.99");
    printf("\n7 - Baby Beardie         $75.00");
    printf("\n8 - Adult Beardie       $150.00");
    printf("\n9 - Heat Lamp            $39.99");
    printf("\n10 - PWM Thermostat     $149.99");
    printf("\n11 - Checkout/Leave     -------");
    printf("\n*******************************");
        
    return;
}//end of showMenu()

int getSelect()
{
    int itemSelect = 0;
    static int count = 0;
    
    
    printf("\nPlease make your selection: ");
    scanf("%d", &itemSelect);
    if(itemSelect > 0 && itemSelect < 12)
    {
        count++;
        showItem(itemSelect);
        //printf("After showItem\n");
        if (itemSelect != 11)
        {
            switch (count)
            {
                case 1:
                    printf("\nYou're eligible for our BOGO half-off sale! ");
                    break;
                case 2:
                    printf("\nYou're eligible for our B2GO free promotion! Add another item on us!");
                    break;
                case 3:
                    printf("\nYou're awesome! We appreciate you business!");
                    break;
                case 4: 
                    printf("\nI bet you won't add another item to your cart...");
                    break;
                case 5: 
                    printf("\nYou get 25 percent off!");
                    break;
                default:
                    break;
            }// end of switch
        }

        return itemSelect;
    }
    else{
        count--;
        getSelect();
    }
    
}//end of getSelect()


void showItem(int x)
{
    switch( x)
    {
        case 1:
            printf("\nYou selected bedding for $16.99!\n");
        break;
        case 2:
            printf("\nYou selected a starter cage for $199.99!\n");
        break;
        case 3:
            printf("\nYou selected a 40-gallon terrarium for $99.99!\n");
        break;
        case 4:
            printf("\nYou selected a baby gecko for $49.99!\n");
        break;
        case 5: 
            printf("\nYou selected a juvenile gecko for $69.99!\n");
        break;
        case 6: 
            printf("\nYou selected an adult gecko for $99.99!\n");
        break;
        case 7:
            printf("\nYou selected a baby beardie for $75.00!\n");
        break;
        case 8:
            printf("\nYou selected an adult beardie for $150.00!\n");
        break;
        case 9: 
            printf("\nYou selected a heat lamp for $39.99!\n");
        break;
        case 10:
            printf("\nYou selected a PWM thermostat for $149.99!\n");
        break;
        case 11:
            printf("You selected to checkout.");
        break;
        default:
            printf("\nYou made an invalid selection!\n");
        break;
    }
}//end of showItem()

float threeItems(int count, float item1, float item2, float item3, float *discount)
{
    int numItems = count;
    float price1 = item1;
    float price2 = item2;
    float price3 = item3;
    float temp = 0;
    

    if(price1 < price2)
    {
        temp = price1;
    }
    else
    {
        temp = price2;
    }
    if( temp < price3)
    {
        *discount = temp;
    }
    else
    {
        *discount = price3;
    }
    
    return *discount;
}

float compareItems(float item1, float item2)
{
    float price1 = item1;
    float price2 = item2;
    
    if (price1 > price2)
    {
        return price2/2;
    }
    else
        return price1/2;
}//end of compareItems()

void receipt(float prices[10], int count)
{
    //float taxRate = 0.07;
    float total = 0;
    float subtotal = 0;
    float discount = 0;
    float tempDiscount = 0;

    for(int i = 0;i < 10; i++)
    {
        total += prices[i];
    }
    //printf("The total is: %.2f", total);

    if(count == 2)
    {
        discount = compareItems(prices[0], prices[1]);
        subtotal = total - discount;
    }
    
    if(count == 3)
    {
        discount = threeItems(count, prices[0], prices[1], prices[2], &discount);
        subtotal = total - discount;
    }

    // if(count == 3)
    // {
    //     prices[2] = 0.00;
    //     for(int i = 0; i < 10; i++)
    //     {
    //         subtotal += prices[i];
    //     }
    //     discount = total - subtotal;
    // }

    if(count == 5)
    {
        discount = total * .25;
        subtotal = total - discount;
    }
    
    float discountedSubtotal = total - discount;
    float taxes = discountedSubtotal * taxRate;
    float grandTotal = discountedSubtotal + taxes;
    printf("\nSubtotal:    $%.2f\n", total);
    printf("Discount:    $%.2f\n", discount);
    printf("Taxes:       $%.2f\n", taxes);
    printf("Grand Total: $%.2f\n", grandTotal);
    
    return;
    
}

float getPrice(int itemSelect)
{
    float items[10] = {16.99, 199.99, 99.99, 49.99, 69.99, 99.99, 75.00, 150.00, 39.99, 149.99};

    float price = items[itemSelect-1];
    
    return price;
}

float * inputPrice(int itemSelect, int *value)
{
    static float prices[10];
    prices[*value] = getPrice(itemSelect);
    //printf("\nInside inputPrice\n");

   /*for (int i = 0; i < 10; i++)
    {
        printf("\nPrices[%d]: %.2f", i, prices[i]);
    }*/

    return prices;
}

