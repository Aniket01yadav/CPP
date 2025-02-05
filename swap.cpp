// # include <iostream>
// using namespace std;

// void swap(int a,int b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
//     cout<<"Values after swap a = "<<a<<" b = "<<b<<endl;
// }

// int main()
// {
//     int a=10,b=45;
//     cout<<"The value of a is : "<<a<<endl;
//     cout<<"The value of b is : "<<b<<endl;
//     swap(a,b);
// return 0;
// }



# include <iostream>
using namespace std;
// void swap(int a, int b){ //temp a b
//     int temp = a;        //4   4  5   
//     a = b;               //4   5  5
//     b = temp;            //4   5  4 
// }
// int main(){
//     int x =4, y=5;
//     cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl;
//     swap(x, y); 
//     cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl; 
//     return 0;
// }

void swapReferenceVar(int &a, int &b){    //temp a b
    int temp = a;          //4   4  5   
    a = b;               //4   5  5
    b = temp;            //4   5  4 
}
int main()
{
    int x =4, y=5;
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl;
    swapReferenceVar(x, y); //This will swap a and b using reference variables
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl; 
    return 0;
}
