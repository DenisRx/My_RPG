/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** animation
*/

#include <stdlib.h>
#include "global.h"

void handle_animation(sfRenderWindow *window, animation_t *animation)
{
    if (sfClock_getElapsedTime(animation->animation_clock).microseconds /
    animation->delay >= 1) {
        if (animation->current_frame == animation->sprite_nb - 1) {
            animation->play_count += 1;
            animation->current_frame = -1;
        }
        animation->current_frame++;
        animation->rectangle = (sfIntRect) {animation->rectangle.width *
            animation->current_frame, 0, animation->texture_size.x /
            animation->sprite_nb, animation->texture_size.y};
        sfSprite_setTextureRect(animation->sprite, animation->rectangle);
        sfClock_restart(animation->animation_clock);
    }
    sfRenderWindow_drawSprite(window, animation->sprite, NULL);
}

void draw_animation(sfRenderWindow* window, animation_t *animation,
game_t *game)
{
    if (animation == NULL || game->paused ||
        game->life_infos.remaining_lives <= 0)
        return;
    if (animation->sprite_nb == 1 || animation->pause) {
        sfRenderWindow_drawSprite(window, animation->sprite, NULL);
        return;
    }
    handle_animation(window, animation);
}

void init_animation(animation_t *animation)
{
    animation->current_frame = -1;
    animation->animation_clock = sfClock_create();
    animation->movement_clock = sfClock_create();
    animation->rectangle = (sfIntRect){0, 0, animation->texture_size.x
        / animation->sprite_nb, animation->texture_size.y/animation->lines_nb};
    sfSprite_setPosition(animation->sprite, animation->position);
    sfSprite_setTextureRect(animation->sprite, animation->rectangle);
}

animation_t *create_animation(const char *path, int sprite_nb, int lines_nb,
sfVector2f scale)
{
    animation_t *animation = malloc(sizeof(animation_t));

    animation->texture = sfTexture_createFromFile(path, NULL);
    animation->sprite = load_sprite(path);
    animation->position = (sfVector2f){0, 0};
    animation->scaling = scale;
    animation->color = sfColor_fromRGBA(255, 255, 255, 255);
    animation->sprite_nb = sprite_nb;
    animation->lines_nb = lines_nb;
    animation->texture_size = sfTexture_getSize(animation->texture);
    animation->delay = 120000;
    animation->pause = 0;
    animation->play_count = 0;
    init_animation(animation);
    sfSprite_setScale(animation->sprite, scale);
    return (animation);
}

int is_animation_ended(animation_t *animation)
{
    if (animation->current_frame == animation->sprite_nb - 1) {
        animation->current_frame = -1;
        return (1);
    }
    return (0);
}