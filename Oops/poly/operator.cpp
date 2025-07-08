
#include<iostream>
using namespace std;

int main(){

class complex{
int real,img;
public:
complex(int r,int i){
    real=r;
    img=i;
}
void show(){
    cout<<real<<"+"<<img<<"i"<<endl;
}

complex operator + (complex &c2){
int rr=this-> real + c2.real;
int ri=this-> img + c2.img;
complex c3(rr,ri);
c3.show();
return c3;
}
};

complex c1(3,4);
complex c2(4,2);
c1+c2;


    return 0;
}
