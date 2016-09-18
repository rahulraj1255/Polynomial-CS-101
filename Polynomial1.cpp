#include"Polynomial.h"
using namespace std;
void Polynomial::read()
{
cin>>size;power=new int[size];coeff=new float[size];
for(int i=0;i<size;i++)
{
cin>>power[i]>>coeff[i];

}

int tempmax=0;
for(int i=0;i<size;i++)
{
if(tempmax<power[i]) tempmax=power[i];
}
maxx=tempmax;
refresh();
}
float Polynomial ::valueAt(float x)
{
float temp=0;
for(int i=0;i<size;i++)
temp+=coeff[i]*pow(x,power[i]);
return temp;
}

void Polynomial::sort()
{int minn=power[0],g=0;
for(int i=0;i<size-1;i++)
{
	for(int j=i+1;j<size;j++)
		{minn=power[i];g=i;
		if(minn>power[j]) {minn=power[j];g=j;}}
	float temp=power[g];
        power[g]=power[i];
		  power[i]=temp;
		  temp=coeff[g];
		  coeff[g]=coeff[i];
		  coeff[i]=temp;
		  }
}

float Polynomial :: root (float xleft,float xright)
{
if(fabs(valueAt(xright))<0.001)return xright;
else if(fabs(valueAt(xleft))<0.001) return xleft;
else
{
float temp;
if(valueAt(xleft)*valueAt(xright)<0) {

	while(xright>xleft+0.001) {
		temp=(xleft+xright)/2;
		if(valueAt(temp)*valueAt(xright)>0)
			xright=temp;
		else
			xleft=temp;
	}
	return xright;
}
else return xleft-1;
}
}

Polynomial Polynomial::operator  / (Polynomial &p)	{
	Polynomial a=*(this),t,temp;p.refresh();
	temp.size=1;
	temp.power=new int[1];temp.coeff=new float [1];
	t.size=size;
	
	t.power=new int[size];
	t.coeff=new float[size];
	for(int i=0;a.power[a.size-1]>=p.power[p.size-1];i++)	{
		temp.coeff[0]=a.coeff[a.size-1]/p.coeff[p.size-1];
		temp.power[0]=a.power[a.size-1]-p.power[p.size-1];
Polynomial b=(p*temp);
a=a-b;
a.refresh();
t.power[i]=temp.power[0];
t.coeff[i]=temp.coeff[0];

}
t.refresh();
return t;
}

void Polynomial::refresh(){
sort();
int g=0;
for(int i=0;i<size-1;)
{	bool b=false;
	while(power[i]==power[i+1])	{
		if(!b)	{	
			g=i;
			b=true;
			}
		coeff[g]+=coeff[i+1];
		coeff[i+1]=0;
		i++;
		}
	if(!b) i++;
}
bool done=true;
while(done)
{done=false;
for(int i=0;i<size-1;i++)
{if(coeff[i]==0)
		for(int j=i+1;j<size;j++)
			{
			if(coeff[j]!=0)
			 {done=true;
			   coeff[i]=coeff[j];
			   coeff[j]=0;
			   power[i]=power[j];
			   break;
			  }
			 }
	}
}
int i=0;
while(coeff[i]!=0) i++;
size=i;
int maxx1=0;
for(i=0;i<size;i++)
if(maxx1<power[i]) maxx1=power[i];
maxx=maxx1;
}

/*void Polynomial::plot(float xleft,float xright)
{
double v=(xright-xleft);
float l=800,b=800;
initCanvas("Graph",l,b);
double scalev=(b)/v,scaleh=(l)/(xright-xleft);
double x=0,y=l/2-scalev*valueAt(xleft),tx=1;
Line l1(0,b/2,l,b/2),l2(l/2,0,l/2,b);
float markx=(xright-xleft)/20,marky=v/20;
for(int i=0;i<10;i++)
{Line g(l/2+i*scaleh*markx,b/2-10,l/2+i*scaleh*markx,b/2+10);
Line h(l/2-i*scaleh*markx,b/2-10,l/2-i*scaleh*markx,b/2+10);
g.imprint();
h.imprint();
}
for(int i=0;i<10;i++)
{
Line c(l/2-10,b/2-i*scalev*marky,l/2+10,b/2-i*scalev*marky);
Line d(l/2-10,b/2+i*scalev*marky,l/2+10,b/2+i*scalev*marky);
c.imprint();
d.imprint();
}
double ty=l/2-scalev*valueAt(xleft+1.0/scaleh);
float f=1;
while(x<scaleh*(xright-xleft))
{
if(fabs(y)<b)
{
Line L(x,y,tx,ty);
L.imprint();
}
f+=1;
x=tx;y=ty;
tx=f;
ty=l/2-scalev*valueAt(xleft+f/scaleh);
}
Text t0(l/2+0*scaleh*markx,(b/2-15),-0*markx),s0(l/2-0*scaleh*markx,b/2-15,-0*markx);
Text t1(l/2+1*scaleh*markx,(b/2-15),-1*markx),s1(l/2-1*scaleh*markx,b/2-15,-1*markx);
Text t2(l/2+2*scaleh*markx,(b/2-15),-2*markx),s2(l/2-2*scaleh*markx,b/2-15,-2*markx);
Text t3(l/2+3*scaleh*markx,(b/2-15),-3*markx),s3(l/2-3*scaleh*markx,b/2-15,-3*markx);
Text t4(l/2+4*scaleh*markx,(b/2-15),-4*markx),s4(l/2-4*scaleh*markx,b/2-15,-4*markx);
Text t5(l/2+5*scaleh*markx,(b/2-15),-5*markx),s5(l/2-5*scaleh*markx,b/2-15,-5*markx);
Text t6(l/2+6*scaleh*markx,(b/2-15),-6*markx),s6(l/2-6*scaleh*markx,b/2-15,-6*markx);
Text t7(l/2+7*scaleh*markx,(b/2-15),-7*markx),s7(l/2-7*scaleh*markx,b/2-15,-7*markx);
Text t8(l/2+8*scaleh*markx,(b/2-15),-8*markx),s8(l/2-8*scaleh*markx,b/2-15,-8*markx);
Text t9(l/2+9*scaleh*markx,(b/2-15),-9*markx),s9(l/2-9*scaleh*markx,b/2-15,-9*markx);
Text u0(l/2-15,b/2-0*scalev*marky,-0*marky),v0(l/2+15,b/2-0*scalev*marky,0*marky);
Text u1(l/2-15,b/2+1*scalev*marky,-1*marky),v1(l/2+15,b/2-1*scalev*marky,1*marky);
Text u2(l/2-15,b/2+2*scalev*marky,-2*marky),v2(l/2+15,b/2-2*scalev*marky,2*marky);
Text u3(l/2-15,b/2+3*scalev*marky,-3*marky),v3(l/2+15,b/2-3*scalev*marky,3*marky);
Text u4(l/2-15,b/2+4*scalev*marky,-4*marky),v4(l/2+15,b/2-4*scalev*marky,4*marky);
Text u5(l/2-15,b/2+5*scalev*marky,-5*marky),v5(l/2+15,b/2-5*scalev*marky,5*marky);
Text u6(l/2-15,b/2+6*scalev*marky,-6*marky),v6(l/2+15,b/2-6*scalev*marky,6*marky);
Text u7(l/2-15,b/2+7*scalev*marky,-7*marky),v7(l/2+15,b/2-7*scalev*marky,7*marky);
Text u8(l/2-15,b/2+8*scalev*marky,-8*marky),v8(l/2+15,b/2-8*scalev*marky,8*marky);
Text u9(l/2-15,b/2+9*scalev*marky,-9*marky),v9(l/2+15,b/2-9*scalev*marky,9*marky);
wait(10);
}
*/

Roots Polynomial::roots(){

       float x = 1,x1 = 1,x2 = 1.1,limit_right,limit_left;
       int size_iterator=0;
       Polynomial q = derivative();
       bool const_deriv=true;
       int going=sgn(q.coeff[0]);
       for(int i=0;i<10;i+=1)
       {
       if(q.valueAt(-1)!=q.valueAt(i))
       const_deriv=false;
       }
       
       if(const_deriv)	{
       int dir=(valueAt(1)*going);
       int j=1;
        
       while(sgn(dir)==sgn(valueAt(j)*going))
       	j*=((dir>0)?-2:2);
       	if(j<1) {limit_left=j;limit_right=1;}
       	else {limit_right=j;limit_left=j;}
       	}
       	
       	
       	
		       
       
       else	{
       bool run = true;
       for(float fact = 0.2; run; fact = fact*2){//cout<<"#1";
                float d1 = q.valueAt(x1),d2 = q.valueAt(x2);
              //  if(q.valueAt(x1)>0){
                    if((fabs(d2)-fabs(d1))>100) {
                        limit_right = x1;
                        run = false;
                    }
                    x1 = x2;
                    x2 = x + fact;
				//   }
    		     }
          x1 = 1; x2 = 0.9;run=true;
        for(float fact = 0.2; run; fact = fact*2){//cout<<"#2";
                float d1 = q.valueAt(x1),d2 = q.valueAt(x2);
             //   if(r.valueAt(x1)>0){
                    if((fabs(d2)-fabs(d1))>100) {
                        limit_left = x1;
                        run = false;
                    }
                    x1 = x2;
                    x2 = x - fact;
            }
        }
            Roots r;
            r.roots=new float[size];
            int l=0;
        bool sign =true;//cout<<endl<<limit_left<<"   "<<limit_right<<endl;
        x1=valueAt(limit_left);
        x2=valueAt(limit_left+(limit_right-limit_left)/100);
        //cout<<x1<<" "<<x2<<endl;int m=0;
        for(float i=limit_left+2*(limit_right-limit_left)/100;i<=limit_right;i=i+(limit_right-limit_left)/100)	{//cout<<endl<<m;m++;
        	if(sgn(x1)!=sgn(x2))	{//cout<<i-2*(limit_right-limit_left)/100<<"      "<<i-(limit_right-limit_left)/100<<endl;
        		r.roots[l]=root(i-2*(limit_right-limit_left)/100,i-(limit_right-limit_left)/100);
        		l++;
        		}
        	/*if(reset)	{
      	  		if(x2>x1) sign =true;
        		else sign=false;
        		reset=false;
        		}
        	if((x2>x1)!=sign)	{
        		float f=rootsfun();
        		if(f!=limit_left)
        			{
        			r.roots[l]==f;
        			l++;
        			reset=true;
        			}
        		}
        		*/
        	x1=x2;
        	x2=valueAt(i);
        	
        }
	x1=q.valueAt(limit_left);
        x2=q.valueAt(limit_left+(limit_right-limit_left)/100);
        
        for(float i=limit_left+2*(limit_right-limit_left)/100;i<=limit_right;i=i+(limit_right-limit_left)/100)	{//cout<<"#4";
        	//cout<<x1<<"  "<<x2<<endl;
        	if(sgn(x1)!=sgn(x2))	{//cout<<endl<<x1<<"  "<<x2;
        		float s=q.root(i-2*(limit_right-limit_left)/100,i-(limit_right-limit_left)/100);//cout<<endl<<s<<endl;
        		if(fabs(valueAt(s))<0.001)
        		{
        		r.roots[l]=s;
        		l++;
        		}
        	}
        	
        	x1=x2;
        	x2=q.valueAt(i);
        	
        }	
     r.rsize=l;
     return r;
    }
