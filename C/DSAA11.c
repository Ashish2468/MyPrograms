#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct Student
{
    char Name[100];
    int marks,Rno;
    struct Student *next;
}*head;
void input(int Rno,int marks, char* Name)
{

    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->marks=marks;
    student->Rno=Rno;
    strcpy(student->Name,Name);
    student->next = NULL;

    if(head==NULL)
    {
        head = student;
    }
    else
    {
        student->next = head;
        head = student;
    }
}
void display()
{
    struct Student * X = head;
    while(X!=NULL)
    {
        printf("Enter the Registration Number: %d\n", X->Rno);
        printf("Enter the Student name: %s\n", X->Name);
        printf("Enter the marks : %d\n", X->marks);
        X = X->next;
    }
}
void Rlowest()
    {
        struct Student * X = head;
        int Mmarks=X->marks;
        while(X!=NULL)
            {
                if(X->marks<=Mmarks)
                {
                    Mmarks=X->marks;
                }
                X = X->next;
            }
        struct Student * X1 = head;
        struct Student * X2 = head;
        while(X1!=NULL)
        {
            if(X1->marks==Mmarks)
            {
                printf("Record with min marks %d Found !!!\n",Mmarks);
                if(X1==X2)
                    {
                        head = head->next;
                        free(X1);
                    }
                else
                    {
                        X2->next = X1->next;
                        free(X1);
                    }
                printf("Record has been Deleted Successfully!\n");
                return;
            }
            X2 = X1;
            X1 = X1->next;
        }
    }

int main()
{
    head = NULL;
    int choice;
    int Rno,marks;
    char Name[100];
    printf("Choose one option :\n1.To Create a list \n2.To Delete the lowest one\n3.To Display list:");
    do
    {
        printf("\nEnter your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                    printf("Enter the Registration Number : ");
                    scanf("%d",&Rno);
                    printf("\nEnter marks : ");
                    scanf("%d",&marks);
                    printf("Enter the Student Name : ");
                    scanf("%s",Name);
                    input(Rno,marks,Name);
                    break;
            case 2:
                Rlowest();
                printf("Deleted Sucessfull");
                break;
            case 3:
                printf("Displaying the details in the list : \n");
                display();
                break;
        }

    } while (choice != 0);
return 0;
}
