#include "Tetris.h"
#include "Block.h"
#include <stdio.h>
#include <time.h>
#include <cstdlib>

const int SPEED_NORMAL = 500;
const int SPEED_QUICK = 50;

Tetris::Tetris(int rows, int cols, int left, int top, int blockSize)
{
	this->leftMargin = left;
	this->topMargin = top;
	this->rows = rows;
	this->cols = cols;
	this->blockSize = blockSize;
	
	for (int i = 0; i < rows; i++) {
		vector<int> mapRow;
		for (int j = 0; j < cols; j++) {
			mapRow.push_back(0);
		}
		map.push_back(mapRow);
	}
}

void Tetris::init()
{
	delay = SPEED_NORMAL;
	srand(time(NULL));
	ratio = 2 / 3;
	/*bgheight = int(1197 * ratio);
	bgwidth = int(900 * ratio);
	为何这种写法无法正确显示*/
	bgheight = 1197 * 2 / 3;
	bgwidth = 900 * 2 / 3;
	initgraph(bgheight, bgwidth);
	loadimage(&imgBg, "res/mybg.jpg", bgheight, bgwidth);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = 0;
		}
	}
}

void Tetris::play()
{
	init();
	int timer = 0;
	

	while (1) {
		keyEvent();
		timer += getDelay();
		if (timer > delay) {
			drop();
			update = true;
			timer = 0;
		}
		if (update) {
			update = false;
			updateWindow();
			Block newblock;
			newblock = Block();
			newblock.draw(leftMargin, topMargin);
			clearLine();
		}
	}
}

void Tetris::keyEvent()
{
}

void Tetris::updateWindow()
{
	putimage(0, 0, &imgBg);

}

int Tetris::getDelay()
{	
	unsigned long long currentTime = GetTickCount();
	static unsigned long long lastTime = 0;
	if (lastTime == 0) {
		lastTime = currentTime;
		return 0;
	}
	else {
		int ret = currentTime - lastTime;
		lastTime = currentTime;
		return ret;
	}
	return 0;
}

void Tetris::drop()
{
}

void Tetris::clearLine()
{
}

