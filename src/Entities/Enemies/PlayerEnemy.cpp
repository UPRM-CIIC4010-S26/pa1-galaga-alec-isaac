#include "PlayerEnemy.hpp"

void PlayerEnemy::draw() {
    if (HitBox::drawHitbox) this->hitBox.draw();
    DrawTexturePro(ImageManager::SpriteSheet, Rectangle{2, 75, 15, 12}, 
                    Rectangle{this->position.first, this->position.second, 30, 30}, 
                    Vector2{0, 0}, 0, WHITE);
}

void PlayerEnemy::update() {
    this->hitBox.box.x = this->position.first;
    this->hitBox.box.y = this->position.second;
    this->cooldown--;

    if (HitBox::Collision(Background::sideWalls.first, this->hitBox)) {
        std::pair<double, double> collision = HitBox::CollisionMargins(this->hitBox, Background::sideWalls.first);
        if (abs(collision.second) < abs(collision.first)) {
            this->position.second += collision.second;
        } else {
            this->position.first += collision.first + 1;
        }
    }
    if (HitBox::Collision(Background::sideWalls.second, this->hitBox)) {
        std::pair<double, double> collision = HitBox::CollisionMargins(this->hitBox, Background::sideWalls.second);
        if (abs(collision.second) < abs(collision.first)) {
            this->position.second += collision.second;
        } else {
            this->position.first += collision.first + 1;
        }
    }
}

void PlayerEnemy::keyInputs() {
    if (IsKeyDown(KEY_LEFT)) this->position.first -= this->speed;
    if (IsKeyDown(KEY_RIGHT)) this->position.first += this->speed;
    if (IsKeyPressed(KEY_UP)) this->attack();
}

void PlayerEnemy::attack() {
    if (cooldown <= 0) {
        Projectile::projectiles.push_back(Projectile(Projectile(position.first + + this->hitBox.box.width / 2, position.second, 1)));
        PlaySound(SoundManager::shoot);
        cooldown = 30;
    }
}