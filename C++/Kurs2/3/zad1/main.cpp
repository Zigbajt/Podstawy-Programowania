#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename typ>
void SB(typ tab[],int ilosc)
{
	for (int i=0;i<ilosc;i++)
	{
		for (int j=ilosc-1;j>=1;j--)
		{
			if (tab[j]<tab[j-1])
			{
				typ zmienna;
				zmienna=tab[j-1];
				tab[j-1]=tab[j];
				tab[j]=zmienna;
			}
		}
	}
}
template <typename typ>
void SpW(typ *tab,int ilosc)
{
	typ zmienna;
	int j;
	for (int i=1;i<ilosc;i++)
	{
		zmienna=tab[i];
		j=i-1;
		while(j>=0&&tab[j]>zmienna)
		{
			tab[j+1]=tab[j];
			--j;
		}
		tab[j+1]=zmienna;
	}
}
template <typename typ>
void Q(typ *tab, int l, int p)
{
	typ z=tab[(l+p)/2];
	typ zmienna;
	int i,j;
	i=l;
	j=p;
	do
	{
		while (tab[i]<z) i++;
		while (tab[j]>z) j--;
		if (i <= j)
		{
			zmienna = tab[i];
			tab[i] = tab[j];
			tab[j] = zmienna;
			i++;
			j--;
		}
	} while (i <= j);
	if (i<p) Q(tab, i, p);
	if (j>l) Q(tab, l, j);
}

int wybierz_rodzaj(void){
    int wybierz=0;
    do{
        cout<<"WYBIERZ:"<<endl;
        cout<<"1.INT"<<endl;
        cout<<"2.FLOAT"<<endl;
        cout<<"3.TEKST"<<endl;
        cout<<"4.KONIEC"<<endl;
        cin>>wybierz;
        if((wybierz<1) || (wybierz>4)){
            cout<<"PODALES BLEDNA WARTOSC"<<endl;
            cout<<endl;
            cout<<"-------------------"<<endl;
            cout<<endl;
        }
    }while((wybierz<1) || (wybierz>4));
    return wybierz;
}
int menu(void){
    int wybierz=0;
    do{
    cout<<"WYBIERZ:"<<endl;
    cout<<"1.Algorytm babelkowy"<<endl;
    cout<<"2.Algorytm przez wstawianie"<<endl;
    cout<<"3.quicksort"<<endl;
    cout<<"4.KONIEC"<<endl;
    cin>>wybierz;
    if((wybierz<1) || (wybierz>4)){
        cout<<"PODALES BLEDNA WARTOSC"<<endl;
        cout<<endl;
        cout<<"-------------------"<<endl;
        cout<<endl;
    }
    }while((wybierz<1) || (wybierz>4));
    return wybierz;
}
template <typename typ>
void wyswietl(typ *tab,int ilosc){
    for(int i=0;i<ilosc;i++){
        cout<<tab[i]<<endl;
    }
}
template <typename typ>
void sortuj(typ tab){
    int wybierz=menu();
    if(wybierz==1){
        SB(tab,10);
        wyswietl(tab,10);
    }
    if(wybierz==2){
        SpW(tab,10);
        wyswietl(tab,10);
    }
    if(wybierz==3){
        Q(tab,0,9);
        wyswietl(tab,10);
    }
    if(wybierz==4){
        cout<<"Koniec programu!"<<endl;
    }
}
int main()
{
    srand(NULL);
    int tab1[10];
    float tab2[10];
    string tab3[10];
    int wybierz=wybierz_rodzaj();
    if(wybierz==1){
        for(int i=0;i<10;i++){
            tab1[i]=rand()%20+1;
        }
        sortuj(tab1);
    }
    if(wybierz==2){
        int liczba;
        for(int i=0;i<10;i++){
            liczba=rand()%20+1;;
            //cout<<liczba<<endl;
            tab2[i]=(float)liczba/(float)20;
        }
        sortuj(tab2);
    }
    if(wybierz==3){
        tab3[0]="Marysia";
        tab3[1]="Ala";
        tab3[2]="Ania";
        tab3[3]="Dom";
        tab3[4]="Kot";
        tab3[5]="Pies";
        tab3[6]="Artur";
        tab3[7]="Adam";
        tab3[8]="Piotr";
        tab3[9]="Elo";
        sortuj(tab3);
    }
    if(wybierz==4){
        return 0;
    }

    cout << "Koniec programu!" << endl;
    return 0;
}
