#ifndef SCHEDULEWIDGET_H
#define SCHEDULEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QDateEdit>
#include <QTimeEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QListWidget>
#include <QCalendarWidget>
#include <QMessageBox>

class Doctor;

class ScheduleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScheduleWidget(QWidget *parent = nullptr);
    void setPatientId(int patientId);

private slots:
    void onSpecialityChanged();
    void onDoctorChanged();
    void onDateChanged();
    void onTimeSlotSelected();
    void onScheduleClicked();
    void onClearFormClicked();
    void onCalendarDateChanged(const QDate& date);

private:
    void setupUI();
    void setupForm();
    void setupCalendar();
    void setupConnections();
    void loadSpecialities();
    void loadDoctorsBySpeciality(const QString& speciality);
    void loadAvailableTimeSlots();
    void clearForm();
    bool validateForm();
    void showSuccess(const QString& message);
    void showError(const QString& message);
    
    // UI Components
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_contentLayout;
    
    // Left side - Form
    QGroupBox *m_formGroup;
    QFormLayout *m_formLayout;
    QComboBox *m_specialityCombo;
    QComboBox *m_doctorCombo;
    QLabel *m_doctorInfoLabel;
    QDateEdit *m_dateEdit;
    QListWidget *m_timeSlotsWidget;
    QTextEdit *m_reasonEdit;
    QPushButton *m_scheduleButton;
    QPushButton *m_clearButton;
    
    // Right side - Calendar
    QGroupBox *m_calendarGroup;
    QVBoxLayout *m_calendarLayout;
    QCalendarWidget *m_calendar;
    QLabel *m_selectedDateLabel;
    
    // Status and info
    QLabel *m_statusLabel;
    QLabel *m_errorLabel;
    
    // Data
    int m_patientId;
    QList<Doctor> m_doctors;
    QStringList m_specialities;
    Doctor m_selectedDoctor;
    QDate m_selectedDate;
    QString m_selectedTime;
};

#endif // SCHEDULEWIDGET_H
