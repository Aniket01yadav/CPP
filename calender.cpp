# include <iostream>
using namespace std;

int main()
{
    cout<<"Mon"<<"\tTue"<<"\tWed"<<"\tThu"<<"\tFri"<<"\tSat"<<"\tSun";
    for(int i=1 ; i<=31 ; i++)
    {
        if(i==1)
        {
            cout<<"\n\t\t\t\t\t\t "<<i;
        }
        // else if(i<=2)
        // {
            cout<<i;
        // }
        // cout<<i;
    }
return 0;
}