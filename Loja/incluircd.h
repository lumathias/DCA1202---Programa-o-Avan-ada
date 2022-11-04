#ifndef INCLUIRCD_H
#define INCLUIRCD_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class IncluirCD;
}

class IncluirCD : public QDialog
{
    Q_OBJECT

public:
    explicit IncluirCD(QWidget *parent = nullptr);
    ~IncluirCD();
     void clear();
private slots:
     void on_buttonBox_accepted();

private:
    Ui::IncluirCD *ui;

    QMessageBox  *error_box;

    QString nome;
    QString preco;
    QString numfaixas;
};

#endif // INCLUIRCD_H
