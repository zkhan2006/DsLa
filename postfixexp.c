#include<stdio.h>
#include<ctype.h>
#define MAX 100

int st[MAX];
int top=-1;

void push(int st[],int val);
int pop(int st[]);
int evaluatePostfixExp(char exp[]);

int main()
{
	int val;
	char exp[100];
	printf("\nEnter any postfix expression: ");
	fgets(exp,sizeof(exp), stdin);     //safe input
	
	
	
	val =evaluatePostfixExp(exp);
	printf("\nValue of the postfix expression =%d\n",val);
	return 0;
}

int evaluatePostfixExp(char exp[]){
	int i=0,op1,op2,value;
	
	while(exp[i]!='\0'&&exp[i]!='\n')
	{
		if (isdigit(exp[i])){
			int digit=exp[i]-'0';
			push(st,digit);
			
		}else if(exp[i]!=' '&&exp[i]!='\t')  //skip spces
		{
			op2=pop(st);
			op1=pop(st);
			
			
			switch(exp[i]){
				case '+':
					value=op1+op2;
					break;
				case '-':
					value=op1-op2;
					break;
				case '*':
					value=op1*op2;
					break;
				case '/':
					value=op1/op2;
					break;
				case '%':
					value=op1%op2;
					break;
					default:
						printf("\nInalid operator: %c",exp[i]);
						return 0;
			}
			push(st,value);
			
		}
		i++;
	}
	return pop(st);
}

void push(int st[],int val){
	if(top==MAX-1){
		printf("\nStack Overflow");
	}else{
		st[++top]=val;
	}
}

int pop(int st[]){
	if(top==-1){
		printf("\nStack underflow");
		return -1;
	}
	return st[top--];
	
}


