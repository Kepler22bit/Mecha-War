#include"gamemenu.h"

gamemenu::gamemenu()
{
    setSceneRect(0,0,1024,512);

    QWidget *mask = new QWidget;
    mask->setAutoFillBackground(true);
    mask->setPalette(QPalette(QColor(0, 0, 0, 80)));
    mask->resize(width(),height());
    maskWidget = addWidget(mask);
    maskWidget->setPos(0,0);
    maskWidget->setZValue(1);
    maskWidget->show();

    QPushButton *PVCBtn = new QPushButton("Player VS Computer");
    PVCBtn->setFont(QFont("Segoe Print",18));
    PVCBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                "QPushButton:hover{color:red;}");
    connect(PVCBtn,SIGNAL(clicked()),this,SLOT(enterPVCmode()));
    PVCbtn = addWidget(PVCBtn);
    PVCbtn->setPos(340,200);
    PVCbtn->setZValue(2);
    PVCbtn->show();


    QPushButton *PVPBtn = new QPushButton("Player VS Player");
    PVPBtn->setFont(QFont("Segoe Print",18));
    PVPBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                "QPushButton:hover{color:red;}");
    connect(PVPBtn,SIGNAL(clicked()),this,SLOT(enterPVPmode()));
    PVPbtn = addWidget(PVPBtn);
    PVPbtn->setPos(340,260);
    PVPbtn->setZValue(2);
    PVPbtn->show();


    QPushButton *onlineBtn = new QPushButton("Player VS Player online");
    onlineBtn->setFont(QFont("Segoe Print",18));
    onlineBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                "QPushButton:hover{color:red;}");
    connect(onlineBtn,SIGNAL(clicked()),this,SLOT(showmessage()));
    Onlinebtn = addWidget(onlineBtn);
    Onlinebtn->setPos(340,320);
    Onlinebtn->setZValue(2);
    Onlinebtn->show();

    titleText = new QGraphicsTextItem;
    addItem(titleText);
    titleText->setHtml(tr("<font color=white>Mecha War</font>"));
    titleText->setFont(QFont("Segoe Print", 35));
    titleText->setPos(320,80);
    titleText->setZValue(2);
    titleText->show();

    authorText = new QGraphicsTextItem;
    addItem(authorText);
    authorText->setHtml(tr("<font color=white>Copyright © 2022,Hua kaiwen. All Rights Reserved."));
    authorText->setFont(QFont("Segoe Script"));
    authorText->setPos(240, 450);
    authorText->setZValue(2);
    authorText->show();
}

gamemenu::gamemenu(QGraphicsView* view,QGraphicsScene* PVC,QGraphicsScene* PVP,QGraphicsScene* online)
{
    setSceneRect(0,0,1024,512);

    this->view=view;
    this->PVC=PVC;
    this->PVP=PVP;
    this->online=online;
    QWidget *mask = new QWidget;
    mask->setAutoFillBackground(true);
    mask->setPalette(QPalette(QColor(0, 0, 0, 80)));
    mask->resize(width(),height());
    maskWidget = addWidget(mask);
    maskWidget->setPos(0,0);
    maskWidget->setZValue(1);
    maskWidget->show();

    QPushButton *PVCBtn = new QPushButton("Player VS Computer");
    PVCBtn->setFont(QFont("Segoe Print",18));
    PVCBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                "QPushButton:hover{color:red;}");
    connect(PVCBtn,SIGNAL(clicked()),this,SLOT(enterPVCmode()));
    PVCbtn = addWidget(PVCBtn);
    PVCbtn->setPos(420,200);
    PVCbtn->setZValue(2);
    PVCbtn->show();


    QPushButton *PVPBtn = new QPushButton("Player VS Player");
    PVPBtn->setFont(QFont("Segoe Print",18));
    PVPBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                "QPushButton:hover{color:red;}");
    connect(PVPBtn,SIGNAL(clicked()),this,SLOT(enterPVPmode()));
    PVPbtn = addWidget(PVPBtn);
    PVPbtn->setPos(420,260);
    PVPbtn->setZValue(2);
    PVPbtn->show();


    QPushButton *onlineBtn = new QPushButton("Player VS Player online");
    onlineBtn->setFont(QFont("Segoe Print",18));
    onlineBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                "QPushButton:hover{color:red;}");
    connect(onlineBtn,SIGNAL(clicked()),this,SLOT(showmessage()));
    Onlinebtn = addWidget(onlineBtn);
    Onlinebtn->setPos(420,320);
    Onlinebtn->setZValue(2);
    Onlinebtn->show();

    titleText = new QGraphicsTextItem;
    addItem(titleText);
    titleText->setHtml(tr("<font color=white>Mecha War</font>"));
    titleText->setFont(QFont("Segoe Print", 35));
    titleText->setPos(330,80);
    titleText->setZValue(2);
    titleText->show();

    authorText = new QGraphicsTextItem;
    addItem(authorText);
    authorText->setHtml(tr("<font color=white>Copyright © 2022,Hua kaiwen. All Rights Reserved."));
    authorText->setFont(QFont("Segoe Script"));
    authorText->setPos(240, 450);
    authorText->setZValue(2);
    authorText->show();

}

void gamemenu::getviewptr(QGraphicsView *view)
{
    this->view=view;
}

void gamemenu::getgamemodeptr(QGraphicsScene *PVC, QGraphicsScene *PVP, QGraphicsScene *online)
{
    this->PVC=PVC;
    this->PVP=PVP;
    this->online=online;
}

void gamemenu::enterPVCmode()
{
    view->setScene(PVC);
}

void gamemenu::enterPVPmode()
{
    view->setScene(PVP);
}

void gamemenu::enterOnlinemode()
{
    view->setScene(online);
}

void gamemenu::showmessage()
{
    QString helpText;
    helpText += tr("正在制作中，敬请期待！\n");
    QMessageBox::information(NULL,tr("感谢您的支持！"),helpText);
}
