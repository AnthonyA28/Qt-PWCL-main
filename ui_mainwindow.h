/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QTabWidget *tabWidget;
    QWidget *tabManual;
    QFormLayout *formLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_12;
    QLineEdit *M_fanSpeedTextBox;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *percentOntTextBox;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_6;
    QWidget *tabAutomatic;
    QFormLayout *formLayout_2;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *setPointTextBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *kcTextBox;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *taufTextBox;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *A_fanSpeedTextBox;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QCheckBox *filterAllCheckBox;
    QCheckBox *posFormCheckBox;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *tauiTextBox;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *taudTextBox;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label;
    QFormLayout *formLayout_6;
    QComboBox *portComboBox;
    QPushButton *setButton;
    QFormLayout *formLayout_3;
    QLabel *label_8;
    QLabel *kcLabelName;
    QLabel *kcLabel;
    QLabel *tauiLabelName;
    QLabel *tauiLabel;
    QLabel *taudLabelName;
    QLabel *taudLabel;
    QLabel *taufLabelName;
    QLabel *taufLabel;
    QLabel *label_13;
    QLabel *modeTextLabel;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QTableWidget *outputTable;
    QLabel *emergencyMessageLabel;
    QCustomPlot *plot;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_15;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(613, 615);
        MainWindow->setMinimumSize(QSize(613, 615));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../qt_PWCL_game/gator_icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(12);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_3->setContentsMargins(-1, -1, 0, -1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(251, 16777215));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        verticalLayout_3->addWidget(label_5);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabManual = new QWidget();
        tabManual->setObjectName(QString::fromUtf8("tabManual"));
        formLayout = new QFormLayout(tabManual);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(3);
        formLayout->setContentsMargins(-1, -1, 15, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(0, QFormLayout::SpanningRole, horizontalSpacer_2);

        label_7 = new QLabel(tabManual);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(69, 16777215));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        M_fanSpeedTextBox = new QLineEdit(tabManual);
        M_fanSpeedTextBox->setObjectName(QString::fromUtf8("M_fanSpeedTextBox"));

        horizontalLayout_12->addWidget(M_fanSpeedTextBox);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_9);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 1);

        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_12);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        percentOntTextBox = new QLineEdit(tabManual);
        percentOntTextBox->setObjectName(QString::fromUtf8("percentOntTextBox"));

        horizontalLayout_14->addWidget(percentOntTextBox);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_10);

        horizontalLayout_14->setStretch(0, 1);
        horizontalLayout_14->setStretch(1, 1);

        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_14);

        label_6 = new QLabel(tabManual);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(122, 16777215));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        tabWidget->addTab(tabManual, QString());
        tabAutomatic = new QWidget();
        tabAutomatic->setObjectName(QString::fromUtf8("tabAutomatic"));
        tabAutomatic->setEnabled(true);
        sizePolicy.setHeightForWidth(tabAutomatic->sizePolicy().hasHeightForWidth());
        tabAutomatic->setSizePolicy(sizePolicy);
        formLayout_2 = new QFormLayout(tabAutomatic);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_2->setHorizontalSpacing(10);
        formLayout_2->setVerticalSpacing(0);
        formLayout_2->setContentsMargins(-1, -1, 15, -1);
        label_9 = new QLabel(tabAutomatic);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        setPointTextBox = new QLineEdit(tabAutomatic);
        setPointTextBox->setObjectName(QString::fromUtf8("setPointTextBox"));
        sizePolicy.setHeightForWidth(setPointTextBox->sizePolicy().hasHeightForWidth());
        setPointTextBox->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(setPointTextBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout_3);

        label_4 = new QLabel(tabAutomatic);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        kcTextBox = new QLineEdit(tabAutomatic);
        kcTextBox->setObjectName(QString::fromUtf8("kcTextBox"));
        sizePolicy.setHeightForWidth(kcTextBox->sizePolicy().hasHeightForWidth());
        kcTextBox->setSizePolicy(sizePolicy);
        kcTextBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(kcTextBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        formLayout_2->setLayout(1, QFormLayout::FieldRole, horizontalLayout_4);

        label_2 = new QLabel(tabAutomatic);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        taufTextBox = new QLineEdit(tabAutomatic);
        taufTextBox->setObjectName(QString::fromUtf8("taufTextBox"));
        sizePolicy.setHeightForWidth(taufTextBox->sizePolicy().hasHeightForWidth());
        taufTextBox->setSizePolicy(sizePolicy);
        taufTextBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(taufTextBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);

        formLayout_2->setLayout(5, QFormLayout::FieldRole, horizontalLayout_9);

        label_11 = new QLabel(tabAutomatic);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(8, QFormLayout::LabelRole, label_11);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        A_fanSpeedTextBox = new QLineEdit(tabAutomatic);
        A_fanSpeedTextBox->setObjectName(QString::fromUtf8("A_fanSpeedTextBox"));
        sizePolicy.setHeightForWidth(A_fanSpeedTextBox->sizePolicy().hasHeightForWidth());
        A_fanSpeedTextBox->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(A_fanSpeedTextBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 1);

        formLayout_2->setLayout(8, QFormLayout::FieldRole, horizontalLayout_8);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_2->setItem(9, QFormLayout::FieldRole, horizontalSpacer);

        filterAllCheckBox = new QCheckBox(tabAutomatic);
        filterAllCheckBox->setObjectName(QString::fromUtf8("filterAllCheckBox"));
        sizePolicy.setHeightForWidth(filterAllCheckBox->sizePolicy().hasHeightForWidth());
        filterAllCheckBox->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(9);
        filterAllCheckBox->setFont(font1);

        formLayout_2->setWidget(10, QFormLayout::SpanningRole, filterAllCheckBox);

        posFormCheckBox = new QCheckBox(tabAutomatic);
        posFormCheckBox->setObjectName(QString::fromUtf8("posFormCheckBox"));
        sizePolicy.setHeightForWidth(posFormCheckBox->sizePolicy().hasHeightForWidth());
        posFormCheckBox->setSizePolicy(sizePolicy);
        posFormCheckBox->setFont(font1);

        formLayout_2->setWidget(11, QFormLayout::SpanningRole, posFormCheckBox);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        tauiTextBox = new QLineEdit(tabAutomatic);
        tauiTextBox->setObjectName(QString::fromUtf8("tauiTextBox"));
        sizePolicy.setHeightForWidth(tauiTextBox->sizePolicy().hasHeightForWidth());
        tauiTextBox->setSizePolicy(sizePolicy);
        tauiTextBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(tauiTextBox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 1);

        formLayout_2->setLayout(2, QFormLayout::FieldRole, horizontalLayout_10);

        label_3 = new QLabel(tabAutomatic);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        taudTextBox = new QLineEdit(tabAutomatic);
        taudTextBox->setObjectName(QString::fromUtf8("taudTextBox"));
        sizePolicy.setHeightForWidth(taudTextBox->sizePolicy().hasHeightForWidth());
        taudTextBox->setSizePolicy(sizePolicy);
        taudTextBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(taudTextBox);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_8);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 1);

        formLayout_2->setLayout(3, QFormLayout::FieldRole, horizontalLayout_11);

        label = new QLabel(tabAutomatic);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label);

        tabWidget->addTab(tabAutomatic, QString());

        verticalLayout_3->addWidget(tabWidget);

        formLayout_6 = new QFormLayout();
        formLayout_6->setSpacing(6);
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        formLayout_6->setHorizontalSpacing(10);
        formLayout_6->setVerticalSpacing(10);
        formLayout_6->setContentsMargins(10, 5, 10, 5);
        portComboBox = new QComboBox(centralWidget);
        portComboBox->setObjectName(QString::fromUtf8("portComboBox"));
        portComboBox->setMinimumSize(QSize(73, 0));
        portComboBox->setEditable(false);
        portComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        portComboBox->setFrame(true);

        formLayout_6->setWidget(0, QFormLayout::LabelRole, portComboBox);

        setButton = new QPushButton(centralWidget);
        setButton->setObjectName(QString::fromUtf8("setButton"));
        setButton->setMinimumSize(QSize(120, 0));
        setButton->setFont(font1);
        setButton->setAutoDefault(true);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, setButton);


        verticalLayout_3->addLayout(formLayout_6);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_3->setHorizontalSpacing(12);
        formLayout_3->setVerticalSpacing(7);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_8);

        kcLabelName = new QLabel(centralWidget);
        kcLabelName->setObjectName(QString::fromUtf8("kcLabelName"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(kcLabelName->sizePolicy().hasHeightForWidth());
        kcLabelName->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, kcLabelName);

        kcLabel = new QLabel(centralWidget);
        kcLabel->setObjectName(QString::fromUtf8("kcLabel"));
        sizePolicy1.setHeightForWidth(kcLabel->sizePolicy().hasHeightForWidth());
        kcLabel->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, kcLabel);

        tauiLabelName = new QLabel(centralWidget);
        tauiLabelName->setObjectName(QString::fromUtf8("tauiLabelName"));
        sizePolicy1.setHeightForWidth(tauiLabelName->sizePolicy().hasHeightForWidth());
        tauiLabelName->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, tauiLabelName);

        tauiLabel = new QLabel(centralWidget);
        tauiLabel->setObjectName(QString::fromUtf8("tauiLabel"));
        sizePolicy1.setHeightForWidth(tauiLabel->sizePolicy().hasHeightForWidth());
        tauiLabel->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, tauiLabel);

        taudLabelName = new QLabel(centralWidget);
        taudLabelName->setObjectName(QString::fromUtf8("taudLabelName"));
        sizePolicy1.setHeightForWidth(taudLabelName->sizePolicy().hasHeightForWidth());
        taudLabelName->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, taudLabelName);

        taudLabel = new QLabel(centralWidget);
        taudLabel->setObjectName(QString::fromUtf8("taudLabel"));
        sizePolicy1.setHeightForWidth(taudLabel->sizePolicy().hasHeightForWidth());
        taudLabel->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, taudLabel);

        taufLabelName = new QLabel(centralWidget);
        taufLabelName->setObjectName(QString::fromUtf8("taufLabelName"));
        sizePolicy1.setHeightForWidth(taufLabelName->sizePolicy().hasHeightForWidth());
        taufLabelName->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(4, QFormLayout::LabelRole, taufLabelName);

        taufLabel = new QLabel(centralWidget);
        taufLabel->setObjectName(QString::fromUtf8("taufLabel"));
        sizePolicy1.setHeightForWidth(taufLabel->sizePolicy().hasHeightForWidth());
        taufLabel->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, taufLabel);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_13);

        modeTextLabel = new QLabel(centralWidget);
        modeTextLabel->setObjectName(QString::fromUtf8("modeTextLabel"));

        formLayout_3->setWidget(5, QFormLayout::FieldRole, modeTextLabel);


        verticalLayout_3->addLayout(formLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_3->setStretch(4, 1);

        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(0, -1, -1, 0);
        outputTable = new QTableWidget(centralWidget);
        if (outputTable->columnCount() < 6)
            outputTable->setColumnCount(6);
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem->setFont(font2);
        outputTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        outputTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        outputTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        outputTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font3);
        outputTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QFont font4;
        font4.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font4.setPointSize(8);
        font4.setBold(true);
        font4.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font4);
        outputTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (outputTable->rowCount() < 1)
            outputTable->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        outputTable->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignLeading|Qt::AlignTop);
        __qtablewidgetitem7->setFlags(Qt::NoItemFlags);
        outputTable->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignLeading|Qt::AlignTop);
        __qtablewidgetitem8->setFlags(Qt::NoItemFlags);
        outputTable->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFlags(Qt::NoItemFlags);
        outputTable->setItem(0, 2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFlags(Qt::NoItemFlags);
        outputTable->setItem(0, 3, __qtablewidgetitem10);
        QFont font5;
        font5.setPointSize(7);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font5);
        __qtablewidgetitem11->setFlags(Qt::NoItemFlags);
        outputTable->setItem(0, 4, __qtablewidgetitem11);
        outputTable->setObjectName(QString::fromUtf8("outputTable"));
        outputTable->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(outputTable->sizePolicy().hasHeightForWidth());
        outputTable->setSizePolicy(sizePolicy2);
        outputTable->setFocusPolicy(Qt::NoFocus);
        outputTable->setContextMenuPolicy(Qt::NoContextMenu);
#ifndef QT_NO_TOOLTIP
        outputTable->setToolTip(QString::fromUtf8(""));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        outputTable->setStatusTip(QString::fromUtf8(""));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        outputTable->setWhatsThis(QString::fromUtf8(""));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        outputTable->setAccessibleName(QString::fromUtf8(""));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        outputTable->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_NO_ACCESSIBILITY
        outputTable->setFrameShape(QFrame::Box);
        outputTable->setLineWidth(1);
        outputTable->setMidLineWidth(0);
        outputTable->setAutoScrollMargin(1);
        outputTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        outputTable->setTabKeyNavigation(false);
        outputTable->setProperty("showDropIndicator", QVariant(false));
        outputTable->setDragDropOverwriteMode(false);
        outputTable->setSelectionBehavior(QAbstractItemView::SelectColumns);
        outputTable->setTextElideMode(Qt::ElideNone);
        outputTable->setShowGrid(true);
        outputTable->setGridStyle(Qt::SolidLine);
        outputTable->setCornerButtonEnabled(false);
        outputTable->horizontalHeader()->setCascadingSectionResizes(true);
        outputTable->horizontalHeader()->setHighlightSections(false);
        outputTable->horizontalHeader()->setMinimumSectionSize(20);
        outputTable->verticalHeader()->setVisible(false);
        outputTable->verticalHeader()->setDefaultSectionSize(29);
        outputTable->verticalHeader()->setHighlightSections(false);
        outputTable->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout->addWidget(outputTable);

        emergencyMessageLabel = new QLabel(centralWidget);
        emergencyMessageLabel->setObjectName(QString::fromUtf8("emergencyMessageLabel"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 0, 4, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        QBrush brush2(QColor(255, 0, 4, 128));
        brush2.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush3(QColor(255, 0, 4, 128));
        brush3.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        QBrush brush5(QColor(255, 0, 4, 128));
        brush5.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
        emergencyMessageLabel->setPalette(palette);
        QFont font6;
        font6.setPointSize(11);
        font6.setBold(false);
        font6.setWeight(50);
        emergencyMessageLabel->setFont(font6);

        verticalLayout->addWidget(emergencyMessageLabel);

        plot = new QCustomPlot(centralWidget);
        plot->setObjectName(QString::fromUtf8("plot"));

        verticalLayout->addWidget(plot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_10->setLineWidth(1);

        horizontalLayout->addWidget(label_10);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_12->setLineWidth(1);

        horizontalLayout->addWidget(label_12);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_14->setLineWidth(1);

        horizontalLayout->addWidget(label_14);

        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_15->setLineWidth(1);

        horizontalLayout->addWidget(label_15);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(2, 1);

        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_2, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 613, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        setButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Portable Wet Control Lab Main", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Portable Wet Control Lab Main</span></p></body></html>", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Fan Speed</span></p></body></html>", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Percent Heater On</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabManual), QApplication::translate("MainWindow", "Manual", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Set Point</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">K</span><span style=\" font-size:11pt; vertical-align:sub;\">C</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\316\244</span><span style=\" font-size:11pt; vertical-align:sub;\">F</span></p></body></html>", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Fan Speed</span></p></body></html>", nullptr));
        filterAllCheckBox->setText(QApplication::translate("MainWindow", "Filter All Terms", nullptr));
        posFormCheckBox->setText(QApplication::translate("MainWindow", "Position Form", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\316\244</span><span style=\" font-size:11pt; vertical-align:sub;\">I</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\316\244</span><span style=\" font-size:11pt; vertical-align:sub;\">D</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAutomatic), QApplication::translate("MainWindow", "Automatic", nullptr));
        setButton->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600; text-decoration: underline;\">Current Parameters</span></p></body></html>", nullptr));
        kcLabelName->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">K</span><span style=\" font-size:9pt; vertical-align:sub;\">C</span></p></body></html>", nullptr));
        kcLabel->setText(QString());
        tauiLabelName->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">\316\244</span><span style=\" font-size:9pt; vertical-align:sub;\">I</span></p></body></html>", nullptr));
        tauiLabel->setText(QString());
        taudLabelName->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">\316\244</span><span style=\" font-size:9pt; vertical-align:sub;\">D</span></p></body></html>", nullptr));
        taudLabel->setText(QString());
        taufLabelName->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">\316\244</span><span style=\" font-size:9pt; vertical-align:sub;\">F</span></p></body></html>", nullptr));
        taufLabel->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Mode</span></p></body></html>", nullptr));
        modeTextLabel->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = outputTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Time \n"
"[min]", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = outputTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Heater\n"
"On [%] ", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = outputTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Temperature\n"
"[\302\260C]", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = outputTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Temperature \n"
"Filtered [\302\260C]", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = outputTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Set \n"
"Point [\302\260C]", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = outputTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Fan Speed", nullptr));

        const bool __sortingEnabled = outputTable->isSortingEnabled();
        outputTable->setSortingEnabled(false);
        outputTable->setSortingEnabled(__sortingEnabled);

        emergencyMessageLabel->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-family:'arial unicode ms,Lucida Sans Unicode,sans-serif'; font-size:9pt; color:#ffaa00; background-color:#ffffff;\">\342\200\242 Set point</span></p></body></html>", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-family:'Code2000,Arial Unicode MS,Lucida Sans Unicode'; font-size:9pt; color:#55ff00; background-color:#fbfffe;\">\342\270\272</span><span style=\" font-family:'arial unicode ms,Lucida Sans Unicode,sans-serif'; font-size:9pt; color:#55ff00; background-color:#ffffff;\">Temp</span></p></body></html>", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-family:'Code2000,Arial Unicode MS,Lucida Sans Unicode'; font-size:9pt; color:#0055ff; background-color:#fbfffe;\">\342\270\272</span><span style=\" font-family:'arial unicode ms,Lucida Sans Unicode,sans-serif'; font-size:9pt; color:#0055ff; background-color:#ffffff;\">Temp Filt </span></p></body></html>", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-family:'Code2000,Arial Unicode MS,Lucida Sans Unicode'; font-size:9pt; color:#55007f; background-color:#fbfffe;\">\342\270\272</span><span style=\" font-family:'arial unicode ms,Lucida Sans Unicode,sans-serif'; font-size:9pt; color:#55007f; background-color:#ffffff;\">% On</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
