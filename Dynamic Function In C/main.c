#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct function{
    float constantOfX;
    float powerOfX;
};

float evaluateFunction(struct function* evt,int noOfTerms,float value) {
    float returnValue = 0;
    int i;

    for(i=0; i<noOfTerms; i++) {
        returnValue += evt[i].constantOfX * pow(value,evt[i].powerOfX);
    }

    return returnValue;
}

int main()
{
   int noOfTermsInFunction;
   struct function* functionPointer;
   int i;

   printf("Enter the no of terms in function: ");
   scanf("%d",&noOfTermsInFunction);

   // dynamic array for the function constants and powers
   functionPointer = (struct function*)malloc(sizeof(struct function)*noOfTermsInFunction);

   // taking the constants and the powers of the terms in the function
   for(i=0; i<noOfTermsInFunction; i++) {
    printf("\n Enter the constant of the %d term in the function: ",i+1);
    scanf("%f",&(functionPointer[i]).constantOfX );

    printf("\n Enter the power of the x in %d term in the function: ",i+1);
    scanf("%f",&(functionPointer[i]).powerOfX );
   }

    float value;
    printf("\nEnter the value of x to calculate in the function:");
    scanf("%f",&value);
    printf("The value of the function at x =  %f  is %f",value,evaluateFunction(functionPointer,noOfTermsInFunction,value) );
    return 0;
}
