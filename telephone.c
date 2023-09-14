#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    char name[30];
    char city[50];
    char state[50];
    long long int mble_no;
    char sex[8];
    char mail[100];
};
typedef struct person person; // Creating a data type for the structure

// prototypes of all the Functions used

void remove_all();
void print_menu();
void add_person();
void start();
void list_record();
void search_person();
void remove_person();
void update_person();
void take_input(person *p);

// Main Fuction
int main()
{
    start(); // int main calling start() Function
    return 0;
}

// This function will start our program.
void start()
{
    int choice;
    while (1) // The loop continues till break is not encountered

    {

        print_menu();
        scanf("%d", &choice);

        switch (choice) // Switch case for performing different conditions

        {

        case 1:
            list_record();
            getchar();
            getchar();
            break;

        case 2:
            add_person();
            getchar();
            getchar();
            break;

        case 3:
            search_person();
            getchar();
            getchar();
            break;

        case 4:
            remove_person();
            getchar();
            getchar();
            break;

        case 5:
            update_person();
            getchar();
            getchar();
            break;

        case 6:
            remove_all();
            getchar();
            getchar();
            break;

        default:
            printf("Thanks for using Telephone Directory visit again : )\n");
            getchar();
            getchar();
            exit(1);
        }
    }
}

// This will print main menu.
void print_menu()
{
    printf("\t\t__________Welcome TO Telephone Directory_______\n\n");

    printf("\t\t\t1) Show record\n\n");

    printf("\t\t\t2) Add person\n\n");

    printf("\t\t\t3) Search person Details\n\n");

    printf("\t\t\t4) Remove person\n\n");

    printf("\t\t\t5) Update person\n\n");

    printf("\t\t\t6) Delete all person's Details\n\n");

    printf("\t\t\t7) Exit Telephone Directory \n\n\n");

    printf("\t\t\t\tEnter your Choice : ");
}

// This function will add contact into Telephone Directory.
void add_person()

{

    FILE *fp;
    fp = fopen("telephone_db", "ab+");

    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        take_input(&p);
        fwrite(&p, sizeof(p), 1, fp);
        fflush(stdin);
        fclose(fp);
        printf("Record added Successfully\n");
        printf("Press any key to continue ....\n");
    }
}

// By this we take contact information.
void take_input(person *p)

{

    int tem = -1;

    getchar();
    printf("Enter name : ");
    scanf("%[^\n]s", p->name); // Here we are using scanset '^' - >  until get

    printf("Enter city : ");
    scanf("%s", p->city);

    getchar();
    printf("Enter state : ");
    scanf("%[^\n]s", p->state);

z:
    printf("Enter mobile no : ");
    scanf("%lld", &p->mble_no);
    if ((p->mble_no) < 1000000000 || (p->mble_no) > 10000000000)

    {

        printf("Wrong Input The Mobile Number is not of 10 Digit \n");
        goto z; // goto is used if the mobile number is not of 10 digits
    }

    printf("Enter sex : ");
    scanf("%s", p->sex);

    printf("Enter e-mail : ");
    scanf("%s", p->mail);
}

// This function will list contact available in Telephone Directory.
void list_record()
{
    FILE *fp;
    fp = fopen("telephone_db", "rb");

    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        printf("\t\t__________Welcome TO Telephone Directory__________\n");
        printf("  NAME\t\t            CITY\t\t             STATE\t\t             PHONE NO\t\t             SEX\t\t             EMAIL\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

        while (fread(&p, sizeof(p), 1, fp) == 1)
        {

            int i;
            int len1 = 26 - strlen(p.name);
            int len2 = 30 - strlen(p.city);
            int len5 = 34 - strlen(p.state);
            int len3 = 23;
            int len4 = 26 - strlen(p.sex);

            printf("  %s", p.name);
            for (i = 0; i < len1; i++)
                printf(" ");

            printf("%s", p.city);
            for (i = 0; i < len2; i++)
                printf(" ");

            printf("%s", p.state);
            for (i = 0; i < len5; i++)
                printf(" ");

            printf("%lld", p.mble_no);
            for (i = 0; i < len3; i++)
                printf(" ");

            printf("%s", p.sex);
            for (i = 0; i < len4; i++)
                printf(" ");

            printf("%s", p.mail);
            printf("\n");

            fflush(stdin);
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue....\n");
    }
}

// This function will search contact in Telephone Directory.
void search_person()
{
    long long int phone;
    printf("Enter Phone number of the person you want to search : ");
    scanf("%lld", &phone);

    FILE *fp;
    fp = fopen("telephone_db", "rb");

    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        int flag = 0;
        person p;

        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (p.mble_no == phone)
            {
                printf("  NAME\t\t\t\t   city\t\t    state\t\t    PHONE NO\t\t    SEX\t\t             EMAIL\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");

                int i;
                int len1 = 40 - strlen(p.name);
                int len2 = 19 - strlen(p.city);
                int len5 = 19 - strlen(p.state);
                int len3 = 15;
                int len4 = 21 - strlen(p.sex);

                printf("%s", p.name);
                for (i = 0; i < len1; i++)
                    printf(" ");

                printf("%s", p.city);
                for (i = 0; i < len2; i++)
                    printf(" ");

                printf("%s", p.state);
                for (i = 0; i < len5; i++)
                    printf(" ");

                printf("%lld", p.mble_no);
                for (i = 0; i < len3; i++)
                    printf(" ");

                printf("%s", p.sex);
                for (i = 0; i < len4; i++)
                    printf(" ");

                printf("%s", p.mail);
                printf("\n");
                flag = 1;
                break;
            }
            else
                continue;
        }
        if (flag == 0) // if the entered Number is not found

            printf("Person is not in the Telephone Directory\n");

        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue....\n");
    }
}

// This function will remove contact from Telephone Directory.
void remove_person()
{
    long long int phone;
    printf("Enter Phone number of the person you want to remove from Telephone Directory : ");
    scanf("%lld", &phone);
    FILE *fp, *temp;
    fp = fopen("telephone_db", "rb");
    temp = fopen("temp", "wb+");

    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        int flag = 0;

        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (p.mble_no == phone)
            {
                printf("Person removed successfully\n");
                flag = 1;
            }
            else
                fwrite(&p, sizeof(p), 1, temp);
            fflush(stdin);
        }
        if (flag == 0)
        {
            printf("No record found for %d number\n", phone);
        }

        fclose(fp);
        fclose(temp);
        remove("telephone_db");
        rename("temp", "telephone_db");
        fflush(stdin);
        printf("Press any key to continue....\n");
    }
}

// This function will update contact information.
void update_person()
{
    long long int phone;
    printf("Enter Phone number of the person you want to update details : ");
    scanf("%lld", &phone);

    FILE *fp, *temp;
    fp = fopen("telephone_db", "rb");
    temp = fopen("temp", "wb+");

    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        int flag = 0;
        person p;

        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (p.mble_no == phone)
            {
                take_input(&p);
                fwrite(&p, sizeof(p), 1, temp);
                printf("Data updated successfully\n");
                flag = 1;
            }
            else
                fwrite(&p, sizeof(p), 1, temp);

            fflush(stdin);
        }

        if (flag == 0)

            printf("No record found for %d number\n", phone);

        fclose(fp);
        fclose(temp);
        remove("telephone_db");
        rename("temp", "telephone_db");
        fflush(stdin);
        printf("Press any key to continue....\n");
    }
}

// This function will clear all the data in the Telephone Directory.
void remove_all()
{

    remove("./telephone_db");
    printf("All data in the Telephone Directory successfully\n");
    printf("Press any key to continue ... \n");
}