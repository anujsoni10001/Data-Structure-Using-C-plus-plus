#include <stdio.h>
#include <conio.h>

struct polynomial{
int coeff;
int exp;
struct polynomial *next;
};

typedef struct polynomial *poly;

poly addTerm(poly head, poly temp) {
	poly p1,p2;
	p1 = p2 = head;
	if (p1 == NULL) {
		head = temp;
	} else {
		while (p1 != NULL && p1 -> exp > temp -> exp) {
			p2 = p1;
			p1 = p1 -> next;
		}
		if (p1 == NULL) {
			p2 -> next = temp;
		} else if (p1 -> exp == temp -> exp) {
			p1 -> coeff = p1 -> coeff + temp -> coeff;
		} else if (p1 -> exp < temp -> exp) {
			if (p2 == p1) {
				temp -> next = p1;
				head = temp;
			} else {
				temp -> next = p1;
				p2 -> next = temp;
			}
		}
	}
	return head;
}

poly create(poly head){
poly temp=NULL;
char ch;
int coeff,exp;
do{
temp=(poly)malloc(sizeof(struct polynomial));
printf("Enter coeff and Exp");
scanf("%d%d",&coeff,&exp);
temp->coeff=coeff;
temp->exp=exp;
temp->next=NULL;
head=addTerm(head,temp);
printf("Do you want another node y or n");
scanf(" %c",&ch);
}while(ch!='n');
return head;
}

void print(poly head) {
	poly temp = head;
	while (temp != NULL) {
		printf("%d X^ %d --->", temp -> coeff, temp -> exp);
		temp = temp -> next;
	}
	printf("NULL\n");
}

poly add(poly head1,poly head2){
poly sum=NULL,p1=head1,p2=head2;
poly temp=NULL;
while(p1!=NULL && p2!=NULL){
temp=(poly)malloc(sizeof(struct polynomial));
if(p1->exp==p2->exp)
{
temp->coeff=p1->coeff+p2->coeff;
temp->exp=p1->exp;
temp->next=NULL;
sum=addTerm(sum,temp);
p1=p1->next;
p2=p2->next;
}
else if(p1->exp<p2->exp){
temp->coeff=p2->coeff;
temp->exp=p2->exp;
temp->next=NULL;
sum=addTerm(sum,temp);
p2=p2->next;
}
else{
temp->coeff=p1->coeff;
temp->exp=p1->exp;
temp->next=NULL;
sum=addTerm(sum,temp);
p1=p1->next;
}
}
while(p1!=NULL){
temp=(poly)malloc(sizeof(struct polynomial));
temp->coeff=p1->coeff;
temp->exp=p1->exp;
temp->next=NULL;
sum=addTerm(sum,temp);
p1=p1->next;
}
while(p2!=NULL){
temp=(poly)malloc(sizeof(struct polynomial));
temp->coeff=p2->coeff;
temp->exp=p2->exp;
temp->next=NULL;
sum=addTerm(sum,temp);
p2=p2->next;
}
return sum;
}

poly sub(poly head1,poly head2){
poly sum=NULL,p1=head1,p2=head2;
poly temp=NULL;
while(p1!=NULL && p2!=NULL){
temp=(poly)malloc(sizeof(struct polynomial));
if(p1->exp==p2->exp)
{
temp->coeff=p1->coeff-p2->coeff;
temp->exp=p1->exp;
temp->next=NULL;
sum=addTerm(sum,temp);
p1=p1->next;
p2=p2->next;
}
else if(p1->exp<p2->exp){
temp->coeff=-(p2->coeff);
temp->exp=p2->exp;
temp->next=NULL;
sum=addTerm(sum,temp);
p2=p2->next;
}
else{
temp->coeff=(p1->coeff);
temp->exp=p1->exp;
temp->next=NULL;
sum=addTerm(sum,temp);
p1=p1->next;
}
}
while(p1!=NULL){
temp=(poly)malloc(sizeof(struct polynomial));
temp->coeff=p1->coeff;
temp->exp=p1->exp;
temp->next=NULL;
sum=addTerm(sum,temp);
p1=p1->next;
}
while(p2!=NULL){
temp=(poly)malloc(sizeof(struct polynomial));
temp->coeff=-(p2->coeff);
temp->exp=p2->exp;
temp->next=NULL;
sum=addTerm(sum,temp);
p2=p2->next;
}
return sum;
}

poly mul(poly head1,poly head2){
poly mul=NULL,temp=NULL;
poly p1=head1,p2=head2; 
while(p1!=NULL)
{
p2=head2;
while(p2!=NULL){
temp=(poly)malloc(sizeof(struct polynomial));
temp->coeff=(p1->coeff)*(p2->coeff);
temp->exp=p1->exp+p2->exp;
temp->next=NULL;
mul=addTerm(mul,temp);
p2=p2->next;
}
p1=p1->next;
}
return mul;
}

void main() {
poly head1=NULL, head2= NULL, result=NULL;
int ch;
printf("Enter the first polynomial \n");
head1 = create(head1);
printf("Enter the second \n");
head2 = create(head2);
result = mul(head1,head2);
printf("The first polynomial");
print(head1);
printf("The second polynomial");
print(head2);
printf("Addition result");
print(result);
}








