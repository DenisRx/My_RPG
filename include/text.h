/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** text
*/

#ifndef TEXT_H_
#define TEXT_H_

#include <SFML/Graphics.h>

typedef struct text_sprite {
    char *base_message;
    char *message;
    sfColor color;
    int size;
    sfVector2f position;
    int hovering;
} text_sprite_t;

#endif /* !TEXT_H_ */
