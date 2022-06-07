#ifndef PLAYERONE_H
#define PLAYERONE_H

#include"baseitem.h"
#include"Bullet.h"

class Playerone:private baseitem{
    friend class pvpmode;
    friend class pvcmode;
public:
    Playerone();
    Playerone(int x,int y,const string &imagefile,int life,QGraphicsScene* scene,int energy);
    bool collide(QGraphicsScene* scene,int power);

protected:
    int life;
    int energy;
};
#endif // PLAYERONE_H
