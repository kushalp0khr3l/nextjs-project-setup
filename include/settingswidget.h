#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QMessageBox>
#include <QProgressBar>

class Patient;

class SettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWidget(QWidget *parent = nullptr);
    void setPatientId(int patientId);
    void loadPatientData();

signals:
    void accountDeactivated();
    void profileUpdated();

private slots:
    void onUpdateProfileClicked();
    void onChangePasswordClicked();
    void onDeactivateAccountClicked();
    void onCancelChangesClicked();
    void onFormDataChanged();

private:
    void setupUI();
    void setupProfileSection();
    void setupSecuritySection();
    void setupAccountSection();
    void setupConnections();
    void populateForm();
    void clearForm();
    bool validateProfileData();
    bool validatePasswordData();
    void showSuccess(const QString& message);
    void showError(const QString& message);
    void enableSaveButton(bool enabled);
    
    // UI Components
    QVBoxLayout *m_mainLayout;
    
    // Header
    QLabel *m_titleLabel;
    
    // Profile Information Section
    QGroupBox *m_profileGroup;
    QFormLayout *m_profileLayout;
    QLineEdit *m_fullNameEdit;
    QLineEdit *m_emailEdit;
    QLineEdit *m_addressEdit;
    QComboBox *m_genderCombo;
    QDateEdit *m_dobEdit;
    QPushButton *m_updateProfileButton;
    QPushButton *m_cancelProfileButton;
    
    // Security Section
    QGroupBox *m_securityGroup;
    QVBoxLayout *m_securityLayout;
    QLineEdit *m_currentPasswordEdit;
    QLineEdit *m_newPasswordEdit;
    QLineEdit *m_confirmPasswordEdit;
    QPushButton *m_changePasswordButton;
    QPushButton *m_cancelPasswordButton;
    
    // Account Management Section
    QGroupBox *m_accountGroup;
    QVBoxLayout *m_accountLayout;
    QLabel *m_accountStatusLabel;
    QLabel *m_registrationDateLabel;
    QLabel *m_lastLoginLabel;
    QCheckBox *m_confirmDeactivationCheck;
    QPushButton *m_deactivateButton;
    
    // Status and Progress
    QLabel *m_statusLabel;
    QProgressBar *m_progressBar;
    
    // Data
    int m_patientId;
    Patient *m_currentPatient;
    bool m_hasUnsavedChanges;
    
    // Helper methods
    void resetPasswordFields();
    void updateAccountInfo();
    bool confirmDeactivation();
};

#endif // SETTINGSWIDGET_H
