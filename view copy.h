#include <iostream>

using namespace std;
class View
{
private:
    int type=0;//Среды вывода - 0 - терминал, 1 - бот и терминал
    
public:
View()
{
    type=0;
}
View(int n)
{
    type=n;
}

template<typename T> void print(T a)
{
    switch (type)
    {
    case 0:
        cout<<a;
    case 1:
        
        break;
    default:
        break;
    }
    
}
template<typename T> void println(T a)
{
    switch (type)
    {
    case 0:
        cout<<a<<endl;
    case 1:
        
        break;
    default:
        break;
    }
}

void menu()
{
    println("Input");
    println("1 to open the 1st lab work"); 
    println("2 to open the 2nd lab work");
    println("3 to open the 3rd lab work");
    println("");

    println("Another number to terminate");
}

void end()
{
    println("The program is terminated");
    println("***");
}
};