#include"shield.h"
using namespace  std;
shield::shield()
{

}

shield::shield(Belong belong,int x,int y,const string &imagefile,int dur):
    baseitem(belong,imagefile)
{
    setPos(x,y);
    this->Dur=dur;
}

bool shield::hit(QGraphicsScene* scene,int power)
{
    if(Dur<=0)
    {
        return false;
    }
    else
    {
        if((Dur-power)<=0)
        {
            Dur=Dur-power;
            del(scene);
            return false;
        }
        else
        {
            Dur=Dur-power;
            return true;
        }
    }
}
