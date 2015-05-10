/*
 * Triples.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: gui
 */

#include "Triples.h"

void Triples::list_files() {
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir("output/triples/")) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL) {
			printf("%s\n", ent->d_name);
		}
		closedir(dir);
	} else {
		/* could not open directory */
		perror("ERROR 1: could not open directory");
	}
}

t_triple Triples::make_triple(int p_word, int p_url, int p_matches) {
	t_triple l_triple;
	l_triple.word = p_word;
	l_triple.url = p_url;
	l_triple.matches = p_matches;
	return l_triple;
}

bool Triples::lower(t_triple p_x, t_triple p_y) {
	if (p_x.word < p_y.word)
		return true;
	else if (p_x.word == p_y.word && p_x.url < p_y.url)
		return true;
	return false;
}

bool Triples::greater(t_triple p_x, t_triple p_y) {
	if (p_x.word > p_y.word)
		return true;
	else if (p_x.word == p_y.word && p_x.url > p_y.url)
		return true;
	return false;
}

void Triples::swap_triples(t_triple &p_a, t_triple &p_b) {
	t_triple temp;
	temp = p_a;
	p_a = p_b;
	p_b = temp;
}

void Triples::quicksort(t_triple p_triples[], int left, int right) {
	int i = left, j = right;
	t_triple pivot = p_triples[(left + right) / 2];

	// partition
	while (i <= j) {
		while (lower(p_triples[i], pivot) && i < right) {
			i++;
		}
		while (greater(p_triples[j], pivot) && j > left) {
			j--;
		}
		if (i <= j) {
			swap_triples(p_triples[i], p_triples[j]);
			i++;
			j--;
		}
	};

	//recursion
	if (j > left) {
		quicksort(p_triples, left, j);
	}
	if (i < right) {
		quicksort(p_triples, i, right);
	}
}

void Triples::quicksort_triples() {
	if (n > 1) // nao ordenar lista com 1 elemento
		quicksort(triples, 0, n - 1);
}

void Triples::clear_triples() {
	/*
	 t_triple null_triple;
	 null_triple.word = 0;
	 null_triple.url = 0;
	 null_triple.matches = 0;
	 fill(triples, triples+LEN, null_triple);
	 */
	n = 0;
	n_file++;
}

void Triples::store_triples() {
	struct stat st; //for verification of directory existence
	ofstream ofile;
	string filename;
	//se nao tiver diretorio, criar
	if (!(stat("output/triples/", &st) == 0 && S_ISDIR(st.st_mode)))
	{
		const int dir_err = system("mkdir -p output/triples/");
		if (-1 == dir_err)
		{
		    printf("Fatal Error: error creating directory!n");
		    exit(1);
		}
	}

	filename = "output/triples/part_" + int_to_string(n_file) + ".txt";
	ofile.open(filename.c_str());
	ofile << to_string();
	ofile.close();
}

Triples::Triples() {
	n = 0;
	len = LEN;
	n_file = 0;
}

Triples::~Triples() {
	// TODO Auto-generated destructor stub
}

string Triples::to_string() {
	string ret = "";
	for (int i = 0; i < n; i++)
		ret += "<" + int_to_string(triples[i].word) + ","
				+ int_to_string(triples[i].url) + ","
				+ int_to_string(triples[i].matches) + ">\n";
	return ret;
}

int Triples::get_n() {
	return n;
}

int Triples::get_len() {
	return len;
}

int Triples::get_n_file() {
	return n_file;
}

void Triples::add_triple(int p_word, int p_url, int p_matches) {
	if (n >= len)
		push_triples();
	triples[n] = make_triple(p_word, p_url, p_matches);
	n++;
}

void Triples::push_triples() {
	// ordenar lista na memoria
	quicksort_triples();
	// armazenar em arquivo
	store_triples();
	//apagar lista, para reuso
	clear_triples();
}

void Triples::heap_triples() {
	cout << n_file << endl;
}

