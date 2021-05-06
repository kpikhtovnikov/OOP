#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include<QPushButton>
#include<QFileDialog>
#include<QFile>
#include<QSpinBox>
#include<QLabel>
#include<QMessageBox>
#include<QTextStream>
#include "canvas.h"

class TInterface: public QWidget
{
    Q_OBJECT
    TCanvas * canvas;
    TGraph * g;
    QLabel * lb_size;
    QSpinBox * size_;
    QLabel * lb_matrix;
    QPushButton * btn_matrix;
    QPushButton * btn_show;

public:
    TInterface(QWidget * parent = nullptr);
    ~TInterface();
protected:
    void closeEvent(QCloseEvent *);
private slots:
    void OpenCanvas();
    void OpenFile();
public slots:
    void CloseCanvas();
signals:
    void ChangeGraph(TGraph *);
};

#endif // TINTERFACE_H
