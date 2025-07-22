#ifndef PATIENTDASHBOARD_H
#define PATIENTDASHBOARD_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QFrame>
#include <QScrollArea>

class AppointmentsWidget;
class ScheduleWidget;
class MedicalRecordsWidget;
class SettingsWidget;
class Patient;

class PatientDashboard : public QWidget
{
    Q_OBJECT

public:
    explicit PatientDashboard(QWidget *parent = nullptr);
    void setPatient(const Patient& patient);
    void refreshData();

signals:
    void logoutRequested();

private slots:
    void onNavigationItemClicked(int index);
    void onLogoutClicked();

private:
    void setupUI();
    void setupSidebar();
    void setupMainContent();
    void setupConnections();
    void updatePatientInfo();
    
    // UI Components
    QHBoxLayout *m_mainLayout;
    
    // Sidebar
    QFrame *m_sidebar;
    QVBoxLayout *m_sidebarLayout;
    QLabel *m_patientAvatar;
    QLabel *m_patientNameLabel;
    QLabel *m_patientIdLabel;
    QListWidget *m_navigationList;
    QPushButton *m_logoutButton;
    
    // Main content area
    QFrame *m_contentArea;
    QVBoxLayout *m_contentLayout;
    QStackedWidget *m_stackedWidget;
    
    // Content widgets
    QWidget *m_dashboardWidget;
    AppointmentsWidget *m_appointmentsWidget;
    ScheduleWidget *m_scheduleWidget;
    MedicalRecordsWidget *m_medicalRecordsWidget;
    SettingsWidget *m_settingsWidget;
    
    // Data
    Patient *m_currentPatient;
    int m_currentPatientId;
    
    // Methods
    void createDashboardWidget();
    void setupNavigationItems();
};

#endif // PATIENTDASHBOARD_H
