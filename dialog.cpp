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

    // QDialog hd; // Static won't work, once constructor is called
                   // hd will be deleted from memory
    // hd.hide();
    // connect(ui->helpButton, &QPushButton::clicked, &hd, &QDialog::show);
                   // help button will connect to memory address,
                   // which will not be in service after hd is
                   // out of scope

    // QDialog* hd2 = new QDialog; // pointer is made, and will connect to
                               // spot in memory out of scope of function
    // hd2->hide();
    // connect(ui->helpButton, &QPushButton::clicked, hd2, &QDialog::show);
                               // Spot will hold in memory,
                               // but will not be deleted with closing
                               // of Dialog class, resulting in
                               // leaked memory
    hd3 = new QDialog;
    hd3->hide();
    connect(ui->helpButton, &QPushButton::clicked, hd3, &QDialog::show);
                        // pointer is declared outside of function,
                        // making the object easier to delete
                        // find the pointer declaration in
                        // dialog.h
}

Dialog::~Dialog()
{
    delete hd3; // deletes the object the pointer is
                // assigned to
    delete ui;
}
