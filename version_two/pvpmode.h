#ifndef CONCTRL_H
#define CONCTRL_H

#include"Bullet.h"
#include"Playerone.h"
#include"Playertwo.h"
#include"shield.h"
#include"gamemenu.h"

#include<QUrl>
#include<QMediaPlayer>
#include<QMediaPlaylist>

using namespace std;

class pvpmode:public QGraphicsScene{
    Q_OBJECT
    friend class menu;
public:
    pvpmode();
    void getgamemenu(QGraphicsScene* scene);
    void getviewptr(QGraphicsView* view);

protected:
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QGraphicsView* view;
    QGraphicsScene* menu;

    string Playeroneimage;
    int Playeronelife;
    int Playeroneenergy;

    string Playertwoimage;
    int Playertwolife;
    int Playertwoenergy;

    string nuclearimageone;
    int nuclearpowerone;

    string nuclearimagetwo;
    int nuclearpowertwo;

    string Bulletimageone;
    int Bulletpowerone;

    string Bulletimagetwo;
    int Bulletpowertwo;

    string shieldimageone;
    int Durone;

    string shieldimagetwo;
    int Durtwo;

    int BulletmoveTimer;
    int energychangeTimer1;
    int energychangeTimer2;

    QPointF Playeronemove;
    int PlayeronemoveTimer;
    QPointF Playertwomove;
    int PlayertwomoveTimer;

    Playerone* playerone;
    Playertwo* playertwo;
    shield* shieldone;
    shield* shieldtwo;
    vector<Bullet*> bulletsone;
    vector<Bullet*> bulletstwo;
    bool cmp1(Bullet* a,Bullet* b);

    QGraphicsRectItem* lifebar11;
    QGraphicsRectItem* lifebar12;
    QGraphicsRectItem* lifebar21;
    QGraphicsRectItem* lifebar22;
    QGraphicsRectItem* energybar11;
    QGraphicsRectItem* energybar12;
    QGraphicsRectItem* energybar21;
    QGraphicsRectItem* energybar22;

    QMediaPlayer* player;
    QMediaPlaylist* playList;

    bool changeposition(Playerone* player,int newx,int newy);
    bool changeposition(Playertwo* player,int newx,int newy);
    bool changeshield(shield* shield,int newx,int newy);
    bool changeBulletposition(Bullet* bullet,int newx,int newy);
    void updateBullets1();
    void updateBullets2();
    void shootBullets1();
    void shootBullets2();
    void shootnuclear1();
    void shootnuclear2();
    void createshield1();
    void createshield2();
    void updatebar1(QGraphicsRectItem *bar,QGraphicsRectItem *frame, const QPointF &pos, qreal var, const QBrush &brush);
    void updatebar2(QGraphicsRectItem *bar,QGraphicsRectItem *frame, const QPointF &pos, qreal var, const QBrush &brush);
    void updatebarenergy(QGraphicsRectItem* bar,QGraphicsRectItem *frame,const QPointF &pos,qreal var,const QBrush &brush);
    void welcomeGame();

    bool hasStarted;
    bool isPause;

    QGraphicsWidget *maskWidget;
    QGraphicsWidget *startGameButton;
    QGraphicsWidget *helpGameButton;
    QGraphicsWidget *continueGameButton;
    QGraphicsWidget *retryGameButton;
    QGraphicsWidget *quitGameButton;

    QGraphicsTextItem *titleText;
    QGraphicsTextItem *authorText;
    QGraphicsTextItem *gameLostText;
    QGraphicsTextItem *gameHelpText;
protected slots:
    void startGame();
    void showHelpMessage();
    void pauseGame();
    void PlayeroneloseGame();
    void PlayertwoloseGame();
    void retryGame();
    void Gamemenu();

};
#endif // CONCTRL_H
