#include<stdio.h>     //to include printf,scanf
#include<stdlib.h>    //to include calloc,free
struct SLLNode
{
  int data;
  struct SLLNode *Next;
};
void menu(void);
void create(struct SLLNode *head,struct SLLNode *last,int n);
void displaydata(struct SLLNode *head);
void displayReverse(struct SLLNode *last,struct SLLNode *head,int n);
void insertPrepend(struct SLLNode *head,struct SLLNode *last,int insData);
void insertAppend(struct SLLNode *head,struct SLLNode *last,int insData);
void insertBetween(struct SLLNode *head,struct SLLNode *last,int insData,int find);
void deletefirst(struct SLLNode *head,struct SLLNode *last);
void deleteLast(struct SLLNode *head,struct SLLNode *last);
void deleteBetween(struct SLLNode *head,struct SLLNode *last,int insData);
int maxNodes(struct SLLNode *head);
void reverseData(struct SLLNode *head,struct SLLNode *last,int n);
void reverseNode(struct SLLNode *head,struct SLLNode *last);
void exitPro(struct SLLNode *head,struct SLLNode *last);
int main(void)
{
    struct SLLNode *NewNode = NULL;
    struct SLLNode *head = NULL;
    struct SLLNode *last = NULL;

    int insData = 0;                      //data to insert
    int n = 0;                            //number of nodes
    int choice = 0;                       //choice from menu
    int max = 0;                          //maximum number of nodes
    int find = 0;
    printf("\nEnter number of nodes: ");
    scanf("%d",&n);
    if(n<0)
    {
      printf("\nNumber should be greater than 0,enter number again");
      scanf("%d",&n);
    }
    else
    {
      create(head,last,n);
    }
    do
    {
      void menu(void);
      printf("\nEnter choice : ");
      scanf("%d",&choice);
      switch (choice)
      {
      case 1:
        create(head,last,n);
        break;

      case 2:
        printf("\nEnter data to insert at head : ");
        scanf("%d",&insData);
        insertPrepend(head,last,insData);
        break;

      case 3:
        printf("\nEnter data to insert data at last : ");
        scanf("%d",&insData);
        insertAppend(head,last,insData);
        break;

      case 4:
        printf("\nEnter data to insert in between : ");
        scanf("%d",&insData);
        printf("Enter data after which you want to add data : ");
        scanf("%d",&find);
        insertBetween(head,last, insData,find);
        break;

      case 5:
        deletefirst(head,last);
        break;

      case 6:
        deleteLast(head,last);
        break;

      case 7:
        printf("\nEnter data you want to delete : ");
        scanf("%d",&insData);
        deleteBetween(head,last,insData);
        break;
      case 8:
        displaydata(head);
        break;

      case 9:
        displayReverse(last,head,n);
        break;

      case 10:
        reverseData(head,last,n);
        break;

      case 11:
        reverseNode(head,last);
        break;

      case 12:
        max = maxNodes(head);
        printf("\nMaximum data from the nodes is  : %d",max);
        reverseNode(head,last);
        break;
      case 0:
        exitPro(head,last);
        break;
      default:
        break;
      }

    } while (choice!=0);
    
    void menu(void);
  return 0;
}
void menu(void)
{
    printf("1. Create\n");
    printf("2. Insert node - prepend\n");
    printf("3. Insert node - last\n");
    printf("4. Insert node - in between\n");
    printf("5. Delete node - first\n");
    printf("6. Delete node - last\n");
    printf("7. Delete node - in between\n");
    printf("8. Display linked list data\n");
    printf("9. Display linked list in reverse\n");
    printf("10. Reverse linked list - data\n");
    printf("11. Reverse linked list - nodes\n");
    printf("12. Maximum number in linked list node\n");
    printf("0. Exit\n");
    printf("\n-----------------------------------------------------------------");
}
void create(struct SLLNode *head,struct SLLNode *last,int n)
{
    struct SLLNode *Newnode = NULL;
    int num = 0;          //number in data of linked list
    int i = 0;            //loop variable
    Newnode = (struct SLLNode *)calloc(n,sizeof(struct SLLNode));
    for(i = 0;i<n ; i++)
    {
      printf("\nEnter data: ");
      scanf("%d",&num);
      Newnode->data = num;
      if(Newnode==NULL)
      {
        printf("\nMemory allocation not possible");
      }
      else
      {
        if(head==NULL)
        {
          head = Newnode;
          last = Newnode;
        }
        else
        {
          last->Next = Newnode;
          last = Newnode;
        }
      }
    }
}
void displaydata(struct SLLNode *head)
{
    struct SLLNode *i = NULL;
     i = head;
    while(i!=NULL)
    {
      printf("%d",i->data);
      i = i->Next;
    }
}
void displayReverse(struct SLLNode *last,struct SLLNode *head,int n)
{
    struct SLLNode *i = NULL;
    int j = 0;                //loop variable for array
    int arr[n] ;         //to store elements of linked list

    i = head;
    while(i!=NULL)
    {
      arr[j] = i->data;
      i = i->Next;
      j++;  
    }
    printf("Data in reverse order : \n");
    j = j - 1;
    while(j>=0)
    {
      printf("%d\t",arr[j]);
       j = j - 1;
    }        
}
void insertPrepend(struct SLLNode *head,struct SLLNode *last,int insData)
{
    struct SLLNode *NewNode = NULL;
    NewNode = (struct SLLNode *)calloc(1, sizeof(struct SLLNode));
    if(NewNode == NULL)
    {
      printf("Memory allocation failed");
    }
    else
    {
      NewNode->data = insData;
      if(head == NewNode)
      {
        head = NewNode;
        last = NewNode;
      }
      else
      {
        NewNode->Next = head;
        head = NewNode;
      }
    }
}
void insertAppend(struct SLLNode *head,struct SLLNode *last,int insData)
{
    struct SLLNode *NewNode = NULL;
    NewNode = (struct SLLNode *)calloc(1, sizeof(struct SLLNode));
    if(NewNode == NULL)
    {
      printf("Memory allocation failed");
    }
    else
    {
      NewNode->data = insData;
      if(head == NewNode)
      {
        head = NewNode;
        last = NewNode;
      }
      else
      {
        NewNode->Next = last;
        last = NewNode;
      }
    }
}
void insertBetween(struct SLLNode *head,struct SLLNode *last,int insData,int find)
{
    struct SLLNode *p = NULL;
    struct SLLNode *q = NULL;
    struct SLLNode *i = NULL;
    struct SLLNode *NewNode = NULL;
    if(NewNode==NULL)
    {
      printf("\nMemory allocation failed");
    }
    else
    {
        while(i!=NULL)
        {
          if(i->data == find)
          {
            p = i;
            q = p->Next ;
            p->Next = NewNode ;
            NewNode->Next = q ;
            i = last ;
          }
          i = i->Next;
        }
    }
}
void deletefirst(struct SLLNode *head,struct SLLNode *last)
{
    struct SLLNode *Dnode = NULL;
    if(head == NULL)
    {
      printf("\nLinked List doesn't exits");
    }
    else
    {
      Dnode = head;
      if(head == last)
      {
        head = NULL;
        last =NULL;
      }
      else
      {
        head = head->Next;
      }
      free(Dnode);
      Dnode = NULL;
    }
}
void deleteLast(struct SLLNode *head,struct SLLNode *last)
{
    struct SLLNode *Dnode = NULL;
    struct SLLNode *it = NULL;
    if(last == NULL)
    {
      printf("\nLinked List doesn't exits");
    }
    else
    {
      Dnode = last;
      if(head == last)
      {
        Dnode = last;
        head = NULL;
        last =NULL;
        free(Dnode);
        Dnode = NULL;
      }
      else
      {
        it = head;
        while(it->Next != last)
        {
          it = it->Next ;
        }
        Dnode = it->Next ;
        last = it ;
        last->Next = NULL ;
        free(Dnode) ;
        Dnode = NULL ;
        it = NULL ;
      }
    }
}
void deleteBetween(struct SLLNode *head,struct SLLNode *last,int insData)
{
    struct SLLNode *id = NULL;
    struct SLLNode *Dnode = NULL;
    struct SLLNode *p = NULL;
    struct SLLNode *q = NULL;
    if (head == NULL)
    {
      Dnode = last;
      head = NULL;
      last = NULL;
      free(Dnode);
      Dnode = NULL;
    }
    else
    {
      id = head;
      while(id != NULL)
      {
        if (id->Next->data == insData)
        {
          p = id ;
          id = NULL;
        }
        else
        {
          id = id->Next ;
        }
      }
        if (p != NULL)
        {
          Dnode = p->Next ;
          q = Dnode->Next ;
          Dnode->Next = NULL ;
          p->Next = q ;
          free(Dnode) ;
          Dnode = NULL ;
          p = NULL ;
          q = NULL ;
          id = NULL ;
        }
    }

}
int maxNodes(struct SLLNode *head)
{
  int max = 0;
  struct SLLNode *i = NULL;
  i = head;
  max = head->data;
  while(i!=NULL)
  {
    if(i->data > max)
    {
      max = i->data;
    }
    i = i->Next;
  } 
  return max;
}
void reverseData(struct SLLNode *head,struct SLLNode *last,int n)
{
    struct SLLNode *i = NULL;
    int arr[n] ;
    i = head;
    while(i!=NULL)
    {
      arr[n-1] = i->data;
      i = i->Next;
      n--;
    }
}
void reverseNode(struct SLLNode *head,struct SLLNode *last)
{
  struct SLLNode *prev = NULL;
  struct SLLNode *curr = NULL;
  
    if(head != NULL)
    {
      prev = head;
      curr= head->Next;
      head = head->Next;
      prev->Next = NULL;
      while(head != NULL)
      {
        head = head->Next;
        curr->Next = prev;
        prev = curr;
        curr = head;
      }
      head = prev;
    }
}
void exitPro(struct SLLNode *head,struct SLLNode *last)
{
  struct SLLNode *i = NULL;
  struct SLLNode *Dnode = NULL;
  if(head == last)
  {
    Dnode = head;
    head = NULL;
    last = NULL;
    free(Dnode);
    Dnode = NULL;
  }
  else
  {
    i = head;
    while(i != NULL)
    {
      Dnode = i;
      i = i->Next;
      Dnode->Next = NULL;
      free(Dnode);
      Dnode = NULL;
      head = NULL;
      last = NULL;
    }
  }
}