/*
Question 5:
Write a program to implement stack as an ADT. Use this ADT to perform expression conversion and evaluation. (Infix → Postfix)
*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define max 50
char stack[max];
int top=-1;

int push(char x)
{
    stack[++top]=x;
    return 0;
}
int pop()
{
    return stack[top--];
}
int precidence(char x)
{
    if(x=='^')
        return 3;
    if(x=='*' || x=='/')
        return 2;
    if(x=='+' || x=='-')
        return 1;
    return 0;
}

int main()
{
    char infix[max],postfix[max],ch;
    int i=0,j=0;
    
    printf("\n Enter a infix expression : \n");
    scanf("%s",infix);
    
    
    while(infix[i]!='\0')
    {
        ch=infix[i];
        
        
        if(isalnum(ch))
        {
            postfix[j++]=ch;
        }
        else if(ch=='(')
        {
            push(ch);   
        }   
        else if(ch==')')
        {
            while(stack[top]!='(')
            {
                postfix[j++]=pop();
            }
            pop();
        }
        else {
        
        while(precidence(stack[top])>=precidence(ch))
            {
                postfix[j++]=pop();
            }
            push(ch);   
        }   
        i++;
    }
    while(top!=-1)
    {
        postfix[j++]=pop();
    }
    
    
    printf("\n The postfix expression of %s is : %s",infix,postfix);
    return 0;       
