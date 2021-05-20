#include "canvas.h"
#include "ui_canvas.h"


TCanvas::TCanvas(StateGraph* p)
{
    g=p;
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
}

TCanvas::~TCanvas()
{
    delete ui;
}

void TCanvas::paint(StateGraph* p)
{
    g=p;
    repaint();
}

void TCanvas::paintEvent (QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QFont font;
    qint16 dest;

    qreal cw = 0.5*rect().width();
    qreal ch = 0.5*rect().height();
    qreal cr = 0.7*(cw>ch?ch:cw);
    qreal cs = 1.5 * cr/g->get_m_lines();
    qreal cf = 0.7 * cs;
    qreal ce = cf*0.3;
    qreal a = 2.0*acos(-1.0)/g->get_m_lines();
    QPointF *t = new QPointF[g->get_m_lines()];

    painter.setPen(QPen(Qt::black));
    font.setPointSize(cf);
    painter.setFont(font);

    for (int i=0; i<g->get_m_lines(); i++)
    {
        t[i] = QPointF(cw+cr*sin(i*a),ch-cr*cos(i*a));
        if (i==g->get_active_node())
        {
            painter.setBrush(QBrush(Qt::green));
        }
        else
        {
            painter.setBrush(QBrush(Qt::white));
        }
        painter.drawEllipse(t[i],cs,cs);
        painter.drawText(t[i].rx()-cs/4-cs*((i+1>9?0.25:0)),t[i].ry()+cs/4,QString().setNum(i+1));
    }

    font.setPointSize(ce);
    painter.setFont(font);

    for (size_t i = 0; i < g->get_m_lines(); i++)
        for (size_t j = 0; j < g->get_m_columns(); j++)
        {
            dest=g->get_matrix()[i][j];
            if (dest!=i)
            {
                QLine tmp(t[i].rx(),t[i].ry(),t[dest].rx(),t[dest].ry());
                double dx=tmp.dx(), dy=tmp.dy(),tmpd,dyp,dxp;
                tmpd=cs/(sqrt(dx*dx+dy*dy));
                dx*=tmpd;
                dy*=tmpd;
                painter.drawLine(t[i]+QPointF(dx,dy),t[dest]-QPointF(dx,dy));

                painter.setPen(QPen(Qt::red));
                painter.drawText(t[i]+QPointF(dx,dy)*0.8+QPointF((-ce/0.7)*(j+1>9?0.5:0.25),ce/2.8),QString().setNum(j+1));
                painter.setPen(QPen(Qt::black));

                QPointF *arrow = new QPointF[3];

                if ((abs(dy)<1)||(abs(dx)<1))
                {
                    dyp=dx;
                    dxp=dy;
                }
                else
                {
                    dyp=dy;
                    dxp=-(dy*dyp)/dx;
                }

                tmpd=cs/(sqrt(dxp*dxp+dyp*dyp));
                dxp*=tmpd;
                dyp*=tmpd;

                arrow[0]=t[dest]-QPointF(dx,dy);
                arrow[1]=t[dest]-QPointF(dx,dy)-0.2*QPointF(dx,dy)+0.1*QPointF(dxp,dyp);
                arrow[2]=t[dest]-QPointF(dx,dy)-0.2*QPointF(dx,dy)-0.1*QPointF(dxp,dyp);

                painter.setBrush(QBrush(Qt::black));

                painter.drawPolygon(arrow,3);

                painter.setBrush(QBrush(Qt::white));

                delete [] arrow;
            }
        }

    delete [] t;
}

void TCanvas::keyPressEvent (QKeyEvent *event)
{
    qint16 tmp;
    switch (event->key())
    {
    case Qt::Key_0:
        tmp=10;
        break;
    case Qt::Key_1:
        tmp=1;
        break;
    case Qt::Key_2:
        tmp=2;
        break;
    case Qt::Key_3:
        tmp=3;
        break;
    case Qt::Key_4:
        tmp=4;
        break;
    case Qt::Key_5:
        tmp=5;
        break;
    case Qt::Key_6:
        tmp=6;
        break;
    case Qt::Key_7:
        tmp=7;
        break;
    case Qt::Key_8:
        tmp=8;
        break;
    case Qt::Key_9:
        tmp=9;
        break;
    default:
        return;
    }
    if (g->emit_event(tmp)==EMIT_SUCCESS)
    {
        repaint();
    }
    return;
}
