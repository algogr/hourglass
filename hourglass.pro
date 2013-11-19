TEMPLATE = app
TARGET = hourglass 

QT        += core gui sql network

HEADERS   += \
    mainwindow.h \
    customer.h \
    constants.h \
    debit_types.h \
    tasks.h \
    migration.h \
    invoice_browser.h \
    invoice_customer.h \
    checkboxdelegate.h \
    chechkablesqlquerymodel.h \
    mailsender.h \
    email_tasks.h \
    weekgraph.h \
    editorcheckbox.h \
    editorspinbox.h \
    invoicereview.h \
    projects.h \
    generalbrowser.h \
    projectsbrowser.h \
    asterisk_callerid_monitor.h \
    incoming_call.h \
    config.h
SOURCES   += main.cpp \
    mainwindow.cpp \
    customer.cpp \
    debit_types.cpp \
    tasks.cpp \
    migration.cpp \
    invoice_browser.cpp \
    invoice_customer.cpp \
    checkboxdelegate.cpp \
    chechkablesqlquerymodel.cpp \
    mailsender.cpp \
    email_tasks.cpp \
    weekgraph.cpp \
    editorcheckbox.cpp \
    editorspinbox.cpp \
    invoicereview.cpp \
    projects.cpp \
    generalbrowser.cpp \
    projectsbrowser.cpp \
    asterisk_callerid_monitor.cpp \
    incoming_call.cpp \
    config.cpp
FORMS     += \    
    mainwindow.ui \
    customer.ui \
    debit_types.ui \
    tasks.ui \
    migration.ui \
    invoice_browser.ui \
    invoice_customer.ui \
    email_tasks.ui \
    invoicereview.ui \
    projects.ui \
    generalbrowser.ui \
    incoming_call.ui \
    config.ui
RESOURCES +=
