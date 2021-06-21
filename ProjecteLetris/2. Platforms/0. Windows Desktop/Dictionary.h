#ifndef DICTIONARY_H
#define DICTIONARY_H


#include <vector>
#include <fstream>
using namespace std;

class Dictionary
{
public:
    typedef enum {
        ENGLISH = 0,
        CATALAN,
        SPANISH
    }CurrentDictionary;

    Dictionary() {}
    ~Dictionary() {}

    void resetDictionary();

    //return true si la palabra pasada por parametro es correcta
    bool checkWord(const string& word);

    int getNDictionary();

    //se fija un idioma para el diccionario
    void setDictionary(int lenguage);

    void loadDictionary(const int lenguage);

private:
    vector<string> m_sDiccionari;
    CurrentDictionary m_eCurrentDictionary;

    int contador = 0;
};

#endif // !DICTIONARY_H