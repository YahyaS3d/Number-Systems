#include <stdio.h>
#include <stdlib.h>
#define TRUE     1
#define FALSE    0
const int MAX_NUMS = 20;
const int MAX_DEC_NUMBER=255;
const int OCT = 8;
const int DEC = 10;
const int BIN  = 2;
int charToInt(char c);
void clearBuffer(void);//delete the spaces in the string
int stringToInt(char number[], int base);
int enterNumber(int numbers[], int totalNums, int base);
void printMenu(int base);
int isValidDigit(int digit, int base);
int howManyEven(int numbers[], int totalNums);
int find(int numbers[], int numKey, int totalNums);
void printArray(int numbers[], int totalNums);
int plusEight(char[]);//Check if its more than 8 digits
int intToString(int num, char numStr[],  int base);
int main()//program
{
    char numStr[10];
    int numsArr[MAX_NUMS];
    int totalNums =0;
    int currBase=DEC;//base
    int Enter=0;
    int Enter1=0;
    char User[1];
    int save=0;
    while(save==0)
    {
        if(currBase==DEC)
            printf("You are in Decimal Mode\n");
        if(currBase==BIN)
            printf("You are in binary Mode\n");
        if(currBase==OCT)
            printf("You are in Octal Mode\n");
        printf("1. Change Base.\n2. Enter a number.\n3. Find a number.\n4. Get the amount  of even numbers.\n5  Print.\n6. Exit.\n");
        scanf("%s",&User);
        getchar();
        Enter=stringToInt(User,DEC);
        if(Enter==0||Enter>6||Enter==-1)
        {
            printf("please Enter number from the main list\n");
            continue;
        }
        while(Enter == 1)
        {
            printf("1. Decimal\n");
            printf("2. Binary\n");
            printf("3. Octal\n");
            scanf("%s",&User);
            Enter1=stringToInt(User,DEC);
            if(Enter1==0||Enter1>6||Enter1==-1)
            {
                printf("please Enter number from the list\n");
                continue;
            }
            if(Enter1 ==1)
            {
                currBase = DEC;
                break;
            }
            else if (Enter1 ==2)
            {
                currBase = BIN;
                break;
            }
            else if((Enter1 == 3 ))
            {
                currBase = OCT;
                break;
            }
            else
                printf("please enter number is on screen\n");
        }
        while(Enter == 2)
        {
            if(enterNumber(numsArr,totalNums,currBase)==TRUE)
                totalNums++;
            break;
        }
        while(Enter == 3)
        {
            int numKey=-1;
            if(numKey==FALSE)
                printf("please enter number\n");
            int Enter3;
                fgets(numStr,10,stdin);
            if(plusEight(numStr)){
            numStr[0] = 'F';
            clearS();
        } else {
            numStr[strlen(numStr) - 1] = '\0';
        }
            numKey=stringToInt(numStr, currBase);
            if(numKey==-1)
            {
                printf("please enter number in base %d\n",currBase);
                continue;
            }
            if(numKey<0 || numKey>255)
            {
                printf("The Number not in the range \n");
                printf("please enter number in base %d\n",currBase);
                continue;
            }
            Enter3 =find(numsArr,numKey,totalNums);
            if(Enter3==FALSE) printf("The number is not found\n");
            if(Enter3==TRUE) printf("The number is found\n");
            break;
        }
        if(Enter==4)
        {
            printf("%d\n",howManyEven(numsArr,totalNums));
        }
        if(Enter==5)
        {
            printArray(numsArr,totalNums);
        }
        if(Enter==6)
            save++;
    }
    return 0;
}

int charToInt(char c)
{
    if((c >= '0' && c <= '9'))
        return (c-'0');
    return -1;
}

int stringToInt(char number[], int base)
{
    if(base<0)
    {
        return -1;
    }
    int size=strlen(number);
    int i;
    if(size==1 && charToInt(number[0])==0)
    {
        return 0;
    }
    for(i=0; i<size; i++)
    {
        if(isValidDigit(charToInt(number[i]),base)==FALSE)
            return -1;
    }
    int counter=0;
    double save=0;
    for(i=size-1; i>=0; i--)
    {
        if(number[i]<'0'||number[i]>'9') return -1;
        save+=(charToInt(number[i])*(pow(base,counter)));
        counter++;
    }
    return save;
}
int intToString(int num, char numStr[],  int base)
{
    int size=sizeof(numStr);
    if(base<0) return -1;
    if(num==0)
    {
        for(int i=size-1; i>=0; i--)
            numStr[i]='0';
        numStr[size]='\0';
        return TRUE;
    }
    if(base==DEC) return num;
    double save=num;
    double sharit=0;
    int pow=1;
    while(save!=0)
    {
        save=save/((double)base);
        sharit+=((save-(int)save)*base)*pow;
        pow*=10;
        save=(int)save;
    }
    for(int i=size-1; i>=0; i--)
    {
        numStr[i]=(((int)sharit)%10)+'0';
        sharit/=10;
        if(sharit==0) break;
    }
    numStr[size]='\0';
    return TRUE;
}

void printMenu(int base)
{
    if(base==DEC)
        printf("You are in Decimal Mode\n");
    if(base==BIN)
        printf("You are in binary Mode\n");
    if(base==OCT)
        printf("You are in Octal Mode\n");
    printf("1. Change Base.\n");
    printf("2. Enter a number.\n");
    printf("3. Find a number.\n");
    printf("4. Get the amount  of even numbers.\n");
    printf("5. Print.\n");
    printf("6. Exit.\n");
}

int isValidDigit(int digit, int base)
{
    if(digit>=0 && digit<base) return TRUE;
    return FALSE;
}
int enterNumber(int numbers[], int totalNums, int base)
{
    if(totalNums==MAX_NUMS)
    {
        printf("The Array is Full\n");
        return FALSE;
    }
    char num[10];
    int Dnum=-1;//decimal number
    printf("please enter number\n");
     fgets(num,10,stdin);
            if(plusEight(num)){
            num[0] = 'F';
            clearS();
        } else {
            num[strlen(num) - 1] = '\0';
        }
    Dnum=stringToInt(num,base);
    while(Dnum>255||Dnum==-1)
    {
        if(Dnum>=0&&Dnum<=255)
            break;
        if(Dnum>255)
        {
            printf("The number is not in range\n");
            printf("please enter number in the range\n");
                fgets(num,10,stdin);
            if(plusEight(num)){
            num[0] = 'F';
            clearS();
        } else {
            num[strlen(num) - 1] = '\0';
        }
            Dnum=stringToInt(num,base);
        }
        if(Dnum==-1)
        {
            printf("please enter number in base %d\n",base);
                fgets(num,10,stdin);
            if(plusEight(num)){
            num[0] = 'F';
            clearS();
        } else {
            num[strlen(num) - 1] = '\0';
        }
            Dnum=stringToInt(num,base);
        }
    }
    numbers[totalNums]=Dnum;
    return TRUE;

}

int find(int numbers[], int numKey, int totalNums)
{
    int i;
    for(i=0; i<totalNums; i++)
        if(numbers[i]==numKey)
            return TRUE;
    return FALSE;
}
int howManyEven(int numbers[], int totalNums)
{
    int i=0;
    int lengths=totalNums;
    for(i=0; i<totalNums; i++)
    {
        lengths=lengths-(numbers[i]&1);
    }
    return lengths;
}
void printArray(int numbers[], int totalNums)
{
    int i,j;
    int appear=-1;

    for(i = 0; i < totalNums; i++)
    {
        for(j = 0; j < totalNums - i - 1; j++)
        {
            if(numbers[j] > numbers[j+1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    char numStr[9];//string

    printf("List Of Numbers \n==============================\nDEC\tBIN\t\tOCT\n");

    for(i = 0; i < totalNums; i++)
    {
        printf("%d\t", numbers[i]);
        intToString(numbers[i], numStr, BIN);
        printf("%s\t", numStr);
        if(numbers[i]==0) printf("%d\n",numbers[i]);
        else
        {
            intToString(numbers[i], numStr, OCT);
            for(j=0; j<9; j++)
            {
                if(numStr[j]!='0')
                    appear=1;
                if(appear==1)
                    printf("%c",numStr[j]);
            }
            appear=-1;//if shows
            printf("\n");
        }
    }
}
int plusEight(char number[]){

    if(strlen(number) == 9 && number[8] != '\n'){
        return TRUE;
    }

    return FALSE;

}
void clearS(void){//empty space
    while(getchar() != '\n');
}
