#ifndef QWITK_H
#define QWITK_H

#include <QMainWindow>

namespace Ui {
class QWITK;
}

class QWITK : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QWITK(QWidget *parent = 0);
    ~QWITK();
    
private:
    Ui::QWITK *ui;
};

#endif // QWITK_H
