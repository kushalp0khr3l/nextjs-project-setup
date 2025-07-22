#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QObject>
#include <QString>
#include <QList>

class Patient;
class Doctor;
class Appointment;
class MedicalRecord;

class DatabaseManager : public QObject
{
    Q_OBJECT

public:
    static DatabaseManager& instance();
    bool initializeDatabase();
    bool createTables();
    
    // Patient operations
    bool registerPatient(const Patient& patient);
    Patient* authenticatePatient(const QString& email, const QString& password);
    bool updatePatient(const Patient& patient);
    bool deactivatePatient(int patientId);
    
    // Doctor operations
    QList<Doctor> getAllDoctors();
    Doctor getDoctorById(int doctorId);
    
    // Appointment operations
    bool scheduleAppointment(const Appointment& appointment);
    QList<Appointment> getPatientAppointments(int patientId);
    bool updateAppointment(const Appointment& appointment);
    bool cancelAppointment(int appointmentId);
    
    // Medical Record operations
    QList<MedicalRecord> getPatientMedicalRecords(int patientId);
    bool addMedicalRecord(const MedicalRecord& record);
    MedicalRecord getMedicalRecordById(int recordId);
    
private:
    DatabaseManager();
    ~DatabaseManager();
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;
    
    QSqlDatabase m_database;
    bool m_isInitialized;
    
    QString hashPassword(const QString& password);
    bool verifyPassword(const QString& password, const QString& hash);
};

#endif // DATABASEMANAGER_H
