/*M.RAGHAVAN[20PW26] PSG COLLEGE OF TECHNOLOGY 1st SEM PROJECT*/
/*HIGH LEVEL MATHEMATICS PROBLEM SOLVING TOOL*/
//DATE STARTED : 16-11-2020[BUILDING OF ALGORITHMS]
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<time.h>

#include<dos.h>
COORD coord={0,0};

   void gotoxy(int x,int y)
{
  	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
/*Function f() is same as f(x) in a mathematical problem...'o' in argument represents choice of user
whether he needs a [1]polynomial function,[2]trigonometrical function */
float f(float x, float a,float b,float c,float d,float e,int o)
{
    float y;
    switch(o)
    {
    case 1:
        {

            system("cls");

     y = a*pow(x,4) + b*pow(x,3) + c*pow(x,2) + d*x + e;  //same as ax^4 + bx^3 + cx^2 + dx + e  e represents the constant
            return y;
            break;
        }
    case 2:
        {
            system("cls");
            y = sin(a*x);           //'a' here represents multiple of the radian x will become still more clear at actual use of this function
            return y;
            break;

        }
    case 3:
        {
            system("cls");
            y = cos(a*x);          //same here to...'a' act as an multiple of the radian
            return y;
            break;
        }
    case 4:
        {
            system("cls");
            y = tan(a*x);
            return y;
            break;
        }


}
}

/* function addition performs arithmetic addition and subtraction too.User needs to specify the compiler to subtract by
specifying '-' (minus) sign in  front of the number
function addition() takes number of values(real) to be added or subtracted as argument and returns the final value*/
float addition(int n)
{
    float sum=0;
    float number;
    int i;
    for(i=0;i<n;i++)
    {
        gotoxy(75,20+i);printf(" Enter %d) number ",i+1);
      gotoxy(110,20+i) ;scanf("%f",&number);
        {
            sum = sum+number;
        }
    }
    return sum;
}
/* the function multiplication() takes number of values to be multiplied and returns the final answer*/
float multiplication(int n)
{
    float prod = 1;
    int i;
    float number;

    for(i=0;i<n;i++)
    {
        gotoxy(75,20+i);printf("Enter  the number multiplied with %f : ",prod);

        gotoxy(120,20+i);scanf("%f",&number);


        prod *=number;
        if(number == 0)
        {
            break;

        }
    }
    return prod;
}
/* the function division takes two arguments number1 and number2 and returns the divided value for  it*/
float division(float number1,float number2)
{
     float div;
    div = number1/number2;
    return div;
}
/*The function factorial intakes an integer number as an argument and returns factorial value for it.At certain stage the results may get
overflowed and results in unpredictable results*/
long fact(int num)
{

    int i;
    long factrl=1;
    for(i=1;i<=num;i++)
    {


        factrl = factrl * i;
    }

    return factrl;
}
int main()
{
    FILE *record;                           //a file pointer variable for storing logs of answer with respective date and time
    time_t t;
    time(&t);
    record = fopen("ansRecord","a");
    int j,sumCount=0,prodCount=0,factCount=0,inteCount=0;
    float sumAns,prodAns;                  /*floating variables for storing the results for a longer time*/
    long factAns;
    int count=0;                          /*flag variable for counting number of operations done*/



        int option;                       /*most important variable that helps user to satisfy his choice*/
        l1:{                                //case label for main menu..!!
        system("cls");


        gotoxy(75,7);                       //user-defined function call for moving the cursor in the console
        printf("HIGHER SECONDARY MATHEMATICS PROBLEM SOLVER");

        gotoxy(75,8);
        printf("****** ********* *********** ******* ******");


        gotoxy(75,9);

        printf("THIS APPLICATION  CAN PERFORM:-");
        gotoxy(75,10);printf("[1] ADDITION & SUBTRACTION");

        gotoxy(75,12-1);printf("[2] MULTIPLICATION");
        gotoxy(75,13-1);printf("[3] DIVISION");
        gotoxy(75,14-1);printf("[4] GRAPHING");

        gotoxy(75,15-1);printf("[5] FACTORIAL OF YOUR INPUT ");
        gotoxy(75,15);printf("[6] INTEGRATION OF A FUNCTION");
        gotoxy(75,16);printf("[7] LOG OF ANSWERS..! ");
        gotoxy(75,19-1);printf("PLEASE ENTER YOUR CHOICE TO CONTINUE:");
        gotoxy(120,19-1);scanf("%d",&option);

        }
        switch(option)
        {

               case 1:                                                                      //option 1 for additon
                   count++;                                                                 //increments as user decided to undergo an operation
                {

                    system("cls");
                    gotoxy(75,10);printf("*****JUST A AID TO ENHACE YOUR MATHEMATCAL SKILL*****");
                    gotoxy(75,11);printf("PLANNING CAN MAKE A 'IDIOT' WIN THE WORLD");

                    gotoxy(75,13);printf("please wait application is loading....");
                    delay(5000);

                    system("cls");
                     L1:{                                                                           //case label for 'addition/subtraction' menu
                            system("cls");
                    gotoxy(75,10);printf("*****YOU HAVE CHOSEN TO ADD*****");

                    gotoxy(75,11);printf("ENTER NUMBER OF NUMBERS TO BE ADDED:");
                    int n;

                    gotoxy(111,11);scanf("%d",&n);
                    float ans = addition(n);
                    fprintf(record, "%s||ADDITION/SUBTRACTION||%f\n",ctime(&t),ans);             //Already opened a file and writes the answer to that file
                    fclose(record);


                    sumAns = ans;
                    //Top border line...
                    gotoxy(10,5);
                    for(j=0; j<20; j++)
                    printf("%c", 223);                                 //it is an extended ascii value for just a block bottom

                    //Bottom border line...
                    gotoxy(10,15);
                    for(j=0; j<=20; j++)
                    printf("%c", 223);

                    //Left and Right border line...
                    for(j=0; j<10; j++)
                    {
                            gotoxy(10,5+j);
                            printf("%c",219);                       //ASCII value 219 stands for a straight rectangular block

                            gotoxy(30,5+j);
                            printf("%c",219);
                    }
                        printf("\n");

                    gotoxy(17,7);printf("ANSWER ",n);
                    gotoxy(17,10);printf("%f\n\n\n\n\n\n\n\n",ans);     // \n\n\n for moving 'process returned with zero' far away from box
                    gotoxy(17,19);printf("TASK SUCCESFULLY COMPLETED \nDO YOU WANT TO ADD ANOTHER SET NUMBERS??[1-FOR YES 0-FOR NO]");
                    gotoxy(133,19);scanf("%d",&option);

                    if(option == 1)
                    {


                        goto L1;                        /*If user has entered 1 then compiler assumes that he needs to goto the add/subtract menu and takes him/her to the same*/
                    }
                    if(option == 0)
                    {
                          system("cls");

                        goto l1;                       // IN THIS CASE COMPILER ASSUMES THAT HE/SHE HAS COMPLETED THE TASK AND HE WANTS TO DO ANOTHER OPERATION THEREFORE, IT TAKES HIS OR HER TO THE MAIN MENU

                         break;
                    }
                }
                }

                        case 2:
                            count++;
                {
                     system("cls");
                    gotoxy(75,10);printf(">>>>> JUST A TIP TO MAKE YOUR MATHEMATICAL DAY!! <<<<<<<");
                    gotoxy(75,11);printf("DIDNOT GOT ANSWER ON YOUR 11TH ATTEMPT?? DONT GIVE IT UP YOU MAY GET IT ON YOUR 15TH ATTEMPT!!");
                    gotoxy(75,13);printf("please wait application is loading....");
                    delay(5000);
                    system("cls");
                    l2:                                             //label for 'multiplication' menu
                        {
                            system("cls");
                            gotoxy(75,10);printf("****YOU HAVE CHOSEN TO MULTIPLY*****");
                            gotoxy(75,11);printf("ENTER NUMBER OF NUMBERS TO BE MULTIPLIED..: ");
                            int n;

                            gotoxy(120,11);scanf("%d",&n);
                            float ans;
                            if(n!=0)
                            ans= multiplication(n);
                            else
                            {
                                goto l2;       //instructs user to enter a valid input.
                            }
                            fopen("ansRecord","a");

                            fprintf(record,"%s MULTIPLICATION %f\n",ctime(&t),ans);       //adds to the log of answers record
                            fclose(record);

                            prodAns = ans;
                            gotoxy(10,5);
                    for(j=0; j<20; j++)
                    printf("%c", 223);

                    //Bottom border line...
                    gotoxy(10,15);
                    for(j=0; j<=20; j++)
                    printf("%c", 223);

                    //Left and Right border line...
                    for(j=0; j<10; j++)
                    {
                            gotoxy(10,5+j);
                            printf("%c",219);

                            gotoxy(30,5+j);
                            printf("%c",219);
                    }
                        printf("\n");

                    gotoxy(17,7);printf("ANSWER ",n);
                    gotoxy(17,10);printf("%f\n\n\n\n\n\n\n\n",ans);
                    gotoxy(17,19);printf("TASK SUCCESFULLY COMPLETED \nDO YOU WANT TO MULTIPLY ANOTHER SET NUMBERS??[1-FOR YES 0-FOR NO]");
                    gotoxy(133,19);scanf("%d",&option);
                    if(option == 1)
                    {
                        goto l2;           //user has ordered the compiler to do another operation.. so it takes him/her to the multiplication menu
                    }
                    else if(option == 0)
                    {
                        system("cls");
                        goto l1;         //takes user to main menu
                        break;
                    }



                }
            }
               case 3:
                   count++;
                {
                    system("cls");
                    gotoxy(75,10);printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~KEEP IN MIND~~~~~~~~~~~~~~~~~~~~~~");
                    gotoxy(75,11);printf("THERE WILL BE ALWAYS ATLEAST ONE IMPOSITOR AMONG EACH PROBLEM");
                    gotoxy(75,13);printf("please wait application is loading....");
                    delay(5000);
                    system("cls");
                    l3:
                        {

                            system("cls");
                            gotoxy(75,10);printf("YOU HAVE CHOSEN TO DIVIDE TWO NUMBERS");
                            gotoxy(75,11);printf("YOU CAN PERFORM FOLLOWING ACTIONS:-");     // This menu offers user three choices
                            gotoxy(75,12);printf("-->[1] DIVIDE PREVIOUS OPERATIONS WITH YOUR REQUIRED NUMBER");
                            gotoxy(75,13);printf("-->[2] DIVIDE PREVIOUS OPERATION RESULT WITH PREVIOUS RESULT EVEN");
                            gotoxy(75,14);printf("-->[3] DIVIDE TWO NUMBERS OF YOUR REQUIREMENT");
                            float number1,number2;
                            char option[100];
                           gotoxy(75,15); printf("ENTER YOUR CHOICE TO CONTINUE");
                           gotoxy(111,15);scanf("%s",option);
                           if(!strcmp(option, "1")|| !strcmp(option, "one"))
                           {
                               system("cls");
                               if( count == 0)                                // Checks whether user has done at-least one operation
                               {
                                   system("cls");
                                   char option[100];
                                    gotoxy(50,10);printf("YOU HAVE NOT PERFORMED ANY ADDITION OPERATION YET..TYPE RETURN TO GO TO MAIN SCREEN TYPE BACK fOR DIVIDE MENU");
                                    gotoxy(75,11);scanf("%s",option);

                                    if(!strcmp(option, "return") || !strcmp(option,"RETURN"))
                                    {

                                        goto l1;

                                    }
                                    else if(!strcmp(option, "back") || !strcmp(option,"BACK"))
                                    {

                                        goto l3;         //takes him to the division menu so that he can chose another option
                                    }
                                    break;




                               }
                               else
                               {
                                   char oper[100];
                                   gotoxy(75,10);printf("ENTER WHICH OPERATION ANSWER YOU NEED TO PROCEED..?(in small letters): ");
                                   gotoxy(75,11);printf("'SUM' for addition answer");
                                   gotoxy(75,12);printf("'PROD' for multiplication answer");
                                   gotoxy(75,13);printf("'FACT' for factorial answer");
                                   gotoxy(75,14);scanf("%s",oper);
                                   if(!strcmp(oper,"sum"))
                                   {
                                       system("cls");
                                   gotoxy(75,10);printf("ENTER YOUR REQUIRED VALUE DIVIDE %f WITH THE VALUE",sumAns);
                                   gotoxy(75,11);scanf("%f",&number2);
                                   number1=sumAns;
                                   float ans=division(number1,number2);
                                   fopen("ansRecord","a");

                                    fprintf(record,"%s DIVIDED %f BY %f = %f\n",ctime(&t),number1,number2,ans); //ADDS TO THE LOG
                                    fclose(record);
                                   system("cls");
                                   gotoxy(75,10);printf("Answer is = %f",ans);

                                   gotoxy(75,11);printf("PROCESS SUCCESFULLY COMPLETED ..DO YOU WANT TO DO THE SAME FOR ANOTHER SET OF NUMBERS??(y/n)");
                                   gotoxy(75,12);scanf("%s",option);
                                   if(!strcmp(option,"y") || !strcmp(option,"Y"))
                                   {
                                       goto l3;
                                       break;

                                   }
                                   else if(!strcmp(option,"N") || !strcmp(option,"n"))
                                   {
                                       system("cls");
                                       goto l1;
                                       break;
                                   }
                                   break;

                                   }
                                   else if(!strcmp(oper,"prod"))
                                   {
                                       system("cls");
                                   gotoxy(75,10);printf("ENTER YOUR REQUIRED VALUE DIVIDE %f WITH THE VALUE",prodAns);
                                   gotoxy(75,11);scanf("%f",&number2);
                                   number1=prodAns;
                                   float ans=division(number1,number2);
                                   fopen("ansRecord","a");

                            fprintf(record,"%s DIVIDED %f BY %f = %f\n",ctime(&t),prodAns,number2,ans);
                            fclose(record);
                                   system("cls");
                                   gotoxy(75,10);printf("ANSWER = %f",ans);
                                    gotoxy(75,11);printf("PROCESS SUCCESFULLY COMPLETED ..DO YOU WANT TO DO THE SAME FOR ANOTHER SET OF NUMBERS??(y=1/n=0)");
                                    short Opt;                     //VARIABLE for getting user choice
                                    gotoxy(75,12);scanf("%hi",&Opt);
                                   if(Opt == 1)
                                   {
                                       goto l3;
                                       break;
                                   }
                                   else if(Opt == 0)
                                   {
                                       goto l1;
                                       break;
                                   }

                                   break;

                                   }
                                   else if(!strcmp(oper,"fact"))
                                   {
                                       if(factAns!=0)
                                       {

                                            system("cls");
                                            gotoxy(75,10);printf("ENTER YOUR REQUIRED VALUE DIVIDE %ld WITH THE VALUE: ",factAns);
                                            gotoxy(75,11);scanf("%f",&number2);
                                            number1=factAns;
                                            float ans = division((float)number1,number2);
                                            fopen("ansRecord","a");

                                            fprintf(record,"%s DIVISION OF %ld BY %f = %f\n",ctime(&t),factAns,number2,ans);
                                            fclose(record);

                                              gotoxy(10,5);                                          /*code snippet for border line*/
                                        for(j=0; j<20; j++)
                                        printf("%c", 223);

                                                                                                        //Bottom border line...
                                        gotoxy(10,15);
                                        for(j=0; j<=20; j++)
                                        printf("%c", 223);

                                                                                                            //Left and Right border line...
                                        for(j=0; j<10; j++)
                                        {
                                            gotoxy(10,5+j);
                                            printf("%c",219);

                                            gotoxy(30,5+j);
                                            printf("%c",219);
                                        }
                                        printf("\n");

                                        gotoxy(17,7);printf("ANSWER ");


                                        gotoxy(17,10);printf("%f\n\n\n\n\n\n\n\n",ans);
                                         gotoxy(17,19);printf("PROCESS SUCCESFULLY COMPLETED ..DO YOU WANT TO DO THE SAME FOR ANOTHER SET OF NUMBERS??(yes/no)");
                                         char control[100];
                                        gotoxy(17,20);scanf("%s",control);



                                   if( !strcmp(control,"yes"))
                                   {
                                       goto l3;

                                   }
                                   else if(!strcmp(control,"no"))
                                   {
                                       system("cls");
                                       goto l1;//comes out of current menu and goes to main menu
                                       break;


                                   }

                                   break;


                                   }





                               }


                        }


                }
                else if(!(strcmp(option,"2")) || !strcmp(option,"two"))
                {
                    system("cls");
                    gotoxy(75,10);printf("WHICH ANSWER DO YOU NEED AS 'DIVEDENT'? ");
                    gotoxy(75,11);printf("-->[1] ANSWER OF SUM");
                    gotoxy(75,12);printf("-->[2] ANSWER OF PRODUCT");
                    gotoxy(75,13);printf("-->[3] ANSWER OF FACTORIAL");
                    gotoxy(75,14);printf("ENTER THE CHOICE: ");
                    int choice;
                    gotoxy(75+17,14);scanf("%d",&choice);
                    if(choice==1)
                    {
                        number1 = sumAns;
                    }
                    else if(choice == 2)
                    {
                        number1 = prodAns;
                    }
                    else if(choice == 3)
                    {
                        number1 = factAns;
                    }
                    system("cls");
                    gotoxy(75,10);printf("WHICH ANSWER DO YOU NEED AS DIVISOR?");
                    gotoxy(75,11);printf("-->[1] ANSWER OF SUM");
                    gotoxy(75,12);printf("-->[2] ANSWER OF PRODUCT");
                    gotoxy(75,13);printf("-->[3] ANSWER OF FACTORIAL");
                    gotoxy(75,14);printf("ENTER THE CHOICE: ");

                    gotoxy(75+17,14);scanf("%d",&choice);
                    if(choice==1)
                    {
                        number2 = sumAns;
                    }
                    else if(choice == 2)
                    {
                        number2 = prodAns;
                    }
                    else if(choice == 3)
                    {
                        number2 = factAns;
                    }
                    float answer = division((float)number1,(float)number2);
                    fopen("ansRecord","a");

                            fprintf(record,"%s DIVIDED %f BY %f = %f\n",ctime(&t),number1,number2,answer); //adds to the log
                            fclose(record);
                      gotoxy(10,5);                                          /*code snippet for border line*/
                                        for(j=0; j<20; j++)
                                        printf("%c", 223);

                    //Bottom border line...
                                        gotoxy(10,15);
                                        for(j=0; j<=20; j++)
                                        printf("%c", 223);

                    //Left and Right border line...
                                        for(j=0; j<10; j++)
                                        {
                                            gotoxy(10,5+j);
                                            printf("%c",219);

                                            gotoxy(30,5+j);
                                            printf("%c",219);
                                        }
                                        printf("\n");

                                        gotoxy(17,7);printf("ANSWER ");

                                        gotoxy(17,10);printf("%f\n\n\n\n\n\n\n\n",answer);
                                        gotoxy(17,19);printf("PROCESS SUCCESFULLY COMPLETED DIVIDE ANOTHER COUPLE OF NUMBERS??[yes/no ]: ");
                                        char Opt[100];
                                        gotoxy(17+78,19);scanf("%s",Opt);
                                        if(!strcmp(Opt,"yes"))
                                        {
                                            goto l3;

                                        }
                                        else if(!strcmp(Opt,"no"))
                                        {
                                            system("cls");
                                            goto l1;
                                            break;


                                        }
                                         break;

                }
                else if(!strcmp(option,"3") || !strcmp(option,"three"))
                {
                    system("cls");
                    gotoxy(75,10);printf("ENTER THE DIVEDEND: ");
                    gotoxy(75+(72-43),10);scanf("%f",&number1);
                    gotoxy(75,11);printf("ENTER THE DIVISOR: ");
                    gotoxy(103,11);scanf("%f",&number2);
                    double ans = division(number1,number2);
                    fopen("ansRecord","a");

                            fprintf(record,"%s DIVIDED %f BY %f = %f\n",ctime(&t),number1,number2,ans);
                            fclose(record);
                    gotoxy(10,5);                                          /*code snippet for border line*/
                                        for(j=0; j<20; j++)
                                        printf("%c", 223);

                    //Bottom border line...
                                        gotoxy(10,15);
                                        for(j=0; j<=20; j++)
                                        printf("%c", 223);

                    //Left and Right border line...
                                        for(j=0; j<10; j++)
                                        {
                                            gotoxy(10,5+j);
                                            printf("%c",219);

                                            gotoxy(30,5+j);
                                            printf("%c",219);
                                        }
                                        printf("\n");

                                        gotoxy(17,7);printf("ANSWER ");

                                        gotoxy(17,10);printf("%f\n\n\n\n\n\n\n\n",ans);
                                        gotoxy(17,19);printf("PROCESS SUCCESFULLY COMPLETED DIVIDE ANOTHER COUPLE OF NUMBERS??[type yes/no]: ");
                                        char Opt[100];
                                        gotoxy(17,20);scanf("%s",Opt);
                                        if(!strcmp(Opt,"yes") )
                                        {
                                               goto l3;

                                        }
                                        else if(!strcmp(Opt,"no"))
                                           {
                                               goto l1;
                                               break;
                                           }
                                           break;








                }




                }
                }




                    case 4:
                            count++;
                        {

                            system("graphfofx.exe");  //includegraphfofx.exe file for graphing

                            goto l1;
                            break;

                        }

                        case 5:
                            count++;
                            {
                                system("cls");
                                gotoxy(75,10);printf("===============TIP OF THE DAY==========");
                                gotoxy(75,11);printf("A PROBLEM A DAY KEEPS 'F' GRADE AWAY..!!");
                                gotoxy(75,12);printf("please wait application is loading......");
                                delay(5000);
                                system("cls");
                                l5:
                                    {
                                        system("cls");
                                        gotoxy(75,10);printf("**YOU HAVE ENTERED TO CALCULATE FACTORIAL**");
                                        gotoxy(75,11);printf("ENTER THE NUMBER FOR WHICH YOU WANT TO FIND THE FACTORIAL");
                                        int n;
                                        gotoxy(148,11);scanf("%d",&n);
                                      gotoxy(10,5);
                                        for(j=0; j<20; j++)
                                        printf("%c", 223);

                   //Bottom border line...
                                        gotoxy(10,15);
                                        for(j=0; j<=20; j++)
                                        printf("%c", 223);

                    //Left and Right border line...
                                        for(j=0; j<10; j++)
                                        {
                                            gotoxy(10,5+j);
                                            printf("%c",219);

                                            gotoxy(30,5+j);
                                            printf("%c",219);
                                        }
                                        printf("\n");

                                        gotoxy(17,7);printf("ANSWER ");
                                        factAns=fact(n);
                                        fopen("ansRecord","a");

                                        fprintf(record,"%s FACTORIAL OF %d = %ld\n",ctime(&t),n,factAns);
                                        fclose(record);
                                        gotoxy(17,10);printf("%ld\n\n\n\n\n\n\n\n",factAns);
                                        gotoxy(17,19);printf("TASK SUCCESFULLY COMPLETED \nDO YOU WANT TO MULTIPLY ANOTHER SET NUMBERS??[1-FOR YES 0-FOR NO]");
                                        gotoxy(67,20);scanf("%d",&option);
                                        if(option == 1)
                                        {
                                            goto l5;
                                        }
                                        else if(option == 0)
                                        {
                                            system("cls");
                                            goto l1;
                                            break;
                                        }
                                    }
                            }
                        case 6:
                            count++;
                            {
                                system("cls");
                                gotoxy(75,10);printf(":::::::::::::::::::: HELP FOR UPGRADING ::::::::::::::::::::::::");
                                gotoxy(75,11);printf("AVOID COMPARISION SO THAT YOU WILL KNOW YOUR MAXIMUM AND MINIMUM");
                                gotoxy(75,13);printf("Please wait your application is loading........");
                                delay(5000);
                                system("cls");
                                l6:
                                    {
                                        system("cls");
                                       gotoxy(75,10); printf("THIS APPLICATION CAN INTEGRATE FOR :-");
                                       gotoxy(75,11);printf("[1] EQUATIONS WITH ONE VARAIBLE HIGHEST DEGREE OF FOUR");
                                       gotoxy(75,12);printf("[2] SINE FUNCTION");
                                       gotoxy(75,13);printf("[3] COSINE FUNCTION");
                                       gotoxy(75,14);printf("[4] TANGENT FUNCTION");
                                       gotoxy(75,15);printf("ENTER YOUR CHOICE: ");
                                       gotoxy(75+19,15);scanf("%d",&option);
                                       double ans,a,b,c,d,e,A,x,B,sum=0;int n=100,i;char decision[100]; //a,b,c,d,e represents variable for coeff. of X^4,X^3,X^2,X^1,constant, A represents initial limit, B represents final limit,n represents no.of divisions(more divisions more accuracy)
                                       switch(option)
                                       {
                                            case 1:
                                                {
                                                    system("cls");
                                                    gotoxy(75,13);printf("ENTER COEFFECIENT OF X^4(if none enter '0'): ");
                                                    gotoxy(120,13);scanf("%lf",&a);
                                                    gotoxy(75,14);printf("ENTER COEFFICIENT OF X^3(if none enter '0'): ");
                                                    gotoxy(120,14);scanf("%lf",&b);
                                                    gotoxy(75,15);printf("ENTER COEFFICIENT OF X^2(if none enter '0'): ");
                                                    gotoxy(120,15);scanf("%lf",&c);
                                                    gotoxy(75,16);printf("ENTER COEFFICIENT OF X(if none enter '0'): ");
                                                    gotoxy(120,16);scanf("%lf",&d);
                                                    gotoxy(75,17);printf("ENTER VALUE OF CONSTANT(if none enter '0'): ");
                                                    gotoxy(120,17);scanf("%lf",&e);



                                                    gotoxy(75,19);printf("Enter the initial limit: ");
                                                    gotoxy(100,19);scanf("%lf",&A);
                                                    gotoxy(75,20);printf("Enter the final limit: ");
                                                    gotoxy(75+23,20);scanf("%lf",&B);
                                                                                                /*Begining Simpson's Procedure: */

                                                 float h=fabs(B-A)/n;
                                                  for(i=1;i<n;i++){
                                                    x=A+i*h;
                                                    if(i%2==0){
                                                      sum=sum+2*f(x,a,b,c,d,e,1);
                                                    }
                                                    else{
                                                      sum=sum+4*f(x,a,b,c,d,e,1);
                                                    }
                                                  }
                                                  double integral=(h/3)*(f(A,a,b,c,d,e,1)+f(B,a,b,c,d,e,1)+sum);
                                                  fopen("ansRecord","a");

                                                    fprintf(record,"%s INTEGRATION FOR X =%lf IS %lf\n",ctime(&t),x,integral); //adds to log
                                                    fclose(record);
                                                  system("cls");

                                                 gotoxy(75,10); printf("%lf",integral);
                                                 gotoxy(75,12);printf("TASK SUCCESSFULLY COMPLETED..DO YOU WANT TO INTEGRATE ANOTHER F(X)??(type 'yes' or 'no') :");
                                                 gotoxy(75,13);scanf("%s",decision);

                                                 if(!(strcmp(decision,"yes")) || !(strcmp(decision,"YES")))
                                                 {

                                                     goto l6;


                                                 }
                                                 else if(!(strcmp(decision,"no")) || !(strcmp(decision,"NO")))
                                                 {

                                                     goto l1;

                                                 }
                                                 break;
                                            case 2:
                                                {
                                                   system("cls");
                                                   gotoxy(75,10);printf("ENTER MULTIPLE OF DEGREE FOR WHICH YOU NEED TO FIND ANSWER: ");
                                                   gotoxy(136,10);scanf("%lf",&a);

                                                   gotoxy(75,12);printf("ENTER LOWER LIMIT: ");
                                                   gotoxy(75+19,12);scanf("%lf",&A);
                                                   gotoxy(75,13);printf("ENTER UPPER LIMIT: ");
                                                   gotoxy(75+19,13);scanf("%lf",&B);
                                                    float h=fabs(B-A)/n;
                                                  for(i=1;i<n;i++){
                                                    x=A+i*h;
                                                    if(i%2==0){
                                                      sum=sum+2*f(x,a,0,0,0,0,2);
                                                    }
                                                    else{
                                                      sum=sum+4*f(x,a,0,0,0,0,2);
                                                    }
                                                  }
                                                  double integral=(h/3)*(f(A,a,0,0,0,0,2)+f(B,a,0,0,0,0,2)+sum);
                                                  fopen("ansRecord","a");

                                                    fprintf(record,"%s INTEGRATION FOR X =%lf IS %lf\n",ctime(&t),x,integral);
                                                    fclose(record);
                                                  system("cls");

                                                 gotoxy(75,10); printf("%f",integral);
                                                  gotoxy(75,12);printf("TASK SUCCESSFULLY COMPLETED..DO YOU WANT TO INTEGRATE ANOTHER F(X)??(type 'yes' or 'no') :");
                                                 gotoxy(75,13);scanf("%s",decision);

                                                 if(!(strcmp(decision,"yes")) || !(strcmp(decision,"YES")))
                                                 {

                                                     goto l6;


                                                 }
                                                 else if(!(strcmp(decision,"no")) || !(strcmp(decision,"NO")))
                                                 {

                                                     goto l1;

                                                 }
                                                 break;
                                                }
                                            case 3:
                                                {
                                                    system("cls");
                                                   gotoxy(75,10);printf("ENTER MULTIPLE OF DEGREE FOR WHICH YOU NEED TO FIND ANSWER: "); //Im passing the value of radian to 'a' because it reduces code complexity
                                                   gotoxy(136,10);scanf("%lf",&a);

                                                   gotoxy(75,12);printf("ENTER LOWER LIMIT: ");
                                                   gotoxy(75+19,12);scanf("%lf",&A);
                                                   gotoxy(75,13);printf("ENTER UPPER LIMIT: ");
                                                   gotoxy(75+19,13);scanf("%lf",&B);
                                                    float h=fabs(B-A)/n;
                                                  for(i=1;i<n;i++){
                                                    x=A+i*h;
                                                    if(i%2==0){
                                                      sum=sum+2*f(x,a,0,0,0,0,3);
                                                    }
                                                    else{
                                                      sum=sum+4*f(x,a,0,0,0,0,3);
                                                    }
                                                  }
                                                  double integral=(h/3)*(f(A,a,0,0,0,0,3)+f(B,a,0,0,0,0,3)+sum);
                                                  fopen("ansRecord","a");

                                                    fprintf(record,"%s INTEGRATION FOR X =%lf IS %lf\n",ctime(&t),x,integral);
                                                    fclose(record);
                                                  system("cls");

                                                 gotoxy(75,10); printf("%f",integral);
                                                  gotoxy(75,12);printf("TASK SUCCESSFULLY COMPLETED..DO YOU WANT TO INTEGRATE ANOTHER F(X)??(type 'yes' or 'no') :");
                                                 gotoxy(75,13);scanf("%s",decision);

                                                 if(!(strcmp(decision,"yes")) || !(strcmp(decision,"YES")))
                                                 {

                                                     goto l6;


                                                 }
                                                 else if(!(strcmp(decision,"no")) || !(strcmp(decision,"NO")))
                                                 {

                                                     goto l1;

                                                 }
                                                 break;
                                                }


                                                }


                                                }


                                                }

                                       }




                                            case 7:
                                                {
                                                    if(count == 0 )
                                                    {
                                                        system("cls");
                                                        gotoxy(55,10);printf("YOU HAVENT PERFORMED ANY OPERATION DO YOU WANT TO GO BACK TO MAIN SCREEN..?(type yes/no(typing no closes program)");
                                                        char goBackorExit[100];
                                                        scanf("%s",goBackorExit);
                                                        if(!strcmp(goBackorExit,"yes"))
                                                        {
                                                            goto l1;
                                                        }
                                                        else if(!strcmp(goBackorExit,"no"))
                                                        {
                                                            exit(0);
                                                        }
                                                    }
                                                    else
                                                    {
                                                        char c;
                                                        system("cls");
                                                        record = fopen("ansRecord","r");      /*coding part for printing the log from  the file "ansRecord"*/
                                                        while(c != EOF)
                                                        {

                                                            printf("%c",c);
                                                            c = fgetc(record);
                                                        }



                                                    }//application ends...



                                                    }
                                                }
                            }







