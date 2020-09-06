#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // QT-5 connect methods
    connect(ui->userEdit, &QLineEdit::textChanged,ui->userEchoEdit,&QLineEdit::setText);
    connect(ui->userEdit, &QLineEdit::textChanged, ui->userEchoLabel, &QLabel::setText);
    connect(ui->clearButton, &QPushButton::clicked, ui->userEdit, &QLineEdit::clear);
    connect(ui->quitButton, &QPushButton::clicked, this, &Dialog::accept);
}

Dialog::~Dialog()
{
    delete ui;
}
