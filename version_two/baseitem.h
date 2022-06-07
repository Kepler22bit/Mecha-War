#ifndef BASEITEM_H
#define BASEITEM_H

#include<QtWidgets>
#include<string>
#include<bits/stdc++.h>

using namespace std;

enum Belong {PLAYERONE,PLAYERTWO};

class baseitem:public QGraphicsPixmapItem{
public:
    baseitem();
    baseitem(Belong belong,const string &imagefile);
    void add(QGraphicsScene *scene);
    void del(QGraphicsScene *scene);

protected:
    enum Belong belong;
};
#endif // BASEITEM_H
