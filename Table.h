#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include "matrix.h"
using namespace std;

class Table
{
private:
    int columns, strings;
    double **cells;
    void init()
    {
        cells=new double *[columns];
        int i=0, j;
        while(i<columns)
        {
            cells[i]=new double[strings];
            j=0;
            while(j<strings)
            {
                cells[i][j]=0;
                j++;
            }
            i++;
        }
    }
    void destroy()
    {
        int i=0, j;
        while(i<columns)
        {
            delete cells[i];
            cells[i]=nullptr;
            i++;
        }
        delete cells;
        cells=nullptr;
    }
public:
    Table()
    {
        strings=3;
        columns=3;
        init();
    }
    Table(int a, int b)
    {
        strings=a;
        columns=b;
        init();
    }
    ~Table()
    {
        destroy();
    }

    void set_array(double **arr, int str , int clm)
    {
        columns=clm;
        strings=str;
        cells=arr;
    }   
    double get_element(int i, int j)
    {
        return cells[i][j];
    }
    void set_element(int i, int j, double x)
    {
        cells[i][j]=x;
    }
    int get_columns()
    {
        return columns;
    }
    int get_strings()
    {
        return strings;
    }

    Table operator =(const Table& table)
    {
        int j=0,i;
        Table t (table.strings, table.columns);
        while (j < strings)
        {
            i=0;
            while (i < columns)
            {
                t.cells[i][j]=table.cells[i][j];
                i++;
            }
            j++;
        }
        return t;
    }

    friend ostream & operator<< (ostream & stream, const Table & t)
    {
        int i=0,j;
        while (i < t.strings)
        {
            j=0;
            while (j < t.columns)
            {
                stream <<t.cells[j][i]<<' ';
                j++;
            }
            cout<<endl;
            i++;
        }
        return stream;
    }

    friend istream & operator>> (istream & in, Table & t)
        {
        int i=0,j;
        while (i < t.columns)
        {
            cout <<"Column "<<i+1<<endl;
            j=0;
            while (j < t.strings)
            {
                in>>t.cells[i][j];
                j++;
            }
            i++;
        }
            return in;
        }

    double sum_column(int n)
    {
        int j=0;
        double s=0;
        while (j < strings)
        {
            s+=cells[n][j];
            j++;
        }
        return s;
    }

    double sum_string(int n)//Check it
    {
        int j=0;
        double s=0;
        while (j < columns)
        {
            s+=cells[j][n];
            j++;
        }
        return s;
    }

    double arithmetic_mean_column(int n)
    {
        int j=0;
        double s=0;
        while (j < strings)
        {
            s+=cells[n][j];
            j++;
        }
        return s/strings;
    }

    double arithmetic_mean_string(int n)//Check it
    {
        int j=0;
        double s=0;
        while (j < columns)
        {
            s+=cells[j][n];
            j++;
        }
        return s/columns;
    }

    double common_arithmetic_mean()
    {
        int j=0;
        double s=0;
        while (j < columns)
        {
            s+=arithmetic_mean_column(j);
            j++;
        }
        return s/columns;
    }

    //The first lab
    double common_sum()
    {
        double s=0, x=common_arithmetic_mean();
        int i=0, j;
        while (i < columns)
        {
            j=0;
            while (j < strings)
            {
                s+=(cells[i][j]-x)*(cells[i][j]-x);
                j++;
            }
            i++;
        }
        return s;
    }
    double factor_sum()
    {
        double s, sf=0, x=common_arithmetic_mean();
        int i=0, j;
        while (i < columns)
        {
            j=0;
            s=0;
            while (j < strings)
            {
                s+=cells[i][j];
                j++;
            }
            s/=strings;
            s-=x;
            sf+=(s*s);
            i++;
        }
        return strings*sf;
    }
    double difference_sum()
    {
        return common_sum()-factor_sum();
    }
    double factor_disperia()
    {
        return factor_sum()/(columns-1);
    }
    double difference_disperia()
    {
        return difference_sum()/(columns*(strings-1));
    }
    double coef_F()
    {
        double s1=factor_disperia(), s2=difference_disperia();
        s1/=s2;
        return s1;
    }
    //The first lab
    //The second lab

    double common_variatsia() //Полностью аналогичен common_sum 
    {
        double s=0, x=common_arithmetic_mean();
        int i=0, j;
        while (i < columns)
        {
            j=0;
            while (j < strings)
            {
                s+=(cells[i][j]-x)*(cells[i][j]-x);
                j++;
            }
            i++;
        }
        return s;
    }

    double column_variatsia()
    {
        double s=0, cs=0, x=common_arithmetic_mean();
        int i=0, j;
        while (i < columns)
        {
            s=arithmetic_mean_column(i);
            s-=x;
            s*=s;
            cs+=s;
            s=0;
            i++;
        }
        cs*=strings;
        return cs;
    }
    double string_variatsia()
    {
        double s=0, cs=0, x=common_arithmetic_mean();
        int i=0, j;
        while (i < strings)
        {
            s=arithmetic_mean_string(i);
            s-=x;
            s*=s;
            cs+=s;
            s=0;
            i++;
        }
        cs*=columns;
        return cs;
    }
    double difference_variatsia()
    {
        double s=0, cs=0, x=common_arithmetic_mean(), ay, by;
        int i=0, j;
        while (i < strings)
        {
            j=0;
            ay=arithmetic_mean_string(i);
            while (j < columns)
            {
                by=arithmetic_mean_column(j);
                by=((cells[j][i]-ay-by+x)*(cells[j][i]-ay-by+x));
                s+=by;
                j++;
            }
            cs+=s;
            s=0;
            i++;
        }
        return cs;
    }
    double common_dispersia()
    {
        return common_variatsia()/(columns*strings);
    }
    double column_dispersia()
    {
        return column_variatsia()/(columns*strings);
    }
    double string_dispersia()
    {
        return string_variatsia()/(columns*strings);
    }
    double difference_dispersia()
    {
        return difference_variatsia()/(columns*strings);
    }
    double coef_Fa()
    {
        return string_variatsia()*(columns-1)/difference_variatsia();
    }
    double coef_Fb()
    {
        return column_variatsia()*(strings-1)/difference_variatsia();
    }
//The second lab    

//The third lab
    Table to_rang()
    {
        Table t(strings,columns);
        int k=0;
        while(k<strings)
        {
            int i=0, j=0;
            double min;
            double *list=new double[columns];
            
            while(i<columns)
            {
                list[i]=cells[i][k];
                i++;
            }

            while(j<columns)
            {
                i=j;
                while(i<columns) 
                {
                    if(list[i]<list[j])
                    {
                        min=list[i];
                        list[i]=list[j];
                        list[j]=min;        
                    }
                    i++;
                }
                j++;
            }

            i=0;
            while(i<columns)
            {
                j=0;
                while(j<columns) 
                {
                    if(list[j]==cells[i][k])
                        t.cells[i][k]=j+1;
                    j++;
                }
                i++;
            }
            list=nullptr;
            k++;
        }
        return t;
    }

    double r_c()
    {
        int i=0;
        double r, s=0, d;
        while (i < columns)
            {
                d=cells[i][0]-cells[i][1];
                d*=d;
                s+=d;
                i++;
            }
        r=1-(6*s/((columns*columns-1)*columns));
        return r;
    }
    double t_c()
    {
        double t;
        t=r_c();
        t=(t*sqrt((columns-2)/(1-t*t)));
        return t;
    }
//The third lab
//The fourth lab
    void lab4(){
        double a,b, rxy, rxy2, aprox, s1, s2, s3, s4, s5;
        int i, j;
        s1=this->sum_column(0);
        s2=this->sum_column(1);
        s3=0; s4=0; s5=0; aprox=0;
        i=0;
        while(i<this->strings){
            s3+=(this->cells[0][i]*this->cells[1][i]);
            s4+=(this->cells[0][i]*this->cells[0][i]);
            s5+=(this->cells[1][i]*this->cells[1][i]);
            i++;
        }
        b=(s3*this->strings-s1*s2)/(s4*this->strings-s1*s1);
        a=this->arithmetic_mean_column(1)-b*this->arithmetic_mean_column(0);
        i=0;
        while(i<this->strings){
            aprox+=abs((this->cells[1][i]-a-this->cells[0][i]*b)/this->cells[1][i]);
            i++;
        }
        aprox/=this->strings;
        rxy=(s3*this->strings-s1*s2)/(sqrt(s4*this->strings-s1*s1)*sqrt(s5*this->strings-s2*s2));
        rxy2=rxy*rxy;

        cout<<"a="<<a<<endl<<"b="<<b<<endl<<"Coefficient of correlation"<<rxy<<endl;
        cout<<"Coefficient of determination is "<<rxy2<<endl<<aprox<<endl;
        
    }
//The fourth lab
void lab5(){
        double x1, x2,y, s1, s2, s3, z1, z2, z3;
        int i, j;
        y=this->arithmetic_mean_column(0);
        x1=this->arithmetic_mean_column(1);
        x2=this->arithmetic_mean_column(2);
        i=0; s1=0; s2=0; s3=0;
        while(i<this->strings){
            s1+=(this->cells[0][i]-y);
            s2+=(this->cells[1][i]-x1);
            s3+=(this->cells[2][i]-x2);
            i++;
        }
        s1/=this->strings;
        s2/=this->strings;
        s3/=this->strings;
        cout<<"s1="<<s1<<"; s2="<<s2<<"; s3="<<s3<<endl;
        i=0; z1=0; z2=0; z3=0;
        while(i<this->strings){
            z1+=(this->cells[0][i]-y)/s1;
            z2+=(this->cells[1][i]-x1)/s2;
            z3+=(this->cells[2][i]-x2)/s3;
            i++;
        }
        cout<<"z1="<<z1<<"; z2="<<z2<<"; z3="<<z3<<endl;
    }
void lab6(){
    this->to_rang();
    double a,b, rxy, rxy2, s1, s2, s3, s4;
    int i, j;
    s1=this->sum_column(0);
    s2=this->sum_column(1);
    i=0;
    while(i<this->strings){
        s3+=(this->cells[0][i]*this->cells[1][i]);
        s4+=(this->cells[0][i]*this->cells[0][i]);
        i++;
    }
    b=(s3*this->strings-s1*s2)/(s4*this->strings-s1*s1);
    a=this->arithmetic_mean_column(1)-b*this->arithmetic_mean_column(0);
    s3=0; s4=0;
    i=0; double* yx=new double[this->strings];
    while(i<this->strings){
        yx[i]=a+b*this->cells[0][i];
        cout<<"error_i is "<<this->cells[1][i]-yx[i]<<endl;
        s3+=abs((this->cells[1][i]-yx[i])/cells[1][i]);
        i++;
    }
    cout<<"common error is "<<s3*100<<"%";

}
void lab7(){
    this->to_rang();
    double a,b, rxy, rxy2, s1, s2, s3, s4;
    int i, j;
    s1=this->sum_column(0);
    s2=this->sum_column(1);
    i=0;
    while(i<this->strings){
        s3+=this->cells[0][i]*this->cells[1][i];
        s4+=this->cells[0][i]*this->cells[0][i];
        i++;
    }
    b=(s3*this->strings-s1*s2)/(s4*this->strings-s1*s1);
    a=this->arithmetic_mean_column(1)-b*this->arithmetic_mean_column(0);
    s3=0; s4=0;
    i=0; double* yx=new double[this->strings];
    while(i<this->strings){
        yx[i]=a+b*this->cells[0][i];
        cout<<"error_i is "<<this->cells[1][i]-yx[i]<<endl;
        s3+=(this->cells[1][i]-yx[i]);
        i++;
    }
    cout<<"mean error is "<<s3/this->strings<<endl;
}
void lab8(){
    this->to_rang();
    double a, b, m, rxy, rxy2, s1, s2, s3=0, s4;
    int i, j;
    matrix m1(this->columns, this->strings), m2(this->columns, this->strings);
    j=1;
    while(j<this->columns){
        s1=this->sum_column(0);
        s2=this->sum_column(1);
        s3=0; s4=0;
        m=this->arithmetic_mean_column(j);
        i=0; 
        while(i<this->strings){
            s3+=((cells[j][i]-m)*(cells[j][i]-m));
            i++;
        }
        s3/=this->strings;
        i=0; 
        while(i<this->strings){
            m1.set(j, i, cells[j][i]/s3);
            i++;
        }
        j++;
    }
    m2=m1;
    m2.trans();
    matrix m3=m1*m2;
    m3=(m3*(1/this->strings));
    cout<<m3;
}



//The load-save functions
    void save_csv(string tablename)
      {
        int i=0, j;
        ofstream out;          
        out.open(tablename); 
        if (out.is_open())
          {
            while(i<strings)
           {
            j=0;
            while(j<columns-1)
              {
                out<<cells[j][i]<<',';
                j++;
              }
            out<<cells[j][i];
            out<<"\n";
            i++;
            }
          }
        out.close();
      }
    void load(string tablename)
    {
        destroy();
        char c;
        strings=0, columns=0;
        string s="", subs="";
        fstream in(tablename);
        if (in.is_open())
            while (!in.eof())
            {
                c=in.get();
                if(((c==' ')or(c==',')or(c=='\n')or(c=='"'))and(strings==0)) columns++;
                if(c=='\n') strings++;
                s+=c;
            }
        in.close();

        init();

        int i=0, j=0, k=0, l=size(s);

        while(k<l)
        {
            subs+=s[k];

            if((s[k+1]==' ')or(s[k+1]==',')or(s[k+1]=='\n')or(c=='"'))
            {
                k++;
                cells[j][i]=stod(subs);
                subs="";
                j++;
                if(j==columns)
                {
                    j=0;
                    i++;
                }
            }
            k++;
        }

    }
};
