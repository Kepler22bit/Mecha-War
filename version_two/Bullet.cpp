#include"Bullet.h"
using namespace std;

Bullet::Bullet()
{

}

Bullet::Bullet(Belong belong,int x,int y,const string &imagefile,const QPointF &dir,int power):
    baseitem(belong,imagefile)
{
    setPos(x,y);
    this->dir=dir;
    this->power=power;
}

pair<qreal,qreal> Bullet::updateposition()
{
    return make_pair(x()+dir.x(),y()+dir.y());
}

void Bullet::collide(QGraphicsScene* scene)
{
    del(scene);
    power=0;
}
