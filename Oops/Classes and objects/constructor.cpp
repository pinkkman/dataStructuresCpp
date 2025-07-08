#include<iostream>
#include <climits>
#include<vector>
#include <string>
using namespace std;

//Classes and Objects ::

class car{
    public:           //if not public then by default its private
string name;
int hspeed;

car(){                                  //NP constr
    cout<<"Params dedo ploxx";
}

car(string n,int hs){        //constructor  
cout<<"class called";         //parameters to set
name=n;
hspeed=hs;
}

string getName(){
return name;
}
int getHs(){
    return hspeed;
}
};

int main(){
car cc;                      // no args                   np constr
car c1("civic ",13);         //arguments to be given      p constr

cout<<"car is "<<c1.getName() <<"and its top speed is "<<c1.getHs();
    return 0;
}