#ifndef PLAYERTWO_H
#define PLAYERTWO_H

#include"baseitem.h"
#include"Bullet.h"

class Playertwo:private baseitem{
    friend class pvpmode;
    friend class pvcmode;
public:
    Playertwo();
    Playertwo(int x,int y,const string &imagefile,int life,QGraphicsScene* scene,int energy);
    bool collide(QGraphicsScene* scene,int power);

protected:
    int life;
    int energy;
};

#endif // PLAYERTWO_H
