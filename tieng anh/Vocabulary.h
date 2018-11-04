#if !defined(VOCABULARY)
#define VOCABULARY
#include<string>
#include<iostream>
using namespace std;

class Vocabulary
{
private:
    string m_word, m_meaning, m_type, m_example, m_topic;
public:
    Vocabulary(string word="", string mean="", string type="", string exam="", string topic="");
    ~Vocabulary();

    string getword();
    string getmean();
    string gettype();
    string getexam();
    string gettopic();

    void setword(string);
    void setmean(string);
    void settype(string);
    void setexam(string);
    void settopic(string);

    friend ostream &operator << (ostream &out,const Vocabulary &a);
    friend istream &operator >> (istream &in, Vocabulary &a);
};

Vocabulary::Vocabulary(string word, string mean, string type, string exam, string topic)
{
    this->m_word=word;
    this->m_meaning=mean;
    this->m_type=type;
    this->m_example=exam;
    this->m_topic=topic;
}

Vocabulary::~Vocabulary()
{
}

string Vocabulary::getword()
{
    return this->m_word;
}
string Vocabulary::getmean()
{
    return this->m_meaning;
}
string Vocabulary::gettype()
{
    return this->m_type;
}
string Vocabulary::getexam()
{
    return this->m_example;
}
string Vocabulary::gettopic()
{
    return this->m_topic;
}

void Vocabulary::setword(string word)
{
    this->m_word=word;
}
void Vocabulary::setmean(string mean)
{
    this->m_meaning=mean;
}
void Vocabulary::settype(string type)
{
    this->m_type=type;
}
void Vocabulary::setexam(string exam)
{
    this->m_example=exam;
}
void Vocabulary::settopic(string topic)
{
    this->m_topic=topic;
}

ostream &operator << (ostream &out,const Vocabulary &a)
{
    out<<a.m_word<<" ("<<a.m_type<<") :"<<a.m_meaning<<endl<<"Example: "<<a.m_example<<endl<<"Topic: "<<a.m_topic<<endl;
    return out;
}
istream &operator >> (istream &in, Vocabulary &a)
{

    cout<<"Word: ";
    // in.ignore();
    getline(in, a.m_word);
    cin.ignore();
    cout<<"Type(n/v/adj/adv): ";
    in>>a.m_type;
    cin.ignore();
    cout<<"Mean: ";
    getline(in, a.m_meaning);
    cin.ignore();
    cout<<"Example: ";
    getline(in, a.m_example);
    cin.ignore();
    cout<<"Topic: ";
    getline(in, a.m_topic);
    cin.ignore();
    return in;
}


#endif // VOCABULARY
