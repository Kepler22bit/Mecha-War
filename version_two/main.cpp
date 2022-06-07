#include"pvpmode.h"
#include"pvcmode.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPixmap welcome(":/image/start.png");
    QSplashScreen Wel(welcome);
    Wel.resize(welcome.size());
    Wel.show();
    app.processEvents();
    Sleep(2000);

    pvpmode* pvpwindow=new pvpmode;
    pvcmode* pvcwindow=new pvcmode;
    gamemenu* Gamemenu=new gamemenu;
    QGraphicsView* view=new QGraphicsView;
    Gamemenu->getviewptr(view);
    Gamemenu->getgamemodeptr(pvcwindow,pvpwindow,nullptr);
    pvpwindow->getviewptr(view);
    pvpwindow->getgamemenu(Gamemenu);
    pvcwindow->getviewptr(view);
    pvcwindow->getgamemenu(Gamemenu);
    Wel.finish(view);
    view->setWindowTitle(QObject::tr("MECHA WAR"));
    view->setScene(Gamemenu);

    view->setBackgroundBrush(QBrush(QPixmap(":/image/background.png")));
    view->show();

    return app.exec();
}
