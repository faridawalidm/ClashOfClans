
#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>

// Forward declarations to avoid circular dependencies
class QGraphicsTextItem;

// Declare score and health variables
extern QGraphicsTextItem *score;
extern int scoreValue;
extern QGraphicsTextItem *health;
extern int healthValue;

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET_H
