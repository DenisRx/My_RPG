/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** menu_free
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "global.h"

void free_choices(struct menu *menu)
{
    menu_choice_t *current = menu->choices->first;

    sfFont_destroy((sfFont *)sfText_getFont(current->text));
    while (current != NULL) {
        sfText_destroy(current->text);
        current = current->next;
    }
    for (int i = 0; i < 5; i++) {
        sfText_destroy(menu->options[i]->title_text);
        sfText_destroy(menu->options[i]->choice_text);
        sfSprite_destroy(menu->options[i]->back_arrow);
        sfSprite_destroy(menu->options[i]->next_arrow);
        free(menu->options[i]);
    }
}

void free_menu(struct menu *menu)
{
    free_choices(menu);
    free(menu->options);
    free_sprite(menu->choice_bg);
    free_sprite(menu->logo);
    sfFont_destroy(menu->font);
    sfMusic_destroy(menu->menu_music);
    free_sound(menu->hover);
    free_sound(menu->select);
    free_sprite(menu->back_arrow);
    free_sprite(menu->next_arrow);
    free(menu);
}