#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = 0);
    ~ChatWindow();

    void SetUserID(unsigned int user_id);

protected:
    bool eventFilter(QObject *obj, QEvent *e);

private:
    void DoSendText();

private slots:
    void on_send_btn_clicked();

private:
    Ui::ChatWindow *ui;
    unsigned int target_user_id_;
};

#endif // CHATWINDOW_H
