// enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPointF>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem *parent = nullptr); // Modify the constructor
    void move();
    Enemy();

public:
    qreal speed = 5; // Adjust speed as needed
};

#endif // ENEMY_H
