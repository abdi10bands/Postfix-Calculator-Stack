

//=========================================================
// stack application (post-fix evaluation)
//Your name: Abdiel Verdin
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: ** The purpose of the program is to test a character stack class that was developed. It will display the stack and preform postfix operations of a calculator using a stack. 
//Algorithm: Should read in an item of char. If it is a number we will be pushing the number into the stack which we may get Overflow exception.  If it is an operator we will pop two numbers in which we might get undeflow exception and apply the operator to the two numbers and push the result. But if it has an ivalid operand throw exception. 
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  // current char
	 // ** do all the steps in the algorithm given in Notes-1 

	 if( isdigit(item))//if its a digit
	   {
	     postfixstack.push(item-'0');
	    
	   }
	 else if((item =='*')||(item =='+')||(item =='-')){
	   
	   //	     int x =int(item)-48; 
	     postfixstack.pop(box1);
	     postfixstack.pop(box2);
	     if(item =='*')
	       postfixstack.push(box2*box1);
	     else if(item =='+')
	       postfixstack.push(box2+box1);
	     else if(item =='-')
	       postfixstack.push(box2-box1);     
	       
	   }
	 else
	   throw"Invalid items detected";
	   
	 	 postfixstack.displayAll();
	   
       }
          // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{cerr << "Error: Overflow. Too many operands.";  exit(1);}//**
      catch (stack::Underflow)
	{cerr << "Error: Underflow, Too few operands "; exit(1); }//**
      catch (char const* errormsg ) // for invalid item case
	{cerr<<" Error s occured :" <<errormsg; exit(1); }/**
	 
      // go back to the loop after incrementing i
      */ 

     
        i++;
       }// end of while
    
 // After the loop successfully completes: 
 // Pop the result and show it.
  // **

  postfixstack.pop(box1);
  cout<<"The result is: "<<endl;
  cout<<box1<<endl;
  if(postfixstack.isEmpty()==false)
      cout<<"incomplete expression "<<endl;
 // If anything is left on the stack, an incomplete expression 
 // was found so inform the user.
 //  **

}// end of the program

    
