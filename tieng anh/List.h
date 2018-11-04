#if !defined(LIST)
#define LIST
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
#include"Topic.h"
using namespace std;


class List
{
private:
    vector<Topic> m_list;
public:
    List();
    ~List();

    friend ostream &operator << (ostream &out,const List &a);
    friend istream &operator >> (istream &in, List &a);

    Topic operator [] (int i)const;

    void QuickSort(int left, int right);
    int BinarySearchTopic(string topic);
    Vocabulary BinarySearchTopicW(string topic, string word);
    Vocabulary SearchWord(string word);

    vector<Vocabulary> ArrayRandomVocabulary(int n=1);

    int sizeList()const;
};

List::List()
{
}

List::~List()
{
}

Topic List::operator[](int i)const
{
    return this->m_list[i];
}

ostream &operator << (ostream &out,const List &a)
{
    
    for(int i = 0; i < a.sizeList(); i++)
    {
        out<<a[i]<<endl;
    }
    
}

istream &operator>> (istream &in, List &a)
{
    string k;
    Vocabulary v;
    while(1){
        cin.ignore();
        cout<<"ban co muon them tu(c/k): ";
        in>>k;
        cin.ignore();
        if (k=="c") {
            in>>v;
            
            if (a.sizeList()==0) {
                Topic m;
                    string s=v.gettopic();
                    m.setName(s);
                    a.m_list.push_back(m);
                    a[a.m_list.size()-1].pushTopic(v);
                    a.QuickSort(0, a.sizeList()-1);
            }
            else{
            for(int i = 0; i < a.sizeList(); i++)
            {
                
                if (a[i].getname()==v.gettopic()) {
                    int tm=0;
                    
                    for(int j = 0; j < a[i].sizeTopic(); j++)
                    {
                        
                        if (v.getword()==a[i][j].getword()) {
                            tm=1;
                            break;
                        }
                        
                    }
                    
                    if (tm==0) {
                        a[i].pushTopic(v);
                    }
                    
                }
                else
                {
                    Topic m;
                    string s=v.gettopic();
                    m.setName(s);
                    a.m_list.push_back(m);
                    a[a.m_list.size()-1].pushTopic(v);
                    a.QuickSort(0, a.sizeList()-1);
                }
                
                
            }
            }
            
        }
        
        if (k=="k") {
            break;
        }
        
    }
    return in;
}

void List::QuickSort(int left, int right)
{
    if(this->m_list.size()==0) return;
    
    if(left>=right) return;

    int middle=left+(right-left)/2;
    string pivot=this->m_list[middle].getname();
    int i=left;int j=right;

    
    while(i<=j){
        
        while(this->m_list[i].getname()<pivot){
            i++;
        }
        
        while(this->m_list[j].getname()>pivot){
            j--;
        }

        
        if (i<=j) {
            string tem=this->m_list[i].getname();
            this->m_list[i].getname()=this->m_list[j].getname();
            this->m_list[j].getname()=tem;
            i++;
            j--;
        }
    }
    
    
    if (left<j) {
        List::QuickSort(left,j);
    }

    
    if (right>i) {
        List::QuickSort(i,right);
    }
}

int List::BinarySearchTopic(string topic)
{
    int min=0;
    int max=this->m_list.size()-1;
    int mid=0;

    
    while(min<=max){
        mid=(min+max)/2;
        
        if (this->m_list[mid].getname()==topic) {
            return mid;
        }
        else
        {
            
            if (this->m_list[mid].getname()<topic) {
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

Vocabulary List::BinarySearchTopicW(string topic, string word)
{
    Vocabulary a;
    int i,k=List::BinarySearchTopic(topic);
    i=this->m_list[k].BinarySearchW(word);
    a=this->m_list[k][i];
    return a;
}

Vocabulary List::SearchWord(string word)
{
    int k;
    Vocabulary a;
    for(int i = 0; i < this->m_list.size(); i++)
    {
        k=this->m_list[i].BinarySearchW(word);
        
        if (k!=-1) {
            a=this->m_list[i][k];
            break;
        }
    }
    return a;
}

vector<Vocabulary> List::ArrayRandomVocabulary(int n)
{
    vector<Vocabulary> arrayrandom;
    int i,j;
    while(arrayrandom.size()<=n){
        srand(time(NULL));
        i=rand()%this->m_list.size();
        j=rand()%this->m_list[i].sizeTopic();
        int tm=0;
        for(int k = 0; k < arrayrandom.size(); k++)
        {
            if (this->m_list[i][j].getword()==arrayrandom[k].getword()) {
                tm=1;
                break;
            }
        }
        
        if (tm==0) {
            arrayrandom.push_back(this->m_list[i][j]);
        }
        
    }
    return arrayrandom;
}

int List::sizeList()const
{
    return this->m_list.size();
}

#endif // LIST
