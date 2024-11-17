
#include "raylib.h"

int main()
{
    const int windowWidth = 1280;
    const int windowHeight = 720;

    InitWindow(windowWidth,windowHeight,"Infinite Ruunner");

    Texture2D player = LoadTexture("textures/scarfy.png");
    
    Rectangle playerRec;
    playerRec.width = player.width/6;
    playerRec.height = player.height;
    playerRec.x =0;
    playerRec.y = 0;
    Vector2 playerPos;
    playerPos.x = windowWidth/2 - playerRec.width/2;
    playerPos.y = windowHeight - playerRec.height;


    const int gravity= 1;

    int velocity = 0;
    int jumpValue = -22;
    bool isGrounded;

    SetTargetFPS(144);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (playerPos.y>=windowHeight - playerRec.height)
        {       
           velocity = 0; //on the ground
           isGrounded = true;
        } 
        else
        {
            /// in the air
            velocity +=gravity;           
            isGrounded = false;
        }


        if (IsKeyPressed(KEY_SPACE) && isGrounded)
        {
            // Jump pressed
            velocity += jumpValue;
            
        }
     
        playerPos.y += velocity;
       
        DrawTextureRec(player,playerRec,playerPos,WHITE);
        
        EndDrawing();
    }
    UnloadTexture(player);
    CloseWindow();

}