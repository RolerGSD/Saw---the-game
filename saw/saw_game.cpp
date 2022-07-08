#include "raylib.h"
int main()
{
    //rozmiar okienka
    int width{800};
    int height{450};
    InitWindow(width, height, "Saw - the game");
    
    //koordynaty kółka
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    //krawedzie kółka
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    //koordynaty piły
    int saw_x{400};
    int saw_y{0};
    int saw_length{50};
    //krawędzie piły
    int l_saw_x{saw_x};
    int r_saw_x{saw_x + saw_length};
    int u_saw_y{saw_y};
    int b_saw_y{saw_y + saw_length};

    int direction{10};
    
    bool collision_with_saw = 
                        (b_saw_y >= u_circle_y) && 
                        (u_saw_y <= b_circle_y) && 
                        (l_saw_x <= r_circle_x) && 
                        (r_saw_x >= l_circle_x);
    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        
        
        if (collision_with_saw)
        {
            DrawText("GAME OVER!", 350, 200, 20, RED);
        }
        else
        {
                //początek logiki
                //odświeżanie krawędzi
                l_circle_x = circle_x - circle_radius;
                r_circle_x = circle_x + circle_radius;
                u_circle_y = circle_y - circle_radius;
                b_circle_y = circle_y + circle_radius;
                l_saw_x = saw_x;
                r_saw_x = saw_x + saw_length;
                u_saw_y = saw_y;
                b_saw_y = saw_y + saw_length;
                //odświeżanie warunków kolizji
                collision_with_saw = 
                        (b_saw_y >= u_circle_y) && 
                        (u_saw_y <= b_circle_y) && 
                        (l_saw_x <= r_circle_x) && 
                        (r_saw_x >= l_circle_x);

            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(saw_x, saw_y, saw_length, saw_length, RED);
            
            //ruch piły
            saw_y += direction;
            if(saw_y > height || saw_y < 0) 
            {
                direction = -direction;
            }
            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }
            //koniec logiki
        }
        
        
        EndDrawing();
    }
   
    
}