//
//  Xml.cpp
//  Core
//
//  Created by 孙昕 on 14-10-17.
//
//

#include "Xml.h"
#include "xml.h"
xml::xml(){
    root=0;
    count=0;
}
xml::~xml(){
    release(root);
    root=0;
}
void xml::release(node *n){
    node *n1=n;
    if(!n1){
        return;
    }
    while(1){
        if(n1->child){
            release(n1->child);
        }else{
            if(n1->next){
                release(n1->next);
            }else{
                if(n1->getprevious()){
                    n1->getprevious()->next=0;
                }else{
                    if(n1->parent)
                        n1->parent->child=0;
                }
                delete n1;
                return;
            }
        }
    }
}




void xml::loadstring(string s){
    
    scan(s);
}

void xml::scan(string s){
    long i=0;
    node *p=0;
    while(1){
        if(i==s.length()){
            break;
        }
        if(s[i]=='<' && s[i+1]!='/'){
            node *n=new node;
            count++;
            n->next=0;
            n->child=0;
            n->count=0;
            n->x=this;
            n->type="node";
            if(s[i+1]=='!'){
                n->type="cdata";
            }
            if(p){
                n->parent=p;
                n->parent->count++;
                node *n1=p->child;
                if(n1){
                    while(n1->next){
                        n1=n1->next;
                    }
                    n1->next=n;
                }else{
                    p->child=n;
                }
            }else{
                n->parent=0;
                if(!root){
                    root=n;
                }else{
                    node* n1=root;
                    while(n1->next){
                        n1=n1->next;
                    }
                    n1->next=n;
                }
            }
            i++;
            while(s[i]!='>'){
                if(s[i]!='/')
                    n->data.append(1,s[i]);
                i++;
            }
            long index=n->data.find(' ');
            n->tag=n->data.substr(0,index!=-1?index:n->data.find('>'));
            if(s[i-1]!='/' && s[i-1]!='?' && s[i-1]!=']'){
                p=n;
            }
            
        }else if(s[i]=='<' && s[i+1]=='/'){
            if(p->parent){
                p=p->parent;
            }else{
                p=0;
            }
            while(s[i]!='>'){
                char t=s[i];
                i++;
            }
        }else if(s[i]!='\t' && s[i]!=' ' && s[i]!='\r' && s[i]!='\n'){
            node *n=new node;
            count++;
            n->next=0;
            n->child=0;
            n->count=0;
            n->parent=p;
            n->x=this;
            n->type="text";
            n->parent->count++;
            node *n1=p->child;
            if(n1){
                while(n1->next){
                    n1=n1->next;
                }
                n1->next=n;
            }else{
                p->child=n;
            }
            while(s[i]!='<'){
                
                n->data.append(1,s[i]);
                i++;
            }
            for(long i1=n->data.length()-1;i1>=0;i1--){
                if(n->data[i1]!='\t' && n->data[i1]!=' ' && n->data[i1]!='\r' && n->data[i1]!='\n'){
                    break;
                }else{
                    n->data.erase(i1,1);
                }
            }
            continue;
        }
        i++;
    }
}
void xml::out(string& s,node *n=0){
    if(!n){
        node *r=root;
        while(r){
            output(r,s);
            s+="\r\n";
            r=r->next;
        }
    }
    else{
        output(n,s);
    }
}
void xml::output(node * n,string& s){
    node *n1=n;
    long tab=0;
    if(n1->gettype()=="text"){
        s=s+n1->data;
        return;
    }else if(n1->child){
        s=s+"<"+n1->data+">"+"\r\n";
    }else if(n1->gettag()=="?xml"){
        s=s+"<"+n1->data+">";
        return;
    }else{
        s=s+"<"+n1->data+"/>";
        return;
    }
    
    while(1){
        
        if(n1->child){
            n1=n1->child;
            tab++;
            for(long i1=0;i1<tab;i1++){
                s=s+"\t";
            }
            if(n1->type=="text"){
                s=s+n1->data+"\r\n";
            }else if(n1->gettype()=="cdata"){
                s=s+"<"+n1->data+">\r\n";
            }else{
                if(n1->count>0){
                    s=s+"<"+n1->data+">"+"\r\n";
                }else{
                    s=s+"<"+n1->data+"/>"+"\r\n";
                }
            }
            
        }else if(n1->next && n1!=n){
            if(n1->count>0){
                for(long i2=0;i2<tab;i2++){
                    s=s+"\t";
                }
                s=s+"</"+n1->tag+">"+"\r\n";
            }
            n1=n1->next;
            for(long i1=0;i1<tab;i1++){
                s=s+"\t";
            }
            if(n1->type=="text"){
                s=s+n1->data+"\r\n";
            }else if(n1->gettype()=="cdata"){
                s=s+"<"+n1->data+">\r\n";
            }else{
                if(n1->count>0){
                    s=s+"<"+n1->data+">"+"\r\n";
                }else{
                    s=s+"<"+n1->data+"/>"+"\r\n";
                }
            }
        }else{
            //s=s+"</"+n1->tag+">"+"/r/n";
            node *n2=n1->parent,*n3=0;
            if(n2 && n2!=n){
                while(n2->next==0){
                    tab--;
                    for(long i1=0;i1<tab;i1++){
                        s=s+"\t";
                    }
                    s=s+"</"+n2->tag+">"+"\r\n";
                    n3=n2;
                    n2=n2->parent;
                    
                    
                    if(n2==n){
                        tab--;
                        for(long i1=0;i1<tab;i1++){
                            s=s+"\t";
                        }
                        s=s+"</"+n->tag+">";
                        goto a;
                    }
                }
                tab--;
                for(long i1=0;i1<tab;i1++){
                    s=s+"\t";
                }
                s=s+"</"+n2->tag+">"+"\r\n";
                n1=n2->next;
                for(long i2=0;i2<tab;i2++){
                    s=s+"\t";
                }
                if(n1->count>0){
                    s=s+"<"+n1->data+">"+"\r\n";
                }else{
                    s=s+"<"+n1->data+"/>"+"\r\n";
                }
            }else{
                s=s+"</"+n->tag+">";
            a:      break;
            }
            
        }
        
    }
}
nodecollect *xml::selectnodes(string s){
    nodecollect *nc=new nodecollect;
    long i=0;
    if(s[i]=='/' && s[i+1]=='/'){
        long index=s.find('/',i+2);
        string s1;
        if(index!=-1){
            s1=s.substr(2,index-2);
        }else{
            s1=s.substr(2);
        }
        long i1=0;
        while(getchild(i1)){
            node *n=getchild(i1);
            if(n->gettag()==s1){
                if(index==-1){
                    nc->push(n);
                }else if(s[index+1]=='/'){
                    string s2=s.substr(index+2);
                    for(long i2=0;i2<n->gettotlecount();i2++){
                        if(n->getchild(i2)->gettag()==s2){
                            nc->push(n->getchild(i2));
                        }
                    }
                }else{
                    node *n1=n->child;
                    string s2=s.substr(index+1);
                    while(n1){
                        if(n1->gettag()==s2){
                            nc->push(n1);
                        }
                        n1=n1->next;
                    }
                }
            }
            i1++;
        }
    }else{
        long index=s.find('/',i+1);
        string s1;
        if(index!=-1){
            s1=s.substr(1,index-1);
        }else{
            s1=s.substr(1);
        }
        node *nn=root;
        while(nn){
            node *n=nn;
            if(n->gettag()==s1){
                if(index==-1){
                    nc->push(n);
                }else if(s[index+1]=='/'){
                    string s2=s.substr(index+2);
                    for(long i2=0;i2<n->gettotlecount();i2++){
                        if(n->getchild(i2)->gettag()==s2){
                            nc->push(n->getchild(i2));
                        }
                    }
                }else{
                    node *n1=n->child;
                    string s2=s.substr(index+1);
                    while(n1){
                        if(n1->gettag()==s2){
                            nc->push(n1);
                        }
                        n1=n1->next;
                    }
                }
            }
            nn=nn->next;
        }
    }
    return nc;
}
nodecollect *xml::select(string s,nodecollect *nc,node *n){
    
    if(!nc){
        nc=new nodecollect;
    }
    if(s[1]=='/'){
        long index=s.find('/',2);
        if(index==-1){
            string data=s.substr(2);
            long attr=data.find('[');
            if(attr!=-1){
                string tag,k,v;
                tag=data.substr(0,attr);
                long i1=attr+1;
                while(data[i1]!='='){
                    k.append(1,data[i1]);
                    i1++;
                }
                i1++;
                while(data[i1]!=']'){
                    v.append(1,data[i1]);
                    i1++;
                }
                if(n){
                    long l=n->gettotlecount();
                    for(long i2=0;i2<l;i2++){
                        node *n1=n->getchild(i2);
                        if(n1->gettag()==tag && n1->getattr(k)==v){
                            nc->push(n1);
                        }
                    }
                    return nc;
                }else{
                    n=root;
                    while(n){
                        if(n->gettag()==tag && n->getattr(k)==v){
                            nc->push(n);
                            
                        }
                        select(s,nc,n);
                        n=n->next;
                    }
                    return nc;
                }
            }else{
                string tag=data;
                if(n){
                    long l=n->gettotlecount();
                    for(long i2=0;i2<l;i2++){
                        node *n1=n->getchild(i2);
                        if(n1->gettag()==tag){
                            nc->push(n1);
                        }
                    }
                    return nc;
                }else{
                    
                    n=root;
                    while(n){
                        if(n->gettag()==tag){
                            nc->push(n);
                        }
                        select(s,nc,n);
                        n=n->next;
                    }
                    return nc;
                }
            }
        }else{
            string data=s.substr(2,index-2);
            string next=s.substr(index);
            long attr=data.find('[');
            if(attr!=-1){
                string tag,k,v;
                tag=data.substr(0,attr);
                long i1=attr+1;
                while(data[i1]!='='){
                    k.append(1,data[i1]);
                    i1++;
                }
                i1++;
                while(data[i1]!=']'){
                    v.append(1,data[i1]);
                    i1++;
                }
                if(n){
                    long l=n->gettotlecount();
                    for(long i2=0;i2<l;i2++){
                        node *n1=n->getchild(i2);
                        if(n1->gettag()==tag && n1->getattr(k)==v){
                            select(next,nc,n1);
                        }
                    }
                    return nc;
                }else{
                    n=root;
                    while(n){
                        if(n->gettag()==tag && n->getattr(k)==v){
                            select(next,nc,n);
                        }
                        for(long i=0;i<n->gettotlecount();i++){
                            if(n->getchild(i)->gettag()==tag && n->getchild(i)->getattr(k)==v){
                                select(next,nc,n->getchild(i));
                            }
                        }
                        n=n->next;
                    }
                }
            }else{
                string tag=data;
                if(n){
                    long l=n->gettotlecount();
                    for(long i2=0;i2<l;i2++){
                        node *n1=n->getchild(i2);
                        if(n1->gettag()==tag){
                            select(next,nc,n1);
                        }
                    }
                    return nc;
                }else{
                    n=root;
                    while(n){
                        if(n->gettag()==tag){
                            select(next,nc,n);
                        }
                        for(long i=0;i<n->gettotlecount();i++){
                            if(n->getchild(i)->gettag()==tag){
                                select(next,nc,n->getchild(i));
                            }
                        }
                        n=n->next;
                    }
                }
            }
        }
        
    }else{
        long index=s.find('/',1);
        if(index==-1){
            string data=s.substr(1);
            long attr=data.find('[');
            if(attr!=-1){
                string tag,k,v;
                tag=data.substr(0,attr);
                long i1=attr+1;
                while(data[i1]!='='){
                    k.append(1,data[i1]);
                    i1++;
                }
                i1++;
                while(data[i1]!=']'){
                    v.append(1,data[i1]);
                    i1++;
                }
                if(n){
                    node *n1=n->child;
                    while(n1){
                        
                        if(n1->gettag()==tag && n1->getattr(k)==v){
                            nc->push(n1);
                        }
                        n1=n1->next;
                    }
                    return nc;
                }else{
                    n=root;
                    while(n){
                        if(n->gettag()==tag && n->getattr(k)==v){
                            nc->push(n);
                            
                        }
                        n=n->next;
                    }
                    return nc;
                }
            }else{
                string tag=data;
                if(n){
                    node *n1=n->child;
                    while(n1){
                        
                        if(n1->gettag()==tag){
                            nc->push(n1);
                        }
                        n1=n1->next;
                    }
                    return nc;
                }else{
                    
                    n=root;
                    while(n){
                        if(n->gettag()==tag){
                            nc->push(n);
                        }
                        n=n->next;
                    }
                    return nc;
                }
            }
        }else{
            string data=s.substr(1,index-1);
            string next=s.substr(index);
            long attr=data.find('[');
            if(attr!=-1){
                string tag,k,v;
                tag=data.substr(0,attr);
                long i1=attr+1;
                while(data[i1]!='='){
                    k.append(1,data[i1]);
                    i1++;
                }
                i1++;
                while(data[i1]!=']'){
                    v.append(1,data[i1]);
                    i1++;
                }
                if(n){
                    node *n1=n->child;
                    while(n1){
                        
                        if(n1->gettag()==tag && n1->getattr(k)==v){
                            select(next,nc,n1);
                        }
                        n1=n1->next;
                    }
                    return nc;
                }else{
                    n=root;
                    while(n){
                        if(n->gettag()==tag && n->getattr(k)==v){
                            select(next,nc,n);
                        }
                        n=n->next;
                    }
                }
            }else{
                string tag=data;
                if(n){
                    node *n1=n->child;
                    while(n1){
                        
                        if(n1->gettag()==tag){
                            select(next,nc,n1);
                        }
                        n1=n1->next;
                    }
                    return nc;
                }else{
                    n=root;
                    while(n){
                        if(n->gettag()==tag){
                            select(next,nc,n);
                        }
                        n=n->next;
                    }
                }
            }
        }
    }
    return nc;
}
long xml::getcount(){
    return count;
}
node *xml::getchild(long i){
    long i1=0;
    node *n=root;
    while(i1!=i){
        if(!n){
            return 0;
        }
        if(n->child){
            n=n->child;
        }else{
            if(n->next){
                n=n->next;
            }else{
                while(n->parent &&  n->parent->next==0){
                    n=n->parent;
                }
                if(n->parent){
                    n=n->parent->next;
                }else{
                    return 0;
                }
            }
        }
        i1++;
    }
    return n;
}
nodecollect *xml::getnodebyname(string s){
    node *n1=root;
    nodecollect *nc=new nodecollect;
    if(n1->tag==s){
        nc->push(n1);
    }
    while(1){
        
        if(n1->child){
            n1=n1->child;
            if(n1->tag==s){
                nc->push(n1);
            }
            
        }else if(n1->next){
            
            n1=n1->next;
            if(n1->tag==s){
                nc->push(n1);
            }
        }else{
            //cout<<"</"<<n1->tag<<">"<<endl;
            node *n2=n1->parent,*n3=0;
            if(n2){
                while(n2->next==0){
                    
                    n3=n2;
                    n2=n2->parent;
                    
                    
                    if(n2==0){
                        
                        goto a;
                    }
                }
                
                n1=n2->next;
                if(n1->tag==s){
                    nc->push(n1);
                }
            }else{
                //  cout<<"</"<<n1->tag<<">"<<endl;
            a:      break;
            }
            
        }
        
    }
    return nc;
}
node *xml::createnode(string s){
    node *n=new node;
    n->x=this;
    n->child=0;
    n->count=0;
    n->next=0;
    n->parent=0;
    n->type="node";
    n->tag=s;
    n->data=s;
    return n;
}
node *xml::createtextnode(string s){
    node *n=new node;
    n->x=this;
    n->child=0;
    n->count=0;
    n->next=0;
    n->parent=0;
    n->type="text";
    n->data=s;
    return n;
}
void xml::loadfile(string s){
    if(root)
    {
        release(root);
        root=0;
    }
    text.clear();
    FILE *f=fopen(s.data(),"rb");
    char buf[2048]={0};
    fread(buf,1,2040,f);
        text=buf;
        while(!feof(f)){
            memset(buf,0,2048);
            fread(buf,1,2047,f);
            text+=buf;
        }
    fclose(f);
    
    loadstring(text);
}
void xml::savefile(string s,long mode){
    flush();
    FILE *f=fopen(s.data(),"wb");
    if(mode==ansi){
        fwrite(text.data(),1,text.length(),f);
    }else if(mode==unicode){
       
    }else if(mode==utf8){
        
    }
    fclose(f);
}
void xml::flush(){
    text="";
    
    string s;
    node *r=root;
    while(r){
        output(r,s);
        text+=s;
        s="";
        text+="\r\n";
        r=r->next;
    }
    //scan(text);
}
string xml::gettext(){
    return text;
}
node *xml::insertpi(){
    node * n=createnode("?xml");
    n->setattr("version","1.0");
    n->data+="?";
    n->next=root;
    root=n;
    count++;
    return n;
}
xml* xml::append(node *n){
    if(root){
        node *n1=root;
        while(n1->next){
            n1=n1->next;
        }
        n1->next=n;
    }else{
        root=n;
    }
    count+=n->gettotlecount()+1;
    return this;
}

nodecollect::nodecollect(){
    count=0;
}
long nodecollect::getcount(){
    return count;
}
node *nodecollect::item(long i){
    return v[i];
}
void nodecollect::push(node* n){
    v.push_back(n);
    count++;
}

node* node::appned(node *n){
    if(child){
        node *n1=child;
        while(n1->next){
            n1=n1->next;
        }
        n1->next=n;
        count++;
        n->parent=this;
        x->count+=n->gettotlecount()+1;
        
    }else{
        child=n;
        count++;
        n->parent=this;
        x->count+=n->gettotlecount()+1;
        
    }
    return this;
}
node* node::insert(long i,node *n){
    if(i==0){
        n->next=child;
        n->parent=this;
        count++;
        child=n;
    }else if(i==count){
        appned(n);
    }else{
        node *n1=child,*n2=0;
        long i1=0;
        while(i1!=i){
            n2=n1;
            n1=n1->next;
            i1++;
        }
        n2->next=n;
        n->next=n1;
        count++;
        n->parent=this;
    }
    return this;
}
node* node::removechild(long i){
    if(i==0){
        node *n=child;
        child=child->next;
        count--;
        x->count=x->count-gettotlecount()-1;
        delete n;
    }else{
        node *n=child,*n1=0;
        long i1=0;
        while(i1!=i){
            n1=n;
            n=n->next;
            i1++;
        }
        n1->next=n->next;
        count--;
        x->count=x->count-gettotlecount()-1;
        
        delete n;
    }
    return this;
}
string node::getattr(string s){
    string ss;
    char *i=(char*)strstr(data.data(),s.data());
c:	if(i && (*(i-1)==' ' || *(i-1)=='\r' || *(i-1)=='\n' || *(i-1)=='\t') && (*(i+s.length())==' ' || *(i+s.length())=='=')){
    char *i1=strstr(i+1,"\"");
    char *i2=strstr(i1+1,"\"");
    i1++;
    while(i1!=i2){
        ss+=*i1;
        i1++;
    }
}else{
    if(i==0){
        return ss;
    }else{
        i=strstr(i+1,s.data());
        goto c;
    }
}
    return ss;
}


node* node::setattr(string k,string v){
    char *i=(char*)strstr(data.data(),k.data());
c:	if(i && (*(i-1)==' ' || *(i-1)=='\r' || *(i-1)=='\n' || *(i-1)=='\t') && (*(i+k.length())==' ' || *(i+k.length())=='=')){
    char *i1=strstr(i+1,"\"");
    char *i2=strstr(i1+1,"\"");
    string d=i2;
    data=data.substr(0,i1-data.data()+1);
    data+=v;
    data+=d;
}else{
    if(i==0){
        if(data.substr(data.length()-1,1)!="?"){
            data=data+' '+k+"="+'\"'+v+'\"';
        }else{
            data=data.substr(0,data.length()-1)+' '+k+"="+'\"'+v+"\"?";
        }
    }else{
        i=strstr(i+1,k.data());
        goto c;
    }
    
    
}
    return this;
}

node* node::setattr(string k,long v){
    char szBuf[10];
    sprintf(szBuf, "%ld",v);
    return setattr(k, szBuf);
}


node* node::removeattr(string s){
    char *i=(char*)strstr(data.data(),s.data());
c:	if(i && (*(i-1)==' ' || *(i-1)=='\r' || *(i-1)=='\n' || *(i-1)=='\t') && (*(i+s.length())==' ' || *(i+s.length())=='=')){
    char *i1=strstr(i+1,"\"");
    char *i2=strstr(i1+1,"\"");
    string d=i2+1;
    data=data.substr(0,i-data.data()-1);
    data+=d;
}else{
    if(i==0){
        return this;
    }else{
        i=strstr(i+1,s.data());
        goto c;
    }
}
    return this;
}
void node::remove(){
    node *n=getparent();
    if(n){
        node *n1=getprevious();
        if(n1){
            n1->next=next;
        }else{
            n->child=next;
        }
        n->count--;
        x->count=x->count-gettotlecount()-1;
        
    }else{
        node *n1=getprevious();
        if(n1){
            n1->next=next;
        }else{
            x->root=x->root->next;
        }
        x->count=x->count-gettotlecount()-1;
        
    }
    
    delete this;
}
node *node::getchild(long i){
    long i1=-1;
    node *n=this;
    while(i1!=i){
        if(n->child){
            n=n->child;
        }else{
            if(n->next){
                n=n->next;
            }else{
                while(n->parent &&  n->parent->next==0 && n->parent!=this){
                    n=n->parent;
                }
                if(n->parent!=this){
                    n=n->parent->next;
                }else{
                    return 0;
                }
            }
        }
        i1++;
    }
    return n;
}
nodecollect *node::getnodebyname(string s){
    node *n1=this->child;
    nodecollect *nc=new nodecollect;
    if(n1->tag==s){
        nc->push(n1);
    }
    while(1){   
        
        if(n1->child){   
            n1=n1->child;   
            if(n1->tag==s){
                nc->push(n1);
            }
            
        }else if(n1->next){   
            
            n1=n1->next;   
            if(n1->tag==s){
                nc->push(n1);
            }
        }else{   
            //cout<<"</"<<n1->tag<<">"<<endl;   
            node *n2=n1->parent,*n3=0;   
            if(n2 && n2!=this){   
                while(n2->next==0){   
                    
                    n3=n2;   
                    n2=n2->parent;   
                    
                    
                    if(n2==this){   
                        
                        goto a;   
                    }   
                }   
                
                n1=n2->next; 
                if(n1->tag==s){
                    nc->push(n1);
                }
            }else{   
                //  cout<<"</"<<n1->tag<<">"<<endl;   
            a:      break;   
            }   
            
        }   
        
    }   
    return nc;
}
long node::getcount(){
    return count;
}
node *node::getnext(){
    return next;
}
node *node::getparent(){
    return parent;
}
node *node::getprevious(){
    if(parent){
        node *n=parent->child;
        while(n && n->next!=this){
            n=n->next;
        }
        return n;
    }else{
        node *n=x->getchild(0);
        while(n && n->next!=this){
            n=n->next;
        }
        return n;
    }
    return 0;
}
string node::gettag(){
    return tag;
}
string node::gettype(){
    return type;
}
long node::gettotlecount(){
    long i1=0;
    node *n=this->child;
    if(n)
        i1++;
    while(n){
        if(n->child){
            n=n->child;
        }else{
            if(n->next){
                n=n->next;
            }else{
                
                while(n->parent &&  n->parent->next==0 && n->parent!=this){
                    n=n->parent;
                }
                if(n->parent!=this){
                    n=n->parent->next;
                }else{
                    break;
                }
                
                
                
            }
        }
        i1++;
    }
    return i1;
}
string node::gettext(){
    string s;
    for(long i=0;i<gettotlecount();i++){
        if(getchild(i)->gettype()=="text"){
            s+=getchild(i)->data;
        }
    }
    return s;
}
node *node::puttext(string s){
    if(child && child->gettype()=="text"){
        child->remove();
    }
    node *n=x->createtextnode(s);
    insert(0,n);
    return this;
}
node *node::puttext(long s){
    if(child && child->gettype()=="text"){
        child->remove();
    }
    char szBuf[10]={0};
    sprintf(szBuf, "%ld",s);
    node *n=x->createtextnode(szBuf);
    insert(0,n);
    return this;
}

nodecollect *node::selectnodes(string s){
    nodecollect *nc=new nodecollect;
    long i=0;
    if(s[i]=='/' && s[i+1]=='/'){
        long index=s.find('/',i+2);
        string s1;
        if(index!=-1){
            s1=s.substr(2,index-2);
        }else{
            s1=s.substr(2);
        }
        long i1=0;
        while(getchild(i1)){
            node *n=getchild(i1);
            if(n->gettag()==s1){
                if(index==-1){
                    nc->push(n);
                }else if(s[index+1]=='/'){
                    string s2=s.substr(index+2);
                    for(long i2=0;i2<n->gettotlecount();i2++){
                        if(n->getchild(i2)->gettag()==s2){
                            nc->push(n->getchild(i2));
                        }
                    }
                }else{
                    node *n1=n->child;
                    string s2=s.substr(index+1);
                    while(n1){
                        if(n1->gettag()==s2){
                            nc->push(n1);
                        }
                        n1=n1->next;
                    }
                }
            }
            i1++;
        }
    }else{
        long index=s.find('/',i+1);
        string s1;
        if(index!=-1){
            s1=s.substr(1,index-1);
        }else{
            s1=s.substr(1);
        }
        node *nn=child;
        while(nn){
            node *n=nn;
            if(n->gettag()==s1){
                if(index==-1){
                    nc->push(n);
                }else if(s[index+1]=='/'){
                    string s2=s.substr(index+2);
                    for(long i2=0;i2<n->gettotlecount();i2++){
                        if(n->getchild(i2)->gettag()==s2){
                            nc->push(n->getchild(i2));
                        }
                    }
                }else{
                    node *n1=n->child;
                    string s2=s.substr(index+1);
                    while(n1){
                        if(n1->gettag()==s2){
                            nc->push(n1);
                        }
                        n1=n1->next;
                    }
                }
            }
            nn=nn->next;
        }
    }
    return nc;
}
nodecollect *node::select(string s){
    return x->select(s,0,this);
}