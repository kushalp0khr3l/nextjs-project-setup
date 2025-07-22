#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QDate>

class Patient
{
public:
    Patient();
    Patient(const QString& fullName, const QString& email, const QString& address,
            const QString& gender, const QDate& dateOfBirth, const QString& password);
    
    // Getters
    int getId() const { return m_id; }
    QString getFullName() const { return m_fullName; }
    QString getEmail() const { return m_email; }
    QString getAddress() const { return m_address; }
    QString getGender() const { return m_gender; }
    QDate getDateOfBirth() const { return m_dateOfBirth; }
    QString getPassword() const { return m_password; }
    bool isActive() const { return m_isActive; }
    QDate getRegistrationDate() const { return m_registrationDate; }
    
    // Setters
    void setId(int id) { m_id = id; }
    void setFullName(const QString& fullName) { m_fullName = fullName; }
    void setEmail(const QString& email) { m_email = email; }
    void setAddress(const QString& address) { m_address = address; }
    void setGender(const QString& gender) { m_gender = gender; }
    void setDateOfBirth(const QDate& dateOfBirth) { m_dateOfBirth = dateOfBirth; }
    void setPassword(const QString& password) { m_password = password; }
    void setActive(bool active) { m_isActive = active; }
    void setRegistrationDate(const QDate& date) { m_registrationDate = date; }
    
    // Validation
    bool isValid() const;
    QString getValidationError() const;
    
private:
    int m_id;
    QString m_fullName;
    QString m_email;
    QString m_address;
    QString m_gender;
    QDate m_dateOfBirth;
    QString m_password;
    bool m_isActive;
    QDate m_registrationDate;
};

#endif // PATIENT_H
