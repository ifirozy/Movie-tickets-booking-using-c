#include<stdio.h>
#include<stdlib.h>

int login()
{
    int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="rimjhim";
    char pass[10]="rimjhim";
    do
    {

        printf("\n  ++++++++++++++++++++++++++++++  LOGIN FIRST  ++++++++++++++++++++++++++++++  ");
        printf(" \n\n                  ENTER USERNAME:-");
        scanf("%s", &uname);
        printf(" \n\n                  ENTER PASSWORD:-");
        while(i<10)
        {
            pword[i]=getch();
            c=pword[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        pword[i]='\0';

        i=0;

        if(strcmp(uname,"rimjhim")==0 && strcmp(pword,"rimjhim")==0)
        {
            printf("  \n\n\n       WELCOME TO OUR BOOKING SYSTEM !!!! LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch();
            break;
        }
        else
        {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;

            getch();

        }
    }
    while(a<=2);
    if (a>2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");

        getch();

    }


}




struct movie
{
    char code[05];
    char name[30];
    char date[10];
    int cost;


} m;

int seat = 50 ;

int inserted_movie();
int view();
int find();
int book_ticket();
int view_booker();


int main()

    {
        login();
        int ch;
        do
        {
            printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
            printf("\n");
            printf("\t Moive Ticket booking ");
            printf("\n");
            printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

            printf("\nEnter >1< To Insert Movie");
            printf("\nEnter >2< To View All Movie");
            printf("\nEnter >3< To Find Movie ");
            printf("\nEnter >4< To Book Tickets");
            printf("\nEnter >5< To View All Transactions");
            printf("\nEnter >0< To Exit ");

            printf("\nEnter your Choice ::");
            scanf("%d",&ch);


            switch (ch)
            {
            case 1 :
                inserted_movie();
                break;
            case 2:
                view();
                break;

            case 3:
                find();
                break;

            case 4:
                book_ticket();
                break;

            case 5:
                view_booker();
                break;

            case 0:
                exit(0);
                break;

            default:
                printf("Wrong choice !");
                break;
            }
        }
        while(ch!=0);





    }









    int inserted_movie()

    {


        FILE *fp;
        struct movie m;
        printf("Enter movie code :- ");
        scanf("%s",m.code);
        printf("Enter  name :- ");
        scanf("%s",m.name);
        printf("Enter Release Date:- ");
        scanf("%s",m.date);
        printf("Enter Ticket Price:- ");
        scanf("%d",&m.cost);

        fp=fopen("inserted movie.txt","a");

        if(fp == NULL)
        {
            printf("FIlE not Found");
        }
        else
        {
            fprintf(fp,"%s %s %s %d \n",m.code,m.name,m.date,m.cost);
            printf("Recorded Successfully");
        }
        printf("\n");
        fclose(fp);


    }


    int view()

    {

        char ch;
        FILE *fp;

        fp = fopen("inserted movie.txt","r");
        if(fp == NULL)
        {
            printf("file does not found !");
            exit(1);

        }
        else
        {

            while( ( ch = fgetc(fp) ) != EOF )
                printf("%c",ch);

        }

        fclose(fp);

    }

    int find()

    {
        struct movie m;
        FILE *fp;

        char ch[05];
        printf("Enter movie code :");
        scanf("%s",ch);

        fp = fopen("inserted movie.txt","r");
        if(fp == NULL)
        {
            printf("file does not found !");
            exit(1);

        }
        else
        {
            do
            {
                fscanf(fp,"%s %s %s %d",m.code,m.name,m.date,&m.cost);
                if(strcmp(m.code,ch) == 0)
                {

                    printf("\n Record Found\n");
                    printf("\n\t\tCode ::%s",m.code);
                    printf("\n\t\tmovie name ::%s",m.name);
                    printf("\n\t\tmovie date ::%s",m.date);
                    printf("\n\t\tprice of ticket ::%d",m.cost);

                }

            }while(getc(fp) != EOF);


        }

        fclose(fp);


    }


    int book_ticket()

    {
        struct movie m;
        FILE *fp;

        FILE *ufp;

        int total_seat,mobile,total_amount;
        char name[30];


        char ch;
        char movie_code[05];


        fp = fopen("inserted movie.txt","r");
        if(fp == NULL)
        {
            printf("file does not found !");
            exit(1);

        }
        else
        {

            while( ( ch = fgetc(fp) ) != EOF )
                printf("%c",ch);

        }
        fclose(fp);


        printf("\n For Book ticket (Enter Movie Code )\n");
        printf("\n Enter movie code :");
        scanf("%s",movie_code);

        fp = fopen("inserted movie.txt","r");
        if(fp == NULL)
        {
            printf("file does not found !");
            exit(1);

        }
        else
        {
            do
            {
                fscanf(fp,"%s %s %s %d",m.code,m.name,m.date,&m.cost);
                if(strcmp(m.code,movie_code) == 0)
                {

                    printf("\n Record Found\n");
                    printf("\n\t\tCode ::%s",m.code);
                    printf("\n\t\tMovie name ::%s",m.name);
                    printf("\n\t\tdate name ::%s",m.date);
                    printf("\n\t\tPrice of ticket::%d",m.cost);
                    break;
                }
            }while(getc(fp) != EOF);


        }
        printf("\n* Fill Deatails  *");
        printf("\n your name :");
        scanf("%s",name);
        printf("\n mobile number :");
        scanf("%d",&mobile);
        printf("\n Total number of tickets :");
        scanf("%d",&total_seat);


        total_amount = m.cost * total_seat;

        printf("\n ENJOY MOVIE \n");
        printf("\n\t\tname : %s",name);
        printf("\n\t\tmobile Number : %d",mobile);
        printf("\n\t\tmovie name : %s",m.name);
        printf("\n\t\tTotal seats : %d",total_seat);
        printf("\n\t\tcost per ticket : %d",m.cost);
        printf("\n\t\tTotal Amount : %d",total_amount);


        ufp=fopen("ticket bookers.txt","a");
        if(ufp == NULL)
        {
            printf("FIle not Found");
        }
        else
        {
            fprintf(ufp,"%s %d %d %d %s %d \n",name,mobile,total_seat,total_amount,m.name,m.cost);
            printf("\n Record insert Sucessfull to the ticket bookers file");
        }
        printf("\n");
        fclose(ufp);
        fclose(fp);

    }

    int view_booker()


    {
        char ch;
        FILE *fp;


        fp = fopen("ticket bookers.txt","r");
        if(fp == NULL)
        {
            printf("file does not found !");
            exit(1);

        }
        else
        {


            while( ( ch = fgetc(fp) ) != EOF )
                printf("%c",ch);

        }
        fclose(fp);


    }






