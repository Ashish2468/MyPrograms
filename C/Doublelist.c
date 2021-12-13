#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  struct node *prev;
  struct node *next;
  int marks;
  int regno;
  char name[100];
  // char name[20];
  int reg, marks;
  struct student *next;
};
struct node *head;
static int node_count = 0;

void insdata()
{
  struct student *temp;
  printf("Enter name,reg,marks\n");
  scanf("%s", temp->name);
  scanf("%d", &temp->reg);
  scanf("%d", &temp->marks);
  temp->next = NULL;
  if (head == NULL)
  {
    head = temp;
    head->next = NULL;
    return;
  }
  struct student *cur;
  cur = head;
  while (cur->next != NULL)
  {
    cur = cur->next;
  }
  cur->next = temp;
  temp->next = NULL;
}

void insertion_beginning()
{
  struct node *ptr;
  int reg;
  char name[100];
  int marks;
  ptr = (struct node *)malloc(sizeof(struct node));
  if (ptr == NULL)
  {
    printf("\nOVERFLOW");
  }
  else
  {
    printf("\nEnter Registration Number : ");
    scanf("%d", &reg);
    printf("\nEnter Name : ");
    scanf("%s", name);
    printf("\nEnter marks : ");
    scanf("%d", &marks);

    if (head == NULL)
    {
      ptr->next = NULL;
      ptr->prev = NULL;
      ptr->regno = reg;
      strcpy(ptr->name, name);
      ptr->marks = marks;
      head = ptr;
    }
    else
    {
      ptr->regno = reg;
      strcpy(ptr->name, name);
      ptr->marks = marks;
      ptr->prev = NULL;
      ptr->next = head;
      head->prev = ptr;
      head = ptr;
      node_count++;
    }
    printf("\nNode inserted\n");
  }
}

void insertion_last()
{
  struct node *ptr, *temp;
  int reg;
  char name[100];
  int marks;
  ptr = (struct node *)malloc(sizeof(struct node));
  if (ptr == NULL)
  {
    printf("\nOVERFLOW");
  }
  else
  {
    printf("\nEnter Registration Number");
    scanf("%d", &reg);
    printf("\nEnter Name");
    scanf("%s", name);
    printf("\nEnter marks");
    scanf("%d", &marks);
    if (head == NULL)
    {
      ptr->next = NULL;
      ptr->prev = NULL;
      head = ptr;
      node_count++;
    }
    else
    {
      temp = head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = ptr;
      ptr->prev = temp;
      ptr->next = NULL;
      node_count++;
    }
  }
  printf("\nnode inserted\n");
}

void display()
{
  struct node *ptr;
  printf("\n printing values...\n");
  ptr = head;
  while (ptr != NULL)
  {
    printf("%d\n", ptr->regno);
    printf("%s\n", ptr->name);
    printf("%d\n", ptr->marks);
    ptr = ptr->next;
  }
}

void main()
{
  int choice = 0;
  while (choice != 9)
  {

    printf("\n1.Insert in begining\n2.Insert at last\n3.Show");
    printf("\nEnter your choice?\n");
    scanf("\n%d", &choice);
    switch (choice)
    {
    case 1:
      insertion_beginning();
      break;
    case 2:
      insertion_last();
      break;
    case 3:
      display();
      break;
      exit(0);
      break;
    default:
      printf("Please enter valid choice..");
    }
  }
}