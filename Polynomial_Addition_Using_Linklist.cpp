//Lakhani Dinky A. 
//IT052 Sem-4
//Batch :- H3

//Polynomial Addition using Linkedlist
#include<iostream>
using namespace std;
#include<string>
struct link
{
    int coef;
    int exp;
    link *next;
};

class impl
{
    private:
      link *first;
    public:
       impl()
    	{
        	first='\0';
    	}      
      void  addafter(int d,int l);
      void  disp();
    	link *return_first()
    	{
    		return first;
		}
    	void addition(link* p,link* q);
    };

void impl::addafter(int d,int l)
{
    link *newptr=new link;
    newptr->coef=d;
    newptr->exp=l;
    
    if(first=='\0')
    {
      first=newptr;
      first->next='\0';
    }
    else {									//Modified
    	link *temp=first;
    	while(temp->next!='\0')
    	{
       		temp=temp->next;
    	}   
    	temp->next=newptr;
    	newptr->next='\0';  
	}
      
}

void impl::disp()
{
    link *ptr=first;
    while(ptr!='\0')
    {
        cout<<ptr->coef<<"x^"<<ptr->exp<<' ';
        ptr=ptr->next;
     }    
}

void impl::addition(link *p,link *q)
{
    
    link *first=p;
    link *second=q;   
    impl third;
    
    while(first!='\0' && second!='\0')
    {
    	if(first->exp==second->exp)
     	{
        	third.addafter(first->coef+second->coef,first->exp);
            first= first->next;
            second=second->next;
    	}
        else if(first->exp > second->exp)		
     	{
   			third.addafter(first->coef,first->exp);
            first= first->next;					
    	}
        else //if(first->exp < second->exp)				
     	{
 			third.addafter(second->coef,second->exp);
            second=second->next;						
    	}
    }													
        if(first!='\0')
        {
        	while(first!='\0')					
        	{
        		third.addafter(first->coef,first->exp);
        		first=first->next;
			}
   			
    	}
        if(second!='\0')
        {
        	while(second!='\0')					
        	{
        		third.addafter(second->coef,second->exp);
        		second=second->next;
			}
 		}
    cout<<"\nPOLYNOMIAL c\n------------------ \n";
   	third.disp();
}
int main()
{
    impl a;   
    a.addafter(5,2);
    a.addafter(3,1);
    a.addafter(5,0);
    
    cout<<"\nPOLYNOMAIL A\n------------------ \n";
    a.disp();
    impl b;   
    b.addafter(5,3);								
    b.addafter(1,2);
    b.addafter(3,1);
    //b.addafter(2,0);
     cout<<"\nPOLYNOMIAL B\n------------------ \n";
    b.disp();
    
   	link *f=a.return_first();
    link *h=b.return_first();
    impl k;
    k.addition(f,h); 
	  cout<<"\nPOLYNOMIAL ADDITION RESULT \n------------------ \n";		
    	k.disp();
}

//Output
/*
POLYNOMAIL A
------------------
5x^2 3x^1 5x^0
POLYNOMIAL B
------------------
5x^3 1x^2 3x^1
POLYNOMIAL c
------------------
5x^3 6x^2 6x^1 5x^0
POLYNOMIAL ADDITION RESULT
------------------
*/