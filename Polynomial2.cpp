#include"Polynomial.h"
using namespace std;
Polynomial::Polynomial()	{
	size=0;
	maxx=0;
}
Polynomial::Polynomial(int size1)	{
	coeff=new float[size1];
	power=new int[size1];
	size=size1;
	maxx=0;
	for(int i=0;i<size1;i++)	{
		coeff[i]=0;power[i]=0;
	}
}
Polynomial::Polynomial(int size1,int *i,float *f)	{
	size=size1;
	coeff=new float[size1];
	power=new int[size1];
	for(int k=0;k<size1;k++)	{
		coeff[k]=f[k];
		power[k]=i[k];
	}
	refresh();
}
Polynomial Polynomial::operator *(Polynomial &p){

    Polynomial temp[size];
    for(int i = 0; i < size; i++){
        temp[i].size = p.size;
        temp[i].coeff = new float [p.size];
        temp[i].power = new int [p.size];

        for(int j = 0; j < p.size; j++)
        {
            temp[i].coeff[j] = coeff[i]*p.coeff[j];
            temp[i].power[j] = power[i] + p.power[j];
        }
    }

    for(int i = 1; i < size; i++){
        temp[0] = temp[0] + temp[i];
    }

    return temp[0];
}
Polynomial Polynomial:: operator -(Polynomial &p)
{

Polynomial q;
for(int i = 0; i < p.size; i++){
    p.coeff[i] = (-1)*p.coeff[i];}
if(size>p.size)
q.size=size;
else q.size=p.size;
q.power=new int[q.size];
q.coeff=new float [q.size];
q = (*this)+ p  ;
return q;
}

Polynomial Polynomial::derivative()
{
Polynomial q;
q.size=size;
q.power=new int [size];
q.coeff=new float [size];
int i=0;
while(i<size)
{
if(power[i]>0)
q.power[i]=power[i]-1;
q.coeff[i]=power[i]*coeff[i];
i++;
}
q.refresh();
return q;
}

Polynomial Polynomial::integral()
{
Polynomial q;
q.size=size;
q.power=new int [size];
q.coeff=new float [size];
int i=0;
while(i<size)
{
q.power[i]=power[i]+1;
q.coeff[i]=coeff[i]/(power[i]+1);
i++;
}
q.refresh();
return q;
}

Polynomial Polynomial:: operator +(Polynomial &p)
{

Polynomial q;
q.coeff=new float[p.size+size];
q.power=new int[p.size+size];
//q.maxx=((maxx)>(p.maxx))?((maxx):(p.maxx));
int j=0,k=0,l=0;
for(int i=0;(j<p.size || k<size);i++)
{float temp=0;
if(p.power[j]==i)
{
temp+=p.coeff[j];
j++;
}
if(power[k]==i)
{
temp+=coeff[k];
k++;
}
if(temp){
q.coeff[l]=temp;
q.power[l]=i;
l++;
}
}
q.size=l;
int tempmax=0;
for(int i=0;i<q.size;i++)
{
if(tempmax<q.power[i]) tempmax=q.power[i];
}
q.maxx=tempmax;
return q;
}

void Polynomial::print()
{refresh();
	cout<<coeff[0];
	if(power[0]==1)cout<<'x';
	else if(power[0]!=0) cout<<"x^"<<power[0];
for(int i=1;i<size;i++)	{
	if(coeff[i]>0) 	{
		cout<<" + ";
	if(coeff[i]!=1) 
	cout<<coeff[i];
	}
else cout<<" "<<"-"<<" "<<fabs(coeff[i]);
cout<<"x^";
cout<<power[i];
}
cout<<endl;
}
