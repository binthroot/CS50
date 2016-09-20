#include <stdio.h>
#include <cs50.h>

int digitCheck(long long);

int main(void)
{
    long long creditCard;
    
    do
    {
        printf("Please give me your credit card number: ");
        creditCard = get_long_long();
    }
    while(creditCard < 0);
    
    int numOfDigits = digitCheck(creditCard);
    
    if (numOfDigits < 13 || numOfDigits == 14)
    {
        printf("INVALID\n");
        return 0;
    }
    
    else if (numOfDigits > 16)
    {
        printf("INVALID\n");
    }
    
    int cardDigitOne;
    int cardDigitTen;
    int cardSum = 0;
    
    // Loops over the digits of the credit card number and adds to sum to see if card is valid
    for (int i=0; i<numOfDigits;i++)
    {
        // takes the last digit of the credit card
        int digit = (creditCard % 10);
        //printf("Current digit: %d\n", digit);
        // removes the last digit of the credit card
        creditCard /= 10;
        //printf("Current card iteration: %lld\n", creditCard);
        
        if (i == numOfDigits-2)
        {
            cardDigitOne = digit;
        }
        
        if (i == numOfDigits-1)
        {
            cardDigitTen = digit;
        }
        
        // if the number being used is an even number from the right
        if ((i+1)%2 == 0)
        {
            // we double that number
            int doubleDigit = digit*2;
            //printf("Digit doubled: %d\n", digit);
            // then we determine if it has two digits
            if (doubleDigit > 9)
            {
                // we add the two digits together
                int productOf = (doubleDigit % 10) + (doubleDigit/10);
                
                // we add this amount to the sum
                cardSum += productOf;
            }
            else
            {
                // we add this to the sum in the case of it being a single digit
                cardSum += doubleDigit;
                //printf("Double Digit: %d Card Sum: %d\n", doubleDigit, cardSum);
            }
        }
        else
        {
            // we add this to the sum in the case of it being an odd number
            cardSum += digit;
        }
        
        
    }
    
    if (cardSum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (numOfDigits == 15)
    {
        printf("AMEX\n");
    }
    else if (numOfDigits == 13)
    {
        printf("MASTERCARD\n");
    }
    
    else if (cardDigitTen == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("MASTERCARD\n");
    }
    return 0;
    
}

int digitCheck(long long n)
{
    int check = 0;
    
    while (n != 0)
    {
        n /= 10;
        check++;
    }
    
    return check;
}
