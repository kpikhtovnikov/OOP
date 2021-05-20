#ifndef CANVAS_H
#define CANVAS_H

#include <stategraph.h>

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>


namespace Ui {
class TCanvas;
}

class TCanvas : public QWidget
{
    Q_OBJECT

public:
    TCanvas(StateGraph*);
    ~TCanvas();
    void paint(StateGraph*);

protected:
    void paintEvent (QPaintEvent *event);
    void keyPressEvent (QKeyEvent *event);

private:
    Ui::TCanvas *ui;
    StateGraph *g;
};

#endif // CANVAS_H
