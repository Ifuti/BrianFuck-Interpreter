#include <stdio.h>
#include <stdlib.h>

char tape[100],inst[1000],b,*i_ = inst;
int head=0,loop;
void interpret(char *instruction)
{
	char *temp;
	while (*instruction)
	{
		switch (*instruction++)
	{
		case '>':head++;break;
		case '<':head--;break;
		case '+':tape[head]++;break;
		case '-':tape[head]--;break;
		case '.':putchar(tape[head]);fflush(stdout);break;
		case ',':tape[head] = getchar();break;
		case '[':
			temp = instruction;
			for(loop=1;loop && *instruction;instruction++)
				loop+=(*instruction=='['),loop-=(*instruction==']');
			if(!loop)
			{
				instruction[-1]=0;
				while( tape[head] )
					interpret(temp);
				instruction[-1]=']';
				break;
			}
		case ']':puts("Parenthesis is not closed!");exit(0);
		default:break;
	}
	if(head<0 || head>99)
		puts("Out of range!"),exit(0);
	}
}
int main(int argc,char *argv[])
{
	FILE *f;
	if(f = fopen(argv[1],"r"))
	{
	while ((b = getc(f))>0)
		*i_++=b;
	i_ = &inst[0];
	}
	interpret(i_);
}