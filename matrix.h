#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class matrix
{
private:
  int cols, rows;
  double **cells;
  void init ()
  {
    int i, j;
      //destroy ();
    cells = new double *[rows];
    for (i = 0; i < rows; i++)
      {
        cells[i] = new double[cols];
        for (j = 0; j < cols; j++)
          {
            cells[i][j] = 0;
          }
      }
  }
  void destroy ()
  {
    int i;
    if (cells)
    {
      for (i = 0; i < rows; i++)
        {
          delete cells[i];
        }
      delete cells;
    }
    cells = nullptr;
  }
public:
  matrix ()
  {
    cols = 3;
    rows = 3;
    init ();
  }
  matrix (int i, int j)
  {
    cols = j;
    rows = i;
    init ();
  }
  ~matrix ()
  {
    destroy ();
  }
  void random ()
  {
    srand (time (0));
    int i, j;
    for (i = 0; i < rows; i++)
      {
      for (j = 0; j < cols; j++)
      {
        cells[i][j] = rand () % 100;
      }
    }
  }
  void set (int i, int j, double d)
  {
	    cells[i][j] = d;
  }
  friend ostream & operator<< (ostream & stream, const matrix & mtr)
  {
    int i, j;
    for (i = 0; i < mtr.rows; i++)
      {
	for (j = 0; j < mtr.cols; j++)
	  {
	    stream << mtr.cells[i][j] << " ";
	  }
	stream << endl;
      }
    return stream;
  }
  friend istream & operator>> (istream & in, const matrix & mtr)
  {
    int i, j;
    for (i = 0; i < mtr.rows; i++)
      {
	for (j = 0; j < mtr.cols; j++)
	  {
	    in >> mtr.cells[i][j];
	  }
    cout<<"A new row is started"<<endl;
      }
    return in;
  }

  matrix *operator = (const matrix & mtr)
  {
    destroy ();
    cols = mtr.cols;
    rows = mtr.rows;
    init ();
    int i, j;
    for (i = 0; i < rows; i++)
      {
	for (j = 0; j < cols; j++)
	  {
	    cells[i][j] = mtr.cells[i][j];
	  }
      }
    return this;
  }
  matrix operator + (const matrix & mtr)
  {
    matrix C (1, 1);

    if ((rows != mtr.rows) || (cols != mtr.cols))
      {
	cout << "Error: different number of the cols or the rows" << ' ';
      }
    else
      {
	matrix C (rows, cols);
	int i, j;
	for (i = 0; i < rows; i++)
	  {
	    for (j = 0; j < cols; j++)
	      {
		C.cells[i][j] = cells[i][j] + mtr.cells[i][j];
	      }
	  }
      }
    return C;
  }
  matrix operator * (const matrix & mtr)
  {
    matrix C(rows, mtr.cols);
    int i, j, s, k;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < mtr.cols; j++)
        {
            s=0;
            for (k = 0; k < cols; k++)
                {
                s+=cells[i][k] * mtr.cells[k][j];
                }
            C.cells[i][j]=s;
        }
    }
    return C;
  }
  matrix operator * (const double & d)
  {
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            cells[i][j]=cells[i][j]*d;
        }
    }
    return (*this);
  }
  void del_row(int n)
  {
    int i;
    n--;
    for (i=n; i<rows-1; i++)
      {cells[i]=cells[i+1];}
      rows--;
    delete [] cells[rows];
  }
  void del_col(int n)
  {
    int i,j;
    double *a;
    n--;
    for (i=0; i<rows; i++)
      {
        for (j=n; j<cols-1; j++)
          {
            cells[i][j]=cells[i][j+1];
          }
          a=&(cells[i][cols-1]);
          delete a;
          a=nullptr;
        }
      cols--;
  }
  void trans(){
    int i, j;
    double d;
    for (i = 1; i < rows; i++)
      {
      for (j = i; j < cols; j++)
      {
        d=cells[i][j];
        cells[i][j]=cells[j][i];
        cells[j][i]=d;
      }
    }
  }
}
;
