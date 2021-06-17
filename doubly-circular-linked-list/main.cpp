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
struct list* temp=first;
int sum=0;
if(first==NULL)
return sum;
else
{
do
{
sum++;
temp=temp->next;
}while(temp!=first);
}
return sum;
}

///DONE Wrongly thats not correct way if u have a link that goes directly to last u need to traverse it till end
//it increases execution time explicitly....
//THATS WRONGLY DONE...
struct list* insert(struct list* first,int data)
{
struct list *temp,*q;
q=first;
temp=create(data);
if(first==NULL)
first=temp;
else
{
while((q->next)!=first) 
q=q->next;
q->next=temp;
temp->prev=q;
}
temp->next=first;
first->prev=temp;
return first;
}

struct list* insert_optimized(struct list* first,int data)
{
struct list *temp;
temp=create(data);
if(first==NULL)
first=temp;
else
{
(first->prev)->next=temp;
temp->prev=first->prev;
}
temp->next=first;
first->prev=temp;
return first;
}

struct list* insert_beggning(struct list* first,int data)
{
struct list *temp,*q;
temp=create(data);
q=first;
if(first==NULL)
{
temp->next=temp;
temp->prev=temp;
}
else{
temp->next=q;
(q->prev)->next=temp;
temp->prev=q->prev;
q->prev=temp;
}
first=temp;
return first;
}

//#Think Differently...
struct list* insert_beggning_optimized(struct list* first,int data)
{
struct list *temp;
temp=create(data);
if(first==NULL)
{
temp->next=temp;
temp->prev=temp;
}
else{
temp->next=first;
(first->prev)->next=temp;
temp->prev=first->prev;
first->prev=temp;
}
first=temp;
return first;
}

// INSERT AT BEGGNING CAN ALSO BE FURTHER OPTIMIZED BY REMOVING Q POINTER ABOVE THIS TEXT in insert_beggning function

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

//USING DO WHILE LOOP TRAVERSAL............
void display(struct list* first)
{
if(first==NULL)
printf("Empty Linked List.......\n");
else
{
struct list* temp=first;
do{
printf("%d-->",temp->data);
temp=temp->next;
}while(temp!=first);
printf("\n");
}
}

/*
//USING WHILE LOOP TRAVERSAL............
void print1(struct list* first)
{
NODE temp;
temp=NULL;
while(temp!=first){
if(temp==NULL)
temp=first;
printf("%d-->",temp->data);
temp=temp->next;
}
printf("\n");
}*/


int search(struct list *first,int data)
{
int count=0;
struct list *temp=first;
if(temp==NULL)
printf("Empty Linked list....");
else
{
    while(temp->data!=data)
    {
    count++;
    temp=temp->next;
    if(temp==first)
    return -1;
    }
return count+1;
}
}

//USING DO-WHILE LOOP
int search_using_do_while_loop(struct list *first,int data)
{
int count=0;
struct list *temp=first;
if(temp==NULL)
return count;
else
{
do{
count++;
if(temp->data==data)
return count;
temp=temp->next;
}while(temp!=first);
return 0;
}
}

struct list* delete_at_first(struct list *first)
{
struct list *q=first;
if(first==NULL)
printf("Empty Linked List !!! No Dseletion Possible....");
else if(q->next==first)
first=NULL;
else{
first=first->next;
(q->prev)->next=first;
first->prev=q->prev;
}
free(q);
return first;
}

struct list* delete_at_end(struct list *first)
{
struct list *temp=first;
if(first==NULL)
printf("Empty Linked List !!! No Deletion Possible....");
else
{
if(first->next==first)
first=NULL;
else
{
while(temp->next!=first)
temp=temp->next;
first->prev=temp->prev;
(temp->prev)->next=first;
}
}
free(temp);
return first;
}

struct list* delete_at_end_optimized(struct list *first)
{
if(first==NULL)
printf("Empty Linked List !!! No Deletion Possible....");
else
{
if(first->next==first)
{
free(first);
first=NULL;
}
else
{
first->prev=(first->prev)->prev;
free((first->prev)->next);
(first->prev)->next=first;
}
}
return first;
}

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
return delete_at_first(first);
else if (position==sum)
return delete_at_end_optimized(first);
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
free(temp);
}
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
first=insert_optimized(first,x);
scanf("%d",&x);
}
//first=insert_beggning_optimized(first,8);
//first=insert_beggndeing(first,21);
//first=insert_At_Position(first,45,2);
//first=insert_At_Position(first,39,2);
//first=delete_at_first(first);
//first=insert_At_Position(first,9999,4);
//first=delete_at_end(first);
//first=delete_at_end_optimized(first);
//first=delete_at_pos(first,1);
//first=delete_at_end(first);
//first=delete_at_pos(first,2);
first=delete_at_pos(first,8);
display(first);
//printf("%d\n",search_using_do_while_loop(first,55));
std::cout << count(first)<< std::endl;
return 0;
}









































