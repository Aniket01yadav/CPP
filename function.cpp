#include<iostream>
using namespace std;

// Function prototype
// type function-name (arguments);
// int sum(int a, int b); //--> Acceptable
// int sum(int a, b); //--> Not Acceptable 
int sum(int, int); //--> Acceptable 
// void g(void); //--> Acceptable 
void g(); //--> Acceptable 

int main(){
    int num1, num2;
    cout<<"Enter first number"<<endl;
    cin>>num1;
    cout<<"Enter second number"<<endl;
    cin>>num2;
    // num1 and num2 are actual parameters
    cout<<"The sum is "<<sum(num1, num2);
    g();
    return 0;
}

int sum(int a, int b){
    // Formal Parameters a and b will be taking values from actual parameters num1 and num2.
    int c = a+b;
    return c;
}

void g(){
    cout<<"\nHello, Good Morning";
}




// # include <iostream>
// using namespace std;
// int sum(int a,int b);
// int main()
// {
//     int a,b;
//     cout<<"Enter the first number : "<<endl;
//     cin>>a;
//     cout<<"Enter the second number : "<<endl;
//     cin>>b;
//     cout<<"The sum is : "<<sum(a,b)<<endl;
//     cout<<10*sum(a,b)<<endl;
//     cout<<sum(a,b)/10;
// return 0;
// }
// int sum(int a,int b)
// {
//     int c;
//     c = a+b;
//     return c;
// }