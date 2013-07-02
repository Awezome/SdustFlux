#ifndef ABOUTFLUX_H
#define ABOUTFLUX_H

#include <QDialog>

namespace Ui {
class AboutFlux;
}

class AboutFlux : public QDialog
{
    Q_OBJECT
    
public:
    explicit AboutFlux(QWidget *parent = 0);
    ~AboutFlux();
    
private:
    Ui::AboutFlux *ui;
};

#endif // ABOUTFLUX_H
