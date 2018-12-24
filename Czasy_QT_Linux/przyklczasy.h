#ifndef PRZYKLCZASY_H
#define PRZYKLCZASY_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class PrzyklczasyClass;
}

class Przyklczasy : public QMainWindow
{
    Q_OBJECT

public:
    Przyklczasy(QWidget *parent = 0);
    ~Przyklczasy();

private:
    Ui::PrzyklczasyClass *ui;

private slots:
    void on_pOK_clicked();
    void on_rPerfectP_clicked();
    void on_rPerfectC_clicked();
    void on_rPerfect_clicked();
    void on_rContinuous_clicked();
    void on_rSimple_clicked();
    void on_rFuture_clicked();
    void on_rPresent_clicked();
    void on_rPast_clicked();
};

#endif // PRZYKLCZASY_H
