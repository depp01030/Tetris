#include <iostream>
#include "raylib.h"
#include "Dependencies/Colors.h"
#include "Dependencies/grid.h"
#include "Dependencies/game.h"
#include "Dependencies/globalParameters.h"
/* The Steps to develop Tetris
* 1. Setup the Game Loop
* 2. Creating the Grid
* 3. Create the Blocks
* 4. Move the Blocks
* 5. Rotate the Blocks
* 6. Checking for collisions
* 7. Check for completed rows
* 8. Game over
* 9. Create User Interface
* 10. Add Score
* 11. Add Next Block
* 12 Add Soudns
*/

/* Game Structure
* Definitions :
*   - Defining the variables needed
*   - Creating the game objects
* Game Loop :
*   - Event Handling (key down event etc.)
*   - Updating the positions of the game objects
*   - Checking for collisions
*   - Drawing Objects
*/
#include <stdio.h>
double lastUpdateTime = 0;


bool EventTriggered(double interval) 
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
     
    return false;
}
int main() { 
	std::cout << "hi" << std::endl;
  
    // init window

    InitWindow(screenWidth + sideBarWidth + edge * 2 , screenHeight + edge * 2, "My first RAYLIB program!");
    SetTargetFPS(60);
    Font font = LoadFontEx("Font/monogram.tff", 64, 0, 0);
    Game game = Game(screenHeight / cellSize, screenWidth / cellSize );

    bool isPause = false;
    while (WindowShouldClose() == false) 
    {

        game.HandleInput();
        if (!game.isPause && EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }


        BeginDrawing();
        ClearBackground(darkBlue) ; 
        DrawTextEx(font, "Score", { SCORE_POS_X , SCORE_POS_Y }, 38, 2, WHITE); 
        DrawTextEx(font, "Next", { NEXT_POS_X, NEXT_POS_Y }, 38, 2, WHITE);
        DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue); 
        DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf_s(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65 }, 38, 2, WHITE);
         
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", { 320, 450 }, 38, 2, WHITE);
        }
        game.Draw();
        EndDrawing(); 
	}
	CloseWindow();
	return 0;

}

