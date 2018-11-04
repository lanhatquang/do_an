#if !defined(FILE)
#define FILE
#include<fstream>
#include<string>
#include<iostream>
#include"List.h"
using namespace std;


void ghifile(string &a, Vocabulary &b)
{
    ofstream fo(a);
    fo<<"{"<<b.getword()<<"|"<<b.gettype()<<"|"<<b.getmean()<<"|"<<b.getexam()<<"|"<<b.gettopic()<<"}"<<"\n";
    fo.close();
}


Vocabulary lay_tu(string &a, string &b)
{
    ifstream fi(a);
    string s;
    int tm=0;
    while(getline(fi,s)){
        string k="";
        for(int i = 1; i < s.length(); i++)
        {
            
            if (s[i]!='|') {
                k+=s[i];
            }else break;
            
        }
        
        if (b==k) {
            tm=1;
            break;
        }
        
    }
    if(tm==0) 
    {
        Vocabulary v;
        return v;
    }
    else
    {
        Vocabulary v;
        string k="";
        int tm=0;
        for(int i = 1; i < s.length(); i++)
        {
            
            if (s[i]=='|' && tm==0) {
                v.setword(k);
                tm+=1;
            }
            if (s[i]=='|' && tm==1) {
                v.settype(k);
                tm+=1;
            }
            if (s[i]=='|' && tm==2) {
                v.setmean(k);
                tm+=1;
            }
            if (s[i]=='|' && tm==3) {
                v.setexam(k);
                tm+=1;
            }
            if (s[i]=='}' && tm==4) {
                v.settopic(k);
            }
            k+=s[i];
        }
        return v;
    }
    
    fi.close();
}

#endif // FILE
