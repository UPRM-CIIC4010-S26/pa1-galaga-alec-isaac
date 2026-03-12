#pragma once

#include <iostream>
#include <string>
#include "raylib-cpp/raylib-cpp.hpp"
#include "Background.hpp"
#include "Player.hpp"
#include "StdEnemy.hpp"
#include "SpEnemy.hpp"
#include "StEnemy.hpp"
#include "DyEnemy.hpp"
#include "PlayerEnemy.hpp" //Bonus
class Program {
    private:
        Background background = Background();
        Player* player = new Player((GetScreenWidth() / 2) - 15, GetScreenHeight() * 0.75f);
// ---- Start of Bonus Area -----------------------------------------------
        PlayerEnemy* player2 = new PlayerEnemy((GetScreenWidth() / 2) - 15, GetScreenHeight() * 0.25f);
// ---- End of Bonus Area -------------------------------------------------
        int respawnCooldown = 1080;
        int respawns = 0;
        int count = 0;
        int delay = 0;
        int lives = 3;
        int pauseFrames = 0;
        
        int score = 0;
        int reset_score = 0;

        bool startup = true;
        bool paused = false;
        bool gameOver = false;

    public:

// ---- Start of Bonus Area -----------------------------------------------
        bool multiplayer = false;
        int winner = 0;
// ---- End of Bonus Area -------------------------------------------------

        Program();
        
        void Update();
        void Draw();
        void ManageEnemyRespawns();
        void DrawStartup();
        void DrawPauseScreen();
        void DrawGameOver();
        void KeyInputs();
        void PlayerReset();
        void Reset();
          
        ~Program() {}
};