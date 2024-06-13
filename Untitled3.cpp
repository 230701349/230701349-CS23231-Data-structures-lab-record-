#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*first=NULL;
void insertbeg(int);
void insertend(int);
void insertbetw(int,int);
void delpos(int);
void display();
int count();
int main()
{  
        
        int choice;
    while (choice!=7)
        {
            printf("\n1 To view the list\n");
            printf("\n2 To insert at the beginning\n");
            printf("\n3 To insert at the end\n");
            printf("\n4 To insert at any position\n");
            printf("\n5 To delete the element at the given position\n");
             printf("\n6 To see the number of nodes\n");
             printf("\nEnter Choice : ");
            scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                display();
                break;
            case 2:
                insertbeg(332);
                break;
            case 3:
                insertend(334);
                break;
            case 4:
                insertbetw(333,2);
                break;
            case 5:
                delpos(2);
                break;
            case 6:
                count();
                break;
            default:
                printf("INVALID CHOICE");
                
        }
        
        }
        return 0;
}
void insertbeg(int rol)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=rol;
	if(first==NULL)
	{
		newnode->link=NULL;
		first=newnode;
	}
	else
	{
		newnode->link=first;
		first=newnode;
	}
}
void insertend(int rol)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=rol;
	if(first==NULL)
	{
		newnode->link=NULL;
		first=newnode;
	}
	else
	{
		temp=first;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=newnode;
		newnode->link=NULL;
    }  
}	
	void display()
	{
		struct node *temp;
		temp=first;
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->link;
		}
	}
void insertbetw(int rol,int loc)
{
        struct node*newnode,*temp;
        newnode=(struct node*)malloc(sizeof(struct node));
        temp=first;
        newnode->data=rol;
        for(int i=1;i<loc-1;i++)
        {
        	if(temp==NULL)
        	{
        		printf("Invalid position");
			}
			temp=temp->link;
		}
        newnode->link=temp->link;
        temp->link=newnode;


}
void delpos(int pos)
{
	struct node *temp=NULL,*prev=NULL;
	temp=first;
	if(pos==1)
    {
        if(temp==NULL)
        {
        	printf("Invalid");
		}
		else
		{
			first=temp->link;
			free(temp);
			temp=NULL;
		}
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            if(temp==NULL)
            printf("Invalid");
            else
            {
                prev=temp;
                temp=temp->link;
            }
        }
        prev->link=temp->link;
        free(temp);
        temp=NULL;
        prev=NULL;
    }
}
int count()
{
    int c=0;
    struct node *temp=first;
    while(temp!=NULL)
    {
        temp=temp->link;
        c++;
    }
   printf("%d",c);
}

