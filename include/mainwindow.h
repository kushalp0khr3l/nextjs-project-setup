#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
class QVBoxLayout;
class QHBoxLayout;
QT_END_NAMESPACE

class RegistrationWindow;
class LoginWindow;
class PatientDashboard;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showRegistrationWindow();
    void showLoginWindow();
    void showPatientDashboard(int patientId);
    void logout();

private:
    void setupUI();
    void setupConnections();
    
    QStackedWidget *m_stackedWidget;
    RegistrationWindow *m_registrationWindow;
    LoginWindow *m_loginWindow;
    PatientDashboard *m_patientDashboard;
    
    int m_currentPatientId;
};

#endif // MAINWINDOW_H
