
#include<iostream>
using namespace std;


class statt{
    public:
static int c;

};
int statt::c=0;

int main(){
statt o1;
statt o2;
cout<<o1.c++;
cout<<o2.c++;
    return 0;
}
