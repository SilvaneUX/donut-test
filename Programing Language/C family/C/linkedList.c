// Write a program to create a singly linked list of integers. Add an integer and delete an integer from the list and display the contents on the screen.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

// required for Position
int getCurrSize(struct Node *node)
{
  int size = 0;

  while (node != NULL)
  {
    node = node->next;
    size++;
  }
  return size;
}

// function to insert after nth node
void insertPosition(int pos, int data, struct Node **head)
{
  int size = getCurrSize(*head);

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  // Can't insert if position to insert is greater than size of Linked List
  // can insert after negative pos
  if (pos < 0 || pos > size)
    printf("Invalid position to insert\n");

  // inserting first node
  else if (pos == 0)
  {
    newNode->next = *head;
    *head = newNode;
  }

  else
  {
    // temp used to traverse the Linked List
    struct Node *temp = *head;

    // traverse till the nth node
    while (--pos)
      temp = temp->next;

    // assign newNode's next to nth node's next
    newNode->next = temp->next;
    // assign nth node's next to this new node
    temp->next = newNode;
  }
}

// to delete nth node
void deletePosition(struct Node **head, int pos)
{
  struct Node *temp = *head;
  struct Node *previous;

  // if the head node itself needs to be deleted
  int size = getCurrSize(*head);

  // not valid
  if (pos < 1 || pos > size)
  {
    printf("Enter valid position\n");
    return;
  }

  // traverse to the nth node
  while (--pos)
  {
    // store previous link node as we need to change its next val
    previous = temp;
    temp = temp->next;
  }
  // change previous node's next node to nth node's next node
  previous->next = temp->next;
  // delete this nth node
  free(temp);
}

void display(struct Node *node)
{
  // as linked list will end when Node is Null
  while (node != NULL)
  {
    printf("DATA = %d\n ", node->data);
    node = node->next;
  }
  printf("\n");
}

int main()
{ // declare variables
  struct Node *head = NULL;
  int n, pos, data, i = 0, t;
  // taking total number of nodes as input
  printf(" Input number of nodes : ");
  scanf("%d", &t);

  // taking input in each node using loop
  for (i = 0; i < t; i++)
  {
    printf(" Input data for node %d : ", i + 1);
    scanf("%d", &data);
    insertPosition(i, data, &head);
  }
  printf("\n");
  // printing the List
  display(head);
  printf("\n");
  // delete nth node
  printf("Enter the position of Node to delete: ");
  scanf("%d", &n);
  deletePosition(&head, n);
  // printing the List
  printf("\n");
  display(head);
  return 0;
}