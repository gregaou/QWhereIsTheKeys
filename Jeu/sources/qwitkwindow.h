#ifndef QWITKWINDOW_H
#define QWITKWINDOW_H

#include <QMainWindow>

namespace Ui {
class QWITKWindow;
}

class QWITKWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QWITKWindow(QWidget *parent = 0);
    ~QWITKWindow();
    
private:
    Ui::QWITKWindow *ui;
};

#endif // QWITKWINDOW_H
