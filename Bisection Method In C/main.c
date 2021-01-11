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

   float xLow,xHigh,xMid;
   re:printf("\n Enter the initial lower value for the root of the function: ");
   scanf("%f",&xLow);

   printf("\n Enter the initial upper value for the root of the function: ");
   scanf("%f",&xHigh);

   float fLow = evaluateFunction(functionPointer,noOfTermsInFunction,xLow);
   float fHigh = evaluateFunction(functionPointer,noOfTermsInFunction,xHigh);

   float fMid,acceptedError,Error;
   if( fLow * fHigh >=0 ) {
    printf("\n Enter another interval");
    goto re;
   } else {
       printf("\n Enter the accepted error rate: ");
       scanf("%f",&acceptedError);
       printf("\n a\t\t b\t\t m\t\t f(a)\t\t f(b)\t\t f(m)\t\t b-a\n");
       do{
        xMid = (xLow + xHigh)/2;
        fMid = evaluateFunction(functionPointer,noOfTermsInFunction,xMid);
        Error = xHigh - xLow;

        printf(" %f\t %f\t %f\t %f\t %f\t %f\t %f\t \n",xLow,xHigh,xMid,fLow,fHigh,fMid,Error);

        if( fLow * fMid < 0 ) {
            xHigh = xMid;
            fHigh = fMid;
        }else {
            xLow = xMid;
            fLow = fMid;
        }
       }while(Error>=acceptedError);
   }
   printf("The root of the function is: %f",xMid);
    return 0;
}
