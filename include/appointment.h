#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <QString>
#include <QDateTime>

class Appointment
{
public:
    enum Status {
        Scheduled,
        Confirmed,
        InProgress,
        Completed,
        Cancelled,
        NoShow
    };
    
    Appointment();
    Appointment(int patientId, int doctorId, const QDateTime& appointmentDateTime,
                const QString& reason, Status status = Scheduled);
    
    // Getters
    int getId() const { return m_id; }
    int getPatientId() const { return m_patientId; }
    int getDoctorId() const { return m_doctorId; }
    QDateTime getAppointmentDateTime() const { return m_appointmentDateTime; }
    QString getReason() const { return m_reason; }
    Status getStatus() const { return m_status; }
    QString getNotes() const { return m_notes; }
    QDateTime getCreatedAt() const { return m_createdAt; }
    QDateTime getUpdatedAt() const { return m_updatedAt; }
    
    // Setters
    void setId(int id) { m_id = id; }
    void setPatientId(int patientId) { m_patientId = patientId; }
    void setDoctorId(int doctorId) { m_doctorId = doctorId; }
    void setAppointmentDateTime(const QDateTime& dateTime) { m_appointmentDateTime = dateTime; }
    void setReason(const QString& reason) { m_reason = reason; }
    void setStatus(Status status) { m_status = status; }
    void setNotes(const QString& notes) { m_notes = notes; }
    void setCreatedAt(const QDateTime& dateTime) { m_createdAt = dateTime; }
    void setUpdatedAt(const QDateTime& dateTime) { m_updatedAt = dateTime; }
    
    // Utility methods
    QString getStatusString() const;
    static Status stringToStatus(const QString& statusStr);
    bool isValid() const;
    
private:
    int m_id;
    int m_patientId;
    int m_doctorId;
    QDateTime m_appointmentDateTime;
    QString m_reason;
    Status m_status;
    QString m_notes;
    QDateTime m_createdAt;
    QDateTime m_updatedAt;
};

#endif // APPOINTMENT_H
