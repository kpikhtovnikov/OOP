#include "canvas.h"
#include <QPainter>
#include <math.h>
#include <QDebug>
#include <QVector>

TCanvas::TCanvas(TGraph *f, QWidget *parent) : QWidget(parent)
{
    g = f;
    setFixedSize(400,400);
}

TCanvas::~TCanvas()
{

}

void TCanvas::paintEvent(QPaintEvent*)
{
    QPainter p;
    p.begin(this);

    int count = g->getCount();

    qreal cw = 0.5*rect().width();
    qreal ch = 0.5*rect().height();
    qreal cr = 0.9*(cw>ch?ch:cw);
    qreal a = 2.0*acos(-1.0)/count;

    qreal rad = 0.05*(cw>ch?ch:cw);
    qreal arrowSize = 10;

    QRectF *t = new QRectF[count];
    for (int i=0; i<count; i++)
    {
        t[i] = QRectF(cw+cr*sin(i*a)-rad, ch-cr*cos(i*a)-rad, 2*rad, 2*rad);
    }

    QPen pen = QPen(Qt::black);
    pen.setStyle(Qt::SolidLine);
    p.setPen(pen);

    p.setBrush(QBrush(Qt::blue));

    QFont font;
    qreal cf = 0.5*rad;
    font.setPointSize(cf);
    font.setBold(true);
    p.setFont(font);

    for (int i=0; i<count; i++)
    {
        p.drawEllipse(t[i]);
        p.drawText(t[i], QString().setNum(i+1), QTextOption(Qt::AlignCenter));
    }

    for (int i=0; i<count; i++)
    {
        for (int j=0; j<count; j++)
        {
            if (i != j && g->getMatrix().Get()[i][j] == 1)
            {
                QLineF line(t[i].center(), t[j].center());
                double angle = atan2(-line.dy(), line.dx());

                line.setP1(line.p1() + QPoint(+rad*cos(angle), -rad*sin(angle)));
                line.setP2(line.p2() - QPoint(+rad*cos(angle), -rad*sin(angle)));

                QPointF arrowP1 = line.p1() + QPointF(sin(angle + M_PI / 3) * arrowSize,
                                                    cos(angle + M_PI / 3) * arrowSize);
                QPointF arrowP2 = line.p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
                                                cos(angle + M_PI - M_PI / 3) * arrowSize);
                QPolygonF arrowHead;
                arrowHead << line.p1() << arrowP1 << arrowP2;

                p.drawLine(line);
                p.drawPolygon(arrowHead);
            }
        }
    }


    delete [] t;

    p.end();
}

void TCanvas::closeEvent(QCloseEvent* event)
{
    emit closing();
    event->accept();
}

void TCanvas::ChangeGraph(TGraph * t)
{
    g = t;
    this->repaint();
}
