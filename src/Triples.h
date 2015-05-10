#ifndef TRIPLES_H_
#define TRIPLES_H_

#define LEN 10

#include <fstream>
#include <dirent.h>

#include "gkio.h"
#include "Vocabulary.h"
#include "URLS.h"

typedef struct node {
	int word;
	int url;
	int matches;
} t_triple;

class Triples {
private:
	int n;
	int len;
	int n_file;
	t_triple triples[LEN];

	t_triple make_triple(int p_word, int p_url, int p_matches);
	bool lower(t_triple p_x, t_triple p_y);
	bool greater(t_triple p_x, t_triple p_y);
	void swap_triples(t_triple &p_a, t_triple &p_b);
	void quicksort(t_triple p_triples[], int left, int right);
	void quicksort_triples();
	void clear_triples();
	void store_triples();

	void list_files(); //TODO ver se precisa.

public:
	Triples();
	virtual ~Triples();
	string to_string();
	int get_n();
	int get_len();
	int get_n_file();
	void add_triple(int p_word, int p_url, int p_matches);
	void push_triples();

	void heap_triples();

};

#endif /* TRIPLES_H_ */
