/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** struct
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "global.h"

effect_t *create_effect(const char *fpath, int sprite_nb)
{
    effect_t *effect = malloc(sizeof(effect_t));
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(fpath, NULL);

    sfSprite_setTexture(sprite, texture, 1);
    effect->sprite = sprite;
    effect->texture = texture;
    effect->scaling = (sfVector2f){0.6, 0.6};
    effect->sprite_nb = sprite_nb;
    effect->texture_size = sfTexture_getSize(effect->texture);
    effect->rectangle = (sfIntRect) {0, 0,
        effect->texture_size.x / effect->sprite_nb, effect->texture_size.y};
    sfSprite_setScale(effect->sprite, effect->scaling);
    sfSprite_setTextureRect(effect->sprite, effect->rectangle);
    return (effect);
}