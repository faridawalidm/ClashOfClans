#include "wall.h"

Wall::Wall() {
    QPixmap basePixmap("/Users/mohamedgazar/Desktop/Screenshot 2024-04-21 at 2.15.48 PM.png");
    setPixmap(basePixmap.scaled(20, 200));

    // Set position of the base item
    qreal x = (800 - pixmap().width()) / 2.0; // Assuming scene width is 800
    qreal y = (600 - pixmap().height()) / 2.0; // Assuming scene height is 600
    setPos(x-100, y);



}
