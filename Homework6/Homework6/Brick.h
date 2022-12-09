#ifndef BRICK_H
#define BRICK_H


#include "GameObject.h"

namespace gm
{
    struct BrickType    
    {
        int health;
        sf::Color col;
        int score;
        sf::Texture*tex;
    };

    
 
    class Brick : public GameObject
    {
    public:

        Brick();
        Brick(const sf::Vector2f& position, const sf::Vector2f& size, const BrickType* type);
        ~Brick();

        virtual void update(sf::RenderWindow& window, float deltaTime) override;

        virtual void render(sf::RenderWindow& window, float deltaTime) override;

        virtual void setPosition(const sf::Vector2f& position) override;
        virtual void setSize(const sf::Vector2f& size) override;

        virtual void SetAlive(bool isAlive);
        const bool GetAlive() const;

        virtual void SetHealth(const int health);
        const int GetHealth() const;
        bool isAlive = true;

        int score = 0;
       

    private:
        sf::RectangleShape body;
        const BrickType* type;

    protected:
       
        sf::Texture* normal_brick_tex;
        sf::Texture* cracked_brick_tex;
       
        int health = 0;
        sf::Texture* tex;
        
       /* sf::Color col;*/
    };

}

#endif // !BRICK_H
