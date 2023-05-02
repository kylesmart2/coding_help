#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int alphaSpace(char*, int *);
int valAddress(char*, int *);
int valState(char*, int *);
int valDigits(char*, int *);

int main()
{
    char fname[MAX_SIZE], lname[MAX_SIZE], street[MAX_SIZE], city[MAX_SIZE], state[20], zip[20], phone[20];
    int valid = 0; 
    
    do {
        printf("Enter your first name: ");
        fgets(fname, sizeof(fname), stdin);
        fname[strcspn(fname, "\n")] = '\0';
        valid = alphaSpace(fname, &valid);
        if (!valid) 
        {
            printf("Invalid input, please only enter valid characters.\n");
        } else {
            printf("Valid entry.\n");
        }
    } while (!valid);

    valid = 0;
    do {
        printf("Enter your last name: ");
        fgets(lname, sizeof(lname), stdin);
        lname[strcspn(lname, "\n")] = '\0';
        valid = alphaSpace(lname, &valid);
        if (!valid) 
        {
            printf("Invalid input, please only enter valid characters.\n");
        } else {
            printf("Valid entry.\n");
        }
    } while (!valid);
    
    valid = 0;
    do {
        printf("Enter your street address: ");
        fgets(street, sizeof(street), stdin);
        street[strcspn(street, "\n")] = '\0';
        valid = valAddress(street, &valid);
        if (!valid) 
        {
            printf("Invalid input, please only enter valid characters.\n");
        } else {
            printf("Valid entry.\n");
        }
    } while (!valid);
    
    valid = 0;
    do {
        printf("Enter your city: ");
        fgets(city, sizeof(city), stdin);
        city[strcspn(city, "\n")] = '\0';
        valid = alphaSpace(city, &valid);
        if (!valid) 
        {
            printf("Invalid input, please only enter valid characters.\n");
        } else {
            printf("Valid entry.\n");
        }
    } while (!valid);
    
    valid = 0;
    do {
        printf("Enter your state abbreviation [IN]: ");
        fgets(state, sizeof(state), stdin);
        state[strcspn(state, "\n")] = '\0';
        valid = valState(state, &valid);
        if (!valid) 
        {
            printf("Invalid input, please only enter valid characters.\n");
        } else {
            printf("Valid entry.\n");
        }
    } while (!valid);
    
    valid = 0;
    do {
        printf("Enter your zip code [47348-1024]: ");
        fgets(zip, sizeof(zip), stdin);
        zip[strcspn(zip, "\n")] = '\0';
        valid = valDigits(zip, &valid);
        if (!valid) 
        {
            printf("Invalid input, please only enter valid characters.\n");
        } else {
            printf("Valid entry.\n");
        }
    } while (!valid);
    
    valid = 0;
    do {
        printf("Enter your number (###)###-####: ");
        fgets(phone, sizeof(phone), stdin);
        phone[strcspn(phone, "\n")] = '\0';
        valid = valDigits(phone, &valid);
        if (!valid) 
        {
            printf("Invalid input, please only enter valid characters.\n");
        } else {
            printf("Valid entry.\n");
        }
    } while (!valid);
    
    return 0;
}

/* function to test user input*/
int alphaSpace(char* str, int *valid)
{
    int i;
    int sentinel = *valid;
    
    for (i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i]) && !isspace(str[i])) 
        {
            return 0;
        }
    }
    sentinel++;
    //printf("%d", sentinel);
    *valid = sentinel;
    return 1;
}//end of alphaSpace()

int valAddress(char* str, int *valid)
{
    int i;
    int sentinel = *valid;
    
    for (i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i]) && !isspace(str[i]) && !isdigit(str[i]) && !ispunct(str[i]))
        {
            return 0;
        }
    }
    sentinel++;
    
    *valid = sentinel;
    return 1;
}//end of valAddress()

int valState(char* str, int *valid)
{
    int i;
    int sentinel = *valid;
    
    //loop to check only two characters were entered before validating
    if(strlen(str) == 2)
    {
        for (i = 0; i < strlen(str); i++) {
            if (!isalpha(str[i]) || !isupper(str[i]))
            {
                return 0;
            }
    
        }    
    }
    else
    {
        return 0;
    }
    sentinel++;
    
    *valid = sentinel;
    return 1;
}//end of valState()

int valDigits(char* str, int *valid)
{
    int i;
    int sentinel = *valid;
    
    //loop to check for valid length before validating entered criteria
    if(strlen(str) >= 10) 
    {
        for (i = 0; i < strlen(str); i++) {
            if (!isdigit(str[i]) && !ispunct(str[i]))
            {
                return 0;
            }
        }
    } else
    {
        return 0;
    }
    sentinel++;
    
    *valid = sentinel;
    return 1;
}//end of valDigits()