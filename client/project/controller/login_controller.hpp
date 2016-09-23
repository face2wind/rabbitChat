#ifndef LOGIN_CONTROLLER_HPP
#define LOGIN_CONTROLLER_HPP

#include <QString>

class LoginController
{
public:
    ~LoginController();

    static LoginController & GetInstance();

    void LoginRequest(const QString &name, const QString &passwd);

protected:
    LoginController();

private:
    bool has_login_;
};

#endif // LOGIN_CONTROLLER_HPP
