#pragma once
#ifndef drzewo_h
#define drzewo_h
struct Node
{
	Node * p, *left, *right;
	int war, bf;
};



class DrzewoAVL
{
public:

	Node * root;  //korzeń
	int count;

	DrzewoAVL();
	~DrzewoAVL();
	Node * RR(Node * A);
	Node * LL(Node * A);
	Node * RL(Node * A);
	Node * LR(Node * A);
	Node * maxNode(Node * g);
	Node * minNode(Node * g);
	Node * bef(Node * g);
	Node * aft(Node * g);
	Node * get_rid(Node * g);
	Node * look(int war);
	bool      insert(Node * n);
	int       maxx(Node * g);
	int       minn(Node * g);
	int       height(Node * g);
	void	  display(Node *, int);
	void      preo(Node * g);
	void      ino(Node * g);
	void      posto(Node * g);
	void      sow(Node * g);
	void      counter();
};
#endif