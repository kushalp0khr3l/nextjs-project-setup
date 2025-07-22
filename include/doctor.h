#ifndef DOCTOR_H
#define DOCTOR_H

#include <QString>
#include <QStringList>

class Doctor
{
public:
    Doctor();
    Doctor(const QString& name, const QString& speciality, const QString& hospital,
           const QString& email, const QString& phone);
    
    // Getters
    int getId() const { return m_id; }
    QString getName() const { return m_name; }
    QString getSpeciality() const { return m_speciality; }
    QString getHospital() const { return m_hospital; }
    QString getEmail() const { return m_email; }
    QString getPhone() const { return m_phone; }
    QStringList getAvailableDays() const { return m_availableDays; }
    QString getAvailableTime() const { return m_availableTime; }
    bool isActive() const { return m_isActive; }
    
    // Setters
    void setId(int id) { m_id = id; }
    void setName(const QString& name) { m_name = name; }
    void setSpeciality(const QString& speciality) { m_speciality = speciality; }
    void setHospital(const QString& hospital) { m_hospital = hospital; }
    void setEmail(const QString& email) { m_email = email; }
    void setPhone(const QString& phone) { m_phone = phone; }
    void setAvailableDays(const QStringList& days) { m_availableDays = days; }
    void setAvailableTime(const QString& time) { m_availableTime = time; }
    void setActive(bool active) { m_isActive = active; }
    
private:
    int m_id;
    QString m_name;
    QString m_speciality;
    QString m_hospital;
    QString m_email;
    QString m_phone;
    QStringList m_availableDays;
    QString m_availableTime;
    bool m_isActive;
};

#endif // DOCTOR_H
