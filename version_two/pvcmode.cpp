#include"pvcmode.h"

const QPointF Lifebarpos1=QPointF(30,30);
const QPointF Lifebarpos2=QPointF(690,30);
const QPointF energybarpos1=QPointF(90,60);
const QPointF energybarpos2=QPointF(750,60);

const int BulletflyTimer=10;
const int PlayermoveTimer=30;
const int energyTimer=200;
const int BulletshootTimer=800;
const int BulletshootTimer2=500;
const int BulletshootTimer3=700;
const int BulletshootTimer4=800;
const int BulletshootTimer5=1200;

pvcmode::pvcmode()
{
    setSceneRect(0,0,1024,512);

    this->Playeroneimage=":/image/me.png";
    this->Playeronelife=100;
    this->Playeroneenergy=50;

    this->Playertwoimage=":/image/Boss.png";
    this->Playertwolife=100;
    this->Playertwoenergy=50;

    this->Bulletimageone=":/image/redbullet.png";
    this->Bulletpowerone=1;

    this->Bulletimagetwo=":/image/bluebullet.png";
    this->Bulletpowertwo=1;

    this->shieldimageone=":/image/myshield.png";
    this->Durone=25;

    this->shieldimagetwo=":/image/shield1.png";
    this->Durtwo=25;

    this->nuclearimageone=":/image/nuclear3.png";
    this->nuclearpowerone=25;

    this->nuclearimagetwo=":/image/nuclear1.png";
    this->nuclearpowertwo=25;

    playerone=nullptr;
    playertwo=nullptr;
    shieldone=nullptr;
    shieldtwo=nullptr;

    lifebar12=new QGraphicsRectItem(Lifebarpos1.x(),Lifebarpos1.y(),Playeronelife*3,20);
    lifebar12->setPen(QPen(Qt::white));
    addItem(lifebar12);
    lifebar12->hide();
    lifebar11=new QGraphicsRectItem(Lifebarpos1.x(),Lifebarpos1.y(),Playeronelife*3,20);
    lifebar11->setBrush(QBrush(Qt::red));
    addItem(lifebar11);
    lifebar11->hide();

    lifebar22=new QGraphicsRectItem(Lifebarpos2.x(),Lifebarpos2.y(),Playertwolife*3,20);
    lifebar22->setPen(QPen(Qt::white));
    addItem(lifebar22);
    lifebar22->hide();
    lifebar21=new QGraphicsRectItem(Lifebarpos2.x(),Lifebarpos2.y(),Playertwolife*3,20);
    lifebar21->setBrush(QBrush(Qt::yellow));
    addItem(lifebar21);
    lifebar21->hide();

    energybar12=new QGraphicsRectItem(energybarpos1.x(),energybarpos1.y(),Playeroneenergy*3,10);
    energybar12->setPen(QPen(Qt::white));
    addItem(energybar12);
    energybar12->hide();
    energybar11=new QGraphicsRectItem(energybarpos1.x(),energybarpos1.y(),0,10);
    energybar11->setBrush(QBrush(Qt::blue));
    addItem(energybar11);
    energybar11->hide();

    playList=new QMediaPlaylist;
    playList->addMedia(QUrl("qrc:///music/music1.mp3"));
    playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    player = new QMediaPlayer(this);
    player->setPlaylist(playList);
    player->play();

    QWidget *mask = new QWidget;
    mask->setAutoFillBackground(true);
    mask->setPalette(QPalette(QColor(0, 0, 0, 80)));
    mask->resize(width(),height());
    maskWidget = addWidget(mask);
    maskWidget->setPos(0,0);
    maskWidget->setZValue(1);
    maskWidget->hide();

    QPushButton *startGameBtn = new QPushButton("Start Game");
    startGameBtn->setFont(QFont("Segoe Print",18));
    startGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                "QPushButton:hover{color:red;}");
    connect(startGameBtn,SIGNAL(clicked()),this,SLOT(startGame()));
    startGameButton = addWidget(startGameBtn);
    startGameButton->setPos(420,200);
    startGameButton->setZValue(2);
    startGameButton->hide();

    QPushButton *helpGameBtn = new QPushButton(tr("Game Help"));
    helpGameBtn->setFont(QFont("Segoe Print",18));
    helpGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                   "QPushButton:hover{color:red;}");
    connect(helpGameBtn,SIGNAL(clicked()),this,SLOT(showHelpMessage()));
    helpGameButton = addWidget(helpGameBtn);
    helpGameButton->setPos(420,260);
    helpGameButton->setZValue(2);
    helpGameButton->hide();

    QPushButton *quitGameBtn = new QPushButton(tr("Game Menu"));
    quitGameBtn->setFont(QFont("Segoe Print",18));
    quitGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                               "QPushButton:hover{color:red;}");
    connect(quitGameBtn,SIGNAL(clicked()),this,SLOT(Gamemenu()));
    quitGameButton = addWidget(quitGameBtn);
    quitGameButton->setPos(420, 320);
    quitGameButton->setZValue(2);
    quitGameButton->hide();

    isPause = false;
    QPushButton *continueGameBtn = new QPushButton(tr("Resume"));
    continueGameBtn->setFont(QFont("Segoe Print",18));
    continueGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                   "QPushButton:hover{color:red;}");
    connect(continueGameBtn,SIGNAL(clicked()),this,SLOT(pauseGame()));
    continueGameButton = addWidget(continueGameBtn);
    continueGameButton->setPos(420,200);
    continueGameButton->setZValue(2);
    continueGameButton->hide();

    titleText = new QGraphicsTextItem;
    addItem(titleText);
    titleText->setHtml(tr("<font color=white>Player VS Computer</font>"));
    titleText->setFont(QFont("Segoe Print", 35));
    titleText->setPos(260,80);
    titleText->setZValue(2);
    titleText->hide();

    authorText = new QGraphicsTextItem;
    addItem(authorText);
    authorText->setHtml(tr("<font color=white>Copyright © 2022,Hua kaiwen. All Rights Reserved."));
    authorText->setFont(QFont("Segoe Script"));
    authorText->setPos(240, 450);
    authorText->setZValue(2);
    authorText->hide();

    gameLostText = new QGraphicsTextItem;
    addItem(gameLostText);
    gameLostText->setFont(QFont("Segoe Print", 35));
    gameLostText->setPos(350, 70);
    gameLostText->setZValue(2);
    gameLostText->hide();

    QPushButton *retryGameBtn = new QPushButton(tr("Retry"));
    retryGameBtn->setFont(QFont("Segoe Print",18));
    retryGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                "QPushButton:hover{color:red;}");
    connect(retryGameBtn,SIGNAL(clicked()),this,SLOT(retryGame()));
    retryGameButton = addWidget(retryGameBtn);
    retryGameButton->setPos(420,200);
    retryGameButton->setZValue(2);
    retryGameButton->hide();

    welcomeGame();
}

void pvcmode::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==PlayeronemoveTimer)
    {
        if(changeposition(playerone,playerone->x()+Playeronemove.x(),playerone->y()+Playeronemove.y())&&shieldone!=nullptr)
        {
          changeshield(shieldone,shieldone->x()+Playeronemove.x(),shieldone->y()+Playeronemove.y());
        }
    }
    if(event->timerId()==PlayertwomoveTimer)
    {
        if(changeposition(playertwo,playertwo->x()+Playertwomove.x(),playertwo->y()+Playertwomove.y())&&shieldtwo!=nullptr)
        {
         changeshield(shieldtwo,shieldtwo->x()+Playertwomove.x(),shieldtwo->y()+Playertwomove.y());
        }
    }
    if(event->timerId()==BulletmoveTimer)
    {
        updateBullets1();
        updateBullets2();
    }
    if(event->timerId()==energychangeTimer1)
    {
        playerone->energy++;
        updatebarenergy(energybar11,energybar12,energybarpos1,3,QBrush(Qt::blue));
        if(playerone->energy==Playeroneenergy)
        {
            killTimer(energychangeTimer1);
        }
    }
    if(event->timerId()==BulletshootTimerid)
    {
        shootBullets2();
    }
    if(event->timerId()==BulletshootTimerid2)
    {
        shootBullets3();
    }
    if(event->timerId()==BulletshootTimerid3)
    {
        shootBullets4();
    }
    if(event->timerId()==BulletshootTimerid4)
    {
        shootBullets5();
    }
    if(event->timerId()==BulletshootTimerid5)
    {
        shootnuclear2();
    }
}

void pvcmode::keyPressEvent(QKeyEvent *event)
{
    try{
    if(event->key()==Qt::Key_W && !event->isAutoRepeat())
    {
        if(playerone==nullptr)
        {
            throw -1;
        }
        if(Playeronemove==QPointF(0,0))
        {
            PlayeronemoveTimer= startTimer(PlayermoveTimer);
        }
        Playeronemove = QPointF(0, -10);
    }
    if(event->key()==Qt::Key_S && !event->isAutoRepeat())
    {
        if(playerone==nullptr)
        {
            throw -1;
        }
        if(Playeronemove==QPointF(0,0))
        {
            PlayeronemoveTimer= startTimer(PlayermoveTimer);
        }
        Playeronemove = QPointF(0, 10);
    }
    if(event->key()==Qt::Key_A && !event->isAutoRepeat())
    {
        if(playerone==nullptr)
        {
            throw -1;
        }
        if(Playeronemove==QPointF(0,0))
        {
            PlayeronemoveTimer= startTimer(PlayermoveTimer);
        }
        Playeronemove = QPointF(-10, 0);
    }
    if(event->key()==Qt::Key_D && !event->isAutoRepeat())
    {
        if(playerone==nullptr)
        {
            throw -1;
        }
        if(Playeronemove==QPointF(0,0))
        {
            PlayeronemoveTimer= startTimer(PlayermoveTimer);
        }
        Playeronemove = QPointF(10, 0);
    }
    if(event->key()==Qt::Key_J)
    {
        if(playerone==nullptr)
        {
            throw -1;
        }
        shootBullets1();
    }
    if(event->key()==Qt::Key_Space)
    {
        if(playerone==nullptr)
        {
            throw -1;
        }
        pauseGame();
    }
    if(event->key()==Qt::Key_K)
    {
        if(playerone==nullptr)
        {
            throw -1;
        }
        if(playerone->energy>=Playeroneenergy)
        {
            delete(shieldone);
            createshield1();
            playerone->energy=0;
            updatebarenergy(energybar11,energybar12,energybarpos1,-150,QBrush(Qt::blue));
            energychangeTimer1=startTimer(energyTimer);
        }
    }
    if(event->key()==Qt::Key_L)
    {
        if(playerone==nullptr)
        {
            throw -1;
        }
        if(playerone->energy>=Playeroneenergy)
        {
            shootnuclear1();
            playerone->energy=0;
            updatebarenergy(energybar11,energybar12,energybarpos1,-150,QBrush(Qt::blue));
            energychangeTimer1=startTimer(energyTimer);
        }
    }
    }
    catch(int)
    {
        return;
    }
}

void pvcmode::keyReleaseEvent(QKeyEvent *event)
{
    if((event->key()==Qt::Key_W || event->key()==Qt::Key_S || event->key()==Qt::Key_A || event->key()==Qt::Key_D)
            && !event->isAutoRepeat())
    {
        Playeronemove = QPointF(0, 0);
        killTimer(PlayeronemoveTimer);
    }
}

void pvcmode::getviewptr(QGraphicsView *view)
{
    this->view=view;
}

void pvcmode::getgamemenu(QGraphicsScene *scene)
{
    this->menu=scene;
}

bool pvcmode::changeposition(Playerone *player, int newx, int newy)
{
    if(player->x()==newx && player->y()==newy)
    {
        return false;
    }
    if(newx<0||newx>width()||newy<0||newy>height()-30)
    {
        return false;
    }
    if(player->collidesWithItem(playertwo))
    {
        Playeronemove=QPointF(0,0);
    }
    if (player->life > 0)
    {
        player->moveBy(newx-player->x(), newy-player->y());
        player->update();
    }
    return player->life>0;
}

bool pvcmode::changeposition(Playertwo *player, int newx, int newy)
{
    if(player->x()==newx && player->y()==newy)
    {
        return false;
    }
    if(newx<0||newx>width()-80||newy<0||newy>height()-150)
    {
        return false;
    }
    if(player->collidesWithItem(playerone))
    {
        Playertwomove=QPointF(0,0);
    }
    if (player->life > 0)
    {
        player->moveBy(newx-player->x(), newy-player->y());
        player->update();
    }
    return player->life>0;
}

bool pvcmode::changeshield(shield *shield, int newx, int newy)
{
    if(shield->x()==newx && shield->y()==newy)
    {
        return true;
    }
    if(newx<0||newx>width()||newy<0||newy>height())
    {
        return true;
    }
    if(shield->Dur>0)
    {
        shield->moveBy(newx-shield->x(),newy-shield->y());
        shield->update();
    }
    return shield->Dur>0;
}

bool pvcmode::changeBulletposition(Bullet *bullet, int newx, int newy)
{
    if (bullet->x() == newx && bullet->y() == newy)
    {
        return true;
    }
    if(bullet->belong==PLAYERONE&&bullet->collidesWithItem(playertwo))
    {
        updatebar1(lifebar21,lifebar22,Lifebarpos2,(bullet->power)*(-3),QBrush(Qt::yellow));
        playertwo->collide(this,bullet->power);
        bullet->collide(this);
        if(playertwo->life<=0)
        {

            PlayertwoloseGame();
        }
     }
    if(bullet->belong==PLAYERTWO&&bullet->collidesWithItem(playerone))
    {
        updatebar2(lifebar11,lifebar11,Lifebarpos1,(bullet->power)*(-3),QBrush(Qt::red));
        playerone->collide(this,bullet->power);
        bullet->collide(this);
        if(playerone->life<=0)
        {

            PlayeroneloseGame();
        }
    }
    if(bullet->belong==PLAYERTWO&&bullet->collidesWithItem(shieldone))
    {
        shieldone->hit(this,bullet->power);
        bullet->collide(this);
        {
            if(shieldone->Dur<=0)
            {
                delete(shieldone);
                shieldone=nullptr;
            }
        }
    }
    if(bullet->belong==PLAYERONE&&bullet->collidesWithItem(shieldtwo))
    {
        shieldtwo->hit(this,bullet->power);
        bullet->collide(this);
        {
            if(shieldtwo->Dur<=0)
            {
                delete(shieldtwo);
                shieldtwo=nullptr;
            }
        }
    }
    if (bullet->power > 0)
    {
        if (newx <= 0 || newx >= width() || newy <= 0 || newy >= height())
        {
            bullet->del(this);
            return false;
        }
        bullet->add(this);
        bullet->moveBy(newx-bullet->x(), newy-bullet->y());
        bullet->update();
    }
    return bullet->power>0;
}

void pvcmode::updatebar1(QGraphicsRectItem *bar, QGraphicsRectItem *frame, const QPointF &pos, qreal var, const QBrush &brush)
{
    qreal wid = bar->rect().width();
    if(var<0)
        wid = max((qreal)0, wid+var);
    else
        wid = min(frame->rect().width(), wid+var);
    bar->setRect(pos.x(), pos.y(), wid, bar->rect().height());
    bar->setBrush(brush);
    bar->update();
}

void pvcmode::updatebar2(QGraphicsRectItem *bar, QGraphicsRectItem *frame, const QPointF &pos, qreal var, const QBrush &brush)
{
    qreal wid = bar->rect().width();
    if(var<0)
        wid = max((qreal)0, wid+var);
    else
        wid = min(frame->rect().width(), wid+var);
    bar->setRect(pos.x(), pos.y(), wid, bar->rect().height());
    bar->setBrush(brush);
    bar->update();
}

void pvcmode::updatebarenergy(QGraphicsRectItem *bar, QGraphicsRectItem *frame, const QPointF &pos, qreal var, const QBrush &brush)
{
    qreal wid = bar->rect().width();
    if(var<0)
        wid = max((qreal)0, wid+var);
    else
        wid = min(frame->rect().width(), wid+var);
    bar->setRect(pos.x(), pos.y(), wid, bar->rect().height());
    bar->setBrush(brush);
    bar->update();
}

void pvcmode::updateBullets1()
{
    sort(bulletsone.begin(),bulletsone.end(),cmp1);
    for (vector<Bullet*>::iterator it = bulletsone.begin(); it != bulletsone.end(); )
    {
        pair<int, int> loc = (*it)->updateposition();
        if (changeBulletposition(*it, loc.first, loc.second))
        {
            it++;
        }
        else
        {
            delete *it;
            it = bulletsone.erase(it);
        }
    }
}

void pvcmode::updateBullets2()
{
    sort(bulletstwo.begin(),bulletstwo.end(),cmp1);
    for (vector<Bullet*>::iterator it = bulletstwo.begin(); it != bulletstwo.end(); )
    {
        pair<int, int> loc = (*it)->updateposition();
        if (changeBulletposition(*it, loc.first, loc.second))
        {
            it++;
        }
        else
        {
            delete *it;
            it = bulletstwo.erase(it);
        }
    }
}

void pvcmode::shootBullets1()
{
    Bullet *bullet = new Bullet(PLAYERONE, playerone->x()+30, playerone->y()+12,
                                Bulletimageone, QPointF(3,0), Bulletpowerone);
    bulletsone.push_back(bullet);
    addItem(bullet);
}

void pvcmode::shootBullets2()
{
    Bullet *bullet = new Bullet(PLAYERTWO, playertwo->x()+30, playertwo->y()+80,
                                Bulletimagetwo, QPointF(-3,0), Bulletpowertwo);
    bulletstwo.push_back(bullet);
    addItem(bullet);
}

void pvcmode::shootBullets3()
{
    Bullet *bullet = new Bullet(PLAYERTWO, playertwo->x()+50, playertwo->y()+160,
                                Bulletimagetwo, QPointF(-3,0), Bulletpowertwo);
    bulletstwo.push_back(bullet);
    addItem(bullet);
}

void pvcmode::shootBullets4()
{
    Bullet *bullet = new Bullet(PLAYERTWO, playertwo->x()+90, playertwo->y()+220,
                                Bulletimagetwo, QPointF(-3,0), Bulletpowertwo);
    bulletstwo.push_back(bullet);
    addItem(bullet);
    Bullet *bullet2 = new Bullet(PLAYERTWO, playertwo->x()+30, playertwo->y()+120,
                                Bulletimagetwo, QPointF(-3,0), Bulletpowertwo);
    bulletstwo.push_back(bullet2);
    addItem(bullet2);
}

void pvcmode::shootBullets5()
{
    Bullet *bullet = new Bullet(PLAYERTWO, playertwo->x()+120, playertwo->y()+280,
                                Bulletimagetwo, QPointF(-3,0), Bulletpowertwo);
    bulletstwo.push_back(bullet);
    addItem(bullet);
}

void pvcmode::shootnuclear1()
{
    Bullet *bullet=new Bullet(PLAYERONE,playerone->x()+30,playerone->y()-20,nuclearimageone,QPointF(12,0),nuclearpowerone);
    bulletsone.push_back(bullet);
    addItem(bullet);
}

void pvcmode::shootnuclear2()
{
    Bullet *bullet=new Bullet(PLAYERTWO,playertwo->x()+150,playertwo->y()+300,nuclearimagetwo,QPointF(-12,0),nuclearpowertwo);
    bulletstwo.push_back(bullet);
    addItem(bullet);
    Bullet *bullet2=new Bullet(PLAYERTWO,playertwo->x()+100,playertwo->y()-30,nuclearimagetwo,QPointF(-12,0),nuclearpowertwo);
    bulletstwo.push_back(bullet2);
    addItem(bullet2);
}

void pvcmode::createshield1()
{
    shieldone=new shield(PLAYERONE,playerone->x()+30,playerone->y(),shieldimageone,Durone);
    addItem(shieldone);
}

void pvcmode::createshield2()
{
    shieldtwo=new shield(PLAYERTWO,playertwo->x(),playertwo->y(),shieldimagetwo,Durtwo);
    addItem(shieldtwo);
}

void pvcmode::welcomeGame()
{
    hasStarted = false;
    maskWidget->show();
    titleText->show();
    startGameButton->show();
    helpGameButton->show();
    quitGameButton->show();
    authorText->show();
}

void pvcmode::startGame()
{
    hasStarted=true;
    titleText->hide();
    startGameButton->hide();
    helpGameButton->hide();
    quitGameButton->hide();
    authorText->hide();
    maskWidget->hide();

    lifebar12->show();
    lifebar11->setRect(Lifebarpos1.x(),Lifebarpos1.y(),Playeronelife*3,lifebar11->rect().height());
    lifebar11->setBrush(QBrush(Qt::red));
    lifebar11->update();
    lifebar11->show();

    lifebar22->show();
    lifebar21->setRect(Lifebarpos2.x(),Lifebarpos2.y(),Playertwolife*3,lifebar21->rect().height());
    lifebar21->setBrush(QBrush(Qt::yellow));
    lifebar21->update();
    lifebar21->show();

    energybar12->show();
    energybar11->update();
    energybar11->show();


    Playeronemove=QPointF(0,0);
    Playertwomove=QPointF(0,0);
    BulletshootTimerid=startTimer(BulletshootTimer);
    BulletshootTimerid2=startTimer(BulletshootTimer2);
    BulletshootTimerid3=startTimer(BulletshootTimer3);
    BulletshootTimerid4=startTimer(BulletshootTimer4);
    BulletshootTimerid5=startTimer(BulletshootTimer5);
    BulletmoveTimer=startTimer(BulletflyTimer);
    energychangeTimer1=startTimer(energyTimer);
    energychangeTimer2=startTimer(energyTimer);

    playerone=new Playerone(100,height()/2,Playeroneimage,Playeronelife,this,0);
    playerone->add(this);
    playertwo=new Playertwo(500,height()/4,Playertwoimage,Playertwolife,this,0);
    playertwo->add(this);

}

void pvcmode::showHelpMessage()
{
    QString helpText;
    helpText += tr("感谢您游玩机甲战争！\n");
    helpText += tr("这是一个即时对战小游戏\n");
    helpText += tr("您可以操控您的机甲进行战斗\n");
    helpText += tr("在单人模式中，您需要对抗强大的BOSS\n");
    helpText += tr("红色进度条为您机甲的生命值\n");
    helpText += tr("黄色进度条为敌人的生命值\n");
    helpText += tr("您可以使用如下按键操控您的机甲：\n");
    helpText += tr("W：上； S：下； A：左； D：右，J：发射子弹，k；产生护盾（需要充能），L；终极技能；（需要充能）\n");
    helpText += tr("击败敌人，即可获得胜利！\n");
    QMessageBox::information(NULL,tr("游戏帮助"),helpText);
}

void pvcmode::Gamemenu()
{
    this->view->setScene(this->menu);
}

void pvcmode::pauseGame()
{
    if(!isPause)
    {
        isPause = true;
        killTimer(BulletshootTimerid);
        killTimer(BulletshootTimerid2);
        killTimer(BulletshootTimerid3);
        killTimer(BulletshootTimerid4);
        killTimer(BulletshootTimerid5);
        killTimer(BulletmoveTimer);
        killTimer(energychangeTimer1);
        killTimer(energychangeTimer2);
        maskWidget->show();
        continueGameButton->show();
        helpGameButton->show();
        quitGameButton->show();
    }
    else
    {
        isPause = false;
        BulletshootTimerid=startTimer(BulletshootTimer);
        BulletshootTimerid2=startTimer(BulletshootTimer2);
        BulletshootTimerid3=startTimer(BulletshootTimer3);
        BulletshootTimerid4=startTimer(BulletshootTimer4);
        BulletshootTimerid5=startTimer(BulletshootTimer5);
        BulletmoveTimer = startTimer(BulletflyTimer);
        energychangeTimer1=startTimer(energyTimer);
        energychangeTimer2=startTimer(energyTimer);
        maskWidget->hide();
        continueGameButton->hide();
        helpGameButton->hide();
        quitGameButton->hide();
    }
}
void pvcmode::PlayeroneloseGame()
{
    killTimer(BulletshootTimerid);
    killTimer(BulletshootTimerid2);
    killTimer(BulletshootTimerid3);
    killTimer(BulletshootTimerid4);
    killTimer(BulletshootTimerid5);
    killTimer(BulletmoveTimer);
    killTimer(energychangeTimer1);
    killTimer(energychangeTimer2);
    updatebarenergy(energybar11,energybar12,energybarpos1,-150,QBrush(Qt::blue));
    maskWidget->show();
    gameLostText->setHtml(tr("<font color=white>You Lose!</font>"));
    gameLostText->show();
    retryGameButton->show();
    helpGameButton->show();
    quitGameButton->show();
}

void pvcmode::PlayertwoloseGame()
{
    killTimer(BulletshootTimerid);
    killTimer(BulletshootTimerid2);
    killTimer(BulletshootTimerid3);
    killTimer(BulletshootTimerid4);
    killTimer(BulletshootTimerid5);
    killTimer(BulletmoveTimer);
    killTimer(energychangeTimer1);
    killTimer(energychangeTimer2);
    updatebarenergy(energybar11,energybar12,energybarpos1,-150,QBrush(Qt::blue));
    maskWidget->show();
    gameLostText->setHtml(tr("<font color=white>You Win!</font>"));
    gameLostText->show();
    retryGameButton->show();
    helpGameButton->show();
    quitGameButton->show();

}

void pvcmode::retryGame()
{
    delete playerone;
    delete playertwo;
    delete shieldone;
    shieldone=nullptr;
    delete shieldtwo;
    shieldtwo=nullptr;
   for(vector<Bullet*>::iterator i=bulletsone.begin();i<bulletsone.end();i++)
   {
       delete *i;
   }
   bulletsone.clear();
   for(vector<Bullet*>::iterator i=bulletstwo.begin();i<bulletstwo.end();i++)
   {
       delete *i;
   }
   bulletstwo.clear();
   gameLostText->hide();
   retryGameButton->hide();
   helpGameButton->hide();
   quitGameButton->hide();
   startGame();
}

bool pvcmode::cmp1(Bullet* a,Bullet* b)
{
    return a->x()>b->x();
}
