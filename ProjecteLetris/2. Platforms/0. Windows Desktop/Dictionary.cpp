#include "Dictionary.h"

void Dictionary::resetDictionary()
{
    m_sDiccionari.clear();
}

bool Dictionary::checkWord(const string& word)
{
    bool paraulaCorrecta = false;
    vector<string>::iterator actual;

    for (actual = m_sDiccionari.begin(); actual != m_sDiccionari.end(); ++actual)
    {
        if (*actual == word)
        {
            paraulaCorrecta = true;
        }
    }

    return paraulaCorrecta;
}

int Dictionary::getNDictionary()
{
    return m_sDiccionari.size();
}

void Dictionary::setDictionary(int lenguage)
{
    switch (lenguage)
    {
    case 0:
        m_eCurrentDictionary = ENGLISH;
        break;
    case 1:
        m_eCurrentDictionary = CATALAN;
        break;
    case 2:
        m_eCurrentDictionary = SPANISH;
        break;
    default:
        break;
    }
}

void Dictionary::loadDictionary(const int lenguage)
{
    ifstream diccionari;
    switch (lenguage)
    {
    case 0:
        diccionari.open("./data/Dictionaries/English.dic");
        break;
    case 1:

        diccionari.open("./data/Dictionaries/Catalan.dic");
        break;
    case 2:

        diccionari.open("./data/Dictionaries/Spanish.dic");
        break;
    default:
        break;
    }

    if (diccionari.is_open())
    {
        string s;
        diccionari >> s;
        while (!diccionari.eof())
        {
            m_sDiccionari.push_back(s);
            diccionari >> s;
        }
        diccionari.close();
        ++contador;
    }
}

