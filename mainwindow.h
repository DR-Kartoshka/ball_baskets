#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "basket.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void setValuesWindow();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void updateLabel(int actionCode);
private:
    Ui::MainWindow *ui;
    Basket basket1;
    Basket basket2;
};
#endif // MAINWINDOW_H
