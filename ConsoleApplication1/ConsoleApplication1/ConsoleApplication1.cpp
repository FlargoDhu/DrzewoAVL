// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"


using namespace std;
//funkcje menu

// Dodaje nowe węzły do drzewa 

void add(DrzewoAVL * T)
{
	cout << "Dodawanie nowych wezlow do drzewa\n";
	T->counter();
	cout << "Podaj liczbe wezlow do utworzenia, a nastepnie wprowadz odpowiednie wartosci nowych wezlow.\n\n";

	int i, n;

	Node * g;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		g = new Node;
		cin >> g->war;
		T->insert(g);
	}

	cout << endl;
	T->sow(T->root);
	T->counter();
}

// Usuwa węzeł

void del(DrzewoAVL * T)
{
	if (T->root) 
	{
		cout << "Usuwanie wezla drzewa \n";
		T->counter();

		Node * g;
		int war;

		cout << "Podaj usuwany wezel : "; cin >> war;

		g = T->look(war);

		if (g)
		{
			delete T->get_rid(g);
			cout << endl;
			if (T->root) T->sow(T->root);
			T->counter();
		}
		else cout << "\nBrak takiego wezla\n";
	}
	else cout << "\nDrzewo jeszcze nie istnieje\n";
}

// Szuka węzła

void check(DrzewoAVL * T)
{
	if (T->root) {
		cout << "Sprawdzenie obecnosci wezla\n"

			"Podaj wezel : ";

		int war;

		cin >> war;

		cout << endl;

		if (T->look(war)) cout << "Wezel znaleziony.\n";
		else               cout << "W drzewie nie ma takiego wezla\n";
	}
	else cout << "\nDrzewo jeszcze nie istnieje\n";
}

// Znajduje minimum i maksimum

void minmax(DrzewoAVL * T)
{
	if (T->root)
	{
		cout << "Znajdowanie minimum i maksimum w drzewie\n"
			"Minimalny  : " << T->minn(T->root) << endl <<
			"Maksymalny : " << T->maxx(T->root) << endl;
	}
	else cout << "\nDrzewo jeszcze nie istnieje\n";
	
}

// poprzednik węzła

void bef(DrzewoAVL * T)
{
	if (T->root)
	{
		cout << "Znajdowanie poprzednika w drzewie\n"
			"Podaj wezel : ";
		int war;
		Node * g;

		cin >> war;
		cout << endl;

		g = T->look(war);

		if (g)
		{
			g = T->bef(g);
			if (g) cout << "Poprzednikiem [" << war << "] jest " << g->war << endl;
			else  cout << "Wezel [" << war << "] nie posiada poprzednika\n";
		}
		else cout << "Wezel o podanym kluczu nie istnieje w drzewie\n";
	}
	else cout << "\nDrzewo jeszcze nie istnieje\n";
}

// następnik węzła

void aft(DrzewoAVL * T)
{
	if (T->root) 
	{
		cout << "Znajdowanie nastepnika w drzewie\n"
			"Podaj wezel : ";
		int war;
		Node * g;

		cin >> war;
		cout << endl;

		g = T->look(war);

		if (g)
		{
			g = T->aft(g);
			if (g) cout << " Następnik [" << war << "] to " << g->war << endl;
			else  cout << "Dla węzła [" << war << "] nie istnieje nastepnik\n";
		}
		else cout << "Wezel ten nie istnieje w drzewie\n";

	}
	else cout << "\nDrzewo jeszcze nie istnieje\n";
}

void preo(DrzewoAVL * T)
{
	if (T->root)
	{
		cout << "Przechodzenie drzewa algorytmem preorder\n";
		T->preo(T->root);
	}
	else cout << "\nDrzewo jeszcze nie istnieje\n";
}



void ino(DrzewoAVL * T)
{
	if (T->root)
	{
		cout << "Przechodzenie drzewa algorytmem inorder\n";
		T->ino(T->root);
	}
	else cout << "\nDrzewo jeszcze nie istnieje\n";
	
}



void posto(DrzewoAVL * T)
{
	if (T->root)
	{
		cout << "Przechodzenie drzewa algorytmem postorder\n";
		T->posto(T->root);
	}
	else cout << "\nDrzewo jeszcze nie istnieje\n";
	
}

void display(DrzewoAVL * T)
{ 
	if (T->root)
	{
		cout << "Wyswietalnie drzewa\n";
		T->display(T->root, 1);
	}
	else cout << "\nDrzewo jeszcze nie istnieje\n";
}

void height(DrzewoAVL * T)
{
	if (T->root)
	{
		cout << "\nWysokosc: ";
		cout << T->height(T->root) << endl;
	}
	else cout << "\nDrzewo jeszcze nie istnieje\n";
}


int main()
{
	DrzewoAVL * T = new DrzewoAVL();
	int choice;

	do
	{	

		cout << "\n" 
			"***Menu***\n"
			" 0  Koniec\n"
			" 1  Dodaj wezly\n"
			" 2  Usun wezel\n"
			" 3  Wyswietl drzewo\n"
			" 4  Wysokosc drzewa\n"
			" 5  Sprawdz obecnosc wezla\n"
			" 6  Wezel min i max\n"
			" 7  Poprzednik\n"
			" 8  Nastepnik\n"
			" 9  Preorder\n"
			" 10 Inorder\n"
			" 11 Postorder\n"
			
			"Twoj wybor : ";

		cin >> choice;

		switch (choice)
		{
		case 1: add(T); break;
		case 2: del(T); break;
		case 3: display(T); break;
		case 4: height(T); break;
		case 5: check(T);  break;
		case 6: minmax(T); break;
		case 7: bef(T); break;
		case 8: aft(T);  break;
		case 9: preo(T);  break;
		case 10: ino(T);   break;
		case 11: posto(T); break;
		
		
	
		}

	} while (choice);

	delete T;
	return 0;
}