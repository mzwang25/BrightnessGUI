#include <QApplication>
#include <QPushButton>
#include <QPlainTextEdit>
#include <iostream>
#include <string>

#include "counter.hh"

int
main(int argc, char** argv)
{
  QApplication a(argc, argv);

  auto c = new Counter;
  c->show();

  return a.exec();

}
