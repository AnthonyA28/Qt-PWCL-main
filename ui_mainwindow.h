/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
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
    QVBoxLayout *verticalLayout;
    QTableWidget *outputTable;
    QLabel *emergencyMessageLabel;
    QCustomPlot *plot;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QTabWidget *tabWidget;
    QWidget *tabManual;
    QFormLayout *formLayout;
    QLabel *label_6;
    QLineEdit *percentOntTextBox;
    QLabel *label_7;
    QLineEdit *M_fanSpeedTextBox;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tabAutomatic;
    QFormLayout *formLayout_2;
    QLabel *label_9;
    QLineEdit *setPointTextBox;
    QLabel *label_4;
    QLineEdit *kcTextBox;
    QLabel *label_3;
    QLineEdit *tauiTextBox;
    QLabel *label;
    QLineEdit *taudTextBox;
    QLabel *label_2;
    QLineEdit *taufTextBox;
    QLabel *label_11;
    QLineEdit *A_fanSpeedTextBox;
    QCheckBox *filterAllCheckBox;
    QCheckBox *posFormCheckBox;
    QFormLayout *formLayout_6;
    QFormLayout *formLayout_5;
    QPushButton *setButton;
    QComboBox *portComboBox;
    QFormLayout *formLayout_3;
    QLabel *label_8;
    QFrame *line;
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
    QFrame *line_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(617, 590);
        MainWindow->setMinimumSize(QSize(542, 590));
        QIcon icon;
        icon.addFile(QStringLiteral("../qt_PWCL_game/gator_icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        outputTable = new QTableWidget(centralWidget);
        if (outputTable->columnCount() < 6)
            outputTable->setColumnCount(6);
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem->setFont(font);
        outputTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        outputTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        outputTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        outputTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        outputTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QFont font2;
        font2.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font2);
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
        QFont font3;
        font3.setPointSize(7);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font3);
        __qtablewidgetitem11->setFlags(Qt::NoItemFlags);
        outputTable->setItem(0, 4, __qtablewidgetitem11);
        outputTable->setObjectName(QStringLiteral("outputTable"));
        outputTable->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(outputTable->sizePolicy().hasHeightForWidth());
        outputTable->setSizePolicy(sizePolicy);
        outputTable->setMinimumSize(QSize(150, 100));
        outputTable->setFocusPolicy(Qt::NoFocus);
        outputTable->setContextMenuPolicy(Qt::NoContextMenu);
#ifndef QT_NO_TOOLTIP
        outputTable->setToolTip(QStringLiteral(""));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        outputTable->setStatusTip(QStringLiteral(""));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        outputTable->setWhatsThis(QStringLiteral(""));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        outputTable->setAccessibleName(QStringLiteral(""));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        outputTable->setAccessibleDescription(QStringLiteral(""));
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
        emergencyMessageLabel->setObjectName(QStringLiteral("emergencyMessageLabel"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 0, 4, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        emergencyMessageLabel->setPalette(palette);
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        emergencyMessageLabel->setFont(font4);

        verticalLayout->addWidget(emergencyMessageLabel);

        plot = new QCustomPlot(centralWidget);
        plot->setObjectName(QStringLiteral("plot"));

        verticalLayout->addWidget(plot);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(2, 1);

        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(251, 0));
        label_5->setMaximumSize(QSize(251, 16777215));
        QFont font5;
        font5.setBold(true);
        font5.setWeight(75);
        label_5->setFont(font5);

        verticalLayout_4->addWidget(label_5);


        verticalLayout_3->addLayout(verticalLayout_4);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(0, 180));
        tabWidget->setMaximumSize(QSize(227, 240));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(21, 21));
        tabWidget->setElideMode(Qt::ElideNone);
        tabManual = new QWidget();
        tabManual->setObjectName(QStringLiteral("tabManual"));
        formLayout = new QFormLayout(tabManual);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(tabManual);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(122, 16777215));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        percentOntTextBox = new QLineEdit(tabManual);
        percentOntTextBox->setObjectName(QStringLiteral("percentOntTextBox"));
        percentOntTextBox->setMaximumSize(QSize(70, 20));

        formLayout->setWidget(1, QFormLayout::FieldRole, percentOntTextBox);

        label_7 = new QLabel(tabManual);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(69, 16777215));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        M_fanSpeedTextBox = new QLineEdit(tabManual);
        M_fanSpeedTextBox->setObjectName(QStringLiteral("M_fanSpeedTextBox"));
        M_fanSpeedTextBox->setMaximumSize(QSize(70, 20));

        formLayout->setWidget(2, QFormLayout::FieldRole, M_fanSpeedTextBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(0, QFormLayout::SpanningRole, horizontalSpacer_2);

        tabWidget->addTab(tabManual, QString());
        tabAutomatic = new QWidget();
        tabAutomatic->setObjectName(QStringLiteral("tabAutomatic"));
        tabAutomatic->setEnabled(true);
        tabAutomatic->setMinimumSize(QSize(100, 300));
        formLayout_2 = new QFormLayout(tabAutomatic);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_2->setHorizontalSpacing(3);
        formLayout_2->setVerticalSpacing(2);
        label_9 = new QLabel(tabAutomatic);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_9);

        setPointTextBox = new QLineEdit(tabAutomatic);
        setPointTextBox->setObjectName(QStringLiteral("setPointTextBox"));
        setPointTextBox->setMaximumSize(QSize(70, 20));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, setPointTextBox);

        label_4 = new QLabel(tabAutomatic);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(18, 16777215));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_4);

        kcTextBox = new QLineEdit(tabAutomatic);
        kcTextBox->setObjectName(QStringLiteral("kcTextBox"));
        sizePolicy1.setHeightForWidth(kcTextBox->sizePolicy().hasHeightForWidth());
        kcTextBox->setSizePolicy(sizePolicy1);
        kcTextBox->setMaximumSize(QSize(70, 20));
        kcTextBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, kcTextBox);

        label_3 = new QLabel(tabAutomatic);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(15, 16777215));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_3);

        tauiTextBox = new QLineEdit(tabAutomatic);
        tauiTextBox->setObjectName(QStringLiteral("tauiTextBox"));
        sizePolicy1.setHeightForWidth(tauiTextBox->sizePolicy().hasHeightForWidth());
        tauiTextBox->setSizePolicy(sizePolicy1);
        tauiTextBox->setMaximumSize(QSize(70, 20));
        tauiTextBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, tauiTextBox);

        label = new QLabel(tabAutomatic);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(19, 16777215));
        QFont font6;
        font6.setPointSize(9);
        label->setFont(font6);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label);

        taudTextBox = new QLineEdit(tabAutomatic);
        taudTextBox->setObjectName(QStringLiteral("taudTextBox"));
        sizePolicy1.setHeightForWidth(taudTextBox->sizePolicy().hasHeightForWidth());
        taudTextBox->setSizePolicy(sizePolicy1);
        taudTextBox->setMaximumSize(QSize(70, 20));
        taudTextBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, taudTextBox);

        label_2 = new QLabel(tabAutomatic);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(17, 16777215));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_2);

        taufTextBox = new QLineEdit(tabAutomatic);
        taufTextBox->setObjectName(QStringLiteral("taufTextBox"));
        sizePolicy1.setHeightForWidth(taufTextBox->sizePolicy().hasHeightForWidth());
        taufTextBox->setSizePolicy(sizePolicy1);
        taufTextBox->setMaximumSize(QSize(70, 20));
        taufTextBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, taufTextBox);

        label_11 = new QLabel(tabAutomatic);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(69, 16777215));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_11);

        A_fanSpeedTextBox = new QLineEdit(tabAutomatic);
        A_fanSpeedTextBox->setObjectName(QStringLiteral("A_fanSpeedTextBox"));
        A_fanSpeedTextBox->setMaximumSize(QSize(70, 20));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, A_fanSpeedTextBox);

        filterAllCheckBox = new QCheckBox(tabAutomatic);
        filterAllCheckBox->setObjectName(QStringLiteral("filterAllCheckBox"));
        sizePolicy1.setHeightForWidth(filterAllCheckBox->sizePolicy().hasHeightForWidth());
        filterAllCheckBox->setSizePolicy(sizePolicy1);
        filterAllCheckBox->setMaximumSize(QSize(249, 16777215));
        filterAllCheckBox->setFont(font6);

        formLayout_2->setWidget(7, QFormLayout::SpanningRole, filterAllCheckBox);

        posFormCheckBox = new QCheckBox(tabAutomatic);
        posFormCheckBox->setObjectName(QStringLiteral("posFormCheckBox"));
        sizePolicy1.setHeightForWidth(posFormCheckBox->sizePolicy().hasHeightForWidth());
        posFormCheckBox->setSizePolicy(sizePolicy1);
        posFormCheckBox->setMaximumSize(QSize(249, 16777215));
        posFormCheckBox->setFont(font6);

        formLayout_2->setWidget(8, QFormLayout::SpanningRole, posFormCheckBox);

        tabWidget->addTab(tabAutomatic, QString());

        verticalLayout_3->addWidget(tabWidget);

        formLayout_6 = new QFormLayout();
        formLayout_6->setSpacing(6);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        formLayout_6->setHorizontalSpacing(2);
        formLayout_6->setVerticalSpacing(3);
        formLayout_5 = new QFormLayout();
        formLayout_5->setSpacing(6);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        setButton = new QPushButton(centralWidget);
        setButton->setObjectName(QStringLiteral("setButton"));
        sizePolicy1.setHeightForWidth(setButton->sizePolicy().hasHeightForWidth());
        setButton->setSizePolicy(sizePolicy1);
        setButton->setMinimumSize(QSize(120, 0));
        setButton->setMaximumSize(QSize(120, 27));
        setButton->setFont(font6);
        setButton->setAutoDefault(true);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, setButton);

        portComboBox = new QComboBox(centralWidget);
        portComboBox->setObjectName(QStringLiteral("portComboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(portComboBox->sizePolicy().hasHeightForWidth());
        portComboBox->setSizePolicy(sizePolicy2);
        portComboBox->setMinimumSize(QSize(73, 0));
        portComboBox->setMaximumSize(QSize(120, 27));
        portComboBox->setEditable(false);
        portComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        portComboBox->setFrame(true);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, portComboBox);


        formLayout_6->setLayout(0, QFormLayout::LabelRole, formLayout_5);


        verticalLayout_3->addLayout(formLayout_6);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_3->setHorizontalSpacing(12);
        formLayout_3->setVerticalSpacing(7);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMaximumSize(QSize(227, 16777215));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_8);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy3);
        line->setMinimumSize(QSize(2, 0));
        line->setMaximumSize(QSize(251, 3));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(2);
        line->setMidLineWidth(1);
        line->setFrameShape(QFrame::HLine);

        formLayout_3->setWidget(1, QFormLayout::SpanningRole, line);

        kcLabelName = new QLabel(centralWidget);
        kcLabelName->setObjectName(QStringLiteral("kcLabelName"));
        sizePolicy1.setHeightForWidth(kcLabelName->sizePolicy().hasHeightForWidth());
        kcLabelName->setSizePolicy(sizePolicy1);
        kcLabelName->setMaximumSize(QSize(16, 16777215));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, kcLabelName);

        kcLabel = new QLabel(centralWidget);
        kcLabel->setObjectName(QStringLiteral("kcLabel"));
        sizePolicy1.setHeightForWidth(kcLabel->sizePolicy().hasHeightForWidth());
        kcLabel->setSizePolicy(sizePolicy1);
        kcLabel->setMaximumSize(QSize(141, 16777215));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, kcLabel);

        tauiLabelName = new QLabel(centralWidget);
        tauiLabelName->setObjectName(QStringLiteral("tauiLabelName"));
        sizePolicy1.setHeightForWidth(tauiLabelName->sizePolicy().hasHeightForWidth());
        tauiLabelName->setSizePolicy(sizePolicy1);
        tauiLabelName->setMaximumSize(QSize(14, 16777215));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, tauiLabelName);

        tauiLabel = new QLabel(centralWidget);
        tauiLabel->setObjectName(QStringLiteral("tauiLabel"));
        sizePolicy1.setHeightForWidth(tauiLabel->sizePolicy().hasHeightForWidth());
        tauiLabel->setSizePolicy(sizePolicy1);
        tauiLabel->setMaximumSize(QSize(141, 16777215));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, tauiLabel);

        taudLabelName = new QLabel(centralWidget);
        taudLabelName->setObjectName(QStringLiteral("taudLabelName"));
        sizePolicy1.setHeightForWidth(taudLabelName->sizePolicy().hasHeightForWidth());
        taudLabelName->setSizePolicy(sizePolicy1);
        taudLabelName->setMaximumSize(QSize(17, 16777215));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, taudLabelName);

        taudLabel = new QLabel(centralWidget);
        taudLabel->setObjectName(QStringLiteral("taudLabel"));
        sizePolicy1.setHeightForWidth(taudLabel->sizePolicy().hasHeightForWidth());
        taudLabel->setSizePolicy(sizePolicy1);
        taudLabel->setMaximumSize(QSize(141, 16777215));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, taudLabel);

        taufLabelName = new QLabel(centralWidget);
        taufLabelName->setObjectName(QStringLiteral("taufLabelName"));
        sizePolicy1.setHeightForWidth(taufLabelName->sizePolicy().hasHeightForWidth());
        taufLabelName->setSizePolicy(sizePolicy1);
        taufLabelName->setMaximumSize(QSize(16, 16777215));

        formLayout_3->setWidget(5, QFormLayout::LabelRole, taufLabelName);

        taufLabel = new QLabel(centralWidget);
        taufLabel->setObjectName(QStringLiteral("taufLabel"));
        sizePolicy1.setHeightForWidth(taufLabel->sizePolicy().hasHeightForWidth());
        taufLabel->setSizePolicy(sizePolicy1);
        taufLabel->setMaximumSize(QSize(141, 16777215));

        formLayout_3->setWidget(5, QFormLayout::FieldRole, taufLabel);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_13);

        modeTextLabel = new QLabel(centralWidget);
        modeTextLabel->setObjectName(QStringLiteral("modeTextLabel"));

        formLayout_3->setWidget(6, QFormLayout::FieldRole, modeTextLabel);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        sizePolicy3.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy3);
        line_2->setMinimumSize(QSize(2, 0));
        line_2->setMaximumSize(QSize(251, 3));
        line_2->setFrameShadow(QFrame::Sunken);
        line_2->setLineWidth(2);
        line_2->setMidLineWidth(1);
        line_2->setFrameShape(QFrame::HLine);

        formLayout_3->setWidget(7, QFormLayout::SpanningRole, line_2);


        verticalLayout_3->addLayout(formLayout_3);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 617, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        setButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Portable Wet Control Lab Main", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = outputTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Time \n"
"[min]", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = outputTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Heater\n"
"On [%] ", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = outputTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Temperature\n"
"[\302\260C]", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = outputTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Temperature \n"
"Filtered [\302\260C]", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = outputTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Set \n"
"Point [\302\260C]", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = outputTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Fan Speed", Q_NULLPTR));

        const bool __sortingEnabled = outputTable->isSortingEnabled();
        outputTable->setSortingEnabled(false);
        outputTable->setSortingEnabled(__sortingEnabled);

        emergencyMessageLabel->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Portable Wet Control Lab Main</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Percent Heater On</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Fan Speed</span></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabManual), QApplication::translate("MainWindow", "Manual", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Set Point</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">K</span><span style=\" font-size:11pt; vertical-align:sub;\">C</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\316\244</span><span style=\" font-size:11pt; vertical-align:sub;\">I</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\316\244</span><span style=\" font-size:11pt; vertical-align:sub;\">D</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\316\244</span><span style=\" font-size:11pt; vertical-align:sub;\">F</span></p></body></html>", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Fan Speed</span></p></body></html>", Q_NULLPTR));
        filterAllCheckBox->setText(QApplication::translate("MainWindow", "Filter All Terms", Q_NULLPTR));
        posFormCheckBox->setText(QApplication::translate("MainWindow", "Position Form", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabAutomatic), QApplication::translate("MainWindow", "Automatic", Q_NULLPTR));
        setButton->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600; text-decoration: underline;\">Current Parameters</span></p></body></html>", Q_NULLPTR));
        kcLabelName->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">K</span><span style=\" font-size:9pt; vertical-align:sub;\">C</span></p></body></html>", Q_NULLPTR));
        kcLabel->setText(QString());
        tauiLabelName->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">\316\244</span><span style=\" font-size:9pt; vertical-align:sub;\">I</span></p></body></html>", Q_NULLPTR));
        tauiLabel->setText(QString());
        taudLabelName->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">\316\244</span><span style=\" font-size:9pt; vertical-align:sub;\">D</span></p></body></html>", Q_NULLPTR));
        taudLabel->setText(QString());
        taufLabelName->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">\316\244</span><span style=\" font-size:9pt; vertical-align:sub;\">F</span></p></body></html>", Q_NULLPTR));
        taufLabel->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Mode</span></p></body></html>", Q_NULLPTR));
        modeTextLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
