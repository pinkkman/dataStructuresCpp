
#include<iostream>
using namespace std;

int main(){

    class Base {
        public:
            void show() { cout << "Base\n"; }
            virtual void bb(){cout<<"vir base";}
        };

        class Derived : public Base {
        public:
            void show() { cout << "Derived\n"; }
           void bb(){
cout<<" vir der ";
            }
        };
        

        Base* b ;
        Derived d;
        b=&d;
        b->show();  //base
        b->bb();    //derived
       
//diff btw virtual and normal funcs

    return 0;
}
