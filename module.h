#ifndef __MODULE_H__
#define __MODULE_H__

#define _UP 'k'
#define _DOWN 'j'
#define _LEFT 'h'
#define _RIGHT 'l'


class Module{

  public:
    void init();
    void mvUp();
    void mvDown();
    void mvLeft();
    void mvRight();
    void show();
    bool isRunning();

  private:
    void check();
    void next();

  private:
    int a[4][4];
    int score;
    bool running;
};

#endif
