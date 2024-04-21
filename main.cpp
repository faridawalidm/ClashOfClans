#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QPixmap> // Include QPixmap for loading images
#include <canon.h>
#include <bullet.h>
#include <enemy.h>
#include <wall.h>
#include <base.h> // Assuming base is your class for the base item

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QGraphicsView *view = new QGraphicsView();
    view->setFixedSize(800, 600);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    // Load background image
    QPixmap backgroundImage("/Users/mohamedgazar/Downloads/10440718-seamless-grass-texture-for-3d-or-2d-texturing.jpg"); // Replace ":/images/background.jpg" with your image file path
    scene->setBackgroundBrush(backgroundImage.scaled(800, 600)); // Scale image to scene size

    Canon *p1 = new Canon();
    p1->setPos(view->width()/1.5, view->height()/1.5 - p1->pixmap().height());
    p1->setFlag(QGraphicsItem::ItemIsFocusable);
    p1->setFocus();
    scene->addItem(p1);

    view->setScene(scene);
    view->show();

    // Placeholder variables
    QGraphicsTextItem *score = new QGraphicsTextItem();
    int scoreValue = 0;
    QGraphicsTextItem *health = new QGraphicsTextItem();
    int healthValue = 100;
    Base *BaseItem = new Base(); // Assuming base is your base item class
    Wall *WallItem = new Wall();

    // Set up score text item
    score->setFont(QFont("times", 16));
    score->setDefaultTextColor(Qt::blue);
    score->setPlainText("Score: " + QString::number(scoreValue));
    score->setPos(700, 10);
    scene->addItem(score);

    // Set up health text item
    health->setFont(QFont("times", 16));
    health->setDefaultTextColor(Qt::red);
    health->setPlainText("Health: " + QString::number(healthValue));
    health->setPos(600, 10);
    scene->addItem(health);


    // Add base item to the scene
    scene->addItem(BaseItem);
    scene->addItem(WallItem);

    QTimer *time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()), p1, SLOT(createEnemy()));
    time->start(2000);

    return a.exec();
}
