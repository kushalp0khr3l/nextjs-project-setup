cmake_minimum_required(VERSION 3.16)
project(HospitalManagementSystem VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 components
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Sql Network)

# Enable automatic MOC, UIC, and RCC processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/registrationwindow.cpp
    src/loginwindow.cpp
    src/patientdashboard.cpp
    src/appointmentswidget.cpp
    src/schedulewidget.cpp
    src/medicalrecordswidget.cpp
    src/settingswidget.cpp
    src/databasemanager.cpp
    src/patient.cpp
    src/appointment.cpp
    src/medicalrecord.cpp
    src/doctor.cpp
)

# Header files
set(HEADERS
    include/mainwindow.h
    include/registrationwindow.h
    include/loginwindow.h
    include/patientdashboard.h
    include/appointmentswidget.h
    include/schedulewidget.h
    include/medicalrecordswidget.h
    include/settingswidget.h
    include/databasemanager.h
    include/patient.h
    include/appointment.h
    include/medicalrecord.h
    include/doctor.h
)

# UI files
set(UI_FILES
    ui/mainwindow.ui
    ui/registrationwindow.ui
    ui/loginwindow.ui
    ui/patientdashboard.ui
    ui/appointmentswidget.ui
    ui/schedulewidget.ui
    ui/medicalrecordswidget.ui
    ui/settingswidget.ui
)

# Create executable
add_executable(HospitalManagementSystem
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
)

# Link Qt libraries
target_link_libraries(HospitalManagementSystem
    Qt6::Core
    Qt6::Widgets
    Qt6::Sql
    Qt6::Network
)

# Set target properties
set_target_properties(HospitalManagementSystem PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
