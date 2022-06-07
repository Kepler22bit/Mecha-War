#ifndef MENU_H
#define MENU_H
#include"pvpmode.h"
using namespace std;

class gamemenu:public QGraphicsScene{
    Q_OBJECT
public:
    gamemenu();
    gamemenu(QGraphicsView* view,QGraphicsScene* PVC,QGraphicsScene* PVP,QGraphicsScene* online);
    void getviewptr(QGraphicsView* view);
    void getgamemodeptr(QGraphicsScene* PVC,QGraphicsScene* PVP,QGraphicsScene* online);

private:
    QGraphicsWidget *maskWidget;
    QGraphicsWidget *PVCbtn;
    QGraphicsWidget *PVPbtn;
    QGraphicsWidget *Onlinebtn;
    QGraphicsTextItem *authorText;
    QGraphicsTextItem *titleText;
    QGraphicsView * view;
    QGraphicsScene* PVC;
    QGraphicsScene* PVP;
    QGraphicsScene* online;
protected slots:
    void enterPVCmode();
    void enterPVPmode();
    void enterOnlinemode();
    void showmessage();
};


#endif // MENU_H
