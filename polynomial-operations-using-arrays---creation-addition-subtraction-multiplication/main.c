#include <stdio.h>
#include <stdlib.h>
#define max 20


void create(int arr[max + 1], int power) {
int i;
for(i=power;i>=0;i--) {
printf("Enter coeff value for %d", i); 
printf(" degree term : ");
scanf("%d",&arr[i]);
}
}

void print(int arr[max + 1], int power) 
{ 
for (int i=power;i>=0;i--)
{
if(i==power)
printf("%d X^ %d -->", arr[i],i);
else
printf(" %d X^ %d -->", arr[i],i); 
}
printf(" NULL\n");
}

void add(int head1[max+1],int hpow1,int head2[max+1],int hpow2,int polyAdd[max+1],int *hpow3)
{
if(hpow1>hpow2)
*hpow3=hpow1;
else
*hpow3=hpow2;
//*hpow3=max(hpow1,hpow2);
for(int i=(*hpow3);i>=0;i--) {
polyAdd[i]=head1[i]+head2[i];
}
}

void sub(int head1[max+1],int hpow1,int head2[max+1],int hpow2,int polyAdd[max+1],int *hpow3)
{
if(hpow1>hpow2)
*hpow3=hpow1;
else
*hpow3=hpow2;
//*hpow3=max(hpow1,hpow2);
for(int i=(*hpow3);i>=0;i--) {
polyAdd[i]=head1[i]-head2[i];
}
}

void mul(int head1[max+1],int hpow1,int head2[max+1],int hpow2,int mulSub[max+1])
{
for(int i=hpow1;i>=0;i--)
{
for(int j=hpow2;j>=0;j--)
{
mulSub[i+j]+=head1[i]*head2[j];
}
}
}
 
void main() {
int hpow1=0,hpow2=0,hpow3=0,ch;
int head1[max+1]={0},head2[max+1]={0},polyAdd[max+1]={0},polySub[max+1]={0},mulSub[max+1]={0};
printf("Enter highest power of the first polynomial");
scanf("%d", &hpow1);
create(head1, hpow1); 
printf("The polynomial");
//print(head1, hpow1);
printf("Enter highest power of the second polynomial");
scanf("%d",&hpow2);
create(head2, hpow2); 
printf("The polynomial");
//print(head2, hpow2);
//add(head1,hpow1,head2,hpow2,polyAdd,&hpow3);
//sub(head1,hpow1,head2,hpow2,polySub,&hpow3);
mul(head1,hpow1,head2,hpow2,mulSub);
printf("\n%d-----",hpow3);
print(mulSub,hpow2+hpow1);
}







