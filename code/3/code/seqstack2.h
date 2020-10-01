#define TRUE 1
#define FALSE 0
#define Stack_Size 50


/*顺序栈-整型*/
typedef struct
{
	int elem[Stack_Size];  /*用来存放栈中元素的一维数组*/
	int  top;          /*用来存放栈顶元素的下标，top为-1表示栈是空栈*/
}nStack;

/*初始化*/
void  nInitStack(nStack *S)
{
/*构造一个空栈S*/
  	S->top=-1;
}

/*判栈空*/
int nIsEmpty(nStack *S)	/*判断栈S为空栈时返回值为真，反之为假*/
{
	return(S->top==-1?TRUE:FALSE);
}

/*判栈满*/
int nIsFull(nStack *S)	/*判断栈S为满栈时返回值为真，反之为假*/
{
	return(S->top==Stack_Size-1?TRUE:FALSE);
}

int nPush(nStack * S, int x)
{
	if(S->top== Stack_Size-1)  return(FALSE);  /*栈已满*/
	S->top++;
	S->elem[S->top]=x;
	return(TRUE);
}

int nPop(nStack * S, int *x)
{  /* 将栈S的栈顶元素弹出，放到x所指的存储空间中 */
	if(S->top==-1)  /*栈为空*/
		return(FALSE);
	else
	{
  		*x= S->elem[S->top];
		S->top--;    /* 修改栈顶指针 */
  		return(TRUE);
	}
}

int nGetTop(nStack *S, int *x)
{  /* 将栈S的栈顶元素弹出，放到x所指的存储空间中，但栈顶指针保持不变 */
	if(S->top==-1)  /*栈为空*/
		return(FALSE);
	else
	{
  		*x = S->elem[S->top];
  		return(TRUE);
	}
}


/*顺序栈-字符型*/
typedef struct
{
	char elem[Stack_Size];  /*用来存放栈中元素的一维数组*/
	int  top;          /*用来存放栈顶元素的下标，top为-1表示栈是空栈*/
}strStack;

/*初始化*/
void strInitStack(strStack *S)
{
/*构造一个空栈S*/
  	S->top=-1;
}

/*判栈空*/
int strIsEmpty(strStack *S)	/*判断栈S为空栈时返回值为真，反之为假*/
{
	return(S->top==-1?TRUE:FALSE);
}

/*判栈满*/
int strIsFull(strStack *S)	/*判断栈S为满栈时返回值为真，反之为假*/
{
	return(S->top==Stack_Size-1?TRUE:FALSE);
}

char strPush(strStack * S, char x)
{
	if(S->top== Stack_Size-1)  return(FALSE);  /*栈已满*/
	S->top++;
	S->elem[S->top]=x;
	return(TRUE);
}

char strPop(strStack * S, char *x)
{  /* 将栈S的栈顶元素弹出，放到x所指的存储空间中 */
	if(S->top==-1)  /*栈为空*/
		return(FALSE);
	else
	{
  		*x= S->elem[S->top];
		S->top--;    /* 修改栈顶指针 */
  		return(TRUE);
	}
}

int strGetTop(strStack *S, char *x)
{  /* 将栈S的栈顶元素弹出，放到x所指的存储空间中，但栈顶指针保持不变 */
	if(S->top==-1)  /*栈为空*/
		return(FALSE);
	else
	{
  		*x = S->elem[S->top];
  		return(TRUE);
	}
}

/*功能函数*/
int Match(char ch,char str)
{		
	if(ch=='('&&str==')')
	{
		return TRUE;
	}
	else if(ch=='['&&str==']')
	{
		return TRUE;
	}
	else if(ch=='{'&&str=='}')
	{
		return TRUE;
	}
	else return FALSE;
}

int In(char ch)
{
	if(ch=='+')
	{
		return TRUE;	
	}
	else if(ch=='-') 
	{
		return TRUE;	
	}
	else if(ch=='*')
	{
		return TRUE;	
	}
	else if(ch=='/')
	{
		return TRUE;	
	}
	else if(ch=='(')
	{
		return TRUE;	
	}
	else if(ch==')')
	{
		return TRUE;	
	}
	else if(ch=='#')
	{
		return TRUE;	
	}
	else return FALSE;
}

char Compare(char x,char ch)
{
	switch(x)
	{
	case '+':
		if(ch=='+'||ch=='-'||ch==')'||ch=='#')
			return '>';	
		else if(ch=='*'||ch=='/'||ch=='(')
				return '<';	
		break;
	case '-':
		if(ch=='+'||ch=='-'||ch==')'||ch=='#')
			return '>';	
		else if(ch=='*'||ch=='/'||ch=='(')
			return '<';	
		break;
	case '*':
		if(ch=='(')
		{
			return '<';
		}
		else
		{
			return '>';
		}
		break;
	case '/':
		if(ch=='(')
				return '<';	
		else
				return '>';	
		break;
	case '(':
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='(')
			return '<';	
		else if(ch==')')
			return '=';	
		else if(ch=='#')
			return '0';	
		break;
	case ')':
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch==')'||ch=='#')
			return '>';	
		else if(ch=='(')
			return '0';	
		break;
	case '#':
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='(')
			return '<';	
		else if(ch=='#')
			return '=';	
		else if(ch==')')
			return '0';	
		break;	
	default:
		return '0';
		break;
	}

}	

int Execute(int a,char op,int b)
{
	switch(op)
	{
	case '+':
		return (a+b);
		break;
	case '-':
		return (a-b);
		break;
	case '*':
		return (a*b);
		break;
	case '/':
		return (a/b);
		break;
	}
}