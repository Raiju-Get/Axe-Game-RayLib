
#include "raylib.h"

int main()
{
    const int windowWidth = 1280;
    const int windowHeight = 720;

    InitWindow(windowWidth,windowHeight,"Infinite Ruunner");

    const int rectWidth = 50;
    const int rectheight = 80;
    const int gravity= 1;
    int pos_x = (windowWidth/2);
    int pos_y = (windowHeight-rectheight);
    int velocity = 10;
    
    SetTargetFPS(144);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (pos_y>=windowHeight - rectheight)
        {       
           velocity = 0; //on the ground
        } 
        else
        {
            /// in the air
            velocity +=gravity;
           
            
        }


        if (IsKeyPressed(KEY_SPACE))
        {
            // Jump pressed
            velocity -= 10;
            
        }
     
        pos_y += velocity;
       
        
        DrawRectangle(pos_x,pos_y,rectWidth,rectheight,RED);
        EndDrawing();
    }
    CloseWindow();

}