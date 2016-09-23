#ifndef UI_MANAGER_HPP
#define UI_MANAGER_HPP

class LoginWindow;

class UIManager
{
public:
    ~UIManager();
    static UIManager & GetInstance();

    void ShowLogin();
    void ShowRegister();
    void ShowMainView();

protected:
    UIManager();

    LoginWindow *login_win_;
};

#endif // UI_MANAGER_HPP
