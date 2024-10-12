#include <iostream>

using namespace std;
class View
{
public:
void menu()
{
    cout<<"Input"<<endl;
    cout<<"1 to open the 1st lab work"<<endl;
    cout<<"2 to open the 2nd lab work"<<endl;
    cout<<"3 to open the 3rd lab work"<<endl;
    // cout<<"4 to open the 4th lab work"<<endl;
    // cout<<"5 to open the 5th lab work"<<endl;
    // cout<<"6 to open the 6th lab work"<<endl;
    // cout<<"7 to open the 7th lab work"<<endl;
    // cout<<"8 to open the 8th lab work"<<endl;

    cout<<"Another number to terminate"<<endl;
}
void print(string s)
{
    cout<<s;
}
void println(string s)
{
    cout<<s<<endl;
}
void print(float s)
{
    cout<<s;
}
void println(float s)
{
    cout<<s<<endl;
}
void print(double s)
{
    cout<<s;
}
void println(double s)
{
    cout<<s<<endl;
}
void print(int s)
{
    cout<<s;
}
void println(int s)
{
    cout<<s<<endl;
}
void print(long s)
{
    cout<<s;
}
void println(long s)
{
    cout<<s<<endl;
}
void print(char s)
{
    cout<<s;
}
void println(char s)
{
    cout<<s<<endl;
}
void print()
{
    cout<<' ';
}
void println()
{
    cout<<endl;
}
void end()
{
    cout<<"The program is terminated"<<endl<<"***"<<endl;
}
};