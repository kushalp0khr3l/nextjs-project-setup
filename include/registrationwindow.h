#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QMessageBox>

class RegistrationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr);

signals:
    void registrationSuccessful();
    void switchToLogin();

private slots:
    void onRegisterClicked();
    void onLoginLinkClicked();
    void validateForm();

private:
    void setupUI();
    void setupConnections();
    void clearForm();
    bool validateInput();
    void showError(const QString& message);
    void showSuccess(const QString& message);
    
    // UI Components
    QVBoxLayout *m_mainLayout;
    QGroupBox *m_registrationGroup;
    QFormLayout *m_formLayout;
    
    QLineEdit *m_fullNameEdit;
    QLineEdit *m_emailEdit;
    QLineEdit *m_addressEdit;
    QComboBox *m_genderCombo;
    QDateEdit *m_dobEdit;
    QLineEdit *m_passwordEdit;
    QLineEdit *m_confirmPasswordEdit;
    
    QPushButton *m_registerButton;
    QPushButton *m_loginLinkButton;
    
    QLabel *m_titleLabel;
    QLabel *m_errorLabel;
};

#endif // REGISTRATIONWINDOW_H
