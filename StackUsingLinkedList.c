#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
};
struct node *top=NULL;
main()
{
int ch;
while(1)
{
printf("\n1.push\n");
printf("\n2.pop\n");
printf("\n3.display\n");
scanf("%d",&ch);
switch(ch)
{
case 1: push();
break;
case 2: pop();
break;
case 3: display();
break;
default:printf("Invalid Choice\n");
}
}
}
push()
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter node\n");
scanf("%d",&temp->data);
temp->link=top;
top=temp;
}
pop()
{
struct node *temp;
if(top==NULL)
{
printf("No elements to delete\n");
}
else{
temp=top;
printf("Element deleted is %d",temp->data);
top=top->link;
temp->link=NULL;
free(temp);
}
}
display()
{
struct node *temp;
if(top==NULL)
printf("No elements in the last\n");
else{
temp=top;
while(temp!=NULL)
{
printf("%d\t",temp->data);
temp=temp->link;
}
}
}