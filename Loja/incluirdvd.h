#ifndef INCLUIRDVD_H
#define INCLUIRDVD_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class IncluirDVD;
}

class IncluirDVD : public QDialog
{
    Q_OBJECT

public:
    explicit IncluirDVD(QWidget *parent = nullptr);
    ~IncluirDVD();
     void clear();
     void signIncluirDVD (QString nome, QString preco, QString duracao);

private slots:
     void on_buttonBox_accepted();

private:
    Ui::IncluirDVD *ui;

    QMessageBox  *error_box;

    QString nome;
    QString preco;
    QString duracao;
};

#endif // INCLUIRDVD_H
