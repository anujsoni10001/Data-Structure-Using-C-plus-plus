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

 void sortList(struct list* head) {  
        //Node current will point to head  
        struct list* current = head, *index = NULL;  
        int temp;  
          
        if(head == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                //Node index will point to node next to current  
                index = current->next;  
                  
                while(index != NULL) {  
                    //If current node's data is greater than index's node data, swap the data between them  
                    if(current->data < index->data) {  
                        temp = current->data;  
                        current->data = index->data;  
                        index->data = temp;  
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
        }  
    }  
    
struct list* add(struct list* head1,struct list* head2)
{

}

int main()
{
struct list *first=NULL;
/*printf("Enter elements upto -1:");
int x=0;
scanf("%d",&x);
while(x!=-1)
{
first=insert(first,x);
scanf("%d",&x);
}*/
first=insert_At_Position(first,3,1);
first=insert_At_Position(first,4,2);
/* display(first);
count(first);
first=insert_beggning(first,85); 
display(first);
count(first);
printf("%d\n",search(first,11));
first=delete_at_first(first);
first=delete_at_end(first); */
//first=delete_at_pos(first,3); 
display(first);
sortList(first);
display(first);
return 0;
}












