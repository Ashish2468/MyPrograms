#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
  struct node *prev;
  char name[30];
  int reg_no;
  float marks;
  struct node *next;
};
struct node *head;
char arr[30];
void create_list()
{
  int num;
  struct node *ptr = head;
  printf("Enter the number of students you want to register:\t");
  scanf("%d", &num);
  printf("Enter name of student 1:  ");
  scanf("%s", head->name);
  printf("Enter registration number of student 1:  ");
  scanf("%d", &head->reg_no);
  printf("Enter marks of student 1:  ");
  scanf("%f", &head->marks);
  for (int i = 2; i <= num; i++)
  {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter name of student %d: ", i);
    scanf("%s", newnode->name);
    printf("Enter registration number of student %d: ", i);
    scanf("%d", &newnode->reg_no);
    printf("Enter marks of student %d: ", i);
    scanf("%f", &newnode->marks);
    newnode->next = NULL;
    newnode->prev = ptr;
    ptr->next = newnode;
    ptr = ptr->next;
  }
}

void display()
{
  printf("Registration number of students sorted in ascending order are:\n");
  struct node *ptr = head;
  while (ptr != NULL)
  {
    printf("%d\t( name: %s  ,marks:%.3f )\n", ptr->reg_no, ptr->name, ptr->marks);
    ptr = ptr->next;
  }
}
void sort_list(char n[])
{
  float mark = 0.0;
  int r;
  struct node *temp = head;
  struct node *temp2;
  for (temp = head; temp != NULL; temp = temp->next)
  {
    for (temp2 = temp->next; temp2 != NULL; temp2 = temp2->next)
    {
      if (temp->reg_no > temp2->reg_no)
      {
        mark = temp->marks;
        r = temp->reg_no;
        strcpy(n, temp->name);
        temp->marks = temp2->marks;
        temp->reg_no = temp2->reg_no;
        strcpy(temp->name, temp2->name);
        temp2->marks = mark;
        temp2->reg_no = r;
        strcpy(temp2->name, n);
      }
    }
  }
  display();
}
int main()
{

  head = (struct node *)malloc(sizeof(struct node));
  printf("Enter 1 to create list.\nEnter 2 to sort list.\nEnter 3 to exit program.\n");
  int choice = 0;
  while (choice != 3)
  {
    printf("Enter your choice:\t");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      create_list();
      break;
    case 2:
      sort_list(arr);
      break;
    case 3:
      exit(0);
      break;
    default:
      printf("You have entered a wrong choice\n");
    }
  }
  return 0;
}