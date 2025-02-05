// # include <iostream>
// using namespace std;
// int main()
// {
//     cout<<"Hello world";
//     return 0;
// }


// # include <iostream>
// using namespace std;
// int main()
// {
//     int a,b;
//     cout<<"Enter the any two number : ";
//     cin>>a>>b;
//     cout<<"The sum is a+b : "<<a+b;
//     return 0;
// }

// # include <iostream>

// using namespace std;

// int main()
// {
//     int a,b,c;
//     cout<<"Enter the value of a,b and c : ";
//     cin>>a>>b>>c;
//     if(a>b && a>c)
//     {
//         cout<<"Greater number is : "<<a;
//     }
//     else if(b>a && b>c)
//     {
//         cout<<"Greater bumber is : "<<b;
//     }
//     else
//     {
//         cout<<"Greater number is : "<<c;
//     }
//     return 0;
// }


// # include <iostream>
// using namespace std;
// int main()
// {
//     int n,i;
//     cout<<"Enter any number : ";
//     cin>>n;
//     for(i=1 ; i<=n ; i++)
//     {
//         cout<<i;
//     }
// }
# include <iostream>
using namespace std;
int main(){
    /* What is a pointer? ----> Data type which holds the 
    address of other data types*/
    int a=3;
    int* b;
    b = &a;

    // & ---> (Address of) Operator
    cout<<"The address of a is "<<&a<<endl;
    cout<<"The address of a is "<<b<<endl;

    // * ---> (value at) Dereference operator
    cout<<"The value at address b is "<<*b<<endl;

    // Pointer to pointer
    int** c = &b;
    cout<<"The address of b is "<<&b<<endl;
    cout<<"The address of b is "<<c<<endl; 
    cout<<"The value at address c is "<<*c<<endl; 
    cout<<"The value at address value_at(value_at(c)) is "<<**c<<endl; 

    return 0;
}
