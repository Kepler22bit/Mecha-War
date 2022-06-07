#include"Playerone.h"

Playerone::Playerone()
{

}

Playerone::Playerone(int x,int y,const string &imagefile,int life,QGraphicsScene* scene,int energy):
    baseitem(PLAYERONE,imagefile)
{
    setPos(x, y);
    this->life = life;
    this->energy=energy;
    scene->addItem(this);
    update();
}

bool Playerone::collide(QGraphicsScene* scene,int power)
{
    if(life<=0)
    {
        return false;
    }
    else
    {
        if((life-power)<=0)
        {
            life=life-power;
            del(scene);
            return false;
        }
        else
        {
            life=life-power;
            return true;
        }
    }
}
