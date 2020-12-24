#include <QApplication>
#include <QPushButton>
#include <QPlainTextEdit>
#include <iostream>
#include <string>

int count = 0;

int
main(int argc, char** argv)
{
  QApplication a(argc, argv);

  QWidget window;

  QPlainTextEdit text("0", &window);
  QPushButton inc("+", &window);
  QPushButton dec("-", &window);

  text.setReadOnly(true);

  text.setGeometry(10, 0, 170, 30);
  inc.setGeometry(10, 50, 80, 30);
  dec.setGeometry(100, 50, 80, 30);

  QObject::connect(&inc, &QPushButton::clicked, &text, 
                    [&](){text.setPlainText(QString::number(++count)); } );

  QObject::connect(&dec, &QPushButton::clicked, &text, 
                    [&](){text.setPlainText(QString::number(--count)); } );


  window.show();


  return a.exec();

}
