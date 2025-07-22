#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H

#include <QString>
#include <QDateTime>
#include <QByteArray>

class MedicalRecord
{
public:
    enum RecordType {
        LabResults,
        Prescription,
        Image,
        VisitNotes,
        Diagnosis,
        Treatment,
        Other
    };
    
    MedicalRecord();
    MedicalRecord(int patientId, int doctorId, const QString& title, 
                  RecordType type, const QString& description);
    
    // Getters
    int getId() const { return m_id; }
    int getPatientId() const { return m_patientId; }
    int getDoctorId() const { return m_doctorId; }
    QString getTitle() const { return m_title; }
    RecordType getType() const { return m_type; }
    QString getDescription() const { return m_description; }
    QDateTime getRecordDate() const { return m_recordDate; }
    QString getFilePath() const { return m_filePath; }
    QByteArray getFileData() const { return m_fileData; }
    QString getFileName() const { return m_fileName; }
    QString getMimeType() const { return m_mimeType; }
    QDateTime getCreatedAt() const { return m_createdAt; }
    
    // Setters
    void setId(int id) { m_id = id; }
    void setPatientId(int patientId) { m_patientId = patientId; }
    void setDoctorId(int doctorId) { m_doctorId = doctorId; }
    void setTitle(const QString& title) { m_title = title; }
    void setType(RecordType type) { m_type = type; }
    void setDescription(const QString& description) { m_description = description; }
    void setRecordDate(const QDateTime& date) { m_recordDate = date; }
    void setFilePath(const QString& filePath) { m_filePath = filePath; }
    void setFileData(const QByteArray& data) { m_fileData = data; }
    void setFileName(const QString& fileName) { m_fileName = fileName; }
    void setMimeType(const QString& mimeType) { m_mimeType = mimeType; }
    void setCreatedAt(const QDateTime& dateTime) { m_createdAt = dateTime; }
    
    // Utility methods
    QString getTypeString() const;
    static RecordType stringToType(const QString& typeStr);
    bool hasFile() const;
    bool saveFile(const QString& directory) const;
    
private:
    int m_id;
    int m_patientId;
    int m_doctorId;
    QString m_title;
    RecordType m_type;
    QString m_description;
    QDateTime m_recordDate;
    QString m_filePath;
    QByteArray m_fileData;
    QString m_fileName;
    QString m_mimeType;
    QDateTime m_createdAt;
};

#endif // MEDICALRECORD_H
