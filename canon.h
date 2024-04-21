// player.h
#ifndef CANON_H
#define CANON_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Canon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Canon();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

public slots:
    void createEnemy();
};

#endif // CANON_H
