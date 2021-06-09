#include<stdio.h>
#include<stdlib.h>
//node creation
struct Node{
    int data;
    struct Node *next,*prev;
};
struct  Node *head=NULL,*ptr;
//cretae function
void insert_beg(int value)
{
    struct Node *temp;
    //dynammic mmemory alloction
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data= value;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        temp->prev=NULL;
        head=temp;
    }
    
}
void insert_end(int value)
{
    struct Node *temp;
    temp= (struct Node *)malloc(sizeof(struct Node));
    temp->data=value;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
            temp->prev=ptr;
            ptr->next=temp;
    }
    
}
void insert_nposition( int value, int ele)
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=value;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        ptr=head;
        while(ptr->data!=ele)
        {
            ptr=ptr->next;
        }
           
            temp->next=ptr->next;
            temp->prev=ptr;
            ptr->next->prev=temp;
            ptr->prev=temp;
    }   
}
void delete_begin()
{
    struct Node *ptr;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        ptr=head;
        head=head->next;
        ptr->next=NULL;
        head->prev=NULL;
        free(ptr);
    }
}
void delete_end()
{
    struct Node *ptr;
        if(head==NULL)
        {
            printf("List is empty\n");
        }
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
                ptr->prev->next=NULL;
                ptr->prev=NULL;
                free(ptr);  
        }
        
   
}
void delete_nposition(int ele)
{
    struct Node *ptr;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        ptr=head;
        while(ptr->data!=ele)
        {
            ptr=ptr->next;
        }
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            ptr->prev=NULL;
            ptr->next=NULL;
            free(ptr);
    }
    
}
void display()
{
    if(head== NULL)
    {
        printf("list is empty");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            printf("<->%d",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
    
}
void main()
{
    int value,ele,ch;
    printf("1.Insert at begining\n");
    printf("2.Insert at nposition\n");
    printf("3.Insert at end\n");
    printf("4.Delete at begining\n");
    printf("5. Delete at nposition\n");
    printf("6.Delelte at end\n");
    printf("7.display\n");
    printf("8.exit\n");
    while(1)
    {
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter the value to insert at beginning:");
                scanf("%d",&value);
                insert_beg(value);
                display();
                break;
            }
            case 2:
            {
                printf("Enter the value to insert nposition:");
                scanf("%d",&value);
                printf("Enter the elements:");
                scanf("%d",&ele);
                insert_nposition(value,ele);
                display();
                break;
            }
            case 3:
            {
                printf("Enter the value to insert at end:");
                scanf("%d",&value);
                insert_end(value);
                display();
                break;
            }
             case 4:
            {
                delete_begin();
                display();
                break;
            }
            case 5:
            {
                printf("Entere element you want to delete:\n");
                scanf("%d",&ele);
                delete_nposition(ele);
                display();
                break;
            }
            case 6:
            {
                delete_end();
                display();
                break;
            }
            case 7:
            {
                display();
            }
            case 8:
            {
                exit(0);
            }
        }
    }
}
   
            