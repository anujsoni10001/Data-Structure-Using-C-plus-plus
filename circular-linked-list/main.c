#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *next;
};

typedef struct node *NODE;

NODE create(int data)
{
NODE temp;
temp=(NODE)malloc(sizeof(struct node));
temp->data=data;
temp->next=NULL;
return temp;
}

NODE addNodes(NODE first,int data)
{
NODE q=first;
NODE temp=create(data);
if(first==NULL)
first=temp;
else
{
while(q->next!=first)
q=q->next;
q->next=temp;
}
temp->next=first;
return first;
}

//USING DO WHILE LOOP TRAVERSAL............
void print(NODE first)
{
if(first==NULL)
printf("Empty Linked List.......\n");
else
{
NODE temp=first;
do{
printf("%d-->",temp->data);
temp=temp->next;
}while(temp!=first);
printf("\n");
}
}

//USING WHILE LOOP TRAVERSAL............
void print1(NODE first)
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
}

int count(NODE first)
{
NODE temp=first;
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

NODE insertAtpositionInCLL(NODE first,int pos, int x)
{
int sum=count(first);
NODE temp = create(x);
NODE q = first;
NODE r;
if ((first == NULL && pos!=1) || pos-1>sum || pos<=0 )
{
printf("No such position in CLL. So insertion is not possible.\n");
return first;
}
if(pos==1 && first==NULL)
{
first=temp;
temp ->next = first;
}
else if (first!=NULL && pos==1)
{
while(q->next!=first)
q=q->next;
q->next=temp;
temp->next=first;
first=temp;
}
else
{
pos=pos-2;
while(pos!=0)
{
q=q->next;
pos--;
}
r=q->next;
q->next=temp;
temp->next=r;
}
return first;
}

NODE deleteAtBeginInCLL(NODE first)
{
NODE q=first;
NODE r=first;
if(first->next==first || first==NULL)
return NULL;
else
{
while(r->next!=first)
r=r->next;
q=q->next;
r->next=q;
return q;
}
free(first);
}

int main()
{
NODE first=NULL;
first=insertAtpositionInCLL(first,1,90);
first=insertAtpositionInCLL(first,1,91);
first=insertAtpositionInCLL(first,1,92);
first=insertAtpositionInCLL(first,2,5);
first=insertAtpositionInCLL(first,3,6);
//first=deleteAtBeginInCLL(first);
//first=deleteAtBeginInCLL(first);
//first=deleteAtBeginInCLL(first);
//first=deleteAtBeginInCLL(first);
//first=deleteAtBeginInCLL(first);
//first=deleteAtBeginInCLL(first);
//first=deleteAtBeginInCLL(first);
print(first);
//printf("%d",count(first));
return 0;
}









