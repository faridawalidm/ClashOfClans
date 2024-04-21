#include "canon.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include "base.h"
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <cmath>

const qreal Pi = 3.141592653589793238462643383279502884; // Define Pi
const qreal TwoPi = 2 * Pi; // Define TwoPi

Canon::Canon()
{
    setPixmap(QPixmap("/Users/mohamedgazar/Downloads/image-removebg-preview-56.png").scaled(100,100));

    // Set the position of the cannon at the top of the screen

    // Set the transformation origin to the bottom center of the pixmap
    setTransformOriginPoint(50, 50); // Assuming the pixmap is 100x100
    setPos(100, 200);
}

void Canon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // Get the position of the mouse click
    QPointF mousePos = event->pos();

    // Calculate the angle between the cannon and the mouse position
    QLineF lineToMouse(QPointF(0, 0), mapFromScene(mousePos));
    qreal angleToMouse = ::acos(lineToMouse.dx() / lineToMouse.length());

    // Adjust the angle based on the relative position of the mouse
    if (lineToMouse.dy() < 0)
        angleToMouse = TwoPi - angleToMouse;

    // Convert the angle to degrees and rotate the cannon
    setRotation(-angleToMouse * 180 / Pi);

    // Create a bullet and add it to the scene
    Bullet *bullet = new Bullet();

    // Set initial velocity components based on cannon angle
    qreal bulletSpeed = 10.0; // Adjust speed as needed
    qreal bulletAngle = -angleToMouse; // In radians

    // Calculate velocity components
    qreal vx = bulletSpeed * qCos(bulletAngle);
    qreal vy = bulletSpeed * qSin(bulletAngle);


    bullet->setPos(x() + 30, y()); // Adjust position as needed
    scene()->addItem(bullet);
}

// CreateEnemy function used to create the enemies
void Canon::createEnemy()
{
    // Create an Enemy object and pass the Base pointer to its constructor
    Enemy* enemy = new Enemy(); // Assuming 'base' is a valid pointer
    scene()->addItem(enemy);
}

