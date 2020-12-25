#ifndef COUNTER_HH
#define COUNTER_HH

class Counter
{
  public:
    Counter();
    void show() {window.show();}
    void hide() {window.hide();}

  private:
    QWidget window;
    QPlainTextEdit text;
    QPushButton inc;
    QPushButton dec;
    int count;
};

inline
Counter::Counter() 
  : text("0", &window),
    inc("+", &window),
    dec("-", &window),
    count(0)
{
  
  text.setReadOnly(true);

  text.setGeometry(10, 0, 170, 30);
  inc.setGeometry(10, 50, 80, 30);
  dec.setGeometry(100, 50, 80, 30);

  QObject::connect(&inc, &QPushButton::clicked, &text, 
                    [&](){text.setPlainText(QString::number(++count)); } );

  QObject::connect(&dec, &QPushButton::clicked, &text, 
                    [&](){text.setPlainText(QString::number(--count)); } );
}

#endif

