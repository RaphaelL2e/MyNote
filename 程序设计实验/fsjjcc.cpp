#include<iostream>
using namespace std;
class Rational{
	private :
		int fz,fm;
	public:
		Rational(int FZ=1,int FM=1){
			fz=FZ;fm=FM;
		}
		Rational Add(Rational &r); //求两个分数的和
		Rational Sub(Rational &r); //求两个分数的差
		Rational Mul(Rational &r); //求两个分数的积
		Rational Div(Rational &r); //求两个分数的商
		 Rational operator +(Rational &r); //重载“+”运算符，求两个分数的和
		 Rational operator -(Rational &r); //重载“-”运算符，求两个分数的差
		 Rational operator *(Rational &r);//重载“*”运算符，求两个分数的积
		 Rational operator /(Rational &r); //重载“/”运算符，求两个分数的商
		
		int Divisor(int a,int b){
			int d;
			if(a<0){
				a= -a;
			}
			if(b<0){
				b= -b;
			}
	 		for(d=(a<b?a:b);d>=1;d--)
				if(a%d==0&&b%d==0) 
				{   break;  }
	 		return d;
		} //求最大公约数				
		friend ostream& operator<<(ostream &output,Rational &r){
			int c;
			c= r.Divisor(r.fz,r.fm);
			r.fz /=c; r.fm /=c;
			return output <<r.fz<<"/"<<r.fm<<endl;
			
		}
};

Rational Rational::Add(Rational &r){
	return  this->operator +(r);
	
}
Rational Rational::Sub(Rational &r){
	return this->operator -(r);
}
Rational Rational::Mul(Rational &r){
	return this->operator *(r);
}
Rational Rational::Div(Rational &r){
	return this->operator /(r);
}
Rational Rational::operator +(Rational &r){
	return Rational(this->fz*r.fm + this->fm*r.fz,this->fm*r.fm);
}
Rational Rational::operator -(Rational &r){
	return Rational(this->fz*r.fm - this->fm*r.fz,this->fm*r.fm);
}
Rational Rational::operator *(Rational &r){
	return Rational(this->fz*r.fz,this->fm*r.fm);
}
Rational Rational::operator /(Rational &r){
	return Rational(this->fz*r.fm,this->fm*r.fz);
}


int main(){
	Rational a(5,15),b(1,-2),c;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	c=a.Add(b); //c=a+b;
	cout<<"a+b="<<c<<endl;
	c=a.Sub(b); //c=a-b;
	cout<<"a-b="<<c<<endl;
	c=a.Mul(b); //c=a*b;
	cout<<"a*b="<<c<<endl;
	c=a.Div(b); //c=a/b;
	cout<<"a/b="<<c<<endl;
}
