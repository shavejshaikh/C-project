#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ram
{
int data;
char name[30];
struct ram *next;
}node;

node *createW(node *);
node *createF(node *);
node *createG(node *);
node *createY(node *);
node *delet(node *);
void display(node *);
int flag1=0,flag2=0,flag3=0,flag4=0;

int main()
{
	node *head;
	head=NULL;
	int choice=0;
	do
	{
		printf("\nSelect the operation");
		printf("\n1.Open WhatsApp\n2.Open Facebook\n3.Open Google Chrome\n4.Open YouTube\n5.Close an application\n6.View RAM Status\n7.Exit the program\n");
		printf("\nEnter Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head=createW(head);
				break;
			case 2: head=createF(head);
				break;
			case 3: head=createG(head);
				break;
			case 4: head=createY(head);
				break;
			case 5: delet(head);
				break;
			case 6: display(head);
				break;
			case 7:exit(0);
				break;	
			default:printf("Invalid Option");

		}//end of switch case

	}while(choice!=7);

return 0;
}

node *createW(node *head)
{
	node *p,*s;
	if(flag1==1)
	{
		printf("\nApplication is already running");
		return(head);
	}
	if(head==NULL)
	{
		p=(node*)malloc(sizeof(node));
		p->data=847;
		strcpy(p->name,"WhatsApp");
		p->next=NULL;
		head=p;
		flag1=1;
		return head;
	}
	else
	{
		p=(node*)malloc(sizeof(node));
		p->data=847;
		strcpy(p->name,"WhatsApp");
		p->next=NULL;
		s=head;
		while(s->next!=NULL)
		{
			s=s->next;
		}
		s->next=p;
		flag1=1;
		return head;
	}
}


node *createF(node *head)
{
	node *p,*s;
	if(flag2==1)
	{
		printf("\nApplication is already running");
		return(head);
	}
	p=(node*)malloc(sizeof(node));
	p->data=1187;
	strcpy(p->name,"Facebook");
	p->next=NULL;
	if(head==NULL)
	{
		head=p;
		flag2=1; 	
	}
	else
	{	
		s=head;
		while(s->next!=NULL)
		{
			s=s->next;
		}
		s->next=p;
		flag2=1;
	}
	return head;
}


node *createG(node *head)
{
	node *p,*s;
	if(flag3==1)
	{
		printf("\nApplication is already running");
		return(head);
	}
	if(head==NULL)
	{
		p=(node*)malloc(sizeof(node));
		p->data=454;
		strcpy(p->name,"Chrome");
		head=p;
		flag3=1;
		return(head);
	}
	else
	{
		p=(node*)malloc(sizeof(node));
		p->data=454;
		strcpy(p->name,"Chrome");
		s=head;
		while(s->next!=NULL)
		{
			s=s->next;
		}
		s->next=p;
		flag3=1;
		return(head);
	}
}


node *createY(node *head)
{
	node *p,*s;
	if(flag4==1)
	{
		printf("\nApplication is already running");
		return(head);
	}
	if(head==NULL)
	{
		p=(node*)malloc(sizeof(node));
		p->data=1567;
		strcpy(p->name,"YouTube");
		head=p;
		flag4=1;
		return(head);
	}
	else
	{
		p=(node*)malloc(sizeof(node));
		p->data=1567;
		strcpy(p->name,"YouTube");
		s=head;
		while(s->next!=NULL)
		{
			s=s->next;
		}
		s->next=p;
		flag4=1;
		return(head);
	}
}

void display(node *head)
{
	node *q;
	int ramtotal=0,x=0,num=0;
	num=flag1+flag2+flag3+flag4;
	q=head;
	if(flag1==0&&flag2==0&&flag3==0&&flag4==0)
	{
		printf("\nNo Applications are running");
		printf("\nAvailable RAM: 8000 MB");
	}
	else
	{
		while(q!=NULL)
		{
			printf("\nApplication Name:%s\nRam Used:%d",q->name,q->data);
			ramtotal+=q->data;
			q=q->next;
		}
		printf("\nTotal RAM Used is % d\n",ramtotal);
		printf("\nAvailable RAM: %d\n",(8000-ramtotal));
	}
}
node *delet(node *head)
{
	int x;
	node *p,*q,*t;
	printf("Select the application you want to close:");
	printf("\n1.WhatsApp\n2.Facebook\n3.Chrome\n4.YouTube\n");
	scanf("%d",&x);
	if(x>4||x==0)
	{
		printf("\nInvalid choice\n");
		return(head);
	}
	else
	{
		if(x==1)
		{
			if(flag1==0)
			{
				printf("\nWhatsApp is not running\n");
				return(head);
			}
			else
			{
				flag1=0;
				x=847;
			}
		}
		if(x==2)
		{
			if(flag2==0)
			{
				printf("\nFacebook is not running\n");
				return(head);
			}
			else
			{
				flag2=0;
				x=1187;
			}
		}
		if(x==3)
		{
			if(flag3==0)
			{
				printf("\nChrome is not running\n");
				return(head);
			}
			else
			{
				flag3=0;
				x=454;
			}
		}
		if(x==4)
		{
			if(flag4==0)
			{
				printf("\nYouTube is not running\n");
				return(head);
			}
			else
			{
				flag4=0;
				x=1567;
			}
		}
		p=head;
		q=NULL;
		while(p!=NULL)
		{
			
			if(p->data==x)
			{
				t=p;
				q->next=p->next;
			}
			q=p;
			p=p->next;
		}
		free(t);
		return(head);
	}
}
