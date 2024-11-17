#include "raylib.h"

int mainGame()
{

    int width = 1280;
    int height = 720;
    int circle_x = (int) width/2;
    int circle_y = (int) height/2;

    int movement =5;
   
    int rectMovemnet = 10;
    int box_y = rectMovemnet;
    int box_x = 800;

    int circle_radius = 20;
    int rectangle_Height = 100;

    int circleBoundingBoxLeft;  
    int circleBoundingBoxRight;  
    int circleBoundingBoxUp;  
    int circleBoundingBoxDown;  

    int rectBoundingBoxLeft;  
    int rectBoundingBoxRight;  
    int rectBoundingBoxUp;  
    int rectBoundingBoxDown;  


    bool intersectLeft;
    bool intersectRight;
    bool intersectUp;
    bool intersectDown;

    bool isPlaying = true;

    InitWindow(width,height,"Axe Game window");
    SetTargetFPS(144);
    while (WindowShouldClose() == false)
    {
       BeginDrawing();
       ClearBackground(WHITE);
        if (isPlaying)
        {
                
            DrawCircle( circle_x,circle_y,circle_radius,BLUE);
            DrawRectangle(box_x,box_y,rectangle_Height,rectangle_Height,RED);
            if (box_y > height || box_y <=0)
            {
                rectMovemnet = - rectMovemnet;
            }
            box_y += rectMovemnet;
            if (circle_x<=width )
            {
                if (IsKeyDown(KEY_D))
                    {
                            circle_x += movement;
                    }                      
            }
            
            if (circle_x>=0)
            {
                if (IsKeyDown(KEY_A))
                    {
                            circle_x -= movement;
                    }
            }
        
            if (circle_y>=0 )
            {
                if (IsKeyDown(KEY_W))
                    {
                            circle_y -= movement;
                    }      
            }
            
            if ( circle_y<=height)
                {
                    if (IsKeyDown(KEY_S))
                        {
                                circle_y += movement;
                        }
                }
            
            circleBoundingBoxLeft = circle_x - circle_radius;  
            circleBoundingBoxRight = circle_x + circle_radius;  
            circleBoundingBoxUp = circle_y - circle_radius;  
            circleBoundingBoxDown= circle_y + circle_radius;  

            rectBoundingBoxLeft = box_x  ;  
            rectBoundingBoxRight= box_x + (rectangle_Height) ;  
            rectBoundingBoxUp = box_y ;  
            rectBoundingBoxDown = box_y +(rectangle_Height) ;  


            intersectLeft =(circleBoundingBoxLeft<=rectBoundingBoxRight);
            intersectRight = (circleBoundingBoxRight>=rectBoundingBoxLeft);
            intersectUp = (circleBoundingBoxUp>=rectBoundingBoxUp);
            intersectDown = (circleBoundingBoxDown<=rectBoundingBoxDown);

        }
        

        if ((intersectLeft&&intersectRight)
         && (intersectUp&&intersectDown))
        {
          DrawText("Game Over", ((int)width/2)-40,(int)height/2,40,BLACK);
          isPlaying = false;
        }
        

       EndDrawing();
       
       
    }
} 