#ifndef ABOUTPASS_H
#define ABOUTPASS_H

#include <QDialog>

namespace Ui {
class AboutPass;
}

class AboutPass : public QDialog
{
    Q_OBJECT
    
public:
    explicit AboutPass(QWidget *parent = 0);
    ~AboutPass();
    
private:
    Ui::AboutPass *ui;
};

#endif // ABOUTPASS_H
