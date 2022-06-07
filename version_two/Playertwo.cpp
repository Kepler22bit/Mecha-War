#include"Playertwo.h"

Playertwo::Playertwo()
{

}

Playertwo::Playertwo(int x,int y,const string &imagefile,int life,QGraphicsScene* scene,int energy):
    baseitem(PLAYERTWO,imagefile)
{
    setPos(x, y);
    this->life = life;
    this->energy=energy;
    scene->addItem(this);
    update();
}

bool Playertwo::collide(QGraphicsScene* scene,int power)
{
    if(life<=0)
    {
        return false;
    }
    else
    {
        if(life-power<=0)
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
