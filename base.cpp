#include "base.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QRectF>
#include <QGraphicsScene>

Base::Base() : QGraphicsPixmapItem() {
    // Initialize base class constructor
    QPixmap basePixmap("/Users/mohamedgazar/Downloads/image-removebg-preview-55.png");
    setPixmap(basePixmap.scaled(150, 150));

    // Set position of the base item
    qreal x = (800 - pixmap().width()) / 2.0; // Assuming scene width is 800
    qreal y = (600 - pixmap().height()) / 2.0; // Assuming scene height is 600
    setPos(x, y);

    // Set flag to enable item's advance method
    setFlag(QGraphicsItem::ItemIsMovable);
}
