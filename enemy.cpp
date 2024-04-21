#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QGraphicsView>
#include <cmath> // for mathematical functions like sqrt, atan2

QGraphicsTextItem *health = new QGraphicsTextItem();
int healthValue = 3;

Enemy::Enemy() {
    setPixmap(QPixmap("/Users/mohamedgazar/Downloads/image-removebg-preview-57.png").scaled(100, 100));

    // Setting the position of the enemy within the view dimensions
    int random_number = rand() % 700;
    setPos(random_number, 0);

    // Calculate direction towards the base
    QPointF basePos(scene()->width() / 2, scene()->height());
    QPointF direction = basePos - pos();
    direction /= sqrt(direction.x() * direction.x() + direction.y() * direction.y()); // Normalize the direction vector

    // Moving the enemies towards the base
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move() {
    // Calculate direction towards the base
    QPointF basePos(scene()->width() / 2, scene()->height());
    QPointF direction = basePos - pos();
    direction /= sqrt(direction.x() * direction.x() + direction.y() * direction.y()); // Normalize the direction vector

    // Move the enemy towards the base
    setPos(x() + direction.x() * speed, y() + direction.y() * speed);

}
