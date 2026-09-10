#include<stdio.h>
#include<string.h>
#include<math.h>



int main() {
int i=2;
int sum=0;
do{
sum+=i;
i+=3;

}
while (i<=100);
printf("%d\n",sum);


    return 0;
}