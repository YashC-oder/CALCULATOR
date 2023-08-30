#include<iostream>
#include<cmath>
#include<cstdlib>
#include<iomanip>
using namespace std;
char ch;
int isnum(char);
double getnum();
double calculate();
void print(double);
int main()
{
    cout<<"HELLO IM YASH\nTHIS IS A CALCULATOR PROGRAM\n";
    cout<<"USE :\n<+> For Addition\n<-> For Subtraction\n<*> For Multiplication\n</> For Division\n<^> For Power Operations"<<endl;
    cout<<"Enter : ";
    double ans=calculate();
    print(ans);
}
int isnum(char ch)
{
    return ch>='0'&&ch<='9';
}
double getnum()
{
    double num=0;
    int N=0;
    ch=getchar();
    while(isnum(ch)||ch=='.')
    {
        if(ch=='.')
        {
          ch=getchar();
          while(isnum(ch))
          {
              N++;
              num=num*10+ch-'0';
              ch=getchar();
          }
          num=num/pow(10,N);
          break;
        }
        num=num*10+ch-'0';
        ch=getchar();
    }
    return num;
}
double calculate()
{
    double a,b,c,A=0;
    a=getnum();
    if(a==0)
    {
        if(ch=='(')
        a=calculate();
        else a=0;
    }
    while(ch!='\n')
    {
        switch(ch)
        {
            case '+':
            b=getnum();
            if(b==0)
            {
                if(ch=='(')
                b=calculate();
            }
            else if(ch!='+')
            {
                A+=a;
                a=b;
                continue;
            }
            a+=b;
            continue;
            
            case '-':
            b=getnum();
            if(b==0)
            {
               if(ch=='(')
               b=calculate();
            }
            else if(ch!='-')
            {
                A+=a;
                a=-b;
                continue;
            }
            a-=b;
            continue;
            
            case '*':
            b=getnum();
            if(b==0)
            {
                if(ch=='(')
                b=calculate();
            }
            if(ch=='^')
            {
            c=getnum();
            if(c==0) c=calculate();
            b=pow(b,c);
            }
            a*=b;
            continue;
            
            case '/':
            b=getnum();
            if(b==0)
            {
                if(ch=='(')
                b=calculate();
            }
            if(ch=='^')
            {
            c=getnum();
            if(c==0) c=calculate();
            b=pow(b,c);
            } 
            a/=b;
            continue;

            case '(':
            b=calculate();
            a*=b;
            continue;
            
            case ')':
            ch=getchar();
            if(ch=='^')
            {
                b=getnum();
                if(b==0) b=calculate();
                a=pow(a+A,b);
                return a;
            }
            else if(ch=='*')
            {
                a+=A;
                while(ch=='*')
                {
                b=getnum();
                if(b==0)
                {
                    if(ch=='(') b=calculate();
                    else b=0;
                }
                a*=b;
                }
                return a;
            }
            else if(ch=='/')
            {
                a+=A;
                while(ch=='/')
                {
                b=getnum();
                if(b==0)
                {
                    if(ch=='(') b=calculate();
                    else b=0;
                }
                a/=b;
                }
                return a;
            }
            else if(ch=='(')
            {
                a+=A;
                continue;
            }
            return a+A;
            
            case '^':
            b=getnum();
            if(b==0)
            {
                if(ch=='(')
                b=calculate();
                else b=0;
            }
            a=pow(a,b);
            continue;
        }
    }
    return a+A;
}
void print(double ans)
{
    int temp=ans;
    if(ans==temp)
    cout<<"=>"<<temp;
    else cout<<fixed<<setprecision(5)<<"=>"<<ans;
}