#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QFont>
#include <QGraphicsTextItem>

#include "enemy.h"

// Define score variable
QGraphicsTextItem *score = new QGraphicsTextItem();
int scoreValue = 0;

Bullet::Bullet(): QObject(), QGraphicsPixmapItem() {
    // Setting the bullets' size
    setPixmap(QPixmap("/Users/mohamedgazar/Downloads/GameAssignmentqt 3/laserpng.png").scaled(50, 50));

    // Generating the Bullets automatically
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move() {
    // Getting the colliding items with the Bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0; i < colliding_items.size(); i++) {
        if(typeid(*(colliding_items[i])) == typeid(Enemy)) {
            scene()->removeItem(colliding_items[i]);
            scoreValue++;
            score->setPlainText("Score: " + QString::number(scoreValue)); // Update score displayed on screen

            // Play bullet sound


            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // Move the bullets upward
    setPos(x(), y() - 10);

    // Check if bullet is out of the scene
    if (pos().y() + 100 < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
