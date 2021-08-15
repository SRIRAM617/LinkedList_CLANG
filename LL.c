#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL ,*second=NULL, *third=NULL;
void Create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }


}
void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
   printf("\nAfter reversing\n");
}
void Rdisplay(struct Node *p)
{
    if(p!=NULL)
    {

        Rdisplay(p->next);
        printf("%d\n",p->data);
    }
}
int count(struct Node *p)
{
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
int Rcount(struct Node *p)
{
    if(p!=NULL)
    {
        return count(p->next)+1;
    }
    else{return 0;}
}
int Add(struct Node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int RAdd(struct Node *p)
{

    if(p!=NULL)
    {
        return Add(p->next)+p->data;
    }
    else
    {
        return 0;
    }
}
int Max(struct Node *p)
{
   int max=-1;
    while(p)
    {
        if(p->data>max)
        {
            max=p->data;


        }
         p=p->next;

    }
    return max;
}
int RMax(struct Node *p)
{
    int x;
    if(p==0)
        return -32768;
    else{
        x=RMax(p->next);
        if(x>p->data)
            return x;
        else{return p->data;}
    }
}
int Min(struct Node *p)
{
    int minimum=32768;
    while(p)
    {
        if(p->data<minimum)
            minimum=p->data;
            p=p->next;
    }
    return minimum;
}
int RMin(struct Node *p)
{
    int minimum=32768;
    if(p==NULL)
    {return minimum;}
    else{
            minimum=RMin(p->next);
        if(minimum>p->data){return p->data;}
        else{return minimum;}
    }
}
struct Node* LSearch(struct Node *p,int key)
{
    struct Node *q;
    while(p!=NULL)
    {
        if(p->data==key)
        {

            q->next=p->next;
            p->next=first;
            first=p;
             return p;
        }
        else{
               q=p; p=p->next;}
    }
}
void insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;
    if(index<0||index>count(p))
        return;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)
    {

        t->next=first;
        first=t;
    }
    else{
            p=first;
        for(i=0;i<index-1;i++){p=p->next;}
        t->next=p->next;
        p->next=t;




    }
}
void InsertLast(struct Node *p,int element)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    struct Node *last=NULL;
    t->data=element;
    if(first==NULL)
    {
        first=t;
        t->next=NULL;
    }
    else{
       p->next=t;
       t->next=NULL;
       last=t;
    }
}
void InsertInSortedList(struct Node *p,int key)
{

    struct Node *q;
      q=(struct Node *)malloc(sizeof(struct Node));
      struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=key;
    if(first==NULL)
    {

        t->next=NULL;
    }
    while(p!=NULL&&p->data<key)
    {


           q=p;
           p=p->next;


    }

    if(p==first)
    {

        t->next=p;
        first=t;
    }
    else{
    q->next=t;
    t->next=p;
    }
}
int deletelist(struct Node *p,int pos)
{
 int i,key;
 struct Node *q=NULL;

 if(pos==1)
 {
     q=first;
     first=p->next;
     key=q->data;
     free(q);
     return key;
 }

 else if((pos>1)&&pos<=(count(first))){
         for(i=0;i<pos-1;i++)
 {
     q=p;
     p=p->next;
 }


 q->next=p->next;
 key=p->data;
 return key;
 free(p);
 }

 else
 {
     printf("\nThere is no such element to delete please enter the values from 1\n");
 }


}
int CheckSort(struct Node *p)
{
    int x=-32768;
    while(p!=NULL)
    {
        if(p->data<x)
        {
            return 0;
        }
        x=p->data;
        p=p->next;

    }
    return 1;

}
void RemoveDup(struct Node *p)
{
    struct Node *q;
    q=p->next;
    while(q!=NULL)
    {


    if(p->data!=q->data)
    {
        p=q;
        q=q->next;
    }
    else{
    p->next=q->next;
    free(q);
    q=p->next;
    }
    }
}
void ReverseEle(struct Node *p)
{
    int i=0;
    int Array[count(first)];
    while(p!=NULL)
    {
       Array[i] =p->data;
       p=p->next;
       i++;

    }
    i--;
    p=first;
    while(p!=NULL)
    {
        p->data=Array[i];
        p=p->next;
        i--;
    }
}
void ReverseLinks(struct Node *p)
{
    struct Node *r=NULL,*q=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;

    }
    first=q;
}
void RecursiveReverse(struct Node *q,struct Node *p)
{

    if(p!=NULL)
    {
        RecursiveReverse(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}
void Create2(int A[],int n)
{
    int i;
    struct Node *t,*last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }


}
void Merge(struct Node *p,struct Node *q)
{
  struct Node *last;


  if(p->data<q->data)
  {
      third=last=p;

      p=p->next;
      last->next=NULL;
  }
  else
    {
    third=last=q;

    q=q->next;
    last->next=NULL;
  }
while(p!=NULL&&q!=NULL)
{


if(p->data<q->data)
{
    last->next=p;
    last=p;
    p=p->next;
    last->next=NULL;
}
else
{
 last->next=q;
 last=q;
    q=q->next;
    last->next=NULL;
}
}
if(p!=NULL)
{
    last->next=p;
}
if(q){
    last->next=q;
}


}
int isLoop(struct Node *f)
{
    struct Node *p,*q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL;
    }while(p&&q);
    return p==q?1:0;
}
int main()
{
    int A[]={1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6};
    int result;

    Create(A,16);


    result=isLoop(first);
    if(result>0)
    {
        printf("\nThere is a loop\n");
    }
    else{printf("\nNo loop\n");}










}

