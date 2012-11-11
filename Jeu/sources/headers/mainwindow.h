#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QtUiTools/QtUiTools>
namespace Ui {
class QWhereIsTheKeysWindows;
}

class QWhereIsTheKeysWindows : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QWhereIsTheKeysWindows(QWidget *parent = 0);
    ~QWhereIsTheKeysWindows();
    
private:
    Ui::QWhereIsTheKeysWindows *ui;
};

#endif // MAINWINDOW_H
