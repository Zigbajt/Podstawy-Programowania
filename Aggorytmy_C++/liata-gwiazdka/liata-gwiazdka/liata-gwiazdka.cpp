// liata-gwiazdka.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <Windows.h>
#include <string>

struct Lista
{
	Lista* nast;
	int id;
	std::string nazwa;
};
struct Dwukierunkowa {
	int id;
	Dwukierunkowa* pop, * next;
};

Lista* pocz = NULL;
Lista* q, * s;
Dwukierunkowa* Dpocz = NULL;
Dwukierunkowa* Dkon = NULL;
Dwukierunkowa* d, * e;

const int num = 10;

int a[num] = { 0,1,2,3,4,5,6,7,8,9 };

void GenerujListe()
{
	int i = 0;
	while (i < num)
	{
		q = new Lista;
		q->nast = pocz;
		q->id = a[i];
		pocz = q;
		i++;
	}
}
void Generuj()
{
	int i = 0;
	while (i < num)
	{
		d = new Dwukierunkowa;
		d->next = Dpocz;
		d->pop = Dkon;
		d->id = a[i];
		Dpocz = d;
		i++;
	}
}


void PrzegladListy()
{
	q = pocz;
	while (q != NULL)
	{
		std::cout << "Lista: " << q->id << std::endl;
		q = q->nast;
	}
}

Lista* SzukajElementu(int elementSzukany)
{
	s = pocz;
	bool nieznalezione = true;
	while (s != NULL && nieznalezione)
	{
		if (s->id == elementSzukany)
		{
			return s;
			nieznalezione = false;
		}
		else
		{
			s = s->nast;
		}
	}
	return NULL;
}

void PolozNaPoczatku(int wartosc)
{
	q = new Lista;
	q->id = pocz->id;
	q->nast = pocz->nast;
	pocz->nast = q;
	pocz->id = wartosc;
}

void SciagnijZPoczatku()
{
	q = new Lista;
	q = pocz;
	pocz = pocz->nast;
	delete q;
}

void UsunElementNa(Lista* s)
{
	Lista* p;

	if (pocz == s)
	{
		SciagnijZPoczatku();
	}
	else
	{
		p = pocz;
		while (p->nast != s)
		{
			p = p->nast;
		}
		p->nast = s->nast;
		delete s;
		std::cout << "Usunieto element" << std::endl;
	}
}

void SciagnijZKonca()
{
	q = new Lista;
	s = new Lista;
	q = pocz;
	while (q->nast->nast != NULL)
	{
		q = q->nast;
	}

	s = q->nast;
	q->nast = NULL;
	delete s;
}
void UsunElementPo1(Lista *s) {
	q = pocz;
	q = s->nast;
	s->nast = q->nast;
	delete q;
	std::cout << "Usunieto element" << std::endl;
}
void PolozNaKoncu5(Lista* s, int wartosc) {
	q = pocz;
	while (q->nast->nast != NULL)
	{
		q = q->nast;
	}
	q->nast = new Lista;
	q->nast->nast = s;
	q->nast->id = wartosc;
}
void PolozPrzedElemetem3(Lista *s,int wartosc)
{
	q = new Lista;
	q->id = wartosc;
	q->nast = s->nast;
	s->nast = q;
}
void ZmienWartosc(Lista* s, int wartosc)
{
	q = pocz;

		while (q->nast == s	) {
			q = q->nast;
		}
		q->id = wartosc;

}


int main()
{
	GenerujListe();
	do
	{
		std::cout << "------------------------" << std::endl;
		PrzegladListy();
		std::cout << "------------------------" << std::endl;
		int b;
		std::cin >> b;
		int c;
		std::cin >> c;
		//PolozNaPoczatku(b);
		s = SzukajElementu(b);
		//UsunElementPo1(s);
		//UsunElementNa(s);
		//PolozPrzedElemetem3(s, c);
		//PolozNaKoncu5(s,c);
		//SciagnijZKonca();
		ZmienWartosc(s, c);
		std::cout << "------------------------" << std::endl;

	} while (GetAsyncKeyState(VK_ESCAPE) == 0);

}