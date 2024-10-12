#include <iostream>
#include <string>
#include <fstream>
#include <math.h>


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
