#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
  struct node *prev;
  char name[30];
  int Rno;
  float marks;
  struct node *next;
};
struct node *head;
char arr[30];
void Create()
{
  int num;
  struct node *ptr = head;
  printf("Enter the number of students you want to register:\t");
  scanf("%d", &num);
  printf("Enter name of student 1:  ");
  scanf("%s", head->name);
  printf("Enter registration number of student 1:  ");
  scanf("%d", &head->Rno);
  printf("Enter marks of student 1:  ");
  scanf("%f", &head->marks);
  for (int i = 2; i <= num; i++)
  {
    struct node *Nnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter name of student %d: ", i);
    scanf("%s", Nnode->name);
    printf("Enter registration number of student %d: ", i);
    scanf("%d", &Nnode->Rno);
    printf("Enter marks of student %d: ", i);
    scanf("%f", &Nnode->marks);
    Nnode->next = NULL;
    Nnode->prev = ptr;
    ptr->next = Nnode;
    ptr = ptr->next;
  }
}
void display()
{
  printf("Registration number in ascending order :\n");
  struct node *ptr = head;
  while (ptr != NULL)
  {
    printf("%d\t( name: %s  ,marks:%.3f )\n", ptr->Rno, ptr->name, ptr->marks);
    ptr = ptr->next;
  }
}
void Sort(char n[])
{
  float mark = 0.0;
  int r;
  struct node *X = head;
  struct node *X2;
  for (X = head; X != NULL; X = X->next)
  {
    for (X2 = X->next; X2 != NULL; X2 = X2->next)
    {
      if (X->Rno > X2->Rno)
      {
        mark = X->marks;
        r = X->Rno;
        strcpy(n, X->name);
        X->marks = X2->marks;
        X->Rno = X2->Rno;
        strcpy(X->name, X2->name);
        X2->marks = mark;
        X2->Rno = r;
        strcpy(X2->name, n);
      }
    }
  }
  display();
}
int main()
{

  head = (struct node *)malloc(sizeof(struct node));
  printf("1.To create list.\n2.To sort list.\n3.To exit program.\n");
  int choice = 0;
  while (choice != 3)
  {
    printf("Enter your choice:\t");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      Create();
      break;
    case 2:
      Sort(arr);
      break;
    case 3:
      exit(0);
      break;
    default:
      printf("Enter option between 1-3 \n");
    }
  }
  return 0;
}
