#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str="1 2 3";
    istringstream iss(str);
    int liczba1,liczba2,liczba3;
    vector<int> a;
    iss>>liczba1>>liczba2>>liczba3;
    a.push_back(liczba1);
    a.push_back(liczba2);
    a.push_back(liczba3);
    for(int j=0;j<a.size();j++){
       cout<<a[j]<<endl;
    }
    return 0;
}
