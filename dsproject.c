#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#define no_of_cars 5
int top=-1,f=-1,r=-1;
struct waiting_list_of_customers
{ int id;
  char name[20],mobile_no[11];
  char model[20];
}s[no_of_cars];
char review[no_of_cars][50];
enum boolean{false,true};
enum boolean w_isempty()
{ if(f==-1)
   return true;
  else
   return false;
}
enum boolean w_isfull()
{ if(r==no_of_cars-1)
   return true;
  else
   return false;
}
enum boolean f_isempty()
{ if(top==-1)
   return true;
  else
   return false;
}
enum boolean f_isfull()
{ if(top==no_of_cars-1)
   return true;
  else
   return false;
}
void push_feedback()
{ if(f_isfull())
  { printf("feed is full\n");
    return;
  }
  printf("enter feedback\n");
  fflush(stdin);
  gets(review[++top]);
  printf("feedback is collected\n");
}
void pop_feedback()
{ if(f_isempty())
  { printf("feed is empty\n");
    return;
  }
  printf("%s is deleted\n",review[top--]);
}
void display_feedback()
{ int i;
  if(f_isempty())
  { printf("feed is empty\n");
    return;
  }
  for(i=top;i>=0;i--)
   printf("%s\n",review[i]);
}
void top_feedback()
{ if(f_isempty())
  { printf("feed is empty\n");
    return;
  }
  printf("top most feedback is %s\n",review[top]);
}
void count_feedback()
{ int count=0,i;
  if(f_isempty())
  { printf("feed is empty\n");
    return;
  }
  for(i=top;i>=0;i--)
   count++;
  printf("total no. of feedbacks are %d\n",count);
}
void insert_customer()
{ time_t t=time(NULL);
  if(w_isfull())
  { printf("waiting list is full,cannot insert\n");
    return;
  }
  if(r==-1)
  { r=0;
    f=0;
  }
  else
   r++;
  printf("enter Id,name,mobile no.,model\n");
  scanf("%d%s%s%s",&s[r].id,s[r].name,s[r].mobile_no,s[r].model);
  printf("given details are entered into list\nyou will receive your order within 4 days of booking\n");
  printf("%s\n",ctime(&t));
}
void delete_customer()
{ if(w_isempty())
  { printf("waiting list is empty,cannot delete\n");
    return;
  }
  printf("front most customer is deleted\n");
  printf("%d\t%s\t%s\t%s\n",s[f].id,s[f].name,s[f].mobile_no,s[f].model);
  if(f==r)
  { f=-1;
    r=-1;
  }
  else
   f++;
}
void front_customer()
{ if(w_isempty())
  { printf("waiting list is empty\n");
    return;
  }
  printf("front most customer details %d %s %s %s\n",s[f].id,s[f].name,s[f].mobile_no,s[f].model);
}
void rear_customer()
{ if(w_isempty())
  { printf("waiting list is empty\n");
    return;
  }
  printf("rear most customer details %d %s %s %s\n",s[r].id,s[r].name,s[r].mobile_no,s[r].model);
}
void display_customer()
{ int i;
  if(w_isempty())
  { printf("waiting list is empty\n");
    return;
  }
  for(i=f;i<=r;i++)
   printf("%d\t%s\t%s\t%s\n",s[i].id,s[i].name,s[i].mobile_no,s[i].model);
}
void count_customer()
{ int count=0,i;
  if(w_isempty())
  { printf("waiting list is empty hence cannot be counted\n");
    return;
  }
  for(i=f;i<=r;i++)
   count++;
  printf("total no. of customers are %d\n",count);
}
void avail()
{ if(r==no_of_cars-1)
  { printf("out of stock come again\n");
    return;
  }
  printf("available\n");
}
void displaymodels()
{ 
  FILE *fp;
  char c;
  fp=fopen("learn.txt","r");
  while((c=getc(fp))!=EOF)
  {
      printf("%c",c);
  }
  fclose(fp);
}
int main()
{ int op1,op2,op3,op4,op5;
  printf("********WELCOME**********\n");
  do
  { printf("enter 1->customer 2->staff 3->exit\n");
    scanf("%d",&op1);
    if(op1==3)
     break;
    if(op1==1)
    { do
    { printf("enter 1->display all car models 2->check avaialability 3->enter customer data 4->enter feedback 5->exit\n");
      scanf("%d",&op2);
      switch(op2)
      { case 1 :displaymodels();
                 break;
        case 2 :avail();
                break;
        case 3 :insert_customer();
                break;
        case 4 :push_feedback();
                 break;
      }
    } while (op2!=5);
    }
    else
    { do
    { printf("enter 1->analyse feedback 2->analyse customer details 3->exit\n");
      scanf("%d",&op3);
      if(op3==3)
       break;
      if(op3==1)
      { do
      { printf("enter 1->top feedback 2->remove feedback 3->display all feedbacks 4->count feedbacks 5->exit\n");
        scanf("%d",&op4);
        if(op4>5)
         printf("wrong input , enter valid input\n");
        switch(op4)
        { case 1 :top_feedback();
                  break;
          case 2 :pop_feedback();
                  break;
          case 3 :display_feedback();
                  break;
          case 4 :count_feedback(); 
                  break;                       
        }
      } while (op4!=5);
      }
      else
      { do
      { printf("enter 1->delete customer 2->front customer 3->rear customer 4->display all customers 5->count customers 6->exit\n");
        scanf("%d",&op5);
        if(op5>5)
         printf("wrong input , enter valid input\n");
        switch(op5)
        { case 1 :delete_customer();
                  break;
          case 2 :front_customer();
                  break;
          case 3 :rear_customer();
                  break;
          case 4 :display_customer();
                  break;
          case 5 :count_customer();
                  break;
        }
      } while (op5!=6);
      }
    } while (op3!=3);
    } 
  }
  while(op1!=3);
  printf("*****THANK YOU*****");
  return 0;
}

