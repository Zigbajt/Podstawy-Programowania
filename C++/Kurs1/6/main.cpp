#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
int main() {
//---deklaracja kolekcji---
vector<string> str;
str.push_back("blok");
str.push_back("koc");
str.push_back("fala");
str.push_back("woda");
str.push_back("radar");
//---wypisanie kolekcji---
int size = str.size();
for(int i=0;i<size;i++)
cout <<i<<" : "<< str.at(i)<<" | ";
//---wyszukiwanie---
cout<<endl<< "wpisz wyszukiwana fraze"<<endl;
string fraze;
cin>>fraze;
int find=0;
size = str.size();
for(int i=0;i<size;i++)
{
size_t nr = str[i].find(fraze);
if (nr!=std::string::npos){
            cout<<"Znaleziono poszukiwany ciag w vektorze nr: "<< i <<endl;
}else
cout << "nie znaleziono podanej frazy"<<endl;

}

}
