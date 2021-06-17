#include <stdio.h>
#include <stdlib.h>
#include <iostream>
struct list{
int data;
struct list *prev;
struct list *next;
};

struct list* create(int data)
{
struct list *temp;
temp=(struct list*)malloc(sizeof(struct list)); 
temp->data=data;
temp->prev=NULL;
temp->next=NULL;
return temp;
}


int count(struct list* first)
{
struct list *temp=first;
int sum=0;
while(temp!=NULL) 
{
sum++;
temp=temp->next;
}
return sum;
}

struct list* insert(struct list* first,int data)
{
struct list *temp,*q;
q=first;
temp=create(data);
if(first==NULL)
first=temp;
else
{
while((q->next)!=NULL) 
q=q->next;
q->next=temp;
temp->prev=q;
}
return first;
}

struct list* insert_beggning(struct list* first,int data)
{
struct list *temp,*q;
temp=create(data);
q=first;
if(first==NULL)
first=temp;
else{
first=temp;
temp->next=q;
q->prev=temp;
}
return first;
}

struct list* insert_At_Position(struct list* first,int data,int position)
{
int sum=count(first);
struct list *temp,*q;
temp=create(data);
if((first==NULL && position!=1) || position-1>sum || position<=0) 
printf("Not Possible.....Invalid Insertion!!!");
else if (position==1)
return insert_beggning(first,data);
else if (position==sum+1)
return insert(first,data);
else
{
position--;
q=first;
while(position!=0) 
{
q=q->next;
position--;
}
(q->prev)->next=temp;
temp->next=q;
temp->prev=q->prev;
q->prev=temp->next;
} 
return first;
}


void display(struct list* first)
{
struct list *temp=first;
while((temp)!=NULL) 
{
printf("%d<->",temp->data);
temp=temp->next;
}
printf("NULL\n");
}


int search(struct list *first,int data)
{
int count=0;
struct list *temp=first;
if(temp==NULL)
printf("Empty Linked list....");
else
{
    while(temp!=NULL && temp->data!=data)
    {
    count++;
    temp=temp->next;
    if(temp==NULL)
    return -1;
    }
return count+1;
}
}

struct list* delete_at_first(struct list *first)
{
struct list *temp=first;
if(first==NULL)
printf("Empty Linked List !!! No Dseletion Possible....");
else
first=first->next;
free(temp);
return first;
}

struct list* delete_at_end(struct list *first)
{
struct list *temp=first;
if(first==NULL)
printf("Empty Linked List !!! No Deletion Possible....");
else
{
if(first->next==NULL)
first=NULL;
else
{
while(temp->next!=NULL)
temp=temp->next;
(temp->prev)->next=NULL;
}
}
free(temp);
return first;
}

struct list* delete_at_pos(struct list* first,int position)
{
struct list *temp=first,*q;
int sum=count(first);
if(first==NULL || position<=0 || position>sum)
{
printf("Empty Linked List or Invalid position....!!!!");
return first;
}
else if (position== 1) 
first=temp->next;
else if (position==sum)
return delete_at_end(first);
else
{
position--;
while(position!=0) 
{
temp=temp->next;
position--;
}
q=temp->next;
(temp->prev)->next=q;
q->prev=temp->prev;
}
free(temp);
return first;
}

///THe same code can be optimized further using think trick which comes from expreience while making the code..................................
struct list* delete_at_pos(struct list* first,int position)
{
struct list *temp=first;
int sum=count(first);
if(first==NULL || position<=0 || position>sum)
{
printf("Empty Linked List or Invalid position....!!!!");
return first;
}
else if (position== 1) 
first=temp->next;
else if (position==sum)
return delete_at_end(first);
else
{
position--;
while(position!=0) 
{
temp=temp->next;
position--;
}
(temp->prev)->next=temp->next;
(temp->next)->prev=temp->prev;
}
free(temp);
return first;
}



struct list* concatenate(struct list* first,struct list* second)
{
struct list* q=first;
if(first==NULL)
return second;
else if (second==NULL)
return first;
else
{
while((q->next)!=NULL)
q=q->next;
q->next=second;
return first;
}
}

int main()
{
struct list *first=NULL;
printf("Enter elements upto -1:");
int x=0;
scanf("%d",&x);
while(x!=-1)
{
first=insert(first,x);
scanf("%d",&x);
}
//first=insert_beggning(first,8);
//first=insert_At_Position(first,45,1);
//first=insert_At_Position(first,39,2);
//first=delete_at_first(first);
//first=insert_At_Position(first,9999,4);
//first=delete_at_end(first);
//first=delete_at_pos(first,1);
//first=delete_at_end(first);
//first=delete_at_pos(first,2);
first=delete_at_pos(first,3);
display(first);
std::cout << count(first)<< std::endl;
return 0;
}

































