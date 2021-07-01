/*
** EPITECH PROJECT, 2021
** myowl
** File description:
** menu_utils
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "global.h"

void center_origin_sprite(sfSprite *sprite)
{
    sfIntRect rectangle = sfSprite_getTextureRect(sprite);

    sfSprite_setOrigin(sprite,
    (sfVector2f){rectangle.width/2, rectangle.height/2});
}

void center_sprite(game_t *game, sfSprite *sprite, int offset)
{
    sfIntRect rectangle = sfSprite_getTextureRect(sprite);

    sfSprite_setOrigin(sprite,
    (sfVector2f){rectangle.width/2, rectangle.height/2});
    sfSprite_setPosition(sprite, (sfVector2f){game->resolution.x/2,
        game->resolution.y/2 + offset});
}

void center_text(game_t *game, sfText *text, int offset_x, int offset_y)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);

    sfText_setOrigin(text, (sfVector2f){rect.width/2, rect.height/2});
    sfText_setPosition(text, (sfVector2f){game->resolution.x/2 + offset_x,
        offset_y});
}

int count_choices(const choice_t choices[])
{
    int count = 0;

    while (choices[count].message != NULL)
        count++;
    return (count);
}