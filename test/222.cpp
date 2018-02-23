#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int main(){
  double twodollars;//int 后面能跟数字吗
  double onedollar;
  double twentycents;
  double tencents;
  double fivecents;
  double onecent;
  double a;
  double b;
  double c;
  double d;
  double e;
  double f;

  double value;
  cout<<"The amount of each denomination that you have and the value"<<endl;
  cin>>twodollars>>onedollar>> twentycents>>tencents>>fivecents>>onecent>>value; //a=0；a<=twodollars;a++  for循环这三个之间要用；隔开 
  int g=0; 
  for(f=0;f<=onecent&&g==0 ;f++){// && 2*a + b + 0.25*c + 0.1*d +0.05*e + 0.01*f<=value
    for(e=0;e<=fivecents&&g==0;e++){//&& 2*a + b + 0.25*c + 0.1*d +0.05*e<=value
      for(d=0;d<=tencents&&g==0 ;d++){//&& 2*a + b + 0.25*c + 0.1*d<=value
	for(c=0;c<=twentycents&&g==0 ;c++){//&& 2*a + b + 0.25*c<=value
	  for(b=0;b<=onedollar&&g==0;b++){//是不是因为我必须要先算这一步才能去算a所以这步执行不了   && 2*a + b<=value对
	    for(a=0;a<=twodollars&&g==0 ;a++){//&& 2*a<=value
	      if(200*a+100*b+25*c+10*d+5*e+1*f==value*100){//如果在这里加上or 
		cout<<a<<" * $2, "<<b<< " * $1, "<<c<<" * 25c, "<<d<<" * 10c, "<<e<<" * 5c, "<<f<< " * 1c,"<<endl;//a=0后面要用； 一个=是赋值==是比较相等不想等   如果你把这个的cout放在else里面他会输出a+1，b+1.。。。因为只有a+1才会跳出循环
		g=1;//break 只能跳出这一个循环不能跳出所有的for循环   
	      } 
	    }
	  }
	}
      }
    }
  }
  
  
  if(g==0){
    cout<<"cannot mnake change"<<endl;
  }
  return 0;
}
