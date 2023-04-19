#include <iostream>
#include <string>
using namespace std;

struct Lista
{
	Lista* nast;
	int id;
	std::string nazwa;
};

Lista* pocz = NULL;
Lista* q, * s;

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
void UsunElementPo(Lista* s) {
	q = pocz;
	q = s->nast;
	s->nast = q->nast;
	delete q;
	std::cout << "Usunieto element" << std::endl;
}


int main()
{
	GenerujListe();

		std::cout << "------------------------" << std::endl;
		PrzegladListy();
		std::cout << "------------------------" << std::endl;
		int b;
		std::cin >> b;
		//PolozNaPoczatku(b);
		//s = SzukajElementu(b);
		//UsunElementPo(s);
		UsunElementNa(s);
		std::cout << "------------------------" << std::endl;
		return 0;
}
