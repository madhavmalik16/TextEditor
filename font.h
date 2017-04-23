#ifndef FONT_H
#define FONT_H

#include <QDialog>

namespace Ui {
class Font;
}

class Font : public QDialog
{
    Q_OBJECT

public:
    explicit Font(QWidget *parent = 0);
    ~Font();

private:
    Ui::Font *ui;
};

#endif // FONT_H
