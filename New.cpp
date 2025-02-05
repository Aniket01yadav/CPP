# include <iostream>
using namespace std;
int main()
{
    int a,b,c,d,e,r;
    cout<<"Enter the your range 1 to ";
    cin>>r;
    switch(r)
    {
        case 10:
        cout<<"You have only one chance\n"<<"You can choose your number between 1 to 10 : ";
        cin>>a;
        if(a==9)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else
        {
            cout<<"YOU CHOOSE THE WRONG NUMBER";
        }
        break;
        case 20:
        cout<<"You have two chanses\n"<<"You can choose your number between 1 to 20 : ";
        cin>>a;
        if(a==13 || a==17)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else{
            cout<<"YOU CHOOSE THE WRONG NUMBER";
        }
        if(a==13 || a==17)
        {
            break;
        }
        cout<<"\nYou have only one chanse\n";
        cin>>b;
        if(b==13 || b==17)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else{
            cout<<"YOU LOST YOUR CHANCE,PLEASE TRY AGAIN.";
        }
        break;
        case 30:
        cout<<"You have three chanses\n"<<"You can choose your number between 1 to 30 : ";
        cin>>a;
        if(a==4 || a==11 || a==23)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else{
            cout<<"YOU CHOOSE THE WRONG NUMBER";
        }
        if(a==4 || a==11 || a==23)
        {
            break;
        }
        cout<<"\nYou have only two chanses\n";
        cin>>b;
        if(b==4 || b==11 || b==23)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else{
            cout<<"YOU CHOOSE THE WRONG NUMBER";
        }
        if(a==4 || a==11 || a==23)
        {
            break;
        }
        cout<<"\nYou have only one chanse\n";
        cin>>c;
        if(c==4 || c==11 || c==23)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else{
            cout<<"YOU LOST YOUR CHANCE,PLEASE TRY AGAIN.";
        }
        break;
        case 40:
        cout<<"You have four chanses\n"<<"You can choose your number between 1 to 40 : ";
        cin>>a;
        if(a==1 || a==19 || a==25 || a==31)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else{
            cout<<"YOU CHOOSE THE WRONG NUMBER";
        }
        if(a==1 || a==19 || a==25 || a==31)
        {
            break;
        }
        cout<<"\nYou have only three chanses\n";
        cin>>b;
        if(b==1 || b==19 || b==25 || b==31)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else{
            cout<<"YOU CHOOSE THE WRONG NUMBER";
        }
        if(b==1 || b==19 || b==25 || b==31)
        {
            break;
        }
        cout<<"\nYou have only two chanse\n";
        cin>>c;
        if(c==1 || c==19 || c==25 || c==31)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else{
            cout<<"YOU CHOOSE THE WRONG NUMBER";
        }
        if(c==1 || c==19 || c==25 || c==31)
        {
            break;
        }
        cout<<"\nYou have only one chanse\n";
        cin>>d;
        if(d==1 || d==19 || d==25 || d==31)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else{
            cout<<"YOU LOST YOUR CHANCE,PLEASE TRY AGAIN.";
        }
        break;
        case 50:
        cout<<"You have five chanses\n"<<"You can choose your number between 1 to 50 : ";
        cin>>a;
        if(a==3 || a==18 || a==28 || a==41 || a==49)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else{
            cout<<"YOU CHOOSE THE WRONG NUMBER";
        }
        if(a==3 || a==18 || a==28 || a==41 || a==49)
        {
            break;
        }
        cout<<"\nYou have only four chanses\n";
        cin>>b;
        if(b==3 || b==18 || b==28 || b==41 || b==49)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else{
            cout<<"YOU CHOOSE THE WRONG NUMBER";
        }
        if(b==3 || b==18 || b==28 || b==41 || b==49)
        {
            break;
        }
        cout<<"\nYou have only three chanse\n";
        cin>>c;
        if(c==3 || c==18 || c==28 || c==41 || c==49)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else{
            cout<<"YOU CHOOSE THE WRONG NUMBER";
        }
        if(c==3 || c==18 || c==28 || c==41 || c==49)
        {
            break;
        }
        cout<<"\nYou have only two chanse\n";
        cin>>d;
        if(d==3 || d==18 || d==28 || d==41 || d==49)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else{
            cout<<"YOU CHOOSE THE WRONG NUMBER";
        }
        if(d==3 || d==18 || d==28 || d==41 || d==49)
        {
            break;
        }
        cout<<"\nYou have only one chanse\n";
        cin>>e;
        if(e==1 || e==19 || e==25 || e==31)
        {
            cout<<"CONGRATS, YOU WON";
        }
        else{
            cout<<"YOU LOST YOUR CHANCE,PLEASE TRY AGAIN.";
        }
        break;
    }
    
}