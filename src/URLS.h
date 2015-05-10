#ifndef URLS_H
#define URLS_H

#ifndef urls_map
#define urls_map URLS::Instance()
#endif

#include <tr1/unordered_map>
#include "gkio.h"


class URLS
{
    private:
        tr1::unordered_map <string, int> map_table;
        int pos;
        URLS();

    public:
        static URLS* Instance();
        virtual ~URLS();

        string to_string();
        int get_pos();
        bool has_word(string p_word);
        int return_id(string p_word);
        void add_word(string p_word);
        void remove_word(string p_word);
        bool is_cleared();
        void clear_map();
    protected:

};

#endif // VOCABULARY_H
