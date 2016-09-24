#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_lsign_txt_linkActivated(const QString &link);

    void on_register_btn_clicked();

    void on_login_btn_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
