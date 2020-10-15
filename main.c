#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char FName  [25][30];
char LName  [25][30];
float English   [30];
float Math      [30];
float Spanish   [30];
float Science   [30];
float Average   [30];

int Sorted;
float Temp;

char Line       [200];
float Grade;
int Counter;
int Choice ;
int VarCount;
char StrInput;
int NumInput;
int Monitor;

char TempStr [25][30];

char Response;
int Valid;


FILE *fpointer;

//This function adds a student to the database
void AddStudent()
{
    FILE *fpointer;
    fpointer = fopen("Database.txt", "a");
    Counter = 1;
//this chunk of code accepts and validates first names
    Valid = 0;
    while(Valid == 0)
    {
        printf("Please enter the student's first name\n");
        scanf("%s", &FName[Counter]);
        if (strlen(FName[Counter]) > 20 )
        {
            printf("Please enter a shorter name\n");
            system("pause");
            system("cls");
        }
        else(Valid = 1);
    }
    fprintf(fpointer ,"\n%s ", FName[Counter]);
//end of first name validation


//this chunk of code accepts and validates last names
    Valid = 0;
    while(Valid == 0)
    {
        printf("Please enter the student's last name\n");
        scanf("%s", &LName[Counter]);
        if (strlen(LName[Counter]) > 20 )
        {
            printf("Please enter a shorter name\n");
            system("pause");
            system("cls");
        }
        else(Valid = 1);
    }
    fprintf(fpointer ,"%s ", LName[Counter]);
//End of validation of last name

//Beginning of validation for a student's english mark
    Valid = 0;
    while (Valid == 0)
    {
        printf("Please enter the student's english mark\n");
        scanf("%f", &English[Counter]);
        if(English[Counter] < 0 || English[Counter] > 100)
        {
            printf("Please enter a valid mark\n");
            system("pause");
            system("cls");
        }else (Valid = 1);
    }
    fprintf(fpointer ,"%.2f ", English[Counter]);


//End of english mark validatioin

//Beginning of validation for a student's math mark
    Valid = 0;
    while(Valid ==0)
    {
        printf("Please enter the student's Math mark \n");
        scanf("%f", &Math[Counter]);
        if (Math[Counter] < 0 || Math[Counter] > 100)
        {
            printf("Please enter a valid mark\n");
            system("pause");
            system("cls");
        } else (Valid =1);
    }
    fprintf(fpointer ,"%.2f ", Math[Counter] );
//End of validation for student's math mark

//beginning of validation of student's Spanish mark
    Valid = 0;
    while(Valid ==0)
    {
        printf("Please enter the student's Spanish mark \n");
        scanf("%f", &Spanish[Counter]);
        if (Spanish[Counter] < 0 || Spanish[Counter] > 100)
        {
            printf("Please enter a valid mark\n");
            system("pause");
            system("cls");
        } else (Valid =1);
    }
    fprintf(fpointer ,"%.2f ", Spanish[Counter] );
//end a validation for sudent's Spanish mark

//beginning of validation for student's Science mark

    Valid = 0;
    while(Valid ==0)
    {
        printf("Please enter the student's Science mark \n");
        scanf("%f", &Science[Counter]);
        if (Science[Counter] < 0 || Science[Counter] > 100)
        {
            printf("Please enter a valid mark\n");
            system("pause");
            system("cls");
        } else (Valid =1);
    }
    fprintf(fpointer ,"%.2f ", Science[Counter] );
//end of validation for a student's Science mark

//the following code calculates and stores the average the average of of each student
    Average[Counter] = (English[Counter] + Math[Counter] + Spanish[Counter] + Science[Counter])/4;
    fprintf(fpointer,"%.2f",Average[Counter]);

    fclose(fpointer);
}

//This function displays all users in the database
void DisplayAll()
{
//printing column headders for the output
    printf("Student name\t\tEnglish\t\tMath\t\tSpanish\t\tScience\t\tAverage\n");
    fpointer = fopen("Database.txt", "r");
    VarCount = 0;

//this while loop prints all the actual marks attained by students into the table
    while(!feof(fpointer))
    {
        VarCount++;
        fscanf(fpointer, "%s",&FName[VarCount]);
        printf("%s ",FName[VarCount]);
        fscanf(fpointer, "%s",&LName[VarCount]);
        printf("%s\t",LName[VarCount]);

        for(Counter =1 ; Counter <= 5; Counter++)
        {
            fscanf(fpointer, "%f", &Grade);
            printf("\t%.2f\t", Grade);
        }
        printf("\n");
    }

}


//this function sorts all the individuals entered by their average in descending order
void Sort()
{
    fclose(fpointer);
    VarCount =0;
    Monitor = 0;
    Counter =0;
    fpointer = fopen("Database.txt", "r");
    printf("Students sorted in decending order according to their average\n\n");
//this while loop stores all the values from the text file in variables used by this program
    while(!feof(fpointer))
    {


        fscanf(fpointer, "%s",&FName[VarCount]);
        fscanf(fpointer, "%s",&LName[VarCount]);

        fscanf(fpointer, "%f", &English[VarCount]);
        fscanf(fpointer, "%f", &Math[VarCount]);
        fscanf(fpointer, "%f", &Spanish[VarCount]);
        fscanf(fpointer, "%f", &Science[VarCount]);
        fscanf(fpointer, "%f", &Average[VarCount]);
        VarCount++;


        Monitor++;
    }

//the following is a bubble sort that sorts in descending order based on averages
    while(1)
    {
        Sorted = 1;
        for (Counter = 0; Counter < Monitor-1; Counter++)
        {

            if (Average[Counter+1] > Average[Counter])
            {
                Temp = Average[Counter+1];
                Average[Counter+1] = Average[Counter];
                Average[Counter]= Temp;


                strcpy(TempStr, FName[Counter+1]);
                strcpy(FName[Counter+1], FName[Counter]);
                strcpy(FName[Counter] , TempStr);


                strcpy(TempStr, LName[Counter+1]);
                strcpy(LName[Counter+1], LName[Counter]);
                strcpy(LName[Counter], TempStr);



                Temp = English[Counter+1];
                English[Counter+1] = English[Counter];
                English[Counter]= Temp;


                Temp = Math[Counter+1];
                Math[Counter+1] = Math[Counter];
                Math[Counter]= Temp;



                Temp = Spanish[Counter+1];
                Spanish[Counter+1] = Spanish[Counter];
                Spanish[Counter]= Temp;



                Temp = Science[Counter+1];
                Science[Counter+1] = Science[Counter];
                Science[Counter]= Temp;

                Sorted = 0;

            }
        }
        if (Sorted == 1)
        {
            break;
        }

    }


//the sorted list of names is displayed to the user from this for loop
    for (Counter =0 ;Counter < Monitor;Counter++)
    {
        printf("%s %s\t",FName[Counter], LName[Counter]);
        printf("%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t\n",English[Counter],
                       Math[Counter],Spanish[Counter],Science[Counter],Average[Counter]);
    }

    printf("\n");
    system("pause");
}

void HomeScreen()
{
//This is a welcome screen for the user to be printed
    printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+ Welcome to Success Primary School Database +\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++\n\n\n");

//ascii art to make the program more easy on the eyes
    printf("     ________________________________    \n");
    printf("    |.==============================.|   \n");
    printf("    ||                              ||   \n");
    printf("    ||    .----.    ,               ||   \n");
    printf("    ||   / ><   \\  /                ||  \n");
    printf("    ||  |        |/\\                ||  \n");
    printf("    ||   \\______//\\/                || \n");
    printf("    ||   _(____)/ /                 ||   \n");
    printf("    ||__/ ,_ _  _/__________________||   \n");
    printf("    '===\\___\\_) |====================' \n");
    printf("         |______|                        \n");
    printf("         |  ||  |                        \n");
    printf("         |__||__|                        \n");
    printf("         (__)(__)                        \n");
}


//this function serves as a promptto ask the user to enter the opperaion they wish to do
void prompt()
{
        do{

            printf("What would you like to do?\n\n");
            printf("1.Add a student(Export) \n2.Import and display all students \n3.Sort and display data\n4.Close program\n");
            scanf("%d",&Choice);
            system("cls");


            if(Choice <1 || Choice >4)
            {
                printf("Please enter a valid option\n\n");
                system("pause");
            }

        }while(Choice <1 || Choice >4);
}

//This is the main program
int main()
{
    HomeScreen();
    printf("\n");
    system("pause");
    system("cls");


//the switch case determines which opperation to perform
   do{
        prompt();
            switch (Choice){
                case 1 : AddStudent();
                            break;
                case 2 : DisplayAll();
                        break;
                case 3 : Sort      ();
                        break;
                case 4 : break;
            }
            Response = 'y';
//validation to ensure a correct response was inputted
            do{

                printf("would you like to continue? (y/n)\n");
                scanf(" %c", &Response);
                system("cls");
                if (Response != 'Y' && Response != 'y' && Response != 'N' && Response != 'n' )
                {
                    printf("Please enter a valid response\n");
                }
            }while (Response != 'Y' && Response != 'y' && Response != 'N' && Response != 'n');

        }while(Response == 'y' || Response == 'Y' );
//end of validation
}

