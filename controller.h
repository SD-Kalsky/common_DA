#include <iostream>
#include <random>
#include "Table.h"
#include "view.h"
using namespace std;

class Controller
{
View view;
Table table;
public:
void start()
{ 
    view.menu();
    char n;
    cin>>n;
    switch(n)
    {
        case '1':
            lab1();
            break;
        case '2':
            lab2();
            break;
        case '3':
            lab3();
            break;
        case '4':
            lab4();
            break;
        case '5':
            lab5();
            break;
        case '6':
            lab6();
            break;
        case '7':
            lab7();
            break;
        case '8':
            lab8();
            break;
        default:
            break;
    }
    view.end();
}
void end() //I dont why do I have it. Let it be
{
    view.end();
}
void lab1()
{
    string tablename="lw1/mytable.csv";
    char n;
    
    view.println("Input");
    view.println("1 to load mytable.csv file");
    view.println("2 to input a name of your file");
    view.println("Another number to terminate");
    cin>>n;
    switch(n)
    {
        case '2':
            view.println("Input a name of the table file ");
            cin>>tablename;
            tablename="lw1/"+tablename;
        case '1':
            table.load(tablename);
            
            view.print("The common sum is " ); view.println(table.common_sum()); // Общая сумма
            view.print("The factor sum is ");view.println(table.factor_sum());// Факторная сумма
            view.print("The sum of the difference is ");view.println(table.difference_sum()); // Сумма разности
            view.print("The factor variance is ");view.println(table.factor_disperia()); // Дисперсия факторная
            view.print("The variance of the difference is ");view.println(table.difference_disperia()); // Дисперсия разности
            view.print("The calculated Fisher's coefficient is ");view.println(table.coef_F());// Рассчитанный коэффициент Фишера
            break;
        default:
            break;
    }
}
void lab2()
{
    string tablename="lw2/mytable.csv";
    char n;

    string sbegin="Since the found value";
    string s0="s ​​of the Fisher coefficient do not exceed the table values, there are no significant differences in the degree of support for candidate voters at the 5% startup level.";
    string sa=" ​​of the Fisher coefficient by A-factor exceeds the table value, there is significant difference in the degree of support for candidate voters at the 5% startup level.";
    string sb=" value ​​of the Fisher coefficient by B-factor exceeds the table value, there is significant difference in the degree of support for candidate voters at the 5% startup level.";
    string sc="s ​​of the Fisher coefficient exceed the table values, there are significant differences in the degree of support for candidate voters at the 5% startup level.";

    
    view.println("Input");
    view.println("1 to load mytable.csv file");
    view.println("2 to input a name of your file");
    view.println("Another number to terminate");
    cin>>n;
    switch(n)
    {
        case '2':
        {            
            view.println("Input a name of the table file ");
            cin>>tablename;
            tablename="lw2/"+tablename;
        }
        case '1':
        {
            table.load(tablename);
            double Fat=Fisher_coef(table.get_strings()-1,(table.get_strings()-1)*(table.get_columns()-1)); //
            double Fbt=Fisher_coef(table.get_columns()-1,(table.get_strings()-1)*(table.get_columns()-1));
            double Fa=table.coef_Fa(), Fb=table.coef_Fb();

            view.print("F_a=");
            view.println(Fa);
            view.print("F_b=");
            view.println(Fb);
            view.print("The Fisher's coefficient of A-factor from the table is ");
            view.println(Fat);
            view.print("The Fisher's coefficient of B-factor from the table is ");
            view.println(Fbt);
            view.print(sbegin);
            if((Fa<Fat)&&(Fb<Fbt)) 
                {
                    view.println(s0);
                }
            else 
                if((Fa>=Fat)&&(Fb>=Fbt)) 
                    {
                        view.println(sc);
                        view.print("Coefficient of determination is ");
                        view.println(table.string_dispersia()/table.common_dispersia());

                        int i=0, n=table.get_strings();
                        while(i<n)
                        {
                            view.print("a");view.print(i+1);view.print("=");
                            view.println(table.arithmetic_mean_column(i)-table.common_arithmetic_mean());
                            i++;
                        }
                    }
                else 
                    if (Fa>=Fat)  
                    {
                        view.println(sa);
                        view.print("Coefficient of determination is ");
                        view.println(table.string_dispersia()/table.common_dispersia());

                        int i=0, n=table.get_strings();
                        while(i<n)
                        {
                            view.print("a");view.print(i+1);view.print("=");
                            view.println(table.arithmetic_mean_column(i)-table.common_arithmetic_mean());
                            i++;
                        }
                        i=0, n=table.get_columns();
                        while(i<n)
                        {
                            view.print("b");view.print(i+1);view.print("=");
                            view.println(table.arithmetic_mean_column(i)-table.common_arithmetic_mean());
                            i++;
                        }
                    }
                    else 
                        if (Fb>=Fbt)
                        {
                            view.println(sb);
                            view.print("Coefficient of determination is ");
                            view.println(table.column_dispersia()/table.common_dispersia());

                            int i=0, n=table.get_columns();
                            while(i<n)
                            {
                                view.print("b");view.print(i+1);view.print("=");
                                view.println(table.arithmetic_mean_column(i)-table.common_arithmetic_mean());
                                i++;
                            }
                        }
                        else
                        {

                        }
            
            break;
        }
            
        default:
            break;       
    }    
}
void lab3()
{
    string tablename="lw3/mytable.csv";
    char n;
    
    view.println("Input");
    view.println("1 to load mytable.csv file");
    view.println("2 to input a name of your file");
    view.println("Another number to terminate");
    cin>>n;
    switch(n)
    {
        case '2':
            view.println("Input a name of the table file ");
            cin>>tablename;
            tablename="lw3/"+tablename;
        case '1':
        {
            table.load(tablename);
            table=table.to_rang();
            view.print("");
            view.println(table.r_c());
            view.print("");
            view.println(table.t_c());


            break;
        }
        default:
            break;
    }    
}
void lab4()
{
    
}
void lab5()
{
    
}
void lab6()
{
    
}
void lab7()
{
    
}
void lab8()
{
    
}

//Searching of the coefficients. -1 is an infinity 
double Fisher_coef(int k1, int k2)
{
    Table t;
    t.load("Fisher_table.csv");

    double f=0;
    bool a=false, b=false;
    int i=1, j=1, n=t.get_columns();
    
    while(i<n)
    {
        a=(k1==(t.get_element(i,0)));
        if (a) break;
        i++;
    }
    n=t.get_strings();
    while(j<n)
    {
        b=(k2==(t.get_element(0,j)));
        if (b) break;
        j++;
    }
    if(a*b)
    {
        f+=t.get_element(i,j);
    }
    return f;
}
double Student_coef(int k, double a) 
{
    Table t;
    t.load("StudentOneSide.csv");

    double f=0;
    bool b1=false, b2=false;
    int i=1, j=1, n=t.get_columns();
    while(i<n)
    {
        b1=(a==(t.get_element(i,0)));
        if (b1) break;
        i++;
    }
    n=t.get_strings();
    while(j<n)
    {
        b2=(k==(t.get_element(0,j)));
        if (b2) break;
        j++;
    }
    if(b1*b2)
    {
        f+=t.get_element(i,j);
    }
    return f;
}
};
