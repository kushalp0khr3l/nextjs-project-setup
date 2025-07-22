#ifndef APPOINTMENTSWIDGET_H
#define APPOINTMENTSWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include <QLineEdit>
#include <QGroupBox>
#include <QHeaderView>
#include <QMessageBox>

class Appointment;
class Doctor;

class AppointmentsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AppointmentsWidget(QWidget *parent = nullptr);
    void setPatientId(int patientId);
    void refreshAppointments();

private slots:
    void onFilterChanged();
    void onViewDetailsClicked();
    void onCancelAppointmentClicked();
    void onRescheduleClicked();
    void onAppointmentSelectionChanged();

private:
    void setupUI();
    void setupTable();
    void setupFilters();
    void setupConnections();
    void loadAppointments();
    void populateTable();
    void applyFilters();
    void showAppointmentDetails(const Appointment& appointment);
    
    // UI Components
    QVBoxLayout *m_mainLayout;
    
    // Header
    QLabel *m_titleLabel;
    
    // Filters
    QGroupBox *m_filtersGroup;
    QHBoxLayout *m_filtersLayout;
    QComboBox *m_statusFilter;
    QComboBox *m_doctorFilter;
    QDateEdit *m_fromDateFilter;
    QDateEdit *m_toDateFilter;
    QPushButton *m_clearFiltersButton;
    
    // Table
    QTableWidget *m_appointmentsTable;
    
    // Action buttons
    QHBoxLayout *m_buttonsLayout;
    QPushButton *m_viewDetailsButton;
    QPushButton *m_rescheduleButton;
    QPushButton *m_cancelButton;
    QPushButton *m_refreshButton;
    
    // Data
    int m_patientId;
    QList<Appointment> m_appointments;
    QList<Doctor> m_doctors;
    
    // Table columns
    enum TableColumns {
        COL_DATE = 0,
        COL_TIME,
        COL_DOCTOR,
        COL_SPECIALITY,
        COL_REASON,
        COL_STATUS,
        COL_HOSPITAL
    };
};

#endif // APPOINTMENTSWIDGET_H
