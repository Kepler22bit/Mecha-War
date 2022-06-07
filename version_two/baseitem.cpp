#include"baseitem.h"

baseitem::baseitem()
{

}

baseitem::baseitem(Belong belong,const string &imagefile):
    QGraphicsPixmapItem(QPixmap(QString::fromStdString(imagefile)))
{
    this->belong=belong;
}

void baseitem::add(QGraphicsScene *scene)
{
    if(!scene->items().contains(this))
    {
        scene->addItem(this);
        update();
    }
}

void baseitem::del(QGraphicsScene *scene)
{
    scene->removeItem(this);
    update();
}
