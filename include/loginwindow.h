#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QCheckBox>

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);

signals:
    void loginSuccessful(int patientId);
    void switchToRegistration();

private slots:
    void onLoginClicked();
    void onRegisterLinkClicked();
    void onForgotPasswordClicked();

private:
    void setupUI();
    void setupConnections();
    void clearForm();
    bool validateInput();
    void showError(const QString& message);
    
    // UI Components
    QVBoxLayout *m_mainLayout;
    QGroupBox *m_loginGroup;
    QFormLayout *m_formLayout;
    
    QLineEdit *m_emailEdit;
    QLineEdit *m_passwordEdit;
    QCheckBox *m_rememberMeCheck;
    
    QPushButton *m_loginButton;
    QPushButton *m_registerLinkButton;
    QPushButton *m_forgotPasswordButton;
    
    QLabel *m_titleLabel;
    QLabel *m_errorLabel;
};

#endif // LOGINWINDOW_H
