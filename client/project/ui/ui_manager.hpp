#ifndef UI_MANAGER_HPP
#define UI_MANAGER_HPP

class QMainWindow;
class LoginWindow;
class RegisterWindow;
class MainWindow;

class UIManager
{
public:
    ~UIManager();
    static UIManager & GetInstance();

    void ShowLogin();
    void ShowRegister();
    void ShowMainView();
    void OnLoginResult(int result);

protected:
    void MoveCenter(QMainWindow *window);
    void MoveLeft(QMainWindow *window);

protected:
    UIManager();

    LoginWindow *login_win_;
    RegisterWindow *register_win_;
    MainWindow *main_win_;

    int desktop_width_;
    int desktop_height_;
};

#endif // UI_MANAGER_HPP
