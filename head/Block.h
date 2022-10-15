#include <graphics.h>

struct Point {
	int row;
	int col;
};

class Block
{
public:
	Block();
	void drop();
	void moveLeftRight(int offset);
	void retate();
	void draw(int leftMargin, int topMargin);

private:
	int blockType;
	Point smallBlocks[4];
	IMAGE *img;

	static IMAGE* imgs[7];
	static int size;
};