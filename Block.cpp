#include "Block.h"
#include "random"
#include <time.h>

IMAGE* Block::imgs[7] = { NULL, };
int Block::size = 36;


Block::Block()
{
	if (imgs[0] == NULL) {
		IMAGE imgTmp;
		loadimage(&imgTmp, "res/tiles.png");
		SetWorkingImage(&imgTmp);
		for (int i = 0; i < 7; i++) {
			imgs[i] = new IMAGE;
			getimage(imgs[i], i * size, 0, size, size);
		}
		SetWorkingImage();
	}
	int blocks[7][4] = {
		1,3,5,7,
		2,4,5,7,
		3,5,4,6,
		3,5,4,7,
		2,3,5,7,
		3,5,7,6,
		2,3,4,5,
	};
	blockType = 1 + rand() % 7;

	for (int i = 0; i < 4; i++) {
		int value = blocks[blockType - 1][i];
		smallBlocks[i].row = value / 2;
		smallBlocks[i].col = value % 2;
	}

	img = imgs[blockType - 1];
}

void Block::drop()
{
}

void Block::moveLeftRight(int offset)
{
}

void Block::retate()
{
}

void Block::draw(int leftMargin, int topMargin)
{
	for (int i = 0; i < 4; i++) {
		int x = leftMargin + smallBlocks[i].col * size;
		int y = topMargin + smallBlocks[i].row * size;
		//printf("%d\n",x);
		putimage(x, y, img);
	}
}
