/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** life.c
*/

#include "global.h"

life_t init_lives(void)
{
    life_t life;

    life.max_lives = 6;
    life.remaining_lives = life.max_lives;
    life.semi = 0;
    life.sprite_half = load_sprite(HALF_HEART);
    life.sprite_full = load_sprite(FULL_HEART);
    life.sprite_empty = load_sprite(EMPTY_HEART);
    return (life);
}

void draw_heart(sfSprite *sprite, sfVector2f position, sfRenderWindow *window)
{
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void display_lives(sfRenderWindow *window, game_t *game)
{
    sfVector2f position = { 10, 10 };
    int offset = 50;
    int full_hearts = game->life_infos.remaining_lives / 2;
    int semi_hearts = game->life_infos.remaining_lives % 2;
    int empty_hearts = MIN((game->life_infos.max_lives
    - game->life_infos.remaining_lives) / 2, game->life_infos.max_lives / 2);

    for (int i = 0; i < full_hearts; i++) {
        position.x += offset;
        draw_heart(game->life_infos.sprite_full, position, window);
    }
    for (int j = 0; j < semi_hearts; j++) {
        position.x += offset;
        draw_heart(game->life_infos.sprite_half, position, window);
    }
    for (int k = 0; k < empty_hearts; k++) {
        position.x += offset;
        draw_heart(game->life_infos.sprite_empty, position, window);
    }
}