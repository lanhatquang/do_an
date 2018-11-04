#include<iostream>
#include<string>
#include"List.h"

using namespace std;

int main(int argc, char const *argv[])
{
    List a;
    cin>>a;
    cout<<a.sizeList();
    cout<<a;
    // a.QuickSort(0, a.getn());
    // cout<<a;
    return 0;
}
