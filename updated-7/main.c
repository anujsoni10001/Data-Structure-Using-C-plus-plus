#include <stdio.h>
#include <stdlib.h>
struct list{
int data;
struct list *next;
};

struct list* create(int data)
{
struct list *temp;
temp=(struct list*)malloc(sizeof(struct list)); 
temp->data=data;
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
temp=create(data);
if(first==NULL)
first=temp;
else
{
q=first;
while((q->next)!=NULL) 
q=q->next;
q->next=temp;
}
return first;
}

struct list* insert_beggning(struct list* first,int data)
{
struct list *temp;
temp=create(data);
temp->next=first;
first=temp;
return first;
}

struct list* insert_At_Position(struct list* first,int data,int position)
{
int sum=count(first);
struct list *temp,*q,*prev;
temp=create(data);
if((first==NULL && position!=1) || position-1>sum || position<=0) 
{
printf("Not Possible.....Invalid Insertion!!!");
return first;
}
if(position==1)
{
    temp->next=first;
    first=temp;
}
else
{
position--;
temp=create(data);
q=first;
while(position!=0) 
{
prev=q;
q=q->next;
position--;
}
prev->next=temp;
temp->next=q;
} 
return first;
}


void display(struct list* first)
{
struct list *temp=first;
while((temp)!=NULL) 
{
printf("%d->",temp->data);
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
   temp=temp->next;
    if(temp==NULL)
    return 0;
    }
return count+1;
}
}

struct list* delete_at_first(struct list *first)
{
struct list *temp=first;
if(first==NULL)
printf("Empty Linked List !!! No Deletion Possible....");
else
first=first->next;
free(temp);
return first;
}

struct list* delete_at_end(struct list *first)
{
struct list *temp=first,*prev;
if(first==NULL)
printf("Empty Linked List !!! No Deletion Possible....");
else
{
if(first->next==NULL)
first=NULL;
else
{
while(temp->next!=NULL)
{
prev=temp;
temp=temp->next;
}
prev->next=NULL;
}
free(temp);
}
return first;
}

struct list* delete_at_pos(struct list* first,int position)
{
int sum=count(first);
if(first==NULL || position<=0 || position>sum)
{
printf("Empty Linked List or Invalid position....!!!!");
return first;
}
struct list *temp=first,*prev,*q;
if (position== 1) {
first=temp->next;
}
else
{
position--;
while(position!=0) 
{
prev=temp;
temp=temp->next;
position--;
}
q=temp->next;
temp->next=prev->next;
prev->next=q;
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

struct list* removeduplicates(struct list* first)
{
struct list* temp=first;
struct list* q;
if(temp==NULL)
return temp;
while(temp->next!=NULL)
{
if(temp->data==(temp->next)->data)
{
q=((temp->next)->next);
free(temp->next);
temp->next=q;
}
else
temp=temp->next;
}
return first;
}

struct list* findUnion(struct list* list1,struct list* list2)
{
list1=removeduplicates(list1);
struct list* temp2=list2;
while(temp2 != NULL) {
      if (!search(list1, temp2->data))
      list1=insert(list1, temp2->data);
      temp2 = temp2->next;
  }
  return list1;
}



struct list* intersection(struct list* list1,struct list* list2)
{
struct list* list3=NULL;
struct list* temp=list2;
while(temp!=NULL)
{
if(search(list1,temp->data))
list3=insert(list3,temp->data);
temp=temp->next;
}
return list3;
}

struct list* sort(struct list* list)
{
int y=0;
struct list* temp=list;
struct list* q=list;
while(temp!=NULL )
{
while(q!=NULL)
{
if((temp->data)<(q->data))
{
y=temp->data;
temp->data=q->data;
q->data=y;
}
q=q->next;
}
q=list;
temp=temp->next;
}
return list;
}

int main()
{
//struct list *third=NULL;
struct list *first=NULL;

printf("Enter elements upto -1:");
int x=0;
scanf("%d",&x);
while(x!=-1)
{
first=insert(first,x);
scanf("%d",&x);
} 
first=sort(first);
//first=removeduplicates(first);
//first=insert_At_Position(first,12,3);
/*struct list *second=NULL;

printf("Enter elements upto -1:");
int y=0;
scanf("%d",&y);
while(y!=-1)
{
second=insert(second,y);
scanf("%d",&y);
} 
*/
//third=intersection(first,second);

//second=insert_At_Position(second,12,3); */

//first=concatenate(first,second);
//first=findUnion(first,second);
/* display(first);
count(first);
first=insert_beggning(first,85); 
display(first);
count(first);
printf("%d\n",search(first,11));
first=delete_at_first(first);
first=delete_at_end(first); */
//first=delete_at_pos(first,3); 

//printf("%d\n",search(first,11));
display(first);
return 0;
}










