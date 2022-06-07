#ifndef SHIELD_H
#define SHIELD_H

#include"baseitem.h"

class shield:private baseitem{
    friend class pvpmode;
    friend class pvcmode;
public:
    shield();
    shield(Belong belong,int x,int y,const string &imagefile,int dur);
    bool hit(QGraphicsScene* scene,int power);
private:
    int Dur;
};
#endif // SHIELD_H
