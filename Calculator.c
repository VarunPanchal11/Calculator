#include <stdio.h>   
#include <stdlib.h>
#include <math.h>  
#include <ctype.h>

//All the variable declared globally 
float k;
float x,y,z;
float a=0,b=0,c=0,d=0,e=0,f=0;
char ch2[10];
char n,m;
char ch,ch1;
float *invent;
static int index = 0;

//All user defined functions
char menu();
char menucheck();
float numcheck();
char varcheck();
void binary(float *);
void oponly(float *);
void unary(float *);
void oponly1(float *);
void vnv();
void adv();
void done();
void memorycheck(float *);
void memoryremove(float *);

       
int main() 
{
    invent = (float *)malloc(100 * sizeof(float));  //Initial memory allocation
    printf("****************************************\n");  
    printf("Name: XY\n");
  	printf("Assignment 3\n"); 
    printf("****************************************\n\n");
  do
  {
    printf("\n\nWelcome to Command Line Calculator\n");  
    printf("Please select one of the following options:\n");
  	printf("B - Binary Mathematical Operations such as addition and subtraction\n"); 
    printf("U - Unary Mathematical Operations, such as square root, and log\n");
    printf("A - Advances Mathematical Operations, using variables, arrays\n");
    printf("V - Define variables and assign them values\n");
    printf("M - check the memory of the calculator\n");
    printf("R - remove all the memory from the calculator\n");
    printf("X – Exit\n");
	scanf(" %c",&n);  
    
    n=menucheck();	 //Function will check whether user input is correct or not
  
    switch(n)                	
	{
		case 'B':
		case 'b':       
			 binary(invent);
             break;
	    case 'U':
		case 'u': 
		     unary(invent);
             break;
	    case 'V':
		case 'v': 
			 vnv();
             break;
	    case 'A':
		case 'a': 
			 adv();
             break;
		
         case 'M':
         case 'm':
             memorycheck(invent);
             break;
	  
	     case 'R':
         case 'r':
             memoryremove(invent);
             break;

	
	     case 'X':
		 case 'x': 
             done();
             break;
    }
  }
    while(n!='X' || n!='x');
    return 0;
}	
  

char menu()  //Menu function that provide the list of options availible
{
    char n;
    printf("\n\nWelcome to Command Line Calculator\n");  
    printf("Please select one of the following options:\n");
	  printf("B - Binary Mathematical Operations such as addition and subtraction\n"); 
    printf("U - Unary Mathematical Operations, such as square root, and log\n");
    printf("A - Advances Mathematical Operations, using variables, arrays\n");
    printf("V - Define variables and assign them values\n");
    printf("M - check the memory of the calculator\n");
    printf("R - remove all the memory from the calculator\n");
    printf("X – Exit\n");
	scanf("      %c",&n);  
    
	 return n;
}

char menucheck()
{
	while(n!='B' && n!='b' && n!='U' && n!='u' && n!='V' && n!='v' && n!='A' && n!='a' && n!='M' && n!='m' && n!='R' && n!='r' && n!='X' && n!='x')  //If user input is not one of these then loop will begin
	{
		printf("Invalid input\n");
		printf("Enter valid option:");
		scanf("      %c",&n);  //Once user input is correct loop will break
	}
    printf("Your choice is %c\n",n);
    return n;
}

float numcheck()
{
	float num;
	char m;
	while(scanf("%f", &num)!=1)    //If user input is not number the loop will start and will break once the user inputs any number               
			{
				if(scanf("%2c", &m))
				{	
				printf("Invalid Input\n");	
				printf("please enter a valid number:");    
				}	
			}
    return num;
}

char varcheck()  //Variable check function
{
	char var;
    scanf(" %c",&var);
	while((var>='f' && var<='z') || (var>='A' && var<='Z') || (var>=0 && var<=96) || (var>=102 && var<=127))  //Here if the ch2 is between f to z or A to z or any other character whos ASCII values are from 0 to 96 or 102-127 then it will enter the while loop
				{
				printf("Invalid Input\n");	
				printf("please enter a character from 'a to e':");
				scanf("  %c",&var);	//Once the right character has entered then it will exit the loop
				}
	return var;
}
	

void binary(float *invent)
{
	float x,y,z;
	char ch,m;
	        printf("please enter first number: \n");    //entering First Number
			x = numcheck();   //checking input is valid or not
			printf("First number:%.2f\n",x);
				
			printf("please enter second number: \n");   //entering Second Number  
	        y = numcheck();  //checking input is valid or not
			printf("Second number:%.2f\n",y);
         				
			printf("\nplease chose an operation\n A to add\n S to minus\n M to multiply \n D to divide\n R for remainder\n P for power\n"); 
	        scanf(" %c",&ch); 
			while(ch!='A' && ch!='a' && ch!='S' && ch!='s' && ch!='M' && ch!='m' && ch!='D' && ch!='d' && ch!='R' && ch!='r' && ch!='P' && ch!='p')
	        {
		    printf("Invalid input\n");
		    printf("Enter valid option:");
		    scanf(" %c",&ch);
	        }
	        if(ch=='A' || ch=='a')  
	        {
		       z=x+y;   
		       printf("result = %.2f\n", z); 
			   invent[index]=z; //Adding answer to memory
			   index++;
		    }
	        else if(ch=='S'|| ch=='s') 
		    {
		       z=x-y;  
		       printf("answer is %.2f\n",z); 
			   invent[index]=z; //Adding answer to memory
			   index++;
	        }
		    else if(ch=='M' || ch=='m')  
		    {
		       z=x*y;  
		       printf("answer is %.2f\n",z); 
			   invent[index]=z; //Adding answer to memory
			   index++;
	        }
	        else if(ch=='D' || ch=='d')  
		    {
		       while(y==0)
		    {
			   printf("please enter vaild second number(non-zero) for division: \n"); 
	           while(scanf("%f", &y)!=1)             //If scanf read character then it will enter the loop and if it reads number it won't enter the loop
                { 
				if(scanf("%2c", &m)) 
				{	
				printf("Invalid Input\n");	
				printf("please enter Second number:");
				}	
			    }	
			   printf("Second number:%.2f\n",y);
		    }			  
		      z=x/y;  
		      printf("answer is %.2f\n",z); 
			  invent[index]=z; //Adding answer to memory
			  index++;
	        }
	        else if(ch=='R' || ch=='r')  
		    {
		        while(y==0) //As long as y is 0 loop will continue
		        {
			    printf("please enter vaild second number(non-zero) for division: \n"); 
	            while(scanf("%f", &y)!=1) //If user enters character then again it will enter another loop
                { 
				if(scanf("%2c", &m))
				{	
				printf("Invalid Input\n");	
				printf("please enter Second number:");
				}	
			    }	
			    printf("Second number:%.2f\n",y);
		    }			  
		        z=fmod(x,y);  
		        printf("answer is %.2lf\n",z);
                invent[index]=z; //Adding answer to memory
			    index++;				
	        }
	        else if(ch=='P' || ch=='p')
	        {
              z=pow(x,y);	
              printf("answer is %.2lf\n",z);
			  invent[index]=z; //Adding answer to memory
			  index++;
            }
	
}

void oponly(float *invent)  //If user has already declared 2 float numbers then this function will be called
{
	printf("\nplease chose an operation\n A to add\n S to minus\n M to multiply \n D to divide\n R for remainder\n P for power\n"); 
	        scanf(" %c",&ch); 
			while(ch!='A' && ch!='a' && ch!='S' && ch!='s' && ch!='M' && ch!='m' && ch!='D' && ch!='d' && ch!='R' && ch!='r' && ch!='P' && ch!='p') //Character check
	        {
		    printf("Invalid input\n");
		    printf("Enter valid option:");
		    scanf(" %c",&ch);
	        }
	        if(ch=='A' || ch=='a')  
	        {
		        z=x+y;   
		        printf("result = %.2f\n", z); 
			    invent[index]=z; //Adding answer to memory
			    index++;
		    }
	        else if(ch=='S'|| ch=='s') 
		    {
		        z=x-y;  
		        printf("answer is %.2f\n",z);
                invent[index]=z; //Adding answer to memory
			    index++;			   
	        }
		    else if(ch=='M' || ch=='m')  
		    {
		        z=x*y;  
		        printf("answer is %.2f\n",z); 
			    invent[index]=z; //Adding answer to memory
			    index++;
	        }
	        else if(ch=='D' || ch=='d')  
		    {
		        while(y==0)
		    {
			    printf("please enter vaild second number(non-zero) for division: \n"); 
	            while(scanf("%f", &y)!=1)             //If scanf read character then it will enter the loop and if it reads number it won't enter the loop
                { 
				if(scanf("%2c", &m))
				{	
				printf("Invalid Input\n");	
				printf("please enter Second number:");
				}	
			    }	
			   printf("Second number:%.2f\n",y);
		    }			  
		       z=x/y;  
		       printf("answer is %.2f\n",z); 
			   invent[index]=z; //Adding answer to memory
			   index++;
	        }
	        else if(ch=='R' || ch=='r')  
		    {
		        while(y==0) //As long as y is 0 loop will continue
		        {
			    printf("please enter vaild second number(non-zero) for division: \n"); 
	            while(scanf("%f", &y)!=1) //If scanf read character then it will enter the loop and if it reads number it won't enter the loop
                { 
				if(scanf("%2c", &m))
				{	
				printf("Invalid Input\n");	
				printf("please enter Second number:");
				}	
			    }	
			    printf("Second number:%.2f\n",y);
		    }			  
		        z=fmod(x,y);  
		        printf("answer is %.2lf\n",z); 
				invent[index]=z; //Adding answer to memory
			    index++;
	        }
	        else if(ch=='P' || ch=='p')
	        {
                z=pow(x,y);	
                printf("answer is %.2lf\n",z);
			    invent[index]=z; //Adding answer to memory
			    index++;
            }
}
	
	


  
void unary(float *invent)
{
	float x1,z1;
	char ch;
	printf("Please choose one of the following:\n S for square root\n L for logarithm\n E for exponentiation\n C for ceiling\n F for floor\n"); 
			scanf(" %c", &ch);
			while(ch!='S' && ch!='s' && ch!='L' && ch!='l' && ch!='E' && ch!='e' && ch!='C' && ch!='c' && ch!='F' && ch!='f') //Character check
	        {
		    printf("Invalid input\n");
		    printf("Enter valid option:");
		    scanf(" %c",&ch);
	        }
			printf("Your choice is  %c\n", ch);
			printf("Please enter a number:\t");
			x1 = numcheck();  //Number check
			
		 if(ch=='S' || ch=='s')
		        {
			  while(x1<=0)   //If x1 is 0 then asking user for another input
		        {
				printf("Invalid Input\n");	
			    printf("please enter a vaild number: \n"); 
				scanf("%2f",&x1);	
				}		
			    z1=sqrt(x1);
			    printf("The square root of %.2lf is %.2lf\n",x1,z1);
				invent[index]=z1; //Adding answer to memory
			    index++;
			     	
		        }
		if(ch=='L' || ch=='l')
		        {
			  while(x1<=0)
		        {
				printf("Invalid Input\n");	
			    printf("please enter a vaild number: \n"); 
				scanf("%2f",&x1);	
				}		
			    z1=log(x1);
			    printf("The log(%.2f) is %.2lf\n",x1,z1);
				invent[index]=z1;//Adding answer to memory
			    index++;
			     
		        }
		if(ch=='E' || ch=='e')
		        {
			    z1=exp(x1);
			    printf("e to power %.2f is %.2lf\n",x1,z1);
				invent[index]=z1;//Adding answer to memory
			    index++;
			     	
		        }	
		if(ch=='C' || ch=='c')
		        {
			    z1=ceil(x1);
			    printf("Ceiling of %.2lf is %.2lf\n", x1, z1);
				invent[index]=z1;//Adding answer to memory
			   index++;
			    
		        }	
		if(ch=='F' || ch=='f')
		        {
			    z1=floor(x1);
			    printf("Floor of %.2lf is %.2lf\n", x1, z1);
				invent[index]=z1;//Adding answer to memory
			    index++;
		        }
}

void oponly1(float *invent) //If user has already declared one float number then this function will be called
{
	        printf("Please choose one of the following:\n S for square root\n L for logarithm\n E for exponentiation\n C for ceiling\n F for floor\n"); 
			scanf(" %c", &ch);
			printf("Your choice is  %c\n", ch);
			printf("Please enter a number:\t");
			while(scanf("  %f",&x)!=1)
			{
				if(scanf("%2c", &m))
				{	
				printf("Invalid Input\n");	
				printf("please enter number:");
				}	
			}	
		 if(ch=='S' || ch=='s')
		        {
			  while(x<=0)   
		        {
				printf("Invalid Input\n");	
			    printf("please enter a vaild number: \n"); 
				scanf("%2f",&x);	
				}		
			    z=sqrt(x);
			    printf("The square root of %.2lf is %.2lf\n",x,z);
				invent[index]=z; //Adding answer to memory
			    index++;
			     	
		        }
		if(ch=='L' || ch=='l')
		        {
			  while(x<=0)
		        {
				printf("Invalid Input\n");	
			    printf("please enter a vaild number: \n"); 
				scanf("%2f",&x);	
				}		
			    z=log(x);
			    printf("The log(%.2f) is %.2lf\n",x,z);
				invent[index]=z;//Adding answer to memory
			    index++;
			     
		        }
		if(ch=='E' || ch=='e')
		        {
			    z=exp(x);
			    printf("e to power %.2f is %.2lf\n",x,z);
				invent[index]=z;//Adding answer to memory
			    index++;
			     	
		        }	
		if(ch=='C' || ch=='c')
		        {
			    z=ceil(x);
			    printf("Ceiling of %.2lf is %.2lf\n", x, z);
				invent[index]=z;//Adding answer to memory
			    index++;
			    
		        }	
		if(ch=='F' || ch=='f')
		        {
			    z=floor(x);
			    printf("Floor of %.2lf is %.2lf\n", x, z);
				invent[index]=z;//Adding answer to memory
			    index++;
		        }
}
	

void vnv() // vnv -  variable and values - both will be declared by user
{
	
	char ch1;
	        printf("please enter a number: \n");    
	        k = numcheck(); //number check
			printf("Enter a character from 'a to e':"); 
		      
			
			ch1 = varcheck(); // variable check
				if(ch1=='a')  
				{
					a=k;
					printf("Variable value of %c is %.2f\n",ch1,k);
				}
				else if(ch1=='b')
				{
					b=k;
					printf("Variable value of %c is %.2f\n",ch1,k);
				}
				else if(ch1=='c')
				{
					c=k;
					printf("Variable value of %c is %.2f\n",ch1,k);
				}
				else if(ch1=='d')
				{
					d=k;
					printf("Variable value of %c is %.2f\n",ch1,k);
				}
				else if(ch1=='e')
				{
					e=k;
					printf("Variable value of %c is %.2f\n",ch1,k);
				}
}
	
	
void adv()
{
	    
	    char s;
	    
		printf("please enter first number or variable(from 'a' to 'e'): \n");  
	        if(scanf("%f",&x))   //If user enters a number it will be stored in variable x
		    	{
			    printf("First number:%.2f\n",x);
		    	}	
		  	else   //If the user enters a character then it will be stored in ch2 array
			  	{	
				ch2[0] = varcheck();	
				printf("You pick variable:%s\n",ch2);
				
				switch(ch2[0])
				{
					case 'a':
					x=a;
					printf("Value of variable %s is %.2f",ch2,x);
					break;
					
					case 'b':
					x=b;
					printf("Value of variable %s is %.2f",ch2,x);
					break;
					
					case 'c':
					x=c;
					printf("Value of variable %s is %.2f",ch2,x);
					break;
					
					case 'd':
					x=d;
					printf("Value of variable %s is %.2f",ch2,x);
					break;
					
					case 'e':
					x=e;
					printf("Value of variable %s is %.2f",ch2,x);
					break;
				}
				}
		  	printf("\nplease enter second number or variable(from 'a' to 'e'): \n");  
	        if(scanf("%f",&y))   //If user enters a number it will be stored in variable y
		    	{
			    printf("Second number:%.2f\n",y);
		    	}	
		  	else   //If the user enters a character then it will be stored in ch2 array
			  	{	
				ch2[0] = varcheck();	
				printf("You pick variable:%s\n",ch2);
				
				switch(ch2[0])
				{
					case 'a':
					y=a;
					printf("Value of variable %s is %.2f",ch2,y);
					break;
					
					case 'b':
					y=b;
					printf("Value of variable %s is %.2f",ch2,y);
					break;
					
					case 'c':
					y=c;
					printf("Value of variable %s is %.2f",ch2,y);
					break;
					
					case 'd':
					y=d;
					printf("Value of variable %s is %.2f",ch2,y);
					break;
					
					case 'e':
					y=e;
					printf("Value of variable %s is %.2f",ch2,y);
					break;
			  	}	
          }
      printf("Please choose one of the following: B, U, X\n"); 
	    scanf("     %c", &s);
	  	printf("Your choice is %c\n",s);
		switch(s)
		{
			case 'B':
            case 'b':
			oponly(invent); //Function call for binary operations
			break;
			
			case 'U':
			case 'u':
			oponly1(invent); //Function call for unary operations
			break;
			
			case 'X':
			case 'x':
			break;     //If user enter x or X it will exit the loop
		}		
    n = menu();			
}

void memorycheck(float *store)
{
	char choice;
	int i,pick;
	if(index==0) //Checking if any calculations are stored in memory or it is empty 
	{
	   printf("The memory is empty\n");
	}
	else
	{
	   printf("There are %d calculations availible in the memory\n",index); 
	}
	printf("You have 3 choice:\n A) - View all memory \n S) - View Specific memory \n X) - Exit\n");
	scanf(" %c",&choice);
	
	while(choice!='X' || choice!=x)
	{
	if(choice=='A' || choice=='a')
	{
	    printf("Below is the memory\n"); //printing all the memories that is availible 
		for(i=0;i<index;i++)
		{
		printf("%f\n",invent[i]);
		}
		n=menu();
	}
	else if(choice=='S' || choice=='s')
	{
		printf("There are 0-%d index availible to check. Which one you want to see? -", index); //Telling user the range of availble memory 
		pick = numcheck(); //After user enters a number it will checked if it is correct or not
		if(pick>index)   //if user enters index that is not in memory it will take user in the first menu
		{
			printf("\nThere is no index availible\n");
			break;
		}
		printf("Index %d = %f\n",pick,invent[pick]); //If user enters correct index then that specific index will display
		n=menu();
	}
	else if(choice=='X' || choice=='x')
	{
		n=menu();
	}
	}
}

void memoryremove(float *store)
{
    index = 0; //Making index 0 to reset the memory 
	invent = (float *)malloc(100* sizeof(float));
	printf("All the memory has been removed\n");
}  		
	
void done()
{
	printf("Thank you for using command line calculator Goodbye!!\n\n");
}
	
		

		
		
	