#ifndef TCANVAS_H
#define TCANVAS_H

#include <QWidget>
#include <QCloseEvent>
#include "graph.h"

class TCanvas : public QWidget
{
    Q_OBJECT

    TGraph *g;
public:
    TCanvas(TGraph *, QWidget *parent = 0);
    ~TCanvas();
public slots:
    void ChangeGraph(TGraph *);
protected:
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent*);
signals:
    void closing();
};

#endif // TCANVAS_H
