#include "stdafx.h"
using namespace std;


// Konstruktor DrzewoAVL

DrzewoAVL::DrzewoAVL()
{
	root = NULL;
	count = 0;
}

// Destruktor DrzewoAVL

DrzewoAVL::~DrzewoAVL()
{
	while (root) delete(get_rid(root));
}

// Rotacja RR

Node * DrzewoAVL::RR(Node * A)
{
	Node * B = A->right, *P = A->p;

	A->right = B->left;
	if (A->right) A->right->p = A;
	B->left = A;
	B->p = P;
	A->p = B;
	if (P)
	{
		if (P->left == A) P->left = B; else P->right = B;
	}
	else root = B;

	if (B->bf == -1)
	{
		A->bf = B->bf = 0;
	}
	else
	{
		A->bf = -1; B->bf = 1;
	}
	return B;
}

// Rotacja LL

Node * DrzewoAVL::LL(Node * A)
{
	Node * B = A->left, *P = A->p;

	A->left = B->right;
	if (A->left) A->left->p = A;
	B->right = A;
	B->p = P;
	A->p = B;
	if (P)
	{
		if (P->left == A) P->left = B; else P->right = B;
	}
	else root = B;

	if (B->bf == 1)
	{
		A->bf = B->bf = 0;
	}
	else
	{
		A->bf = 1; B->bf = -1;
	}

	return B;
}

// Rotacja RL

Node * DrzewoAVL::RL(Node * A)
{
	Node * B = A->right, *C = B->left, *P = A->p;

	B->left = C->right;
	if (B->left) B->left->p = B;
	A->right = C->left;
	if (A->right) A->right->p = A;
	C->left = A;
	C->right = B;
	A->p = B->p = C;
	C->p = P;
	if (P)
	{
		if (P->left == A) P->left = C; else P->right = C;
	}
	else root = C;

	A->bf = (C->bf == -1) ? 1 : 0;
	B->bf = (C->bf == 1) ? -1 : 0;
	C->bf = 0;

	return C;
}

// Rotacja LR

Node * DrzewoAVL::LR(Node * A)
{
	Node * B = A->left, *C = B->right, *P = A->p;

	B->right = C->left;
	if (B->right) B->right->p = B;
	A->left = C->right;
	if (A->left) A->left->p = A;
	C->right = A;
	C->left = B;
	A->p = B->p = C;
	C->p = P;
	if (P)
	{
		if (P->left == A) P->left = C; else P->right = C;
	}
	else root = C;

	A->bf = (C->bf == 1) ? -1 : 0;
	B->bf = (C->bf == -1) ? 1 : 0;
	C->bf = 0;

	return C;
}

// Wstawia element

bool DrzewoAVL::insert(Node * n)
{
	Node * g = root, *y, *z;

	y = n->left = n->right = NULL;
	n->bf = 0;

	while (g)
	{
		if (g->war == n->war)
		{
			delete n;
			return false;
		}
		y = g;
		g = (n->war < g->war) ? g->left : g->right;
	}

	count++;

	if (!(n->p = y))
	{
		root = n;
		return true;
	}
	if (n->war < y->war) y->left = n; else y->right = n;
	if (y->bf)
	{
		y->bf = 0;
		return true;
	}
	y->bf = (y->left == n) ? 1 : -1;
	z = y->p;
	while (z)
	{
		if (z->bf) break;
		z->bf = (z->left == y) ? 1 : -1;
		y = z; z = z->p;
	}

	if (!z) return true;

	if (z->bf == 1)
	{
		if (z->right == y)
		{
			z->bf = 0;
			return true;
		}
		if (y->bf == -1) LR(z); else LL(z);
		return true;
	}
	else
	{
		if (z->left == y)
		{
			z->bf = 0;
			return true;
		}
		if (y->bf == 1) RL(z); else RR(z);
		return true;
	}
}

// Wyszukuje element wg wartości

Node * DrzewoAVL::look(int war)
{
	Node * g = root;

	while ((g) && (g->war != war))
		g = (war < g->war) ? g->left : g->right;

	return g;
}

// masymalna wartość

int DrzewoAVL::minn(Node * g)
{
	while (g->left) g = g->left;
	return g->war;
}

//minimalna wartość 

int DrzewoAVL::maxx(Node * g)
{
	while (g->right) g = g->right;
	return g->war;
}


Node * DrzewoAVL::minNode(Node * g)
{
	while (g->left) g = g->left;
	return g;
}


Node * DrzewoAVL::maxNode(Node * g)
{
	while (g->right) g = g->right;
	return g;
}

//zwraca poprzenidka

Node * DrzewoAVL::bef(Node * g)
{
	if (g->left) return maxNode(g->left);

	Node * y;

	do
	{
		y = g;
		g = g->p;
	} while (g && (g->right != y));

	return g;
}

// Zwraca następnika

Node * DrzewoAVL::aft(Node * g)
{
	if (g->right) return minNode(g->right);

	Node * y;

	do
	{
		y = g;
		g = g->p;
	} while (g && (g->left != y));

	return g;
}

// Usuwa element g. Zwraca usunięty węzeł

Node * DrzewoAVL::get_rid(Node * g)
{
	Node * t, *y, *z;
	bool nest;

	if ((g->left) && (g->right))
	{
		y = get_rid(bef(g));
		count++;
		nest = false;
	}
	else
	{
		if (g->left)
		{
			y = g->left; g->left = NULL;
		}
		else
		{
			y = g->right; g->right = NULL;
		}
		g->bf = 0;
		nest = true;
	}

	if (y)
	{
		y->p = g->p;
		if (y->left = g->left)  y->left->p = y;
		if (y->right = g->right) y->right->p = y;
		y->bf = g->bf;
	}

	if (g->p)
	{
		if (g->p->left == g) g->p->left = y; else g->p->right = y;
	}
	else root = y;

	if (nest)
	{
		z = y;
		y = g->p;
		while (y)
		{
			if (!(y->bf))
			{

				

				y->bf = (y->left == z) ? -1 : 1;
				break;
			}
			else
			{
				if (((y->bf == 1) && (y->left == z)) || ((y->bf == -1) && (y->right == z)))
				{

					

					y->bf = 0;
					z = y; y = y->p;
				}
				else
				{
					t = (y->left == z) ? y->right : y->left;
					if (!(t->bf))
					{

						

						if (y->bf == 1) LL(y); else RR(y);
						break;
					}
					else if (y->bf == t->bf)
					{

						

						if (y->bf == 1) LL(y); else RR(y);
						z = t; y = t->p;
					}
					else
					{

						

						if (y->bf == 1) LR(y); else RL(y);
						z = y->p; y = z->p;
					}
				}
			}
		}
	}
	count--;
	return g;
}

// Wyswietla ładnie drzewo

void DrzewoAVL::display(Node *g, int level)
{
	int i;
	if (g != NULL)
	{
		display(g->right, level + 1);
		printf("\n");
		if (g == root)
			cout << "Korzen -> ";
		for (i = 0; i < level && g != root; i++)
			cout << "        ";
		cout << g->war;
		display(g->left, level + 1);
	}
	else cout << "Drzewa jeszcze nie ma" << endl;
}

// Przechodzi przez drzewo Preorder


void DrzewoAVL::preo(Node * g)
{
	if (g)
	{
		cout << g->war << endl;  
		preo(g->left);
		preo(g->right);
	}
}

// Przechodzi przez drzewo Inorder

void DrzewoAVL::ino(Node * g)
{
	if (g)
	{
		ino(g->left);
		cout << g->war << endl;  
		ino(g->right);
	}
}

// Przechodzi przez drzewo Postorder

void DrzewoAVL::posto(Node * g)
{
	if (g)
	{
		posto(g->left);
		posto(g->right);
		cout << g->war << endl;  
	}
}

// Przechodzi przez drzewo siejąc zawartość węzłów

void DrzewoAVL::sow(Node * g)
{
	cout << g->war << " : bf = " << setw(2) << g->bf << " : Left-> ";
	if (g->left) cout << setw(3) << g->left->war;
	else        cout << "NIL";
	cout << ", Right-> ";
	if (g->right) cout << setw(3) << g->right->war;
	else         cout << "NIL";
	cout << " : p -> ";
	if (g->p) cout << setw(3) << g->p->war;
	else     cout << "NIL";
	cout << endl;
	if (g->left)  sow(g->left);
	if (g->right) sow(g->right);
}

int DrzewoAVL::height(Node *well)
{
	int h = 0;
	if (well != NULL)
	{
		int l_height = height(well->left);
		int r_height = height(well->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

// Wypisuje do cout liczbę węzłów drzewa DrzewoAVL

void DrzewoAVL::counter()
{
	cout << "\nLiczba wezlow drzewa: " << count << endl << endl;
}