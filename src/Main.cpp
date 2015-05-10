//============================================================================
// Name        : Main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "gkio.h"
#include "Vocabulary.h"
#include "URLS.h"
#include "Triples.h"

Triples *t = new Triples();

void ex1() {
	t->add_triple(7, 1, 1);
	t->add_triple(1, 1, 5);
	t->add_triple(2, 1, 4);
	t->add_triple(2, 2, 2);
	t->add_triple(2, 2, 2);
	t->add_triple(3, 2, 1);
	t->add_triple(7, 2, 1);
	t->add_triple(1, 3, 5);
	t->add_triple(2, 3, 4);
	t->add_triple(2, 3, 2);
	t->add_triple(222, 222, 222);
	t->add_triple(10, 11, 12);
	t->add_triple(13, 14, 15);
	t->add_triple(13, 15, 16);
	t->add_triple(111, 111, 111);
	if (t->get_n() > 0)
		t->push_triples();
}

void ex2() {
	t->heap_triples();
}

int main() {
	ex1();
	ex2();
	return 0;
}
