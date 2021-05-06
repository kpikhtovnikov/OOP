#include "polygon.h"
#include <math.h>

Polygon::Polygon(int quantityOfAngles)
{
    this->quantityOfAngles = quantityOfAngles;
}

void Polygon::draw(QPainter* p, QRect r, QColor c)
{
    qreal cw = 0.5*r.width();
    qreal ch = 0.4*r.height();
    qreal cr = 0.9*(cw>ch?ch:cw);
    qreal a = 2.0*acos(-1.0)/quantityOfAngles;
    QPointF *t = new QPointF[quantityOfAngles];
    for (int i=0; i<quantityOfAngles; i++)
    {
        t[i] = QPointF(cw+cr*sin(i*a),ch-cr*cos(i*a));
    }
    p->setPen(QPen(Qt::black));
    p->setBrush(QBrush(c));
    p->drawPolygon(t,quantityOfAngles);
    QFont font;
    qreal cf = 0.25*cr;
    font.setPointSize(cf);
    font.setBold(true);
    p->setFont(font);
    p->drawText(QRectF(cw-cf,ch-cf,2.0*cf,2.0*cf),
                QString().setNum(quantityOfAngles),
                QTextOption(Qt::AlignCenter));
    delete [] t;
}
