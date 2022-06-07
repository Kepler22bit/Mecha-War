#ifndef BULLET_H
#define BULLET_H

#include<baseitem.h>

using namespace std;

class Bullet: private baseitem{

    friend class pvpmode;
    friend class pvcmode;
public:
    Bullet();
    Bullet(Belong belong,int x,int y,const string &imagefile,const QPointF &dir,int power );
    pair<qreal,qreal> updateposition();
    void collide(QGraphicsScene* scene);

private:
    QPointF dir;
    int power;
};
#endif // BULLET_H
