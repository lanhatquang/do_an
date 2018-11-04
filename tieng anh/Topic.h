#if !defined(TOPIC)
#define TOPIC

#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
#include"Vocabulary.h"
using namespace std;


class Topic
{
private:
    string m_name;
    vector<Vocabulary> m_list;
public:
    Topic();
    ~Topic();

    friend ostream &operator << (ostream &out,const Topic &a);

    void pushTopic(const Vocabulary &a);

    void setName(string &a);

    Vocabulary operator [] (int i)const;

    void QuickSort(int left, int right);
    int BinarySearchW(string word);
    string getname();
    int sizeTopic()const;

    vector<Vocabulary> ArrayRandomForTopic(int n=1);
};

Topic::Topic()
{
    this->m_name="";
}

Topic::~Topic()
{
}

Vocabulary Topic::operator[](int i)const
{
   
    return this->m_list[i];
}

ostream &operator << (ostream &out,const Topic &a)
{
    out<<"Topic: "<<a.m_name<<endl;
    for(int i = 0; i < a.sizeTopic(); i++)
    {
        out<<a[i]<<endl;
    }
    
}

void Topic::pushTopic(const Vocabulary &a)
{
    this->m_list.push_back(a);
    this->QuickSort(0,this->sizeTopic()-1);
}

void Topic::setName(string &a)
{
    this->m_name=a;
}

void Topic::QuickSort(int left, int right)
{
    if(this->m_list.size()==0) return;
    
    if(left>=right) return;

    int middle=left+(right-left)/2;
    string pivot=this->m_list[middle].getword();
    int i=left;int j=right;

    
    while(i<=j){
        
        while(this->m_list[i].getword()<pivot){
            i++;
        }
        
        while(this->m_list[j].getword()>pivot){
            j--;
        }

        
        if (i<=j) {
            string tem=this->m_list[i].getword();
            this->m_list[i].getword()=this->m_list[j].getword();
            this->m_list[j].getword()=tem;
            i++;
            j--;
        }
    }
    
    
    if (left<j) {
        Topic::QuickSort(left,j);
    }

    
    if (right>i) {
        Topic::QuickSort(i,right);
    }
}

int Topic::BinarySearchW(string word)
{
    int min=0;
    int max=this->m_list.size()-1;
    int mid=0;

    
    while(min<=max){
        mid=(min+max)/2;
        
        if (this->m_list[mid].getword()==word) {
            return mid;
        }
        else
        {
            
            if (this->m_list[mid].getword()<word) {
                min=mid+1;
            }
            else
            {
                max=mid-1;
            }
        }
        return -1;
    }
}

string Topic::getname()
{
    return this->m_name;
}

int Topic::sizeTopic() const
{
    return this->m_list.size();
}

vector<Vocabulary> Topic::ArrayRandomForTopic(int n)
{
    vector<Vocabulary> arrayVocabulary;
    int i;
    while(arrayVocabulary.size()<n){
        srand(time(NULL));
        i=rand()%this->m_list.size();
        int tm=0;
        
        for(int j = 0; j < arrayVocabulary.size(); j++)
        {
            
            if (arrayVocabulary[j].getword()==this->m_list[i].getword()) {
                tm=1;
                break;
            }
            
        }
        
        if (tm==0) {
            arrayVocabulary.push_back(this->m_list[i]);
        }
        
    }
    return arrayVocabulary;
}

#endif // TOPIC
