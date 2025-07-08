#include<iostream>
#include <climits>
#include<vector>
#include <string>
using namespace std;

//practice

class user{
int id;
string password;

public:
string username;

user(int id){
this-> id=id;
}

void setPassword(string password){  //parameterized
    this-> password=password;
}

string getPassword(){
return password;
}
};


int main(){
user user1(11);
user1.username="pinkkman";
user1.setPassword("ridlet");
cout<<"hello "<<user1.username<<" your password is "<<user1.getPassword();

    return 0;
}