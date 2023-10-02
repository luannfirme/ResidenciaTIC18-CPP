#include <iostream>

using namespace std;

int main(){
   int arms, check, sum, rem;
  
  sum = 0;
   
   cout<<"Informe um numero: ";
   cin>>arms;
   check = arms;
   
   while(check != 0){
       rem = check % 10;
       sum = sum + (rem*rem*rem);
       check = check / 10;
   }
   
   if(sum == arms){
       cout<<arms<<" e um numero Armstrong"<<endl;
   }else{
       cout<<arms<<" nao e um numero Armstrong"<<endl;
   }
    return 0;
}