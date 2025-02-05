
// // Structure, union and enum

// #include<iostream>
// using namespace std;

// typedef struct employee
// {
//     /* data */
//     int eId; //4
//     char favChar; //1
//     float salary; //4
// } ep;

// union money
// {
//     /* data */
//     int rice; //4
//     char car; //1
//     float pounds; //4
// };


// int main(){
//     enum Meal{ breakfast, lunch, dinner};
//     Meal m1 = lunch;
//     cout<<(m1==2);
//     // cout<<breakfast;
//     // cout<<lunch;
//     // cout<<dinner; 
//     // union money m1;
//     // m1.rice = 34;
//     // m1.car = 'c';
//     // cout<<m1.car;

//     // ep harry;
//     // struct employee shubham;
//     // struct employee rohanDas;
//     // harry.eId = 1;
//     // harry.favChar = 'c';
//     // harry.salary = 120000000;
//     // cout<<"The value is "<<harry.eId<<endl; 
//     // cout<<"The value is "<<harry.favChar<<endl; 
//     // cout<<"The value is "<<harry.salary<<endl; 
//     return 0;
// }


// # include <iostream>
// using namespace std;
// struct student
// {
//     int roll_no;
//     char favchar;
//     float marks;
// };
// int main()
// {
//     student aniket;
//     aniket.roll_no = 22665143;
//     aniket.favchar = 'A';
//     aniket.marks = 88;
//     cout<<"The roll_no is "<<aniket.roll_no<<endl;
//     cout<<"The favchar is "<< aniket.favchar<<endl;
//     cout<<"The marks is "<<aniket.marks<<endl;


// return 0;
// }

# include <iostream>
using namespace std;
union marks
{
    float number;
    char grade;
};
int main()
{
    union marks aniket;
    
return 0;
}