#include<iostream>
//#include<simplecpp>
#include<math.h>
#define sgn(a) ( ((a)<0) ?  -1 : 1)
using namespace std;
struct Roots{
float *roots;
int rsize;
};
class Polynomial
{private:
int size,maxx;
float *coeff;
int *power;
public:
Polynomial();
Polynomial(int size1);
Polynomial(int size1,int *i,float *f);
void read();
void sort();
void print();
void refresh();
float valueAt(float x);
Roots roots();
Polynomial derivative();
Polynomial integral();
Polynomial operator /(Polynomial &p);
Polynomial operator +(Polynomial &p);
Polynomial operator *(Polynomial &p);
Polynomial operator-(Polynomial &p);
float root(float xleft,float xright);
//void plot(float x,float y);
};
