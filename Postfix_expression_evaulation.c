/* postfix evaluation by the help of stack */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 40
void evaluation ();
void push (int symbol);
int pop ();
int a[size];
int top = -1;
int isoperator (char symbol);
int
main ()
{
  evaluation ();
}

	// evaluation for postfix expression
void
evaluation ()
{
  char postfix[20];
  int i = 0;
  char item;
  int x, y, value;
  printf ("Enter the postfix expression:\n");
  scanf ("%s", postfix);
  while (postfix[i] != '\0')
    {
      if (isdigit (postfix[i]))
	push (postfix[i] - '0');
      else if (isoperator (postfix[i]) == 1)
	{
	  item = postfix[i];
	  x = pop ();
	  y = pop ();
	  switch (item)
	    {
	    case '+':
	      value = x + y;
	      break;
	    case '-':
	      value = y - x;
	      break;
	    case '/':
	      value = y / x;
	      break;
	    case '*':
	      value = y * x;
	      break;
	    case '^':
	      value = y ^ x;
	      break;
	    }
	  push (value);
	}
      i++;
    }
  printf ("The evaluation is:\n");
  printf ("%d\n", pop ());
}

	// for push value on the stack
void
push (int symbol)
{
  if (top == size - 1)
    printf ("stack is full:\n");
  else
    {
      top++;
      a[top] = symbol;
    }
}

int
isoperator (char symbol)
{
  if (symbol == '-' || symbol == '+' || symbol == '*' || symbol == '^'
      || symbol == '/')
    return 1;
  else
    return 0;
}

	// for poped value from the stack
int
pop ()
{
  int x;
  if (top == -1)
    {

      printf
	("#######################################################################\n");
      printf
	("#                        STACK IS EMPTY                               #\n");
      printf
	("#######################################################################\n");
    }
  else
    {
      x = (int) a[top];
      top--;
      return x;
    }
}

