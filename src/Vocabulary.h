#ifndef VOCABULARY_H
#define VOCABULARY_H

#ifndef vocabulary_map
#define vocabulary_map Vocabulary::Instance()
#endif

#include <tr1/unordered_map>
#include "gkio.h"


class Vocabulary
{
    private:
        tr1::unordered_map <string, int> map_table;
        int pos;
        Vocabulary();

    public:
        static Vocabulary* Instance();
        virtual ~Vocabulary();

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
