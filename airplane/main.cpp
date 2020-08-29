#include <iostream>
int fact(int);
using namespace std;

int main()
{
    int n;
    double prob;
    cout<<"Enter number of passengers:"<<endl;
    cin>>n;
    prob=1/double(fact(n));
    cout<<"The probability of nth passenger getting his own seat is:"<<prob<<endl;

    return 0;
}

int fact(int x)
{
    int fact=1;
    while(x>=1)
    {
        fact=fact*x;
        x--;
    }
    return fact;
}
