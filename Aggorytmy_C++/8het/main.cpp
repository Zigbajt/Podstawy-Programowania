#include <iostream>
#define n 6
using namespace std;

int w[n];
init()
//wartosci poczatkowe tablicy w
{int i;
 w[0]=0;
 for (i=1; i<n; i++) w[i]=-1;
}
wolne(int x, int y)
// sprawdzenie, czy pole <x,y> jest atakowane przez
 // hetmany ustawione w kolumnach 1,2,...,x-1
{int i;
 for (i=0; i<x; i++)
 if (w[i]-i==y-x || w[i]+i==y+x || w[i]==y)return 0;
 return 1;
}

int hetmany(int k)
{ // k – numer kolumny
 if (k<n)
 { w[k]=-1;
 while (w[k]<n)
 { do
 {w[k]++;}
 while (w[k]<n && wolne(k,w[k])==0);
 if (w[k]<n)
 { if (hetmany(k+1)) return n; }
 else return -1;
 }
 }
 else return n;
}
main()
{int i,j;
 init();
 if (hetmany()==n){ cout << endl;
 for (i=0; i<n; i++) cout << w[i];
 cout << endl << endl;
 for(i=0; i<n; i++)
 {for(j=0; j<n; j++)
 if (w[j]==i) cout << "x ");
 else cout << "o ";
 cout << endl;
 }
 } else cout << "nie mozna rozstawic hetmanow";
}
