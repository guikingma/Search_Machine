#include "URLS.h"

URLS* URLS::Instance()
{
    static URLS instance;
    return &instance;
}

URLS::URLS()
{
    pos=0;
}

URLS::~URLS()
{
    //dtor
}

string URLS::to_string()
{
    string ret = "";
    tr1::unordered_map<string, int>::iterator it;
    for (it = map_table.begin(); it !=  map_table.end(); ++it)
        ret += "{" + it->first + ":" + int_to_string(it->second) + "}\n";
    return ret;
}

int URLS::get_pos()
{
    return pos;
}

bool URLS::has_word(string p_word)
{
    if (map_table.count(p_word) > 0)
        return true;
    return false;

    /*if (map_table.find(p_word) == mapa.end())
        return false;
    return true;*/
}

int URLS::return_id(string p_word)
{
    if (has_word(p_word))
        return map_table[p_word];
    return -1;
}

void URLS::add_word(string p_word)
{
    map_table[p_word] = pos;
    pos++;
}

void URLS::remove_word(string p_word)
{
    if (has_word(p_word)) { //TODO ver se da pra fazer esse teste com o it
        tr1::unordered_map<string, int>::iterator it;
        it = map_table.find(p_word);
        map_table.erase(it);
    }
}

bool URLS::is_cleared()
{
    if (map_table.empty())
        return true;
    return false;
}

void URLS::clear_map()
{
    //if (!is_cleared()) //TODO testar sem if
        //map_table.erase(map_table.begin(), map_table.end());
    map_table.clear();
}
