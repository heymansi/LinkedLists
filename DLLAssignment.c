#include<stdio.h>           //includes printf,scanf
#include<stdlib.h>          //for calloc, free

struct DLLNode
{
    struct DLLNode *prev;
    int data;
    struct DLLNode *next;
};
void menu(void);
void create(struct DLLNode **fhead,struct DLLNode **flast,int data);
void display(struct DLLNode *head);
void insertHead(struct DLLNode **fhead,struct DLLNode **flast,int insData);
void insertLast(struct DLLNode **fhead,struct DLLNode **flast,int insData);
void displayReverse(struct DLLNode *head,struct DLLNode *last,int n);
void deleteHead(struct DLLNode **fhead,struct DLLNode **flast);
void deleteLast(struct DLLNode **fhead,struct DLLNode **flast);
void insertBetween(struct DLLNode **fhead,struct DLLNode **flast,int insData,int find);
void deleteBetween(struct DLLNode **fhead,struct DLLNode **flast,int find);
void reverseData(struct DLLNode *head,struct DLLNode *last,int n);
void reverseAddress(struct DLLNode *head,struct DLLNode *last);
void removeDLL(struct DLLNode *head,struct DLLNode *last);
int main(void)
{
    struct DLLNode *head = NULL;
    struct DLLNode *last = NULL;
    int n = 0;                      //number of nodes in dll
    int choice = 0;                 //to choose from 
    int insData = 0;                //data to insert
    int find = 0;                   //to insert or delete data after this node
    int data = 0;
    int i = 0;                      //loop variable
    printf("\nEnter number of nodes for DLL : ");
    scanf("%d",&n);                 //read number of nodes
    if(n<0)
    {
        printf("\nPlease enter positive number : ");
        scanf("%d",&n);
    }
    else
    {
        for(i = 0 ; i < n ; i++)
        {
            printf("\nEnter Data : ");
            scanf("%d",&data);
            create(&head,&last,data);
        }
    }
    do
    {
        menu();
        printf("\nEnter choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Data : ");
            scanf("%d",&data);
            create(&head,&last,data);
            break;

        case 2:
            display(head);
            break;

        case 3:
            displayReverse(head,last,n);
            break;

        case 4:
            printf("\nEnter Data to insert at beginning of DLL");
            scanf("%d",&insData);
            insertHead(&head,&last,insData);
            break;

        case 5:
            printf("\nEnter Data to insert at end of DLL");
            scanf("%d",&insData);
            insertLast(&head,&last,insData);
            break;

        case 6:
            printf("\nEnter data after which you want to insert : ");
            scanf("%d",&find);
            printf("\nEnter Data to insert : ");
            scanf("%d",&insData);
            insertBetween(&head,&last,insData,find);
            break;

        case 7:
            deleteHead(&head,&last);
            break;

        case 8:
            deleteLast(&head,&last);
            break;

        case 9:
            printf("\nEnter data you want to delete in between head and last node");
            scanf("%d",&find);
            deleteBetween(&head,&last,find);
            break;

        case 10:
            reverseData(head,last,n);
            break;

        case 11:
            reverseAddress(head,last);
            break;  
        
        default:
            break;
        }
    } while (choice!=0);
    
    removeDLL(head,last);
    return 0;
}
void menu(void)
{
    printf("\n***********MENU************");
    printf("\n1.Create DLL ");
    printf("\n2.Display DLL");
    printf("\n3.Display reverse DLL");
    printf("\n4.Insert data at beginning");
    printf("\n5.Insert data at end");
    printf("\n6.Insert data in between");
    printf("\n7.Delete data at beginning");
    printf("\n8.Delete data at end");
    printf("\n9.Detele data in between");
    printf("\n10.Reverse DLL by data");
    printf("\n11.Reverse DLL by address");
    printf("\n0.Exit");
    printf("\n---------------------------------------------------");
}
void create(struct DLLNode **fhead,struct DLLNode **flast,int data)
{
    struct DLLNode *Newnode = NULL;
    int i = 0;                          //loop variable
    Newnode = (struct DLLNode *)calloc(1,sizeof(struct DLLNode));
    struct DLLNode *head = NULL;
    struct DLLNode *last = NULL;
    head = *fhead;
    last = *flast;

        Newnode->data = data;
        if(Newnode==NULL)
        {
            printf("\nMemory allocation not possible");
        }
        else
        {
            if(head == NULL)
            {
                head = Newnode;
                last = Newnode;
            }
            else
            {
                last -> next = Newnode;
                Newnode->prev = last;
                last = Newnode;
            }
        }
        *fhead = head;
        *flast = last;
}
void display(struct DLLNode *head)
{
    struct DLLNode *i = NULL;
    i = head;
    if(head == NULL)
    {
        printf("\nDLL empty , nothing is display");
    }
    else
    {
        while (i!=NULL)
        {
            printf("\n%d",i->data);
            i = i->next;
        }
    }
}
void insertHead(struct DLLNode **fhead,struct DLLNode **flast,int insData)
{
    struct DLLNode *NewNode = NULL;
    NewNode = (struct DLLNode *)calloc(1,sizeof(struct DLLNode));
    struct DLLNode *head = NULL;
    struct DLLNode *last = NULL;
    head = *fhead;
    last = *flast;
    if(NewNode==NULL)
    {
        printf("\nMemory allocation failed");
    }
    else
    {
        NewNode->data = insData;
        if(head==NULL)
        {
            head = NewNode;
            last = NewNode;
        }
        else
        {
            NewNode->next = head;
            head->prev = NewNode;
            head = NewNode;
        }
    }
    *fhead = head;
    *flast = last;
}
void insertLast(struct DLLNode **fhead,struct DLLNode **flast,int insData)
{
    struct DLLNode *NewNode = NULL;
    struct DLLNode *head = NULL;
    struct DLLNode *last = NULL;
    head = *fhead;
    last = *flast;
    
    NewNode = (struct DLLNode *)calloc(1,sizeof(struct DLLNode));
    if(NewNode==NULL)
    {
        printf("\nMemory allocation failed");
    }
    else
    {
        NewNode->data = insData;
        if(head==NULL)
        {
            head = NewNode;
            last = NewNode;
        }
        else
        {
            NewNode->prev = last;
            last->next = NewNode;
            last = NewNode;
        }
    }
    *fhead = head;
    *flast = last;
}
void insertBetween(struct DLLNode **fhead,struct DLLNode **flast,int insData,int find)
{
    struct DLLNode *NewNode = NULL;
    struct DLLNode *head = NULL;
    struct DLLNode *last = NULL;
    head = *fhead;
    last = *flast;
    struct DLLNode *p = NULL;
    struct DLLNode *q = NULL;
    struct DLLNode *i = NULL;
    int flag = 0;               //to know if we find the data 

    NewNode = (struct DLLNode *)calloc(1,sizeof(struct DLLNode));
    if(NewNode == NULL)
    {
        printf("\nMemory allocation failed");
    }
    else
    {
        if(head!=NULL)
        {
            while(i!=NULL)
            {
                if(i->data == find)
                {
                    p = i;
                    q = p->next;
                    q->prev = p;
                    p->next = NewNode;
                    NewNode->prev = p;
                    NewNode->next = q;
                    q->prev = NewNode;
                    i = last;
                    flag = 1;
                }
                i = i->next;
            }
            if(flag==0)
            {
                printf("\nData after which you want to enter not found !!");
                free(NewNode);
                NewNode = NULL;

            }
        }
        else
        {
            printf("\nDLL empty");
        }
    }
    *fhead = head;
    *flast = last;
}
void displayReverse(struct DLLNode *head,struct DLLNode *last,int n)
{
    struct DLLNode *i = NULL;
    int arr[n];
    int j = 0;          //loop variable for array
    i = head;
    while(i!=NULL)
    {        
        arr[j] = i->data;
        i = i->next;
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
void deleteHead(struct DLLNode **fhead,struct DLLNode **flast)
{
    struct DLLNode *Dnode = NULL;
    struct DLLNode *head = NULL;
    struct DLLNode *last = NULL;
    head = *fhead;
    last = *flast;
    if(head == NULL)
    {
        printf("\nDLL does not exits !!");
    }
    else
    {
        Dnode = head;
        if(head == last)
        {
            head = NULL;                //Set Head & Last to NULl
            last = NULL;                // As the Linked list contains only one node
        }
        else
        {
            head = head->next;          // Set Head to Next node
            Dnode->next = NULL;         // Separate Dnode from the linked list
            head->prev = NULL;          /// Separate Dnode from the linked list
        }
        free(Dnode);
        Dnode = NULL;
    }
    *fhead = head;
    *flast = last;
}
void deleteLast(struct DLLNode **fhead,struct DLLNode **flast)
{
    struct DLLNode *Dnode = NULL;
    struct DLLNode *head = NULL;
    struct DLLNode *last = NULL;
    head = *fhead;
    last = *flast;
    if(head == NULL)
    {
        printf("\nDLL does not exits !!");
    }
    else
    {
        Dnode = last;
        if(head == last)
        {
            head = NULL;
            last = NULL;
        }
        else
        {
            last = last->prev;
            last->next = NULL;
            Dnode->prev = NULL;           
        }
        free(Dnode);
        Dnode = NULL;
    }  
    *fhead = head;
    *flast = last; 
}
void deleteBetween(struct DLLNode **fhead,struct DLLNode **flast,int find)
{
    struct DLLNode *Dnode = NULL;
    struct DLLNode *head = NULL;
    struct DLLNode *last = NULL;
    head = *fhead;
    last = *flast;
    struct DLLNode *p = NULL;
    struct DLLNode *q = NULL;
    struct DLLNode *i = NULL;
    if(head == NULL)
    {
        printf("\nDLL does not exits ");
    }
    else
    {
        i = head;
        while(i!=NULL)
        {
            if(i->next->data == find)
            {
                p = i;
                i = NULL;
            }
            else
            {
                i = i->next;
            }
        }
        if(p!=NULL)
        {
            Dnode = p->next;
            q = Dnode->next;
            Dnode->next = NULL;
            Dnode->prev = NULL;
            p->next = q;
            q->prev = p;
            free(Dnode);
            Dnode = NULL;
            p = NULL;
            q = NULL;
            i = NULL;
        }
    }
    *fhead = head;
    *flast = last;
}
void reverseData(struct DLLNode *head,struct DLLNode *last,int n)
{
    struct DLLNode *i = NULL;
    int arr[n];
    i = head;
    while(i!=NULL)
    {
      arr[n-1] = i->data;
      i = i->next;
      n--;
    }
}
void reverseAddress(struct DLLNode *head,struct DLLNode *last)
{
    struct DLLNode *temp = NULL;
    struct DLLNode *current = NULL;
    current = head;
    while (current!=NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp!=NULL)
    {
        head = temp->prev;
    }   
}
void removeDLL(struct DLLNode *head,struct DLLNode *last)
{
    struct DLLNode *Dnode = NULL;
    struct DLLNode *i = NULL;
    if(head == last)
    {
        head = NULL;
        last = NULL;
    }
    else
    {
        i = head;
        while(i!=NULL)
        {
            Dnode = i;
            i = i->next;
            Dnode->next = NULL;
            Dnode->prev = NULL;
            free(Dnode);
            Dnode = NULL;
        }
        head = NULL;
        last = NULL;
    }
}