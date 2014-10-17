//
//  Xml.h
//  Core
//
//  Created by 孙昕 on 14-10-17.
//
//

#ifndef __Core__Xml__
#define __Core__Xml__

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class xml;
class nodecollect;
class node{
public:
    string getattr(string);
    node* setattr(string,string);
    node* setattr(string,long);
    node* appned(node *);
    node* removechild(long);
    node* insert(long,node*);
    node *getnext();
    node *getparent();
    node *getprevious();
    node *getchild(long);
    nodecollect *getnodebyname(string);
    long getcount();
    string gettag();
    string gettype();
    node* removeattr(string);
    void remove();
    long gettotlecount();
    string gettext();
    node *puttext(string);
    node *puttext(long);
    nodecollect *selectnodes(string);
    nodecollect *select(string);
    xml* getXml()
    {
        return x;
    }
private:
    friend class xml;
    long count;
    node *child;
    node *next;
    node *parent;
    string data;
    string tag;
    string type;
    xml *x;
    
};
class nodecollect{
public:
    nodecollect();
    long getcount();
    node *item(long);
    void push(node*);
private:
    long count;
    vector<node*> v;
};
class xml{
public:
    xml();
    ~xml();
    void loadstring(string);
    void scan(string);
    void out(string&,node *);
    node *getchild(long);
    nodecollect *getnodebyname(string);
    long getcount();
    node *createnode(string);
    node *createtextnode(string);
    void loadfile(string);
    void savefile(string,long =ansi);
    void flush();
    string gettext();
    node  *insertpi();
    xml* append(node *);
    nodecollect *selectnodes(string);
    nodecollect *select(string,nodecollect * =0,node * =0);
    void loadurl(string);
    enum {ansi=1,unicode=2,utf8=3};
    void release(node *);
private:
    friend class node;
    node* root;
    long count;
    string text;
    void output(node *,string&);
};      

#endif /* defined(__Core__Xml__) */
