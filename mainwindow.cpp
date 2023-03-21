#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cctype>
#include <cmath>

#if _WIN32 //defining DECIMAL as '.' for windows machines
#define DECIMAL '.'
#endif

#if __unix //defining DECIMAL as ',' for unix machines
#define DECIMAL ','
#endif

MainWindow::MainWindow(QWidget *root) : QMainWindow(root), ui(new Ui::MainWindow) {
    setWindowTitle("PE5 Simple Calculator");
    setMinimumSize(400, 647);
    setMaximumSize(400, 647);
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("0");
    ui->lineEdit->setReadOnly(true);
    renderCalcWidget();
    renderDisplay();
    mainWidget = new QWidget;
    renderFullCalc();
}

MainWindow::~MainWindow() { //delete window
    delete ui;
}

bool MainWindow::onlyNums() { //boolean to set state to show that only numbers are in operation
    return justNums;
}

void MainWindow::boolNum(bool boolFlip) { //sets justNums to the boolean value according to if numbers or not
    justNums = boolFlip;
}

void MainWindow::numSelected() { //sends pressed number to display
    QString num = ((QPushButton*)sender())->text();
    ui->lineEdit->setText(ui->lineEdit->text() + num);
}

void MainWindow::operatorSelected() { //
    if (onlyNums()) {
        QString opType = ((QPushButton*)sender())->text();
        if (ui->lineEdit->text().length()) {
            ui->lineEdit->setText(ui->lineEdit->text() + opType);
            boolNum(false);
        }
        else if (opType == "-")
            ui->lineEdit->setText(opType + ui->lineEdit->text());
    }
}

void MainWindow::renderFullCalc() { //combines number pad and display to create full calculator
    mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);
    mainLayout->addWidget(displayWidget, 0, 0, 1, 3);
    mainLayout->addWidget(calcWidget,  1, 0, 2, 3);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
}

void MainWindow::renderCalcWidget() { //sets up numpad for calculator
    QPushButton* zeroButton = new QPushButton("0"); //making and defining buttons
    QPushButton* oneButton = new QPushButton("1");
    QPushButton* twoButton = new QPushButton("2");
    QPushButton* threeButton = new QPushButton("3");
    QPushButton* fourButton = new QPushButton("4");
    QPushButton* fiveButton = new QPushButton("5");
    QPushButton* sixButton = new QPushButton("6");
    QPushButton* sevenButton = new QPushButton("7");
    QPushButton* eightButton = new QPushButton("8");
    QPushButton* nineButton = new QPushButton("9");
    QPushButton* addButton = new QPushButton("+");
    QPushButton* subtractButton = new QPushButton(QString::fromUtf8("-"));
    QPushButton* timesButton = new QPushButton(QString::fromUtf8("\u00D7"));
    QPushButton* divideButton = new QPushButton(QString::fromUtf8("\u00F7"));
    QPushButton* equalsButton = new QPushButton("=");
    QPushButton* deleteCharButton = new QPushButton(QString::fromUtf8("\u232B"), this);
    QPushButton* clearLineButton = new QPushButton(QString::fromUtf8("AC"), this);
    QString numStyle = "QPushButton { color: black; background-color: #cccccc; border: none; font: 20pt 'Helvetica'; outline: none;} QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 2px; border-color: #000000; } QPushButton:pressed { background-color: #e6e6e6; border-style: solid; border-width: 2px; border-color: #000000; }";
    QString operatorsStyle =   "QPushButton { color: black; background-color: #cccccc; border: none; font: 20pt 'Helvetica'; outline: none; } QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 2px; border-color: #000000; } QPushButton:pressed { background-color: #e6e6e6; border-style: solid; border-width: 2px; border-color: #000000; }";
    QString deleteCharStyle = "QPushButton { color: black; background-color: #cccccc; border: none; font: 20pt 'Helvetica'; outline: none; } QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 2px; border-color: #000000; } QPushButton:pressed { background-color: #e6e6e6; border-style: solid; border-width: 2px; border-color: #000000; }";
    QString lineClearStyle =     "QPushButton { color: black; background-color: #cccccc; border: none; font: 20pt 'Helvetica'; outline: none; } QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 2px; border-color: #000000; } QPushButton:pressed { background-color: #e6e6e6; border-style: solid; border-width: 2px; border-color: #000000; }";

    zeroButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    oneButton->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred); //configring button sizes
    twoButton->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred);
    threeButton->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred);
    fourButton->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred);
    fiveButton->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred);
    sixButton->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred);
    sevenButton->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred);
    eightButton->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred);
    nineButton->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred);
    addButton->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred);
    subtractButton->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred);
    timesButton->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred);
    divideButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    equalsButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    zeroButton->setStyleSheet(numStyle);
    oneButton->setStyleSheet(numStyle); // configuring button styles
    twoButton->setStyleSheet(numStyle);
    threeButton->setStyleSheet(numStyle);
    fourButton->setStyleSheet(numStyle);
    fiveButton->setStyleSheet(numStyle);
    sixButton->setStyleSheet(numStyle);
    sevenButton->setStyleSheet(numStyle);
    eightButton->setStyleSheet(numStyle);
    nineButton->setStyleSheet(numStyle);
    addButton->setStyleSheet(operatorsStyle);
    subtractButton->setStyleSheet(operatorsStyle);
    timesButton->setStyleSheet(operatorsStyle);
    divideButton->setStyleSheet(operatorsStyle);
    equalsButton->setStyleSheet(operatorsStyle);
    deleteCharButton->setStyleSheet(deleteCharStyle);
    clearLineButton->setStyleSheet(lineClearStyle);
    deleteCharButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    clearLineButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    calcLayout = new QGridLayout(this);
    calcLayout->setSpacing(0);
    calcLayout->setContentsMargins(0, 0, 0, 0);
    calcLayout->addWidget(sevenButton,0, 0, 1, 1);
    calcLayout->addWidget(eightButton,0, 1, 1, 1);
    calcLayout->addWidget(nineButton,0, 2, 1, 1); //configuring layout of buttons
    calcLayout->addWidget(divideButton,0, 3, 1, 1);
    calcLayout->addWidget(deleteCharButton,0, 4, 1, 1);
    calcLayout->addWidget(fourButton,1, 0, 1, 1);
    calcLayout->addWidget(fiveButton,1, 1, 1, 1);
    calcLayout->addWidget(sixButton,1, 2, 1, 1);
    calcLayout->addWidget(timesButton,1, 3, 1, 1);
    calcLayout->addWidget(clearLineButton,1, 4, 1, 1);
    calcLayout->addWidget(oneButton,2, 0, 1, 1);
    calcLayout->addWidget(twoButton,2, 1, 1, 1);
    calcLayout->addWidget(threeButton,2, 2, 1, 1);
    calcLayout->addWidget(subtractButton,2, 3, 1, 1);
    calcLayout->addWidget(equalsButton,2, 4, 2, 1);
    calcLayout->addWidget(zeroButton,3, 0, 1, 3);
    calcLayout->addWidget(addButton,3, 3, 1, 1);
    calcWidget = new QWidget(this);
    calcWidget->setLayout(calcLayout);

    connect(zeroButton,SIGNAL(clicked()), this, SLOT(numSelected()));
    connect(oneButton,SIGNAL(clicked()), this, SLOT(numSelected())); //connecting slots
    connect(twoButton,SIGNAL(clicked()), this, SLOT(numSelected()));
    connect(threeButton,SIGNAL(clicked()), this, SLOT(numSelected()));
    connect(fourButton,SIGNAL(clicked()), this, SLOT(numSelected()));
    connect(fiveButton,SIGNAL(clicked()), this, SLOT(numSelected()));
    connect(sixButton,SIGNAL(clicked()), this, SLOT(numSelected()));
    connect(sevenButton,SIGNAL(clicked()), this, SLOT(numSelected()));
    connect(eightButton,SIGNAL(clicked()), this, SLOT(numSelected()));
    connect(nineButton,SIGNAL(clicked()), this, SLOT(numSelected()));
    connect(addButton,SIGNAL(clicked()), this, SLOT(operatorSelected()));
    connect(subtractButton,SIGNAL(clicked()), this, SLOT(operatorSelected()));
    connect(timesButton,SIGNAL(clicked()), this, SLOT(operatorSelected()));
    connect(divideButton,SIGNAL(clicked()), this, SLOT(operatorSelected()));
    connect(equalsButton, SIGNAL(clicked()), this, SLOT(Equals()));
    connect(clearLineButton, SIGNAL(clicked()), this, SLOT(clearLine()));
    connect(deleteCharButton, SIGNAL(clicked()), this, SLOT(deleteChar()));
}

void MainWindow::renderDisplay() { //creates display screen for calculator
    QString displayStyle = "QLineEdit {font: 20pt 'Helvetica'; qproperty-alignment: AlignRight; padding: 90px; border-style: solid; border-width: 2px; border-color: #000000; background-color: #ffffff;}";
    ui->lineEdit->setStyleSheet(displayStyle);
    displayLayout = new QGridLayout(this);
    displayLayout->setSpacing(0);
    displayLayout->setContentsMargins(0, 0, 0, 0);
    displayLayout->addWidget(ui->lineEdit,2, 2, 2, 6);
    displayWidget = new QWidget(this);
    displayWidget->setLayout(displayLayout);
}

void MainWindow::Equals() { //performs entered computations
    boolNum(true);
    std::string expr = ui->lineEdit->text().toStdString();
    std::string target = expr.substr(1);
    std::string result = "";
    if (!std::isdigit(*(expr.rbegin())))
        deleteChar();
    if (target.find('+') != std::string::npos)
        { // addition
        std::string::size_type pos;
        double lhs  = std::stod(expr, &pos);
        double rhs = std::stod(expr.substr(pos + 1));
        double calcResult = lhs + rhs;
        result = std::to_string(calcResult);
        while (*(result.rbegin()) == '0')
            result.pop_back();
        if (*(result.rbegin()) == DECIMAL)
            result.pop_back();
        ui->lineEdit->setText(QString(result.c_str()));
         }
        else if (target.find('-') != std::string::npos)
        { //subtraction
        std::string::size_type pos;
        double lhs  = std::stod(expr, &pos);
        double rhs = std::stod(expr.substr(pos + 1));
        double calcResult = lhs - rhs;
        result = std::to_string(calcResult);
        while (*(result.rbegin()) == '0')
            result.pop_back();
        if (*(result.rbegin()) == DECIMAL)
            result.pop_back();
        ui->lineEdit->setText(QString(result.c_str()));
        }
        else if (target.find("\u00D7") != std::string::npos)
        { // multilplication
        std::string::size_type pos;
        double lhs  = std::stod(expr, &pos);
        double rhs = std::stod(expr.substr(pos + 2));
        double calcResult = lhs * rhs;
        result = std::to_string(calcResult);
        while (*(result.rbegin()) == '0')
            result.pop_back();
        if (*(result.rbegin()) == DECIMAL)
            result.pop_back();
        ui->lineEdit->setText(QString(result.c_str()));
        }
    else if (target.find("\u00F7") != std::string::npos)
        { // division
        std::string::size_type pos;
        double lhs  = std::stod(expr, &pos);
        double rhs = std::stod(expr.substr(pos + 2));
        double calcResult = lhs / rhs;
        result = std::to_string(calcResult);
        while (*(result.rbegin()) == '0')
            result.pop_back();
        if (*(result.rbegin()) == DECIMAL)
            result.pop_back();
        ui->lineEdit->setText(QString(result.c_str()));
        }
}

void MainWindow::clearLine() { //clears all characters from display
    ui->lineEdit->clear();
    boolNum(true);
}

void MainWindow::deleteChar() { //deletes most recent entered characters from display
    int lineLen = ui->lineEdit->text().length();
    if (lineLen) {
        char endChar = ui->lineEdit->text().at(lineLen - 1).unicode();
        if (!std::isdigit(endChar))
            boolNum(true);
        ui->lineEdit->setText(ui->lineEdit->text().left(lineLen - 1));
    }
}


