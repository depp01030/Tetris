#include "colors.h"

const Color darkGrey = { 26, 31, 40, 150 };
const Color green = { 47, 230, 23, 150 };
const Color red = { 232, 18, 18, 150 };
const Color orange = { 226, 116, 17, 150 };
const Color yellow = { 237, 234, 4, 150 };
const Color purple = { 166, 0, 247, 150 };
const Color cyan = { 21, 204, 209, 150 };
const Color blue = { 13, 64, 216, 150 };
const Color lightBlue = { 59, 85, 162, 150 };
const Color darkBlue = { 44, 44, 127, 255 };

std::vector<Color> GetCellColors()
{ 
	return { darkGrey, green, red, orange, yellow, purple, cyan, blue };

}