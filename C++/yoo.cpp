 #include <iostream>
 using namespace std;
 class complexno
 {    
int a, b; 
public:    
void setdata(int x, int y)
 {        
a=x;       
 b=y; }  
void getdata()    
{    cout<<"a = "<<a <<"b = "<<b;    }    
    
     
operator int()    
{        
return (a+b);    }
 };
 int main()
 {    
complexno c1;    
c1.setdata(3,4);    
int x;    
x=c1;    
cout<<endl<<"x="<<x;        
return 0;
 }
