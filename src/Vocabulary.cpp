#include "Vocabulary.h"

Vocabulary* Vocabulary::Instance()
{
    static Vocabulary instance;
    return &instance;
}

Vocabulary::Vocabulary()
{
    pos=0;
}

Vocabulary::~Vocabulary()
{
    //dtor
}

string Vocabulary::to_string()
{
    string ret = "";
    tr1::unordered_map<string, int>::iterator it;
    for (it = map_table.begin(); it !=  map_table.end(); ++it)
        ret += "{" + it->first + ":" + int_to_string(it->second) + "}\n";
    return ret;
}

int Vocabulary::get_pos()
{
    return pos;
}

bool Vocabulary::has_word(string p_word)
{
    if (map_table.count(p_word) > 0)
        return true;
    return false;

    /*if (map_table.find(p_word) == mapa.end())
        return false;
    return true;*/
}

int Vocabulary::return_id(string p_word)
{
    if (has_word(p_word))
        return map_table[p_word];
    return -1;
}

void Vocabulary::add_word(string p_word)
{
    map_table[p_word] = pos;
    pos++;
}

void Vocabulary::remove_word(string p_word)
{
    if (has_word(p_word)) { //TODO ver se da pra fazer esse teste com o it
        tr1::unordered_map<string, int>::iterator it;
        it = map_table.find(p_word);
        map_table.erase(it);
    }
}

bool Vocabulary::is_cleared()
{
    if (map_table.empty())
        return true;
    return false;
}

void Vocabulary::clear_map()
{
    //if (!is_cleared()) //TODO testar sem if
        //map_table.erase(map_table.begin(), map_table.end());
    map_table.clear();
}
