#ifndef MEDICALRECORDSWIDGET_H
#define MEDICALRECORDSWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include <QLineEdit>
#include <QGroupBox>
#include <QMessageBox>
#include <QFileDialog>
#include <QProgressBar>

class MedicalRecord;
class Doctor;

class MedicalRecordCard : public QFrame
{
    Q_OBJECT

public:
    explicit MedicalRecordCard(const MedicalRecord& record, QWidget *parent = nullptr);
    const MedicalRecord& getRecord() const { return m_record; }

signals:
    void viewDetailsRequested(int recordId);
    void downloadRequested(int recordId);

private slots:
    void onViewDetailsClicked();
    void onDownloadClicked();

private:
    void setupUI();
    QString getRecordTypeColor() const;
    QString formatDate(const QDateTime& dateTime) const;
    
    MedicalRecord m_record;
    QVBoxLayout *m_layout;
    QLabel *m_dateLabel;
    QLabel *m_typeLabel;
    QLabel *m_titleLabel;
    QLabel *m_doctorLabel;
    QHBoxLayout *m_buttonsLayout;
    QPushButton *m_viewButton;
    QPushButton *m_downloadButton;
};

class MedicalRecordsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MedicalRecordsWidget(QWidget *parent = nullptr);
    void setPatientId(int patientId);
    void refreshRecords();

private slots:
    void onSearchTextChanged();
    void onRecordTypeFilterChanged();
    void onDateFilterChanged();
    void onApplyFiltersClicked();
    void onClearFiltersClicked();
    void onViewRecordDetails(int recordId);
    void onDownloadRecord(int recordId);
    void onRefreshClicked();

private:
    void setupUI();
    void setupFilters();
    void setupRecordsArea();
    void setupConnections();
    void loadRecords();
    void populateRecords();
    void applyFilters();
    void showRecordDetails(const MedicalRecord& record);
    void downloadRecord(const MedicalRecord& record);
    void clearRecordsArea();
    
    // UI Components
    QVBoxLayout *m_mainLayout;
    
    // Header
    QHBoxLayout *m_headerLayout;
    QLabel *m_titleLabel;
    QLineEdit *m_searchEdit;
    
    // Filters
    QGroupBox *m_filtersGroup;
    QHBoxLayout *m_filtersLayout;
    QComboBox *m_recordTypeFilter;
    QDateEdit *m_fromDateFilter;
    QDateEdit *m_toDateFilter;
    QPushButton *m_applyFiltersButton;
    QPushButton *m_clearFiltersButton;
    
    // Active filters display
    QHBoxLayout *m_activeFiltersLayout;
    QLabel *m_activeFiltersLabel;
    
    // Records area
    QScrollArea *m_scrollArea;
    QWidget *m_recordsContainer;
    QGridLayout *m_recordsLayout;
    
    // Action buttons
    QHBoxLayout *m_buttonsLayout;
    QPushButton *m_refreshButton;
    QLabel *m_recordCountLabel;
    
    // Pagination
    QHBoxLayout *m_paginationLayout;
    QPushButton *m_prevPageButton;
    QLabel *m_pageLabel;
    QPushButton *m_nextPageButton;
    
    // Data
    int m_patientId;
    QList<MedicalRecord> m_allRecords;
    QList<MedicalRecord> m_filteredRecords;
    QList<Doctor> m_doctors;
    
    // Pagination
    int m_currentPage;
    int m_recordsPerPage;
    int m_totalPages;
    
    // Helper methods
    void updatePagination();
    void showPage(int page);
    Doctor getDoctorById(int doctorId) const;
};

#endif // MEDICALRECORDSWIDGET_H
