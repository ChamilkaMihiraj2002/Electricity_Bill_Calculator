#include <stdio.h>
#include <stdlib.h>

int Pbill(int present,int previous,int value,int bill,int name)
{
    FILE * fpointer = fopen("ElecBill.txt","a");


    fprintf(fpointer,"------------------------------------------\n");
    fprintf(fpointer,"House No :  %d\n",name);
    fprintf(fpointer,"Meter Reading");
    fprintf(fpointer,"     Cost\n");
    fprintf(fpointer,"______________");
    fprintf(fpointer,"    ______________\n");
    fprintf(fpointer," Present : %d",present);
    fprintf(fpointer,"    Cost For Usage Rs. %d\n",bill);
    fprintf(fpointer," Previous: %d\n",previous);
    fprintf(fpointer," Usage   : %d\n",value);

    fprintf(fpointer,"------------------------------------------\n\n");

    fclose(fpointer);
}

int billMake(int value)
{
    const int fix = (64 * 5);
    int bill;

    if (value > 64)
    {
        bill = fix + ((value - 64) * 10);
    }
    else
    {
        bill = (value * 5);
    }
    
    return bill;
}

int main()
{
    int a = 0;
    int name;
    while (a < 1)
    {
        //Variables :
        int previous,present,value,bill;

       
        printf("House No : ");
        scanf("%d",&name);

        //Getting Inputs :
        printf("\nEnter Present Reading : ");
        scanf("%d",&present);
        printf("Enter Past Reading    :");
        scanf("%d",&previous);

        //Calcuation Usage :
        value = (present - previous);
        bill = billMake(value);

        //Output Bill :
        printf("Bill is Rs. %d\n\n",bill);

        Pbill(present,previous,value,bill,name);
    }
    
    
    return 0;
}
