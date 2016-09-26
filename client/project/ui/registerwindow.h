#ifndef RegisterWindow_H
#define RegisterWindow_H

#include <QMainWindow>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = 0);
    ~RegisterWindow();

    void OnRegisterSucc();
    void OnHasAccount();

private slots:
    void on_login_btn_clicked();

    void on_return_login_clicked();

private:
    Ui::RegisterWindow *ui;
};

#endif // RegisterWindow_H
