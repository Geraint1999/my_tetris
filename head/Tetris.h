#include <vector>
#include <graphics.h>
using namespace std;

class Tetris
{
public:
    Tetris(int rows, int cols, int left, int top, int blockSize);
    void init();
    void play();

private:
    void keyEvent();
    void updateWindow();
    //调用时间计时器
    int getDelay();
    void drop();
    void clearLine();

private:
    int delay = 30;
    bool update = true;
    vector<vector<int>> map;
    int rows;
    int cols;
    int leftMargin;
    int topMargin;
    int blockSize;
    int bgheight;
    int bgwidth;
    float ratio;
    IMAGE imgBg;
};
